/*
 * DLList.h
 *
 *  Created on: 2011-11-24
 *      Author: morin
 */

#ifndef DLLIST_H_
#define DLLIST_H_

namespace ods {

template<class T>
class DLList {
protected:
	struct Node {
		T x;
		Node *prev, *next;
	};
	Node dummy;
	int n;
	void remove(Node *w);
	Node* addBefore(Node *w, T x);
	Node* getNode(int i);
public:
	DLList();
	virtual ~DLList();
	int size() {
		return n;
	}
	T get(int i);
	T set(int i, T x);
	virtual void add(int i, T x);
	virtual void add(T x) {
		add(size(), x);
	}
	virtual void absorb(DLList<T> &l2);
	virtual T remove(int i);
	virtual void clear();
	virtual bool isPalendrome();
	virtual DLList deal();
	virtual void rotate(int r);

};

template<class T>
DLList<T>::DLList() {
	dummy.next = &dummy;
	dummy.prev = &dummy;
	n = 0;
}

template<class T>
typename DLList<T>::Node* DLList<T>::addBefore(Node *w, T x) {
	Node *u = new Node;
	u->x = x;
	u->prev = w->prev;
	u->next = w;
	u->next->prev = u;
	u->prev->next = u;
	n++;
	return u;
}

template<class T>
typename DLList<T>::Node* DLList<T>::getNode(int i) {
	Node* p;
	if (i < n / 2) {
		p = dummy.next;
		for (int j = 0; j < i; j++)
			p = p->next;
	} else {
		p = &dummy;
		for (int j = n; j > i; j--)
			p = p->prev;
	}
	return (p);
}

template<class T>
DLList<T>::~DLList() {
	clear();
}

template<class T>
void DLList<T>::clear() {
	Node *u = dummy.next;
	while (u != &dummy) {
		Node *w = u->next;
		delete u;
		u = w;
	}
	n = 0;
}

template<class T>
void DLList<T>::remove(Node *w) {
	w->prev->next = w->next;
	w->next->prev = w->prev;
	delete w;
	n--;
}

template<class T>
T DLList<T>::get(int i) {
	return getNode(i)->x;
}

template<class T>
T DLList<T>::set(int i, T x) {
	Node* u = getNode(i);
	T y = u->x;
	u->x = x;
	return y;
}

template<class T>
void DLList<T>::add(int i, T x) {
	addBefore(getNode(i), x);
}

template<class T>
T DLList<T>::remove(int i) {
	Node *w = getNode(i);
	T x = w->x;
	remove(w);
	return x;
}

template<class T>
bool DLList<T>::isPalendrome() {
	Node *temp1 = dummy.next;
	Node *temp2 = dummy.prev;

	bool returnval = false;
	for (int i = 0; i < size(); i++) {
		if (temp1->x != temp2->x) {
			return false;
		} else {
			returnval = true;
		}
		temp1 = temp1->next;
		temp2 = temp2->prev;

	}
	return returnval;

	/*if (this->size() % 2 == 0) {
	 return returnval;
	 } else {
	 return true;
	 for (int i = 0; i < this->size(); i++) {

	 if (get(i) == get(this->size() - i - 1)) {
	 returnval = true;
	 } else {
	 returnval = false;
	 }
	 }
	 return returnval;
	 }
	 }*/
}

template<class T>
void DLList<T>::absorb(DLList<T> &l2) {

	l2.dummy.next->prev = dummy.prev;
	dummy.prev->next = l2.dummy.next;
	dummy.prev = l2.dummy.prev;
	l2.dummy.prev->next = &dummy;
	l2.dummy.next = &l2.dummy;
	l2.dummy.prev = &l2.dummy;
	delete &l2.dummy;
	n = n + l2.size();

	//update the pointers of the two lists

	/*for (int i = 0; i < l2.size() - 1; i++) {
	 this->add(l2.get(i));

	 }
	 l2.clear();*/
}

template<class T>
DLList<T> DLList<T>::deal() {
	DLList<T> list2;
	Node* temp1 = dummy.next;
	for (int i = 1; i < this->size(); i++) {
		if (i == 1) {

			temp1->next->prev = temp1->prev;
			temp1->prev->next = temp1->next;
			temp1->next = &list2.dummy;
			temp1->prev = &list2.dummy;
			list2.dummy->next = temp1->x;
			list2.dummy.prev = temp1->x;

		} else if (i % 2 != 0) {

			temp1->next->prev = temp1->prev;
			temp1->prev->next = temp1->next;
			temp1->next = list2.dummy.next;
			temp1->prev = &list2.dummy;
			list2.dummy.next = temp1->x;
		}

		temp1 = temp1->next;
	}

	return list2;
}

template<class T>
void DLList<T>::rotate(int r) {

	dummy.next->prev = dummy.prev;
	dummy.prev->next = dummy.next;
	dummy.next = getNode(r);
	dummy.prev = getNode(r - 1);
	getNode(r)->prev = &dummy;
	getNode(r - 1)->next = &dummy;

}

}
/* namespace ods */
#endif /* DLLIST_H_ */
