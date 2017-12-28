CXXFLAGS=-std=c++11 -Wall -pedantic-errors

all: postfix

calculator.o: calculator.cc calculator.hh

postfix.o: postfix.cc

unary.o: unary.cc unary.hh

negate.o: negate.cc negate.hh

sqrt.o: sqrt.cc sqrt.hh

binary.o: binary.cc binary.hh

plus.o: plus.cc plus.hh

minus.o: minus.cc minus.hh

multiply.o: multiply.cc multiply.hh

divide.o: divide.cc divide.hh

manipulating.o: manipulating.cc manipulating.hh

dup.o: dup.cc dup.hh

drop.o: drop.cc drop.hh

swap.o: swap.cc swap.hh

rot3.o: rot3.cc rot3.hh

composite.o: composite.cc composite.hh operation.hh

literal.o: literal.cc literal.hh operation.hh calculator.hh

postfix: calculator.o postfix.o unary.o negate.o sqrt.o binary.o plus.o minus.o multiply.o divide.o manipulating.o dup.o drop.o swap.o rot3.o composite.o literal.o
	g++ -o postfix calculator.o postfix.o unary.o negate.o sqrt.o binary.o plus.o minus.o multiply.o divide.o manipulating.o dup.o drop.o swap.o rot3.o composite.o literal.o

clean:
	rm -rf *.o postfix
