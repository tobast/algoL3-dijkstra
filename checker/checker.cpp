
/******************************************************************************
 * Algorithmic project (l3) - Dijkstra algorithm using Fibonacci heap
 ******************************************************************************
 * Théophile Bastian <contact@tobast.fr>, Noémie Cartier
 ******************************************************************************
 * File: checker.cpp
 ***********
 * WARNING * This file is *NOT* part of the project by itself, but it is
 *********** merely a *tool* to check that the project is correct!
 *
 * Implements the project in C++ using C++ priority_queue (which are correct),
 * allowing us to check our results against the results of this checker.
 *****************************************************************************/

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	Edge(int weight, int id) : weight(weight), id(id) {}
	int weight, id;
};

struct DijPos {
	DijPos(int weight, int pos) : weight(weight), pos(pos) {}
	int weight, pos;
	bool operator<(const DijPos& e) const {
		return weight > e.weight;
	}
};

void dijkstra(const vector<vector<Edge> >& graph, const int source,
		vector<int>& results)
{
	priority_queue<DijPos> toProcess;
	toProcess.push(DijPos(0,source));

	while(!toProcess.empty()) {
		DijPos pos = toProcess.top();
		toProcess.pop();
		
		if(results[pos.pos] < 0) {
			results[pos.pos] = pos.weight;
			
			for(size_t child=0; child < graph[pos.pos].size(); child++) {
				toProcess.push(DijPos(
					pos.weight + graph[pos.pos][child].weight,
					graph[pos.pos][child].id));
			}
		}
	}
}

int main(void) {
	// Input graph
	int nbVert, nbEdges;
	scanf("%d %d", &nbVert, &nbEdges);

	vector<vector<Edge> > graph(nbVert);
	for(int edge=0; edge < nbEdges; edge++) {
		int from,to,weight;
		scanf("%d %d %d", &from, &to, &weight);
		graph[from].push_back(Edge(weight, to));
	}

	int nbSources;
	scanf("%d", &nbSources);

	for(int sourceId=0; sourceId < nbSources; sourceId++) {
		int sourceVert;
		scanf("%d", &sourceVert);

		vector<int> distances(nbVert, -1);
		dijkstra(graph, sourceVert, distances);

		// Output path
		for(int vert=0; vert < nbVert; vert++) {
			if(distances[vert] < 0)
				printf("%d: +∞\n", vert);
			else
				printf("%d: %d\n", vert, distances[vert]);
		}
	}

	return 0;
}

