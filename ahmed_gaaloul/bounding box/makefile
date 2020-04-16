prog:boundingbox.o main.o
	gcc boundingbox.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

main.o: main.c
	gcc -c main.c

boundingbox.o: boundingbox.o
	gcc -c boundingbox.c
