#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  std::cout << "Geben sie eine Rechnung in der Form 1+2 an: " << '\n';
  std::string rechnung;
  std::cin >> rechnung;
  int ergebnis;
  //Werte auslesen
  int a = ((int)rechnung[0]-48);
  int b = ((int)rechnung[2]-48);
  //Rechnungen operationen werden erkannt und durchgeführt
  if (rechnung[1] == '+') {
    ergebnis  = a + b;
  }
  if (rechnung[1] == '-') {
    ergebnis  = a - b;
  }
  if (rechnung[1] == '*') {
    ergebnis  = a * b;
  }

  if (rechnung[2] == '0') { //Division durch Null wird abgefangen
    std::cout << "Division durch Null verboten!" << '\n';
  } else {
    if (rechnung[1] == '/') {
      ergebnis  = a / b;
    }
  }

  std::cout << " = " << ergebnis << '\n';
  return 0;
}
