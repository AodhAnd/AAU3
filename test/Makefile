VPATH = ../inc
CXX = clang++
CXXFLAGS = -Wall -g3
LDFLAGS = -L/usr/local/lib
LDLIBS = -lboost_thread-mt -lboost_system
DEPS = thread_test.cpp
OBJ = thread_test.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CFLAGS) -c -o $@ $<

thread_test: $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
    
clean:
	rm -rf *.o

	
