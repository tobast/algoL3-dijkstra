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

#include <cstdio>
#include <cmath>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

typedef size_t VertId;
typedef unordered_map<VertId,VertId> VertMap;

class OsmToGraph {
public:
	struct Vert {
		Vert(VertId id, double lat, double lon) : id(id),lat(lat),lon(lon) {}
		VertId id;
		double lat,lon;
	};
	struct Edge {
		Edge(Vert& v1, Vert& v2) : v1(v1),v2(v2) {}
		Vert& v1;
		Vert& v2;

		int len() { // In meters.
			static auto sq = [](double x) { return x*x; };

			static const int EARTH_RADIUS = 6371000; // meters
			static const long double PI = 3.14159265359;
			long double dlat = PI * (v1.lat - v2.lat)/180.;
			long double dlon = PI * (v1.lon - v2.lon)/180.;
			long double avgLat = PI*(v1.lat + v2.lat)/360.; // average in rad
			
			return round(EARTH_RADIUS *
				sqrt(sq(dlat) + sq(cos(avgLat) * dlon)));
		}
	};

	OsmToGraph(const string& fname);
	void exec(ofstream& ofs, ofstream& outCorresp);

private: //meth
	void newVert(VertId origId, double lat, double lon, ofstream& outCorresp);
	void newEdge(Vert& v1, Vert& v2);
	
	short getAttribute(const string& str, const string& attrName);

	void writeToStream(ofstream& ofs);
	
private:
	const string& fname;
	VertMap mappedVerts;
	vector<Vert> vertices;
	vector<Edge> edges;

	size_t lineNumber;
};

