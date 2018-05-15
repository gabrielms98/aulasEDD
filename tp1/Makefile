all: Tetris.o jogoTetris.cpp teste.cpp
	g++ Tetris.o jogoTetris.cpp -lncurses -ojogo

Tetris.o: Tetris.cpp Tetris.h
	g++ -c Tetris.cpp Tetris.h

rm:
	rm *.o *.gch
