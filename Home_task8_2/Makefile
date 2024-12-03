CC = gcc
CFLAGS = -Wall -Wextra

all: test_c_list

test_c_list: test_c_list.o c_list.o
	$(CC) $(CFLAGS) -o test_c_list test_c_list.o c_list.o

c_list.o: c_list.c c_list.h
	$(CC) $(CFLAGS) -c c_list.c

test_c_list.o: test_c_list.c c_list.h
	$(CC) $(CFLAGS) -c test_c_list.c

clean:
	rm -f *.o test_c_list
	