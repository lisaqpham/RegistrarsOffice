#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

template <typename T>
class GenQueue {
  public:
    GenQueue(); //default constructor
    ~GenQueue();

    //core functions
    void insert(T d);
    T remove();

    //aux functions
    T peek();
    bool isFull();
    bool isEmpty();

    //vars
    int size;
    int newSize;
    int numElements;
    int getSize();

    DoublyLinkedList<T> *myQueue;
};

template <typename T>
GenQueue<T>::GenQueue() {
  //default constructor
  //i'll let you guys implement this
  myQueue = new DoublyLinkedList<T>();
  numElements = 0;
}

template <typename T>
GenQueue<T>::~GenQueue(){
  //do this one on your own
  delete myQueue;
}

template <typename T>
void GenQueue<T>::insert(T d) {
  myQueue->insertBack(d);
  ++numElements;
}

template <typename T>
T GenQueue<T>::remove() {
  --numElements;
  return myQueue->removeFront();
}

template <typename T>
T GenQueue<T>::peek() {
  return (myQueue->peek());
}

template <typename T>
bool GenQueue<T>::isFull(){
  return (numElements == size);
}

template <typename T>
bool GenQueue<T>::isEmpty(){
  return (numElements == 0);
}

template <typename T>
int GenQueue<T>::getSize(){
  return numElements;
}
