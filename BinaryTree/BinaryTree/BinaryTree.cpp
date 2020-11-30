// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    this->root = NULL;
}

BinaryTree::BinaryTree(int val) {
    this->root = new Node(val);
}

Node* BinaryTree::get(int val) {
    return get(this->root, val);
}

Node* BinaryTree::get(Node* node, int val) {
    if (node == NULL) {
        return NULL;
    }

    if (node->val == val) {
        return node;
    }

    Node* left = get(node->left, val);

    if (left != NULL && left->val == val) {
        return left;
    }

    Node* right = get(node->right, val);

    return right;
}

bool BinaryTree::isExist(Node* leaf) {
    return get(leaf->val) != NULL;
}

Node* BinaryTree::lowestCommonAncestor(Node* p, Node* q) {
    if (p == NULL || q == NULL) {
        return NULL;
    }
    if (isExist(p) && isExist(q)) {
        return lowestCommonAncestor(this->root, p, q);
    }

    return NULL;
}

Node* BinaryTree::lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL) {
        return right;
    }
    else if (right == NULL) {
        return left;
    }
    else {
        return root;
    }
}

int main()
{

    BinaryTree* tree = new BinaryTree(10);
    Node* p = new Node(6);
    Node* q = new Node(16);

    tree->root->left = new Node(8);
    tree->root->right = new Node(12);
    tree->root->left->left = p;
    tree->root->left->right = q;



    Node* LCA = tree->lowestCommonAncestor(p, q);
    std::cout << LCA->val;
}

