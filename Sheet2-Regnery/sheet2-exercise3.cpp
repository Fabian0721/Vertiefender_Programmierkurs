#include <iostream>

bool is_prime(int number) {
  for (int i = 2; i < number; i++) {
    if ((number%i) == 0) {
      return false;
    }
  }
  return true;
}

void print_primes(int upto) {
  for (int i = 2; i < upto; i++) {
    if (is_prime(i)) {
      std::cout << i << " ";
    }
  }
}


int main(int argc, char const *argv[]) {
  std::cout << "Geben sie eine Zahl an: " << '\n';
  int n;
  std::cin >> n;
  //std::cout << is_prime(n) << '\n';
  print_primes(n);
  return 0;
}
