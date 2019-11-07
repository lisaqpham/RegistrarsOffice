#include <iostream>

class Window {
  public:
    int prevOpen;
    int currOpen;
    bool open;

    Window(); //default constructor
    Window(int a, int n); //overloaded constructor

    bool isOpen();

};
