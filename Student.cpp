#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() {
  minArrived = 0;
  minNeed = 0;
}

Student::Student(int a, int n) {
  minArrived = a;
  minNeed = n;
}
