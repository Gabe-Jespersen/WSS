CC = g++
CFLAGS = -std=c++11 -g -Wall -fpermissive -O2
BINARY = JWSS

all: JWSS

JWSS: main.o puzzle.o utils.o malgo.o
	$(CC) $(CFLAGS) main.o puzzle.o utils.o malgo.o -o $(BINARY)

main.o: main.cpp puzzle.h utils.h malgo.h
	$(CC) $(CFLAGS) -c main.cpp

puzzle.o: puzzle.cpp puzzle.h
	$(CC) $(CFLAGS) -c puzzle.cpp

utils.o: utils.cpp utils.h
	$(CC) $(CFLAGS) -c utils.cpp

malgo.o: malgo.cpp puzzle.h malgo.h
	$(CC) $(CFLAGS) -c malgo.cpp

clean:
	rm -rf *.o $(BINARY)
