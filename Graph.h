#pragma once
#include <vector>
#include <string>
using namespace std;

const int Vmax = 50;
const int Emax = Vmax * (Vmax - 1) / 2;

class Edge {
public:
	int source, destination, weight;

	Edge(int src, int dest, int w) : source(src), destination(dest), weight(w) {}
};

class Graph {
public:
	Graph(const vector<Edge>& edges, int numVertices, const vector< string>& cities);

	void DFS(int startCityIndex) const;
	void Dijkstra(int startCityIndex) const;

private:
	vector< vector<int>> adjacencyMatrix;
	vector<Edge> edges;
	vector< string> cities;

	void DFSHelper(int cityIndex, vector<bool>& visited) const;
	int getMinDistance(const  vector<int>& distances, const  vector<bool>& visited) const;
	void printPath(const  vector<int>& parents, int currentCityIndex) const;
};
