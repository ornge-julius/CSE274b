//============================================================================
// Name        : Assignment6.cpp
// Author      : Julius ware
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BinaryHeap.h"
#include <iostream>
using namespace std;
using namespace ods;

int main() {


	BinaryHeap<int> Heap;

	for(int i =0; i < 10; i++){
		Heap.add(i);
	}

	for(int i = 0; i < 5; i++){
		cout << "removed: " << Heap.remove2(i) << endl;
	}

	for(int i =0; i < 10; i++){
			cout << Heap.get(i) << endl;
		}

	// im pretty sure something is wrong with the heap check because it returns false even for the regular remove function
	cout << Heap.heapCheck();

	return 0;
}
