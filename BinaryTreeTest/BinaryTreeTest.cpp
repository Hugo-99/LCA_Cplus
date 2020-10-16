#include "pch.h"
#include "CppUnitTest.h"
#include "../BinaryTree/BinaryTree.h"
#include "../BinaryTree/Node.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryTreeTest
{
	TEST_CLASS(BinaryTreeTest)
	{
	public:
		
		TEST_METHOD(LCATest)
		{
			BinaryTree* tree = new BinaryTree(10);
			Node* p = new Node(8);
			Node* q = new Node(12);

			tree->root->left = p;
			tree->root->right = q;
			tree->root->left->left = new Node(6);
			tree->root->right->right = new Node(14);

			Node* LCA = tree->lowestCommonAncestor(p, q);

			Assert::AreEqual(LCA, tree->root);
		}
	};
}
