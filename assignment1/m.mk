compile: a.out
a.out:dll.o queue.o music_player.o
	gcc dll.o queue.o music_player.o
dll.o : dll.c dll.h
	gcc -c dll.c
queue.o : queue.c dll.h queue.h
	gcc -c queue.c
music_player.o :music_player.c dll.h queue.h music_player.h
	gcc -c music_player.c

run:
	clear
	./a.out
	./a.out > output.txt

clean:
	rm *out *o