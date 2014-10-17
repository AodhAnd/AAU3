/*
 * posix_thread.hpp
 *
 *  Created on: 10/10/2014
 *      Author: benjaminkrebs
 */

#ifndef POSIX_THREAD_HPP_
#define POSIX_THREAD_HPP_

#include <iostream>
#include <pthread.h>
#include <sys/timerfd.h>

class PosixThread
{
public:

	typedef struct{
		void* args;
		PosixThread* obj;
	} thread_args_t;

	PosixThread(void* (*func)(void*));
	PosixThread(void* (*func)(void*),unsigned int periodicity_ms);

	~PosixThread();

	void startThread();
	void startThread(void* args);
	void stopThread(); //Will block until work is done!


	bool& isPeriodic(){return mIsPeriodic;};

private:
	void* (*mFunc)(void*);
	bool mIsPeriodic;
	unsigned int mPeriodicityUs;
	pthread_t mPthreadStruct;

	void makePeriodic();
	void waitPeriod();
	void* periodicThread(void* args);
	static void* staticPeriodicThread(void* args);

	bool mThreadStop;
	int mTimerfd;
	unsigned long long mWakeUpsMissed;
	thread_args_t mThreadArgs;

};

#endif /* POSIX_THREAD_HPP_ */
