#include <iostream>

int convert_number(std::string number, int base) {
  int erg = 0;
  for (int i = 0; i < number.size(); i++) {
    erg = erg * base + (number[i]-48);
  }
  return erg;
}

int main(int argc, char const *argv[]) {
  std::cout << "Geben sie eine Zahl in einem beliebigen Zahlensystemen ein: " << '\n';
  std::string eingabe;
  std::cin >> eingabe;
  std::cout << "Geben sie ihre Zahlensystems Basis an: " << '\n';
  int base;
  std::cin >> base;
  std::cout << convert_number(eingabe, base) << '\n';
  return 0;
}
