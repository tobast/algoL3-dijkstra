#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct Loc {
	Loc(double lat,double lon):lat(lat),lon(lon) {}
	double lat,lon;
};

int main(int argc, char** argv) {
	if(argc < 2) {
		fprintf(stderr, "ERROR: Missing argument. Usage:\n%s [corres file]\n",
				argv[0]);
		exit(1);
	}

	vector<Loc> locations;

	ifstream corres(string(argv[1]), fstream::in);
	string line;
	while(getline(corres, line).good()) {
		int junk1, junk2;
		double lat,lon;
		sscanf(line.c_str(), "%d %d %lf %lf", &junk1, &junk2, &lat, &lon);
		locations.push_back(Loc(lat,lon));
	}
	corres.close();


	vector<Loc> givenLocs;
	while(getline(cin, line).good()) {
		int id=atol(line.c_str());
		givenLocs.push_back(locations[id]);
	}

	cout << "<html><body>" <<
		"<div id=\"mapdiv\"></div>" <<
		"<script src=\"http://www.openlayers.org/api/OpenLayers.js\">" <<
		"</script><script>" <<
		"map = new OpenLayers.Map(\"mapdiv\");" <<
		"map.addLayer(new OpenLayers.Layer.OSM());" <<
	    "var markers = new OpenLayers.Layer.Markers( \"Markers\" );" <<
		"map.addLayer(markers);";
	
	for(size_t pos=0; pos < givenLocs.size(); pos++) {
		cout << "markers.addMarker(new OpenLayers.Marker(" <<
			"new OpenLayers.LonLat(" <<
			givenLocs[pos].lon << "," << givenLocs[pos].lat <<
			").transform(new OpenLayers.Projection(\"EPSG:4326\")," <<
			"map.getProjectionObject())));";
	}

	cout << "map.setCenter(" <<
		"new OpenLayers.LonLat(" <<
		givenLocs.front().lon << "," << givenLocs.front().lat <<
		").transform(new OpenLayers.Projection(\"EPSG:4326\")," <<
		"map.getProjectionObject())" <<
		", 16);" <<
		"</script></body></html>";
}

