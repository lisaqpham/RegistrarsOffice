#include "ListNode.h"
#include <cstddef>
#include <iostream>

using namespace std;

//Gen Linked List
template <typename T>
class DoublyLinkedList {
  private:
    ListNode<T> *front; //front pointer
    ListNode<T> *back; //back pointer
    unsigned int size;

  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    T deletePos(int pos); //aka removeAt()
    int find(T d); //aka contains()

    T peek();
    void printList();
    unsigned int getSize();

};

// implementation file
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
  size = 0;
  front = NULL; //null pointer
  back = NULL;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  // figure it out
  // you will have to iterate through the list
}

template <typename T>
void DoublyLinkedList<T>::insertFront(T d) {
  ListNode<T> *node = new ListNode<T>(d);

  if (size == 0) {
    // we have an empty list
    back = node;
  } else {
    // not an empty list
    node->next = front;
    front->prev = node;
  }
  front = node;
  size++;
}

template <typename T>
T DoublyLinkedList<T>::removeFront() {
  // check if empty first
  ListNode<T>* temp = front;

  if (front->next == NULL) {
    // only one element in the list
    back = NULL;
  } else {
    // more than one element in the list
    front->next->prev = NULL;
  }
  front = front->next;

  T* data = temp->data;

  delete temp;
  size--;
  return data;

}

template <typename T>
void DoublyLinkedList<T>::insertBack(T d){
  ListNode<T>* node = new ListNode<T>(d);

  //size = 0
  if(size == 0) {
    front = node;
  } else {
    back->next = node;
    node->prev = back;
  }

  back=node;
  size++;
}

template <typename T>
T DoublyLinkedList<T>::removeBack() {
  // check if empty first


}

template <typename T>
unsigned int DoublyLinkedList<T>::getSize() {
  return size;
}

template <typename T>
void DoublyLinkedList<T>::printList() {
  ListNode<T> *curr = front;

  while(curr !=  NULL) {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <typename T>
T DoublyLinkedList<T>::peek() {
  return front->data;
}

template <typename T>
T DoublyLinkedList<T>::deletePos(int pos) {
  int idx = 0;
  ListNode<T> *prev = front;
  ListNode<T> *curr = front;

  while(idx != pos) {
    prev = curr;
    curr = curr->next;
    idx++;
  }

  //found the node to be deleted
  prev->next = curr->next;
  curr->next = NULL;
  int tmp = curr->data;

  delete curr;
  size--;

  return tmp;
}

template <typename T>
int DoublyLinkedList<T>::find(T d) {
  int idx = 0;
  ListNode<T> *curr = front;

  while(curr != NULL) {
    if (curr->data == d)
      break;

    curr = curr->next;
    idx++;
  }

  if(curr == NULL) //we did not find the value we were looking for
    idx = -1;

  return idx;
}
