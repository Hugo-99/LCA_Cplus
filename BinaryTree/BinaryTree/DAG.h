#pragma once
#include <unordered_map> 
#include <vector>

class DAG {
public:
	DAG();
	void addVertex(int v);
	void addEdges(int start, int end);
	std::vector<int> getAdjacent(int v);
	bool containsVertex(int v);
	bool containsEdge(int start, int end);
	void removeVertex(int v);
	void removeEdge(int start, int end);
	std::vector<std::vector<int>> getAllPaths(int src, int dst);
	int lowestCommonAncestor_DAG(int root, int p, int q);

private:
	std::unordered_map<int, std::vector<int>> edges;
	void getPath(int src, int dst, std::vector<int> path, std::vector<std::vector<int>>& pathList);

};