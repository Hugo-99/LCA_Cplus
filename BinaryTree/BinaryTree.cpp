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

Node* BinaryTree::get(Node *node, int val) {
    if (node == NULL) {
        return NULL;
    }

    if (node->val == val) {
        return node;
    }

    struct Node* left = get(node->left, val);

    if (left != NULL && left->val == val) {
        return node;
    }

    struct Node* right = get(node->right, val);

    return right;
}

bool BinaryTree::isExist(Node* leaf) {
    return get(leaf->val) != NULL;
}

Node* BinaryTree::lowestCommonAncestor(Node* p, Node* q) {
    if (isExist(p) && isExist(q)) {
        return lowestCommonAncestor(this->root, p, q);
    }

    return NULL;
}

Node* BinaryTree::lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    struct Node* left = lowestCommonAncestor(root->left, p, q);
    struct Node* right = lowestCommonAncestor(root->right, p, q);

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
    Node* p = new Node(8);
    Node* q = new Node(12);

    tree->root->left = p;
    tree->root->right = q;
    tree->root->left->left = new Node(6);
    tree->root->right->right = new Node(14);

    

    Node* LCA = tree->lowestCommonAncestor(p,q);
    std::cout << LCA->val;
}

