CC=g++
CFLAGS=-std=c++11 -Wall -I. -I../catch2 -I../fakeit
DEPS = SerialProcessor.hpp

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: main.o SerialProcessor.o SerialProcessorTest.o 
	$(CC) -o binary main.o SerialProcessor.o SerialProcessorTest.o

.PHONY: clean

clean:
	rm -f *.o *~