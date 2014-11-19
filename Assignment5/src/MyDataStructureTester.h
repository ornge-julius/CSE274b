

#ifndef DATASTRUCTURETESTER_H_
#define DATASTRUCTURETESTER_H_
#include <iostream>
#include <stdlib.h>
#include<ctime>
namespace ods {

template<class T>
class DataStructureTester {
private:
  int timer;
  int xRand;
  int startTime;
  int endTime;

public:
  int start;
  int end;
  int n;
  int step;


  DataStructureTester();
  int DoSequentialAdd(int start, int end, int step);
  int DoRandomAdd(int n);
  int DoSequentialRemove(int start, int end, int step);
  int DoRandomRemove(int n);
  int DoSequentialFind(int start, int end, int step);
  int DoRandomFind(int n);

};

template<class T>
void DataStructureTester<T>::DataStructureTester() {
  start = 0;
  end = 0;
  n = 0;
  step = 0;
  startTime = 0;
  endTime = 0;
  timer = endTime - startTime;
  srand(time(0));
}

template<class T>
int DataStructureTester<T>::DoSequentialAdd(int start, int end, int step) {
  startTime = clock();
  for (int i = start; i < end; i = i + step) {
    // what do i do here?
    //add items;
  }
  endTime = clock();
  return timer;

}

template<class T>
int DataStructureTester<T>::DoRandomAdd(int n) {

  startTime = clock();
  for (int i = 0; i < n; i++) {
    xRand = rand() % 1000 + 1;
    // how to i add to generic structure??
    // add xRand
  }
  endTime = clock();
  return timer;
}
template<class T>
int DataStructureTester<T>::DoSequentialRemove(int start, int end, int step){
  startTime = clock();
   for (int i = start; i < end; i = i + step) {
     // what do i do here?
     //remove items
   }
   endTime = clock();
   return timer;
}

template<class T>
int DataStructureTester<T>::DoRandomRemove(int n){
  startTime = clock();
   for (int i = 0; i < n; i++) {
     xRand = rand() % 1000 + 1;
     // how to i add to generic structure??
     // remove xRand
   }
   endTime = clock();
   return timer;
}

template<class T>
int DataStructureTester<T>::DoSequentialFind(int start, int end, int step){
  startTime = clock();
  for(int i = start; i < end; i = i+step){
    //find i
  }
  endTime = clock();
  return timer;
}

template<class T>
int DataStructureTester<T>::DoRandomFind(int n){
  startTime = clock();

  xRand = rand()% 100+1;

}

}

#endif /* DATASTRUCTURETESTER_H_ */
