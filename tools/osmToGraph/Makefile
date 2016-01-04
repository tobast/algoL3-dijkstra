CPP=g++
CPPFLAGS=-Wall -Wextra -O3 -std=c++11
OBJS=osmToGraph.o main.o

all: $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o osmToGraph

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) osmToGraph
