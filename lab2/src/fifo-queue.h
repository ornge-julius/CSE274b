/*
 * fifo-queue.h
 *
 *  Created on: Sep 2, 2014
 *      Author: warejc2
 */

#ifndef FIFO_QUEUE_H_
#define FIFO_QUEUE_H_

class FifoQueue {
private:
  char array[50];

public:
   FifoQueue();
   bool Enqueue(char item);
   char Dequeue();

};

FifoQueue::FifoQueue(){
  //Complexity is o^n
  for(int i = 0; i < sizeof(array); i++){
    array[i] = 0;
  }
}

bool FifoQueue::Enqueue(char item){
  for(int i = 0; i < sizeof(array); i++){
    if(array[i] == 0){
      array[i] = item;
      return true;
    }
  }
return false;
}

char FifoQueue::Dequeue(){
  char result = array[0];
  for(int i = 0; i < sizeof(array) - 1; i++){
    array[i] = array[i+1];
  }
  array[sizeof(array)-1] = 0;
  return result;
}

#endif /* FIFO_QUEUE_H_ */
