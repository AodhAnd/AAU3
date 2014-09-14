VPATH = ../inc
CXX = g++
CXXFLAGS = -Wall -g3
LDFLAGS = -L/usr/local/lib
LDLIBS = 
DEPS = parser_test.cpp
OBJ = parser_test.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CFLAGS) -c -o $@ $<

parser_test: $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
    
clean:
	rm -rf *.o

	
