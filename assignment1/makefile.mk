compile: a.out
a.out: main.o dll.o queue.o music_player.o
	gcc main.o dll.o queue.o music_player.o
main.o : main.c dll.h queue.h music_player.h
	gcc -c main.c
dll.o : dll.c dll.h
	gcc -c dll.c
queue.o : queue.c dll.h queue.h
	gcc -c queue.c
music_player.o : main.c music_player.c dll.h queue.h music_player.h
	gcc -c music_player.c

run:
	clear
	./a.out
	./a.out > output.txt

clean:
	rm *out *o
