#include "pch.h"
#include "CppUnitTest.h"
#include <algorithm>
#include "../BinaryTree/DAG.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DAGTest
{
	TEST_CLASS(DAGTest)
	{
	public:

		TEST_METHOD(DAGTestCase0) {
			DAG* map = new DAG();

			/*
			* Empty Graph
			*/

			int cmp = map->lowestCommonAncestor_DAG(0, 6, 4);
			int expected = -1;
			Assert::AreEqual(cmp, expected);
		}
		TEST_METHOD(DAGTestCase1) {
			DAG* map = new DAG();

			map->addVertex(0);

			/*
			* Graph with only a root
				0
			*/

			int cmp = map->lowestCommonAncestor_DAG(0, 6, 4);
			int expected = -1;
			Assert::AreEqual(cmp, expected);
		}

		TEST_METHOD(DAGTestCase2) {
			DAG* map = new DAG();

			map->addVertex(0);
			map->addVertex(1);
			map->addVertex(2);
			map->addVertex(3);
			map->addVertex(4);
			map->addVertex(5);
			map->addVertex(6);
			map->addVertex(7);

			map->addEdges(0, 1);
			map->addEdges(0, 2);
			map->addEdges(1, 5);
			map->addEdges(2, 3);
			map->addEdges(5, 6);
			map->addEdges(3, 7);
			map->addEdges(7, 6);
			map->addEdges(7, 4);
			/*
			* Binary Tree Graph
						0
					   / \
					  1   2
				     /     \
					5       3
					         \
							  7
							 / \
							6   4

			*/

			int cmp = map->lowestCommonAncestor_DAG(0, 5, 4);
			int expected = 0;
			Assert::AreEqual(cmp, expected);
		}

		TEST_METHOD(DAGTestCase3)
		{
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

			/* Acyclic Graph
						0
					   / \
					  1   2——3
					 /       /
					5 __    7
						\  / \
						 6    4


			*/

			int cmp = map->lowestCommonAncestor_DAG(0,6,4);
			int expected = 7;
			Assert::AreEqual(cmp,expected);
		}

		TEST_METHOD(DAGTestCase4) {
			DAG* map = new DAG();

			map->addVertex(0);
			map->addVertex(1);
			map->addVertex(2);
			map->addVertex(3);
			map->addVertex(4);
			map->addVertex(5);
			map->addVertex(6);
			map->addVertex(7);

			map->addEdges(0, 1);
			map->addEdges(0, 2);
			map->addEdges(1, 3);
			map->addEdges(1, 4);
			map->addEdges(1, 5);
			map->addEdges(4, 6);
			map->addEdges(5, 7);
			/*
			* N-ary Acylic Graph
						0
					   / \
					  1    2
					/ | \  /
				   3  4  5    
					  |	  \ 
					  6    7
			*/

			int cmp = map->lowestCommonAncestor_DAG(0, 6, 7);
			int expected = 1;
			Assert::AreEqual(cmp, expected);
		}
	};
}
