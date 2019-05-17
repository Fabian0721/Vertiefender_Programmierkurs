#include <iostream>

int pow(int base, int exp) {
  int erg = 1;
  for (int i = 0; i < exp; i++) {
    erg = erg * base;
  }
  return erg;
}
int main(int argc, char const *argv[]) {
  std::cout << "Geben sie die Basis ein: " << '\n';
  int basis;
  std::cin >> basis;
  std::cout << "Geben sie den Exponenten ein: " << '\n';
  int expo;
  std::cin >> expo;
  std::cout << "Das Ergebnis ist: " << pow(basis, expo) << '\n';
  return 0;
}
