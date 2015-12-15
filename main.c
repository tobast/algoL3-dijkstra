
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: main.c
 * Main file.
 *****************************************************************************/

#include <stdio.h>
#include <string.h>

#include "graph.h"
#include "genericStruct.h"
#include "naiveDijkstra.h"
//#include "dijkstra.h" //TODO

Arguments args(int argc, char** argv) {
	Arguments out;
	out.useNaiveDijkstra = false;

	for(int par=1; par < argc; par++) {
		if(strcmp(argv[par], "--naive"))
			out.useNaiveDijkstra = true;
	}
	return out;
}

int main(int argc, char** argv) {
	Arguments prgmArgs = args(argc, argv);

	// Input graph
	//TODO

	// BEHOLD, as Dijkstra itself is executed.
	if(prgmArgs.useNaiveDijkstra) { // Use the naive array-based version
		//TODO
	}
	else { // Here comes the real stuff.
		//TODO
	}

	// Output path
	//TODO

	return 0;
}

