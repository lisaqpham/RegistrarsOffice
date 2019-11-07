#include "Office.h"
#include <iostream>

using namespace std;

Office::Office() {
  windows = 0;
}

Office::Office(int w) {
  windows = w;
  idleTimes = new int[10];
}
