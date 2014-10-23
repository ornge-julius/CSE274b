//============================================================================
// Name        : Assignment3.cpp
// Author      : Julius ware
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ChainedHashTable.h"
#include"LinearHashTable.h"
#include <time.h>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
using namespace std;
using namespace ods;

int main() {

	ChainedHashTable<int> myTable;
	srand(time(NULL));
	//myTable.SetLocalFactor(8);
	for (int i = 0; i < 8000; i++) {


		int z = rand();
		myTable.add(z);

	}

	for(int i = 0; i < myTable.size(); i++){
		cout << "list " << i << " size:" << cout << myTable.t[i].size() << endl;
	}
	cout << "longest list:" << myTable.getLongList() << endl;
	cout << "t.length:" <<  myTable.t.length<< endl;
	cout << "table size: " << myTable.size() << endl;



	return 0;
}

