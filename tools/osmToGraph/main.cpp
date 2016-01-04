/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: main.cpp -- osmToGraph
 * 
 * Main of osmToGraph -- a tool that converts OpenStreetMap data to a graph.
 *****************************************************************************/

#include <cstdio>
#include <fstream>
#include <string>

#include "osmToGraph.h"

int main(int argc, char** argv) {
	if(argc < 3) {
		fprintf(stderr, "ERROR: Missing argument(s). Usage:\n"
			"%s inFile.osm outFile outCorrespTable\n", argv[0]);
		exit(1);
	}

	string infile = string(argv[1]);
	string outfile = string(argv[2]);
	string outCorresp = string(argv[3]);

	OsmToGraph otg(infile);
	ofstream outStream = ofstream(outfile, fstream::out);
	ofstream outCorrespHandle = ofstream(outCorresp, fstream::out);
	otg.exec(outStream, outCorrespHandle);
	return 0;
}

