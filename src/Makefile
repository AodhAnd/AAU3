VPATH = ../inc
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g3 
LDLIBS = -lpthread
DEPS = shell_if/shell_server.hpp shell_if/shell_client.hpp momentum_motor.hpp
DEPS += controller/controller_base.hpp
DEPS += controller/controller_factory.hpp
DEPS += controller/controller_test.hpp

OBJ = shell_if/shell_server.o shell_if/shell_client.o momentum_motor.o main.o
OBJ += controller/controller_base.o
OBJ += controller/controller_test.o
OBJ += controller/controller_factory.o

DEPS += posix_thread/posix_thread.hpp
OBJ += posix_thread/posix_thread.o

DEPS += i2c.hpp
OBJ += i2c.o

DEPS += imu.hpp
OBJ += imu.o

DEPS += bbb_gpio.hpp
OBJ += bbb_gpio.o

DEPS += bbb_adc.hpp
OBJ += bbb_adc.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CFLAGS) -c -o $@ $<

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)
    
clean:
	rm -rf *.o
	rm -rf controller/*.o
	rm -rf shell_if/*.o
	rm -rf posix_thread/*.o

	
