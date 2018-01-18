all: turtle

point.o: point.hh point.cc

color.o: color.hh color.cc

turtle.o: turtle.hh turtle.cc

ps_turtle.o: ps_turtle.hh ps_turtle.cc

main.o: main.cc

turtle: point.o color.o turtle.o ps_turtle.o main.o
	g++ -o turtle point.o color.o turtle.o ps_turtle.o main.o

clean:
	rm -f *.o turtle
