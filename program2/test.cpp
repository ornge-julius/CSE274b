//============================================================================
// Name        : Program2.cpp
// Author      : Julius ware
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "DLList.h"

using namespace ods;
using namespace std;

int main() {

	DLList<char> myList;
//test for isPalendrome
	myList.add('r');
	myList.add('a');
	myList.add('c');
	myList.add('e');
	myList.add('c');
	myList.add('a');
	myList.add('r');



    cout << myList.isPalendrome() << endl;

//test for absorb

   DLList<char> myOtherList;
    myOtherList.add('d');
    myOtherList.add('f');
    myOtherList.add('j');
    cout << myOtherList.size() << endl;

    myList.absorb(myOtherList);
   cout<< myList.size() << endl;

for(int i = 0; i < myList.size(); i++){

	cout << myList.get(i) << endl;

}

//test for deal
//this part runs an infinite loop and never fully returns

/*myOtherList = myList.deal();

for(int i = 0; i < myOtherList.size(); i++){

	cout << myList.get(i) << endl;
	cout << myOtherList.get(i) << endl;

}*/

//test for rotate
cout << myList.get(0) << endl;
myList.rotate(3);
cout << myList.get(0) << endl;
myList.rotate(1);
cout << myList.get(0) << endl;
myList.rotate(2);
cout << myList.get(0) << endl;
return 0;

  }
