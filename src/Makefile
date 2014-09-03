VPATH = ../inc
CXX = clang++
CXXFLAGS = -Wall -g3 
LDLIBS = 
DEPS = i2c.hpp imu.hpp types.hpp 
OBJ = i2c.o imu.o 

%.o: %.cpp $(DEPS)
	$(CXX) $(CFLAGS) -c -o $@ $<

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
    
clean:
	rm -rf *.o

	
