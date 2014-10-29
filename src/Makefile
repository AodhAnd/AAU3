VPATH = ../inc
CXX = g++
CXXFLAGS = -Wall -g3 
LDLIBS = -lpthread
DEPS = shell_if/shell_server.hpp shell_if/shell_client.hpp momentum_motor.hpp
OBJ = shell_if/shell_server.o shell_if/shell_client.o momentum_motor.o main.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CFLAGS) -c -o $@ $<

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)
    
clean:
	rm -rf *.o

	
