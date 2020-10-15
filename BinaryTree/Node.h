#pragma once

class Node {
	public:
		int val;
		struct Node *left, *right;
		Node(int val);
};