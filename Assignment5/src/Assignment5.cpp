#include <iostream>
#include "ChainedHashTable.h"
#include "DataStructureTester.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

using namespace std;
using namespace ods;

int main() {
	DataStructureTester<BinarySearchTree<BSTNode1<int>, int> > test;

	//test.AddRandom(10);

	test.DoRandomAdd(100000);
	//test.DoSequentialAdd(0, 100000, 1);

	DataStructureTester<RedBlackTree<RedBlackNode1<int>, int> > test2;
	//test2.DoRandomAdd(100000);
	//test2.DoSequentialAdd(0, 100000, 1);

	//DataStructureTester<LinearHashTable<int>(0,-1)> test3;
	//test3.DoSequentialAdd(0, 100000, 1);

	return 0;
}
