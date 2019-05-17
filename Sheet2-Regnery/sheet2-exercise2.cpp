#include <iostream>

bool is_prime(int number) {
  for (int i = 2; i < number; i++) {
    if ((number%i) == 0) {
      std::cout << "Ist keine Primzahl" << '\n';
      return 0;
    }
  }
  std::cout << "Ist eine Primzahl" << '\n';
  return 1;
}
int main(int argc, char const *argv[]) {
  std::cout << "Geben sie eine Zahl an: " << '\n';
  int n;
  std::cin >> n;
  std::cout << is_prime(n) << '\n';
  return 0;
}
