VPATH = ../../inc
CXX = g++
CXXFLAGS = -std=c++0x -Wall -g3 
DEPS = ../../inc/reverse_polish_notation_calculator.hpp ../../inc/shunting_yard.hpp  rpn_test_main.cpp
OBJ = ../../src/reverse_polish_notation_calculator.o ../../src/shunting_yard.o rpn_test_main.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

rpn_test_main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)
    
clean:
	rm -rf *.o

	
