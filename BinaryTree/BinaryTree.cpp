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
    if (root == NULL || root->val == p->val || root->val == q->val) {
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
    tree->root->left = new Node(8);
    tree->root->right = new Node(12);
    tree->root->left->left = new Node(6);
    tree->root->right->right = new Node(14);

    Node* p = new Node(8);
    Node* q = new Node(12);

    Node* LCA = tree->lowestCommonAncestor(p,q);
    std::cout << "hello?\n" << LCA->val;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
