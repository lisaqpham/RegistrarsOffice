#include <cstddef>
#include <iostream>

using namespace std;

template <typename T>
class ListNode {
  public:
    T data;
    ListNode *next;
    ListNode *prev;

    //constructors & destructor
    ListNode();
    ListNode(T d);
    ~ListNode();
};

template <typename T>
ListNode<T>::ListNode() {
  data = NULL;
  next = NULL;
  prev = NULL;
}

template <typename T>
ListNode<T>::ListNode(T d) {
  data = d;
  next = NULL; //null pointer
  prev = NULL;
}

template <typename T>
ListNode<T>::~ListNode() {
  next = NULL;
  prev = NULL;
}
