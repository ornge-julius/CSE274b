/*
 * Rectangle.h
 *
 *  Created on: Aug 28, 2014
 *      Author: warejc2
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <iostream>
using namespace std;

class Rectangle {
 private:
	int width, height;
 public:
    void set_values (int,int);
    int area();
};




#endif /* RECTANGLE_H_ */
