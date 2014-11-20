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
	DataStructureTester<RedBlackTree<RedBlackNode1<int>, int> > test2;
	DataStructureTester<LinearHashTable<int> > test3;
	DataStructureTester<ChainedHashTable<int> > test4;

//BStree test

	for(int i = 0; i < 20; i++){
	cout << "BST Sequential add" << i+1 << ":" << test.DoSequentialAdd(0, 50000, 1) << endl;
	cout << "BST Random add" << i+1 << ":" << test.DoRandomAdd(50000) << endl;
	cout << "BST SeqFind" << i+1 << ":" << test.DoSequentialFind(0, 50000, 1) << endl;
	cout << "BST RandFind" << i+1 << ":" << test.DoRandomFind(50000) << endl;
	cout << "BST SeqRem" << i+1 << ":" << test.DoSequentialRemove(0, 50000, 1) << endl;
	cout << "BST RandRem" << i+1 << ":" << test.DoRandomRemove(50000) << "\n"<< endl;

//RBtree test
	cout << "RBTree Sequential add" << i+1 << ":" << test2.DoSequentialAdd(0, 50000, 1) << endl;
	cout << "RBTree Random add" << i+1 << ":" << test2.DoRandomAdd(50000) << endl;
	cout << "RBTree SeqFind" << i+1 << ":" << test2.DoSequentialFind(0, 50000, 1) << endl;
	cout << "RBTree RandFind" << i+1 << ":" << test2.DoRandomFind(50000) << endl;
	cout << "RBTree SeqRem" << i+1 << ":" << test2.DoSequentialRemove(0, 50000, 1) << endl;
	cout << "RBTree RandRem" << i+1 << ":" << test2.DoRandomRemove(50000) << "\n"<< endl;


//LHashTable test
		cout << "LHT Sequential add" << i+1 << ":" << test3.DoSequentialAdd(0, 50000, 1) << endl;
		cout << "LHT Random add" << i+1 << ":" << test3.DoRandomAdd(50000) << endl;
		cout << "LHT SeqFind" << i+1 << ":" << test3.DoSequentialFind(0, 50000, 1) << endl;
		cout << "LHT RandFind" << i+1 << ":" << test3.DoRandomFind(50000) << endl;
		cout << "LHT SeqRem" << i+1 << ":" << test3.DoSequentialRemove(0, 50000, 1) << endl;
		cout << "LHT RandRem" << i+1 << ":" << test3.DoRandomRemove(50000) << "\n"<< endl;


//CHashTable test
		cout << "CHT Sequential add" << i+1 << ":" << test4.DoSequentialAdd(0, 50000, 1) << endl;
		cout << "CHT Random add" << i+1 << ":" << test4.DoRandomAdd(50000) << endl;
		cout << "CHT SeqFind" << i+1 << ":" << test4.DoSequentialFind(0, 50000, 1) << endl;
		cout << "CHT RandFind" << i+1 << ":" << test4.DoRandomFind(50000) << endl;
		cout << "CHT SeqRem" << i+1 << ":" << test4.DoSequentialRemove(0, 50000, 1) << endl;
		cout << "CHT RandRem" << i+1 << ":" << test4.DoRandomRemove(50000) << "\n"<< endl;

	}
	return 0;

}
