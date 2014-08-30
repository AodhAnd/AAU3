VPATH = ../inc
CXX = clang++
CXXFLAGS = -Wall -g3 
LDLIBS = 

default: main.o i2c.o imu.o
	$(CXX) $(CXXFLAGS) -o main main.o i2c.o imu.o $(LDLIBS)

main.o: i2c.hpp imu.hpp types.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp 

i2c.o: i2c.hpp types.hpp
	$(CXX) $(CXXFLAGS) -c i2c.cpp
	
imu.o: imu.hpp i2c.hpp types.hpp
	$(CXX) $(CXXFLAGS) -c imu.cpp
 
    
clean:
	rm -rf *.o

	
