#include "Node.h"
#include <iostream>

Node::Node() {

}

Node::Node(int val) {
	this->val = val;
	this->left = NULL;
	this->right = NULL;
}