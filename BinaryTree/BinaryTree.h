#pragma once

#include "Node.h"

class BinaryTree {
	public:
		struct Node* root;
		BinaryTree();
		BinaryTree(int val);
		Node* get(int val);
		bool isExist(Node* leaf);
		Node* lowestCommonAncestor(Node* p, Node* q);
	private:
		Node* get(Node* root, int val);
		Node* lowestCommonAncestor(Node* root, Node* p, Node* q);
};