//============================================================================
// Name        : Program1.cpp
// Author      : Julius ware
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "array.h"
#include "ArrayDeque.h"
#include "Trequeue.h"


using namespace std;
using namespace ods;

int main() {
	Trequeue<int> queue;

	queue.add(0,4);
	queue.add(0, 5);
	queue.add(0, 8);
	queue.add( 6, 7);
	 cout << queue.get(6) << endl;

	return 0;
}
