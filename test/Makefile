VPATH = ../inc
CXX = clang++
CXXFLAGS = -Wall -g3
LDFLAGS = -L/usr/local/lib
LDLIBS = 
DEPS = ../inc/thread.hpp thread_test.cpp
OBJ = ../src/thread.o thread_test.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CFLAGS) -c -o $@ $<

thread_test: $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
    
clean:
	rm -rf *.o

	
