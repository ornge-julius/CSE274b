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

	/*queue.add(0, 4);
	queue.add (0, 5);
	queue.add(0,3);
	queue.add(0,6);
	queue.add(10,8);
	queue.add(6,5);*/

for(int i = 0; i < 4000; i ++){
	queue.add(i, i+5);
}

	cout <<"size of front: " <<  queue.front.size() << endl;
	cout << "size of back: " << queue.back.size() << endl;
	cout <<"total size: " << queue.size() << endl;
	cout << queue.get(0) << endl;
	cout << queue.get(1) << endl;

	for(int i = queue.size() -2; i > 2;  i = i -2){
		queue.remove(i);
	}
queue.remove(2000);
queue.remove(0);
queue.remove(1);
queue.set(0, 0);
		cout <<"size of front: " <<  queue.front.size() << endl;
		cout << "size of back: " << queue.back.size() << endl;
		cout <<"total size: " << queue.size() << endl;
		cout << queue.get(0) << endl;
		cout << queue.get(1) << endl;
	return 0;

}
