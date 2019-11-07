#include "GenQueue.h"
#include "Student.h"
#include <iostream>
#include <cstddef>
#include <fstream>

using namespace std;

// global variables
int n;
int windows;
int minute = 0;
int tArrival;
int sArrived;
GenQueue<Students> students;
GenQueue<int> readFile;


int main (int argc, char ** argv) {
  // Error handling for files
  if (argc != 2) { // line args error
    cout << "Error: Incorrect command line arguments" << endl;
    cout << "   expecting 2 arguments; received " << argc << endl;
    cout << "Suggestion: Check spacing" << endl;

    return 0;
  } else {
    ifstream infile(argv[1]);
    if (!infile.is_open()) {
      cout << "Error: Could not open file" << endl; // file opening error
    } else {
      while (infile >> n) {
        readFile.insert(n);
      }
    }
  }
  windows = readFile.remove();
  while (!readFile.isEmpty()) {
    tArrival = readFile.remove();
    sArrived = readFile.remove();
    for (int i = 0; i < sArrived; i++) {
      Student s;
      s.minArrived = tArrival;
      s.minNeed = readFile.remove();
      students.insert(s));
    }
  }



  return 0;
}
