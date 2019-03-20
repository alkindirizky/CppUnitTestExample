CC=g++
CFLAGS=-std=c++11 -Wall -I. -I../catch2 -I../fakeit
DEPS = MotorDriver.hpp

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: main.o MotorDriver.o MotorDriverTest.o 
	$(CC) -o binary main.o MotorDriver.o MotorDriverTest.o

.PHONY: clean

clean:
	rm -f *.o *~