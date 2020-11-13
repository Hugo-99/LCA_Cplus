#include <iostream>
#include "DAG.h"

DAG::DAG() {

}

void DAG::addVertex(int v) {
	if (edges.find(v)!=edges.end()) {
		edges[v] = std::vector<int>();
	}
}

void DAG::addEdges(int src, int dst) {
	if (edges.find(src) == edges.end()) {
		std::vector<int> tmp = edges.at(src);
		tmp.push_back(dst);
		edges[src] = tmp;
	}
	else {
		addVertex(src);
		addEdges(src,dst);
	}
}

std::vector<int> DAG::getAdjacent(int v) {
	return edges.at(v);
}

bool DAG::containsVertex(int v) {
	return edges.find(v) == edges.end();
}

bool DAG::containsEdge(int src, int dst) {
	if (containsVertex(src)) {
		std::vector<int> tmp = edges.at(src);
		
	}
}

void DAG::getPath(int src, int dst, std::vector<int> path, std::vector<std::vector<int>> pathList) {
	path.push_back(src);

	if (src == dst) {
		pathList.push_back(path);
	}

	std::vector<int> adjacents = getAdjacent(src);

	for (int x : adjacents) {
		getPath(x,dst,path,pathList);
	}
	path.pop_back();
}

std::vector<std::vector<int>> DAG::getAllPaths(int src, int dst) {
	std::vector<std::vector<int>> paths;
	if (!containsVertex(src) || !containsVertex(dst)) {
		return paths;
	}

	getPath(src,dst, std::vector<int>(),paths);

	return paths;
}

int DAG::lowestCommonAncestor_DAG(int root, int p, int q) {
	std::vector<std::vector<int>> path1 = getAllPaths(root,p);
	std::vector<std::vector<int>> path2 = getAllPaths(root,q);

	int lca_depth = 0;
	int lca = -1;

	for (std::vector<int> tmpP : path1) {
		for (std::vector<int> tmpQ : path2) {
			int curVertex = -1;
			int curDepth = 0;

			for (int i = 0; i < tmpP.size() && i < tmpQ.size(); i++) {
				if (tmpP.at(i) != tmpQ.at(i)) {
					break;
				}
				curDepth++;
				curVertex = tmpP.at(i);
			}

			if (curVertex != -1 && curDepth > lca_depth) {
				lca_depth = curDepth;
				lca = curVertex;
			}
		}
	}

	return lca;
}