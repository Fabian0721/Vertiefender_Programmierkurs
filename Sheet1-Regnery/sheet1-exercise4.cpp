#include <iostream>

int main(int argc, char const *argv[]) {

  std::cout << "Summing all squares until (and including) n = " << '\n';
  int number;
  std::cin >> number;
  int sum, quad;
  for (int i=0; i <= number; i++) {
    quad = i * i; 
    sum = sum + quad;
  }
  std::cout << "Result: " << sum << std::endl;
  return 0;
}
