#include <iostream>
#include <cmath>

int main(int argc, char const *argv[]) {
  //Eingaben
  std::cout << "Geben sie a ein: " << '\n';
  double a;
  std::cin >> a;
  std::cout << "Geben sie b ein: " << '\n';
  double b;
  std::cin >> b;
  std::cout << "Geben sie c ein: " << '\n';
  double c;
  std::cin >> c;
  //Berechnung
  double x1 = (-b + sqrt((b*b)-(4*a*c)))/(2*a);
  double x2 = (-b - sqrt((b*b)-(4*a*c)))/(2*a);
  //Ausgabe
  std::cout << "X1 = " << x1 << " und X2 = " << x2 << '\n';
  return 0;

}
