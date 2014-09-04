VPATH = ../inc
CXX = g++
CXXFLAGS = -Wall -g3 
LDLIBS = -lpigpio -lpthread -lrt
DEPS = i2c.hpp imu.hpp types.hpp io_service.hpp
OBJ = i2c.o imu.o io_service.o main.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CFLAGS) -c -o $@ $<

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)
    
clean:
	rm -rf *.o

	
