CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
OBJS = main.o calculator.o parser.o

calc: $(OBJS)
	$(CXX) $(CXXFLAGS) -o calc $(OBJS)

main.o: main.cpp calculator.h parser.h
calculator.o: calculator.cpp calculator.h
parser.o: parser.cpp parser.h

clean:
	rm -f *.o calc