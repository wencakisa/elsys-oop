CXXFLAGS = -Wall -std=c++11

all: maze

point.o: point.hh point.cc

color.o: color.hh color.cc

turtle.o: turtle.hh turtle.cc

ps_turtle.o: ps_turtle.hh ps_turtle.cc

cell.o: cell.hh cell.cc

board.o: board.hh board.cc

main.o: main.cc

maze: point.o color.o turtle.o ps_turtle.o cell.o board.o main.o
	g++ -o maze point.o color.o turtle.o ps_turtle.o cell.o board.o main.o

clean:
	rm -f *.o maze
