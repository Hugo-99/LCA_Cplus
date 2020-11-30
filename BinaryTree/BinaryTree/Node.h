#pragma once

class Node {
public:
	Node(int val);
	Node();
	int val;
	Node* left, * right;
};