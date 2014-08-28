// classes example
#include <iostream>
#include "Rectangle.h"
using namespace std;


int main () {
  Rectangle rect; // creates and initializes new object; not just a reference!!

  Rectangle &refRect = rect; // creates a reference to the object rect; rect and refRect point to the same thing
  	  	  	  	  	  	  	 // this has to be one line, reference must be initialized

  Rectangle rect2 = rect; // this copies the object rect and creates a new place in the memory

  Rectangle *pRect = new Rectangle (); // creates a pointer to Rectangle...a memory location on the Heap.
 // pRect = &rect;  // returns the memory location of rect. These lines can be put together.

  pRect->set_values(7,8); // accesses the data and methods to the pointer

  rect.set_values (3,4);
  rect2.set_values(5,6);
  refRect.set_values(10,5); // rect and refRect point to same object; now area will be that of refRect

  cout << "area: " << rect.area() << endl << "area2: " << rect2.area() << endl ;
  cout << "pointer to rect " << pRect << endl;

  cout << "area of pointer " << pRect->area() << endl;
  return 0;
}
