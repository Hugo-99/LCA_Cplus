#include <iostream>
#include "DAG.h"

DAG::DAG() {

}

void DAG::addVertex(int v) {
	if (edges.find(v) == edges.end()) {
		edges[v] = std::vector<int>();
	}
}

void DAG::addEdges(int src, int dst) {
	if (edges.find(src) != edges.end()) {
		edges.at(src).push_back(dst);
	}
	else {
		addVertex(src);
		addEdges(src, dst);
	}
}

std::vector<int> DAG::getAdjacent(int v) {
	return edges.at(v);
}

bool DAG::containsVertex(int v) {
	return edges.find(v) != edges.end();
}

void DAG::getPath(int src, int dst, std::vector<int> path, std::vector<std::vector<int>>& pathList) {
	path.push_back(src);

	if (src == dst) {
		pathList.push_back(path);
		return;
	}

	std::vector<int> adjacents = getAdjacent(src);

	for (int x : adjacents) {
		getPath(x, dst, path, pathList);
	}
	path.pop_back();
}

std::vector<std::vector<int>> DAG::getAllPaths(int src, int dst) {
	std::vector<std::vector<int>> paths;
	if (!containsVertex(src) || !containsVertex(dst)) {
		return paths;
	}

	getPath(src, dst, std::vector<int>(), paths);

	return paths;
}

int DAG::lowestCommonAncestor_DAG(int root, int p, int q) {
	std::vector<std::vector<int>> path1 = getAllPaths(root, p);
	std::vector<std::vector<int>> path2 = getAllPaths(root, q);

	/*
	for (std::vector<int> A : path2) {
		for (int x : A) {
			std::cout << x << " ";
		}
		std::cout << "\n";
	}
	*/

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

int main() {
	DAG* map = new DAG();

	map->addVertex(0);
	map->addVertex(1);
	map->addVertex(2);
	map->addVertex(3);
	map->addVertex(4);
	map->addVertex(5);
	map->addVertex(6);
	map->addVertex(7);

	map->addEdges(0,1);
	map->addEdges(0,2);
	map->addEdges(1,5);
	map->addEdges(2,3);
	map->addEdges(5,6);
	map->addEdges(3,7);
	map->addEdges(7,6);
	map->addEdges(7,4);

	int ans = map->lowestCommonAncestor_DAG(0, 5, 4);
	std::cout << ans;
}