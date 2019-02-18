CCFLAGS = -Wall -std=c++11

solution.exe: main.o Equation.o
	g++ $(CCAFLAGS) -o solution.exe main.o Equation.o

main.o: main.cpp
	g++ $(CCFLAGS) -c main.cpp

Equation.o: Equation.cpp Equation.h
	g++ $(CCFLAGS) -c Equation.cpp

clean:
	-rm *.o solution.exe
