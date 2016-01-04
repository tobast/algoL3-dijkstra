/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: osmToGraph.cpp
 *
 * Converts an Open Street Maps file to a graph formatted as our Dijkstra
 * wants it to be.
 *****************************************************************************/

#include "osmToGraph.h"

OsmToGraph::OsmToGraph(const string& fname) : fname(fname)
{}

void OsmToGraph::exec(ofstream& ofs, ofstream& outCorresp) {
	ifstream handle(fname, fstream::in);
	string line;
	lineNumber = 0;

	vector<VertId> curWay;

	while(getline(handle, line).good()) {
		lineNumber++;
		const char* lineData = line.c_str();
		if(line.find("<node") != string::npos) {
			// Node definition
			short id = getAttribute(line, "id"),
				lat = getAttribute(line, "lat"),
				lon = getAttribute(line, "lon");
			newVert(atol(lineData+id),
				atof(lineData+lat),
				atof(lineData+lon),
				outCorresp);
		}
		else if(line.find("<way") != string::npos) {
			curWay.clear();
		}
		else if(line.find("<nd") != string::npos) {
			curWay.push_back(atol(lineData+getAttribute(line, "ref")));
		}
		else if(line.find("</way>") != string::npos) {
			if(curWay.size() < 2)
				continue;

			for(size_t pos=1; pos < curWay.size(); pos++) {
				newEdge(vertices[mappedVerts[curWay[pos-1]]],
					vertices[mappedVerts[curWay[pos]]]);
			}
		}
	}

	handle.close();
	outCorresp.close();

	writeToStream(ofs);
}

void OsmToGraph::newVert(VertId origId, double lat, double lon,
		ofstream& outCorresp)
{
	VertId nId = vertices.size();
	outCorresp << origId << ' ' << nId << '\n';
	mappedVerts.insert(make_pair(origId, nId));
	vertices.push_back(Vert(nId, lat, lon));
}

void OsmToGraph::newEdge(Vert& v1, Vert& v2) {
	edges.push_back(Edge(v1,v2));
}

short OsmToGraph::getAttribute(const string& str,
		const string& attrName)
{
	size_t pos = str.find(attrName+"=\"");
	if(pos == string::npos) {
		char buffer[150];
		sprintf(buffer, "Attribute \"%s\" was not found at line %lu.",
			attrName.c_str(), lineNumber);
		throw out_of_range(buffer);
	}

	pos += attrName.size() + 2;
	return pos;
}

void OsmToGraph::writeToStream(ofstream& ofs) {
	ofs.sync_with_stdio(false); // We will need this as fast as possible.

	ofs << vertices.size() << ' ' << edges.size() << '\n';
	for(size_t pos=0; pos < edges.size(); pos++) {
		Edge& edge = edges[pos];
		ofs << edge.v1.id << ' ' << edge.v2.id << ' ' << edge.len() << '\n';
	}

	ofs.close();
}

