#include <iostream>

int main(int argc, char const *argv[]) {
//a)
std::cout << "Aufgabe a:" << '\n';
  std::cout << "Geben sie eine Schranke an: " << '\n';
  int n;
  std::cin >> n;
  int summe = 0;
  for (int i = 0; i < n; i++) {
    summe = i + summe;
    std::cout << summe << '\n';
  }
//b)
std::cout << "Aufgabe b:" << '\n';
  for (int i = 0; i < 20; i++) {
    if (i % 2 == 0) {
      std::cout << i*i << '\n';
    }
  }
//c)
std::cout << "Aufgabe c:" << '\n';
  std::cout << "Geben sie eine Zahl ein: " << '\n';
  std::cin >> n;
  /*
  for (int i = 0; i <= n; i++) {
    std::cout << i << " ";
  }
  std::cout << '\n';*/

  for (int i = 0; i <= n; i++) {
    for (int k = 0; k <= n; k++) {
      std::cout << i*k << '\t';
    }
    std::cout << '\n' << '\n' << '\n';
  }

  return 0;
}
