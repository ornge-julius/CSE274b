#include <iostream>
#include <ctime>
#include <time.h>

namespace ods {

template<class H>
class DataStructureTester {
protected:
	H list;
	float timer;

public:

	int xRand;
	int DoSequentialAdd(int start, int end, int step);
	int DoRandomAdd(int n);
	int DoSequentialRemove(int start, int end, int step);
	int DoRandomRemove(int n);
	int DoSequentialFind(int start, int end, int step);
	int DoRandomFind(int n);

};

template<class H>
int DataStructureTester<H>::DoSequentialAdd(int start, int end, int step) {

	timer = clock();
	for (int i = start; i < end; i = i + step) {

		list.add(i);

	}

	timer = clock() - timer;
	timer = 1000 * (((float) timer) / CLOCKS_PER_SEC);

	return timer;

}

template<class H>
int DataStructureTester<H>::DoRandomAdd(int n) {
	timer = clock();
	srand(time(0));
	for (int i = 0; i < n; i++) {
		xRand = rand() % n + 1;
		list.add(xRand);

	}

	timer = clock() - timer;
	timer = 1000 * (((float) timer) / CLOCKS_PER_SEC);

	return timer;
}

template<class H>
int DataStructureTester<H>::DoSequentialRemove(int start, int end, int step) {

	timer = clock();
	for (int i = start; i < end; i = i + step) {

		list.remove(i);

	}

	timer = clock() - timer;
	timer = 1000 * (((float) timer) / CLOCKS_PER_SEC);

	return timer;
}

template<class H>
int DataStructureTester<H>::DoRandomRemove(int n) {
	timer = clock();
	srand(time(0));
	for (int i = 0; i < n; i++) {
		xRand = rand() % n + 1;
		list.remove(xRand);

	}

	timer = clock() - timer;
	timer = 1000 * (((float) timer) / CLOCKS_PER_SEC);
	;

	return timer;
}

template<class H>
int DataStructureTester<H>::DoSequentialFind(int start, int end, int step) {

	timer = clock();
	for (int i = start; i < end; i = i + step) {

		list.find(i);

	}

	timer = clock() - timer;
	timer = 1000 * (((float) timer) / CLOCKS_PER_SEC);

	return timer;

}

template<class H>
int DataStructureTester<H>::DoRandomFind(int n) {

	timer = clock();
	srand(time(0));
	for (int i = 0; i < n; i++) {
		xRand = rand() % n + 1;
		list.find(xRand);

	}

	timer = clock() - timer;
	timer = 1000 * (((float) timer) / CLOCKS_PER_SEC);

	return timer;
}

}

