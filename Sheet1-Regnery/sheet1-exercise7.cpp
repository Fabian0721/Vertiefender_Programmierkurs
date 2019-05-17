#include <iostream>

int main(int argc, char const *argv[]) {
  unsigned int a = 0;
  unsigned int b = 1;
  unsigned int c;
  std::cout << "Geben sie die Anzahl der Operationen an:" << '\n';
  unsigned int n;
  std::cin >> n;
  std::cout << a << '\n';
  std::cout << b << '\n';
  for (unsigned int i = 0; i < n; i++) {
    c = a + b;
    std::cout << c << '\n';
    a = b;
    b = c;
  }
  return 0;
}

//Man brauch unsigned integer damit der Speicher nicht überläuft
//und der Therm wird 32 mal durchgeführt damit er unter 4000000 bleibt
