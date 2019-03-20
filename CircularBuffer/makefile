CC=g++
CFLAGS=-std=c++11 -Wall -I. -I../catch2 -I../fakeit
DEPS = CircularBuffer.hpp

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: main.o CircularBuffer.o CircularBufferTest.o 
	$(CC) -o binary main.o CircularBuffer.o CircularBufferTest.o

.PHONY: clean

clean:
	rm -f *.o *~