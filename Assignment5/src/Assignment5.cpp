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

//These are holders for the sums of the total number of milliseconds for each test

	float t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

//BStree test

//Runs each test 20 times and sums up the times
	for (int i = 0; i < 20; i++) {

		t1 = t1 + test.DoSequentialAdd(0, 50000, 1);
		t2 = t2 + test.DoRandomAdd(50000);
		t3 = t3 + test.DoSequentialFind(0, 50000, 1);
		t4 = t3 + test.DoRandomFind(50000);
		t5 = t5 + test.DoSequentialRemove(0, 50000, 1);
		t6 = t6 + test.DoRandomRemove(50000);

	}

//Prints out the averages of each test then resets the holders
	cout << t1 / 20 << endl;
	cout << t2 / 20 << endl;
	cout << t3 / 20 << endl;
	cout << t4 / 20 << endl;
	cout << t5 / 20 << endl;
	cout << t6 / 20 << "\n" << endl;
	t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

//RBtree test

	for (int i = 0; i < 20; i++) {

		t1 = t1 + test2.DoSequentialAdd(0, 50000, 1);
		t2 = t2 + test2.DoRandomAdd(50000);
		t3 = t3 + test2.DoSequentialFind(0, 50000, 1);
		t4 = t3 + test2.DoRandomFind(50000);
		t5 = t5 + test2.DoSequentialRemove(0, 50000, 1);
		t6 = t6 + test2.DoRandomRemove(50000);

	}

	cout << t1 / 20 << endl;
	cout << t2 / 20 << endl;
	cout << t3 / 20 << endl;
	cout << t4 / 20 << endl;
	cout << t5 / 20 << endl;
	cout << t6 / 20 << "\n" << endl;
	t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

//LHashTable test

	for (int i = 0; i < 20; i++) {

		t1 = t1 + test3.DoSequentialAdd(0, 50000, 1);
		t2 = t2 + test3.DoRandomAdd(50000);
		t3 = t3 + test3.DoSequentialFind(0, 50000, 1);
		t4 = t3 + test3.DoRandomFind(50000);
		t5 = t5 + test3.DoSequentialRemove(0, 50000, 1);
		t6 = t6 + test3.DoRandomRemove(50000);

	}

	cout << t1 / 20 << endl;
	cout << t2 / 20 << endl;
	cout << t3 / 20 << endl;
	cout << t4 / 20 << endl;
	cout << t5 / 20 << endl;
	cout << t6 / 20 << "\n" << endl;
	t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

//CHashTable test

	for (int i = 0; i < 20; i++) {

		t1 = t1 + test4.DoSequentialAdd(0, 50000, 1);
		t2 = t2 + test4.DoRandomAdd(50000);
		t3 = t3 + test4.DoSequentialFind(0, 50000, 1);
		t4 = t3 + test4.DoRandomFind(50000);
		t5 = t5 + test4.DoSequentialRemove(0, 50000, 1);
		t6 = t6 + test4.DoRandomRemove(50000);

	}

	cout << t1 / 20 << endl;
	cout << t2 / 20 << endl;
	cout << t3 / 20 << endl;
	cout << t4 / 20 << endl;
	cout << t5 / 20 << endl;
	cout << t6 / 20 << "\n" << endl;

	return 0;

}
