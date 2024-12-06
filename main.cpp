#include "Draft.cpp"
#include <fstream>
#include <iostream>

int main() {
  //make the draft and add names.txt to the draft
  Draft d("names.txt");
  //create the draft
  d.create();
  
  return 0;
}
