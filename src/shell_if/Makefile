VPATH =
CXX = g++-4.6
CXXFLAGS = -Wall -g3 
LDLIBS = -lpthread
DEPS = shell_client.hpp  shell_server.hpp
OBJ = shell_client.o shell_server.o test.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CFLAGS) -c -o $@ $<

test: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)
    
clean:
	rm -rf *.o

	
