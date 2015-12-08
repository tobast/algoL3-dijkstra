CC=gcc
CCFLAGS=-Wall -Werror -std=c99 -O2
CCLIBS=
TARGET=dijkstra
OBJS=linkedLists.o main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ $(CCFLAGS) $(CCLIBS) -o $@

%.o: %.cpp
	$(CC) -c $< $(CCLIBS) $(CCFLAGS) -o $@

.PHONY: clean

clean:
	rm -f *.o $(TARGET)