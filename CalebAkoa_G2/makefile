prog:input.o scrolling.o deplacerPerso.o main.o
	gcc input.o scrolling.o deplacerPerso.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
input.o:input.c
	gcc -c input.c -lSDL -lSDL_image -g
scrolling.o:scrolling.c
	gcc -c scrolling.c -lSDL -lSDL_image -g
deplacerPerso.o:deplacerPerso.c
	gcc -c deplacerPerso.c -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -g