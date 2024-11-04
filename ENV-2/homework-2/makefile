CC=g++

CGFLAGS=-c

all: hello

hello: main.o Sort.o ComplexNumber.o
	$(CC) $^ -o hello

main.o: main.cpp	
	$(CC) $(CGFLAGS) main.cpp

Sort.o: Sort.cpp
	$(CC) $(CGFLAGS) Sort.cpp

ComplexNumber.o: ComplexNumber.cpp
	$(CC) $(CGFLAGS) ComplexNumber.cpp

clean:
	rm -rf *.o hello
