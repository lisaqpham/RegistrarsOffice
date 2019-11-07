#include "Window.h"
#include <iostream>

using namespace std;

Window::Window() {
  open = true;
}

Window::Window(int a, int n) {
  open = true;
}

bool Window::isOpen(){
  return open;
}
