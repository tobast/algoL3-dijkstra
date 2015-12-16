CC=gcc
CCFLAGS=-Wall -Wextra -std=c99 -Wno-unused-result -O2
CCLIBS=
TARGET=dijkstra
CHECKER=checker/checker
OBJS=genericStruct.o extendLists.o tree.o linkedLists.o fiboHeap.o graph.o \
	naiveDijkstra.o dijkstra.o main.o

all: $(TARGET) $(CHECKER)

$(CHECKER):
	g++ -Wall -Wextra -O2 $(CHECKER).cpp -o $(CHECKER)
$(TARGET): $(OBJS)
	$(CC) $^ $(CCFLAGS) $(CCLIBS) -o $@

%.o: %.c
	$(CC) -c $< $(CCLIBS) $(CCFLAGS) -o $@

.PHONY: clean

clean:
	rm -f *.o $(TARGET)
