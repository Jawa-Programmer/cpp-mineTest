

all: clean testGame
	./mineTest

testGame: main.o
	g++ testGame.o -o mineTest -I /usr/include -lglut -lGL -lGLU

main.o: testGame.cpp
	g++ -c testGame.cpp

clean:
#	rm -rf *.o mineTest
	rm -rf mineTest
clear:
	rm -rf *.o