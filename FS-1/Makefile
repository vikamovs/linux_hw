CXX = g++
CXXFLAGS = -Wall -Wextra -O2
TARGET = readFile

all:$(TARGET)

$(TARGET):readFile.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) readFile.o

read-file.o:readFile.cpp
	$(CXX) $(CXXFLAGS) -c readFile.cpp

clean:
	rm -f *.o $(TARGET)
