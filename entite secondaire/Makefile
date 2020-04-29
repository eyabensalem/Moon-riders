
SDL_CFLAGS = $(shell sdl-config --cflags) -Wall
SDL_LDFLAGS = $(shell sdl-config --libs)

sprites : sprites.c
	${CC}  ${SDL_CFLAGS} ${SDL_LDFLAGS} sprites.c -o sprites
