prog: quiz.o main.o
	gcc quiz.o main.o -o prog -lSDL -lSDL_ttf
main.o: main.c
	gcc -c main.c -lSDL -lSDL_ttf
quiz.o: quiz.c
	gcc -c quiz.c -lSDL -lSDL_ttf