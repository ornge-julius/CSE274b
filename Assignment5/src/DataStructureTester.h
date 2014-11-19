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
	void AddRandom(int i) {
		list.add(i);
		std::cout << "find " << list.find(i) << std::endl;
	}

	int xRand;
	int DoSequentialAdd(int start, int end, int step);
	int DoRandomAdd(int n);
	int DoSequentialRemove(int start, int end, int step);
	int DoRandomRemove(int n);

};

template<class H>
int DataStructureTester<H>::DoSequentialAdd(int start, int end, int step) {
	timer = clock();
	for (int i = start; i < end; i = i + step) {

		// what do i do here?
		//add items;
		list.add(i);
		std::cout << "find " << list.find(i) << std::endl;
	}

	timer = clock() - timer;
	timer = (((float) timer) / CLOCKS_PER_SEC);
	std::cout << "took " << timer << " seconds" << std::endl;

	return 0;

}

template<class H>
int DataStructureTester<H>::DoRandomAdd(int n) {
	timer = clock();
	srand(time(0));
	for (int i = 0; i < n; i++) {
		xRand = rand() % n + 1;
		list.add(xRand);
		std::cout << "find " << list.find(xRand) << std::endl;
		// how to i add to generic structure??
		// add xRand

	}

	timer = clock() - timer;
	timer = (((float) timer) / CLOCKS_PER_SEC);
	std::cout << "took " << timer << " seconds" << std::endl;

	return 0;
}


template<class H>
int DataStructureTester<H>::DoSequentialRemove(int n)

}
