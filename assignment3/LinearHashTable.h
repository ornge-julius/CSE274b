/*
 * LinearHashTable.h
 *
 *  Created on: 2011-12-16
 *      Author: morin
 */

#ifndef LINEARHASHTABLE_H_
#define LINEARHASHTABLE_H_
#include <climits>
#include <iostream>
using namespace std;
#include "array.h"
namespace ods {

extern unsigned int tab[4][256];

template<class T>
class LinearHashTable {

	static const int w = 32;
	static const int r = 8;
	array<T> t;
	int n;
	int q;
	int d;
	int z;
	T null, del;
	void resize();
	int hash(T x) {
		return ((unsigned) ((z * 3) * x)) % (1 << d);
	}
	int hash2(T x) {
		return 1 + (hash(x) % ((1 << d) - 1));
	}


public:
	// FIXME: get rid of default constructor
	LinearHashTable();
	LinearHashTable(T null, T del);
	virtual ~LinearHashTable();
	bool add(T x);
	bool addSlow(T x);
	T remove(T x);
	T find(T x);
	int size() {
		return n;
	}
	void clear();
	// FIXME: yuck
	void setNull(T null) {
		this->null = null;
		t.fill(null);
	}
	void setDel(T del) {
		this->del = del;
	}
	void PrintList();
	void PrintList2();
};

/*
 template<>
 LinearHashTable<int>::LinearHashTable() : t(2, INT_MIN) {
 null = INT_MIN;
 del = INT_MIN + 1;
 n = 0;
 q = 0;
 d = 1;
 }
 */

/**
 * FIXME: Dangerous - leaves null and del uninitialized
 */
template<class T>
LinearHashTable<T>::LinearHashTable() :
		t(2) {
	/*
	 this->null = null;
	 this->del = del;
	 */
	n = 0;
	q = 0;
	d = 1;
	z = rand() | 1;     // is a random odd integer
}

template<class T>
LinearHashTable<T>::LinearHashTable(T null, T del) :
		t(2, null) {
	this->null = null;
	this->del = del;
	n = 0;
	q = 0;
	d = 1;
	z = rand() | 1;     // is a random odd integer
	cout << "random integer is: " << z << endl;
}

template<class T>
LinearHashTable<T>::~LinearHashTable() {
}

template<class T>
void LinearHashTable<T>::resize() {
	d = 1;
	while ((1 << d) < 3 * n)
		d++;
	array<T> tnew(1 << d, null);
	q = n;

	for (int k = 0; k < t.length; k++) {

		if (t[k] != null && t[k] != del) {
			int i = 0;
			int pr = ( hash(t[k]) + (i * hash2(t[k])) ) % (tnew.length);
			while (tnew[pr] != null) {
				i = (i == tnew.length - 1) ? 0 : i + 1; // increment i
				pr = (hash(tnew[pr]) + (i * hash2(tnew[pr]))) % (tnew.length); // DOUBLE HASHING IMPLEMENTATION
			}
			tnew[pr] = t[k];
		}
	}
	t = tnew;
}

template<class T>
void LinearHashTable<T>::clear() {
	n = 0;
	q = 0;
	d = 1;
	array<T> tnew(2, null);
	t = tnew;
}

template<class T>
bool LinearHashTable<T>::add(T x) {
	if (find(x) != null)
		return false;
	if (2 * (q + 1) > t.length)
		resize();   // max 50% occupancy
	int i = 0;
	int pr = (hash(x) + (i * hash2(x))) % (t.length);
	while (t[pr] != null && t[pr] != del) {
		i = (i == t.length - 1) ? 0 : i + 1; // increment i
		pr = (hash(x) + (i * hash2(x))) % (t.length); // DOUBLE HASHING IMPLEMENTATION
	}
	if (t[pr] == null)
		q++;
	n++;
	t[pr] = x;
	return true;
}

template<class T>
T LinearHashTable<T>::find(T x) {
	int i = 0;
	int pr = (hash(x) + (i * hash2(x))) % (t.length);
	while (t[pr] != null) {
		if (t[pr] != del && t[pr] == x)
			return t[pr];
		{
			i = (i == t.length - 1) ? 0 : i + 1; // increment i
			pr = (hash(x) + (i * hash2(x))) % (t.length); // DOUBLE HASHING IMPLEMENTATION
		}
	}
	return null;
}

template<class T>
T LinearHashTable<T>::remove(T x) {
	int i = 0;
	int pr = (hash(x) + (i * hash2(x))) % (t.length);
	while (t[pr] != null) {
		T y = t[pr];
		if (y != del && x == y) {
			t[pr] = del;
			n--;
			if (8 * n < t.length)
				resize(); // min 12.5% occupancy
			return y;
		}
		i = (i == t.length - 1) ? 0 : i + 1; // increment i
		pr = (hash(x) + (i * hash2(x))) % (t.length); // DOUBLE HASHING IMPLEMENTATION
	}
	return null;
}

template<class T>
bool LinearHashTable<T>::addSlow(T x) {
	if (2 * (q + 1) > t.length)
		resize();   // max 50% occupancy
	int i = 0;
	int pr = (hash(x) + (i * hash2(x))) % (t.length);
	while (t[pr] != null) {
		if (t[pr] != del && x.equals(t[pr]))
			return false;
		i = (i == t.length - 1) ? 0 : i + 1; // increment i
		pr = (hash(x) + (i * hash2(x))) % (1 << d); // DOUBLE HASHING IMPLEMENTATION
	}
	t[pr] = x;
	n++;
	q++;
	return true;
}

template<class T>
void LinearHashTable<T>::PrintList() {
	for (int i = 0; i < t.length; i++) {
		cout << "Value added: " << t[i] << endl;
		cout << "Index: " << i << endl;
	}
}

template<class T>
void LinearHashTable<T>::PrintList2() {
	for (int i = 0; i < t.length; i++) {
		if (t[i] != -1 && t[i] != -2){
			cout << t[i] << endl;
		}
	}
}

} /* namespace ods */
#endif /* LINEARHASHTABLE_H_ */
