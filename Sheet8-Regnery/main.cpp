#include "linklist.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  
  Linklist Liste;

  Liste.add(5);
  Liste.add(89);
  Liste.add(14);
  Liste.print();
  Liste.erase(89);
  std::cout << " " << '\n';
  Liste.print();


  return 0;
}
