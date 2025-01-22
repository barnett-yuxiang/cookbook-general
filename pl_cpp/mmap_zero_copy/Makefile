CC = g++
CFLAGS = -std=c++17 -Wall
TARGET = mmap_reader

all: $(TARGET)

$(TARGET): mmap_reader.o mmap_utils.o
	$(CC) $(CFLAGS) -o $(TARGET) mmap_reader.o mmap_utils.o

mmap_reader.o: mmap_reader.cpp mmap_utils.h
	$(CC) $(CFLAGS) -c mmap_reader.cpp

mmap_utils.o: mmap_utils.cpp mmap_utils.h
	$(CC) $(CFLAGS) -c mmap_utils.cpp

clean:
	rm -f *.o $(TARGET)