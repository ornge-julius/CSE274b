
 #ifndef Trequeue_H_
#define Trequeue_H_
#include "ArrayDeque.h"

namespace ods {

template<class T>
class Trequeue {
public:
	ArrayDeque<T> front;
	ArrayDeque<T> back;
	void balance();
public:
	Trequeue();
	virtual ~Trequeue();
	int size();
	T get(int i);
	T set(int i, T x);
	virtual void add(int i, T x);
	virtual T remove(int i);
	virtual void clear();
};

template<class T> inline
T Trequeue<T>::get(int i) {
	if (i < front.size()) {
		return front.get(i);
	} else {
		return back.get(i - front.size());
	}
}

template<class T> inline
T Trequeue<T>::set(int i, T x) {
	if (i < front.size()) {
		return front.set(i, x);

	} else {
		return back.set(i - front.size(), x);
	}
}

template<class T>
Trequeue<T>::Trequeue() {
}

template<class T>
Trequeue<T>::~Trequeue() {

}

template<class T>
int Trequeue<T>::size() {
	return front.size() + back.size();
}

template<class T>
void Trequeue<T>::add(int i, T x) {
	if (i < front.size()) {
		front.add(i, x);
	} else {
		back.add(i - front.size(), x);
	}
	balance();
}

template<class T>
T Trequeue<T>::remove(int i) {
    T x;
    if (i < front.size()) {
            x = front.remove(i);
    } else {
            x = back.remove(i-front.size());
    }
    balance();
 return x;
}

template<class T>
void Trequeue<T>::balance() {
	T xy;
	if(front.size() == back.size() + 2){
		xy = front.remove(front.size());
		back.add(0, xy);
	} else if (back.size() == front.size() + 2) {
		xy = back.remove(back.get(0));
		front.add(front.size(), xy);
	}

return;

}


template<class T>
void Trequeue<T>::clear() {
	front.clear();
	back.clear();
}

}
#endif /* Trequeue_H_ */
