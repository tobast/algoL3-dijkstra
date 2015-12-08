CC=gcc
CCFLAGS=-Wall -Werror -O2
CCLIBS=
TARGET=dijkstra
OBJS=main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ $(CCFLAGS) $(CCLIBS) -o $@

%.o: %.cpp
	$(CC) -c $< $(CCLIBS) $(CCFLAGS) -o $@

.PHONY: clean

clean:
	rm -f *.o $(TARGET)
