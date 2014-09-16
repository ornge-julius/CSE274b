/*
 * Trequeue.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Julius Ware
 */

#ifndef TREQUEUE_H_
#define TREQUEUE_H_
#include "ArrayDeque.h"
#include "array.h"
#include "utils.h"



template <class T>
class Trequeue{
  protected:
	 	 ArrayDeque<T> front;
	 	 ArrayDeque<T> back; /* there is something wrong with the way I am calling ArrayDeque.
	 	 	 	 	 	 	 Because of this I am not able to call the functions I need to compile and run the code.
	 	 	 	 	 	 	 These functions are giving the red errors here and below.*/
	 	 void balance();
  public:
	 	 Trequeue();
	 	 ~Trequeue();
	 	 int size();
	 	 T get(int index);
	 	 T set(int index, T input);
	 	 void add(int index, T input);
	 	 T remove(int index);
	 	 void clear;


};

template <class T> inline // what does this do? (inline)
T Trequeue<T>::get(int index){
	if(index < front.size()){
		return front.get(front.size() - index - 1);
	} else {
		return back,get(index - front.size());
	}
}

template <class T> inline
T Trequeue<T>::set(int index, T input){
	if( index < front.size()) {
		return front.set(front.size() - index - 1, input);

	} else {
		return back.set(index - front.size(), input);
	}
}

template <class T> inline
void Trequeue <T>::add(int index, T input){
	if(index < front.size()) {
		front.add(front.size() - index, input);
	} else {
		back.add(index - front.size(), input);
	}
  balance();
}

template<class T>
T Trequeue<T>::remove(int index){
	T input;
	if (index < front.size()){
		input = front.remove(front.size()- index - 1);
	} else {
		input = back.remove(index - front.size());
	}
  balance();
}

// does the code overall look how it should? does it make sense??


#endif /* TREQUEUE_H_ */
