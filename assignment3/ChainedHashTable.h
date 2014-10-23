#ifndef CHAINEDHASHTABLE_H_
#define CHAINEDHASHTABLE_H_
#include <climits>
#include "utils.h"
#include "array.h"
#include "ArrayStack.h"
#include "DLList.h"
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;
namespace ods {

template<class T>
class ChainedHashTable {
protected:
	typedef DLList<T> List;
	T null;

	int n;
	int d;
	int z;



	static const int w = 32; //sizeof(int)*8;
	void allocTable(int m);
	void resize();
	int hash(T x) {

		return (unsigned) (x*z)%t.length /*<< (w-d) >> (w-d))*/;
	}

public:
	ChainedHashTable();
	array<List> t; // remember to place this back as protected when done testing
	virtual ~ChainedHashTable();
	bool add(T x);
	float loadFactor = 1;
	void SetLocalFactor(float f);
	int getLongList();
	T remove(T x);
	T find(T x);
	int size() {
		return n;
	}
	void clear();
};

/**
 * FIXME:  A copy-constructor for arrays would be useful here
 */
template<class T>
void ChainedHashTable<T>::resize() {
	d = 1;
	while (1 << d <= n/loadFactor)
		d++;
	n = 0;
	array<List> newTable(1 << d);
	for (int i = 0; i < t.length; i++) {
		for (int j = 0; j < t[i].size(); j++) {
			T x = t[i].get(j);
			newTable[hash(x)].add(x);
			n++;
		}
	}
	t = newTable;
}
/*
 template<>
 ChainedHashTable<int>::ChainedHashTable() : t(2)
 {
 n = 0;
 d = 1;
 null = INT_MIN;
 z = rand() | 1;     // is a random odd integer
 }
 */

template<class T>
ChainedHashTable<T>::ChainedHashTable() :
		t(2) {
	//loadFactor = 1;
	n = 0;
	d = 1;
	null = INT_MIN;
	z = rand() | 1;     // is a random odd integer
}

template<class T>
ChainedHashTable<T>::~ChainedHashTable() {
}

template<class T>
bool ChainedHashTable<T>::add(T x) {
	if (find(x) != null)
		return false;
	if (n + 1 > (loadFactor * t.length))
		resize();
	t[hash(x)].add(x);
	n++;
	return true;
}

template<class T>
T ChainedHashTable<T>::remove(T x) {
	int j = hash(x);
	for (int i = 0; i < t[j].size(); i++) {
		T y = t[j].get(i);
		if (x == y) {
			t[j].remove(i);
			n--;
			return y;
		}
	}
	return null;
}

template<class T>
T ChainedHashTable<T>::find(T x) {
	int j = hash(x);
	for (int i = 0; i < t[j].size(); i++)
		if (x == t[j].get(i))
			return t[j].get(i);
	return null;
}

template<class T>
void ChainedHashTable<T>::clear() {
	n = 0;
	d = 1;
	array<List> b(2);
	t = b;
}

//This function sets the loading factor
template<class T>
void ChainedHashTable<T>::SetLocalFactor(float f) {
	loadFactor = f;
}

//Returns the longest list in the table
template<class T>
int ChainedHashTable<T>::getLongList() {
	int longNum = 0;
	int temp = 0;
	for (int i = 0; i < t.length; i++) {
		temp = t[i].size();

		if (temp >= longNum) {
			longNum = temp;
			cout << i << endl;
		}
	}
	return longNum;
}

}

/* namespace ods */
#endif /* CHAINEDHASHTABLE_H_ */
