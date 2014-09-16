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


using namespace std;
using namespace ods;

int main() {
	ArrayDeque<char> queue;

	queue.add(0, 'a');
	queue.add(0, 'b');
	queue.add(0, 'c');

   char result = queue.get(1);
   cout << "position 1 " << result << endl;
   result = queue.get(2);
   cout << "position 2" << result << endl;

	return 0;
}
