CC=gcc
CCFLAGS=-Wall -Wextra -std=c99 -Wno-unused-result -O2
CCLIBS=
TARGET=dijkstra
OBJS=genericStruct.o extendLists.o tree.o linkedLists.o fiboHeap.o main.o

#all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ $(CCFLAGS) $(CCLIBS) -o $@

%.o: %.c
	$(CC) -c $< $(CCLIBS) $(CCFLAGS) -o $@

.PHONY: clean

clean:
	rm -f *.o $(TARGET)
