prog:perso.o main.o
	gcc perso.o main.o -o prog -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
perso.o:perso.c
	gcc -c perso.c -g


