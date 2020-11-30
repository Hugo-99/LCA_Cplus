#include "pch.h"
#include "CppUnitTest.h"
#include "../BinaryTree/BinaryTree.cpp"
#include "../BinaryTree/Node.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryTreeTest
{
	TEST_CLASS(BinaryTreeTest)
	{
	public:
		
		TEST_METHOD(LCATestCase0)
		{
			/*
				Empty Tree with null nodes
			*/
			BinaryTree* tree = new BinaryTree();
			Node* p = new Node();
			Node* q = new Node();

			Node* LCA = tree->lowestCommonAncestor(p, q);
			Assert::IsNull(LCA);
		}

		TEST_METHOD(LCATestCase1)
		{
			/*
				Empty Tree with nodes
			*/
			BinaryTree* tree = new BinaryTree();
			Node* p = new Node(8);
			Node* q = new Node(12);

			Node* LCA = tree->lowestCommonAncestor(p, q);
			Assert::IsNull(LCA);
		}

		TEST_METHOD(LCATestCase2)
		{
			/*
				Normal Tree Case 1

					  10
					  / \
					 8   12
					/     \
				   6       14
			*/
			BinaryTree* tree = new BinaryTree(10);
			Node* p = new Node(8);
			Node* q = new Node(12);

			tree->root->left = p;
			tree->root->right = q;
			tree->root->left->left = new Node(6);
			tree->root->right->right = new Node(14);

			Node* LCA = tree->lowestCommonAncestor(p, q);

			Assert::AreEqual(LCA->val, 10);
		}

		TEST_METHOD(LCATestCase3)
		{
			/*
				Normal Tree Case 2

					  10
					  / \
					 8   12
					/ \
				   6   16
			*/
			BinaryTree* tree = new BinaryTree(10);
			Node* p = new Node(6);
			Node* q = new Node(16);

			tree->root->left = new Node(8);
			tree->root->right = new Node(12);
			tree->root->left->left = p;
			tree->root->left->right = q;

			Node* LCA = tree->lowestCommonAncestor(p, q);

			Assert::AreEqual(LCA->val, 8);
		}

		TEST_METHOD(LCATestCase4)
		{
			/*
				Normal Tree Case 3

					  10
					  / \
					 8   12
					/
				   6
				  /
				 1
			*/
			BinaryTree* tree = new BinaryTree(10);
			Node* p = new Node(1);
			Node* q = new Node(12);

			tree->root->left = new Node(8);
			tree->root->right = q;
			tree->root->left->left = new Node(6);
			tree->root->left->left->left = p;

			Node* LCA = tree->lowestCommonAncestor(p, q);

			Assert::AreEqual(LCA->val, 10);
		}
	};
}
