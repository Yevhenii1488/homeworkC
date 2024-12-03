CC = gcc
CFLAGS = -Wall -Wextra -g

all: polygons

polygons: main.o
	$(CC) $(CFLAGS) -o polygons main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o polygons