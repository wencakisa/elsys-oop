all: hexagon star sierpinski


turtle.o: turtle.hh turtle.cc

svg_turtle.o: svg_turtle.hh svg_turtle.cc


figure.o: figure.hh figure.cc

axis.o: axis.hh axis.cc


hexagon.o: hexagon.hh hexagon.cc

hexagon_main.o: hexagon_main.cc


star.o: star.hh star.cc

star_main.o: star_main.cc


sierpinski.o: sierpinski.hh sierpinski.cc

sierpinski_main.o: sierpinski_main.cc


hexagon: turtle.o svg_turtle.o figure.o axis.o hexagon.o hexagon_main.o
	g++ -o hexagon turtle.o svg_turtle.o figure.o axis.o hexagon.o hexagon_main.o

star: turtle.o svg_turtle.o figure.o axis.o star.o star_main.o
	g++ -o star turtle.o svg_turtle.o figure.o axis.o star.o star_main.o

sierpinski: turtle.o svg_turtle.o figure.o sierpinski.o sierpinski_main.o
	g++ -o sierpinski turtle.o svg_turtle.o figure.o sierpinski.o sierpinski_main.o


clean:
	rm -f *.o hexagon star sierpinski *.eps *.html
