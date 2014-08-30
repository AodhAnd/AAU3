/* AAU3_main.c */
// Compile with -lpigpio -lpthread -lrt
  
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/timerfd.h> //For the timers
#include "AAU3_i2c.h"
#include "AAU3_motors.h"
#include "MPU6050.h"
#include "PCF8591.h"

#define I2C_DEVICE "/dev/i2c-1"
#define MPU1_ADDR 0x68
#define MPU2_ADDR 0x69
#define ADDA_ADDR 0x4F
#define MOTOR_IO_CW 18
#define MOTOR_IO_CCW 23


pthread_t thread_id[8];
pthread_attr_t thread_attr[8];
struct sched_param sched_par[8];
pthread_mutex_t msg_mutex;


enum commands
{
	STOP,
	BEGIN,
	INFO,
	EMPTY,
	MOTOR_CW,
	MOTOR_CCW,
	MOTOR_OFF
};

struct periodic_info
{
	int timer_fd;
	unsigned long wakeups_missed;
};


enum commands cmd_msg = EMPTY;

void* prompt(void* var);
void* controller(void* var);
static int make_periodic(unsigned int period, struct periodic_info *info);
void wait_period (struct periodic_info *info);
struct PCF pcfDevice;


void* testfunction(void* var){
	struct periodic_info pinfo;

	make_periodic(10000,&pinfo);

	int dac_ctrl = 0;

	while(cmd_msg != STOP){


		if (cmd_msg == MOTOR_CW){
			if(gpioWrite(MOTOR_IO_CW, 1) < 0){
				perror("Couldn't write CW value to motor");
			}
			if(gpioWrite(MOTOR_IO_CCW, 0) < 0){
				perror("Couldn't write CCW value to motor");
			}
			cmd_msg = EMPTY;
		}
		else if(cmd_msg == MOTOR_CCW){
			if(gpioWrite(MOTOR_IO_CW, 0) < 0){
				perror("Couldn't write OFF value to motor");
			}
			if(gpioWrite(MOTOR_IO_CCW, 1) < 0){
				perror("Couldn't write OFF value to motor");
			}
			cmd_msg = EMPTY;			
		}
		else if(cmd_msg == MOTOR_OFF){
			if(gpioWrite(MOTOR_IO_CW, 0) < 0){
				perror("Couldn't write OFF value to motor");
			}
			if(gpioWrite(MOTOR_IO_CCW, 0) < 0){
				perror("Couldn't write OFF value to motor");
			}
			cmd_msg = EMPTY;			
		}
		else if(cmd_msg == INFO){
			printf("ADC Channel 0: %d\n", readADC(0,&pcfDevice));
			cmd_msg = EMPTY;
		}


		if (cmd_msg != EMPTY && cmd_msg != STOP)
		{
			cmd_msg = EMPTY;
		}


		if(dac_ctrl == 0){
			setDAC(&pcfDevice, 0x00);
			dac_ctrl = 1;
		}
		else{
			setDAC(&pcfDevice, 0xFF);
			dac_ctrl = 0;
		}


		wait_period(&pinfo);
	}

	printf("test function terminated\n");
	pthread_exit(NULL);
}


/****** MAIN ******/

int main(void){

	/* initialisation */
	if(pthread_mutex_init(&msg_mutex, NULL)){
		perror("Mutex init");
	}

	// I2C interface
	int i2c_fd = i2cOpen(I2C_DEVICE);

	// DAC and ADC's
	pcfDevice = initPCF(ADDA_ADDR, I2C_DEVICE);


	// Motors
	initMotors();

	// Servo


	// UDP interface


	// MPU's 
	/*
	struct MPU mpu1, mpu2;
	mpu1.i2cDevice_fd = i2c_fd;
	mpu2.i2cDevice_fd = i2c_fd;
	mpu1 = initMPU6050(MPU1_ADDR);
	mpu2 = initMPU6050(MPU2_ADDR);
	*/


	/* Threads */
	pthread_attr_init(&thread_attr[0]);
	sched_par[0].sched_priority = 90;
	pthread_attr_setschedparam(&thread_attr[0], &sched_par[0]);

	if(pthread_create(&thread_id[1], &thread_attr[0], testfunction, NULL)<0){
		perror("creating testfunction thread");
		pthread_exit(NULL);
		exit(1);
	}


	// Prompt interpreter
	if(pthread_create(&thread_id[0], NULL, prompt, NULL)<0){
		perror("creating prompt thread");
		pthread_exit(NULL);
		exit(1);
	}

	// Controller





	/* Join threads and close up */
	pthread_join(thread_id[0], NULL);
	pthread_join(thread_id[1], NULL);

	//terminateConMPU6050(mpu1);

	pthread_mutex_destroy(&msg_mutex);

	//Terminate Motor Controls
	if(gpioWrite(MOTOR_IO_CW, 0) < 0){
		perror("WARNING! Couldn't turn off motor!!");
	}
	if(gpioWrite(MOTOR_IO_CCW, 0) < 0){
		perror("WARNING! Couldn't turn off motor!!");
	}
	gpioTerminate();

	PCFterminate(pcfDevice);

	exit(0);
}








void interpreter(char msg){

	if (cmd_msg != EMPTY && msg != 's')
	{
		printf("Interpreter was called before the former command was executed\n");
	}
	else{
		switch(msg){
			case 's':
				cmd_msg = STOP;
				break;
			case 'b':
				cmd_msg = BEGIN;
				break;
			case 'i':
				cmd_msg = INFO;
				break;
			case 'c':
				cmd_msg = MOTOR_CW;
				break;
			case 'w':
				cmd_msg = MOTOR_CCW;
				break;
			case 'f':
				cmd_msg = MOTOR_OFF;
				break;
			default:
				printf("Unknown command\n");
				cmd_msg = EMPTY;
				break;
		}
	}
}



void* prompt(void* var){
	printf("Available commands: \n's' : Stop execution \n'i' : Write out general status \n'c' : Motor CW\n'w' : Motor CCW\n'f' : Stop Motor\n");
	while(1){
		char msg;

		scanf(" %c",&msg);

		if(pthread_mutex_lock(&msg_mutex)<0){
			perror("msg mutex lock");
		}

		interpreter(msg);

		if(cmd_msg == STOP){
			break;
		}

		if(pthread_mutex_unlock(&msg_mutex)<0){
			perror("msg mutex unlock");
		}

	}

	printf("Prompt terminated\n");
	pthread_exit(NULL);
}



void* controller(void* var){


}

static int make_periodic(unsigned int period, struct periodic_info *info)
{
	int ret;
	unsigned int ns;
	unsigned int sec;
	int fd;
	struct itimerspec itval;

	/* Create the timer */
	fd = timerfd_create (CLOCK_MONOTONIC, 0);
	info->wakeups_missed = 0;
	info->timer_fd = fd;
	if (fd == -1)
		return fd;

	/* Make the timer periodic */
	sec = period/1000000;
	ns = (period - (sec * 1000000)) * 1000;
	itval.it_interval.tv_sec = sec;
	itval.it_interval.tv_nsec = ns;
	itval.it_value.tv_sec = sec;
	itval.it_value.tv_nsec = ns;
	ret = timerfd_settime (fd, 0, &itval, NULL);
	return ret;
}

void wait_period (struct periodic_info *info)
{
	unsigned long long missed;
	int ret;

	/* Wait for the next timer event. If we have missed any the
	   number is written to "missed" */
	ret = read (info->timer_fd, &missed, sizeof (missed));
	if (ret == -1)
	{
		perror ("read timer");
		return;
	}

	/* "missed" should always be >= 1, but just to be sure, check it is not 0 anyway */
	if (missed > 1){
		info->wakeups_missed += missed;
		printf("Missed a wakeup!! %d\n",missed);
	}
}



void adda_write(void){
	char ctrl_reg = 0x40; // Enable DAC and read AIN0
	char dac_out = 0x80;

}
