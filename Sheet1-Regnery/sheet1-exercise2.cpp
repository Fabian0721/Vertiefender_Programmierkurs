#include <iostream>

int main(int argc, char const *argv[]) {
  double celsius, fahrenheit;
  std::cout << "Geben die Temperatur in Fahrenheit an: ";
  std::cin >> fahrenheit;
  celsius = ((fahrenheit - 32) * 5) / 9;
  std::cout << "Die Temperatur berägt: " << celsius << '\n';
  return 0;
}
