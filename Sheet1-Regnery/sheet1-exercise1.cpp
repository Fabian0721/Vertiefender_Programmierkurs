#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  std::string vorname, nachname, beruf, netto;
  std::cout << "Geben sie ihren Vornamen ein: ";
  std::cin >> vorname;
  std::cout << "Geben sie ihren Nachnamen ein: ";
  std::cin >> nachname;
  std::cout << "Geben sie ihren Beruf ein: ";
  std::cin >> beruf;
  std::cout << "Geben sie ihr Nettoverdienst an: ";
  std::cin >> netto;
  std::cout << vorname << " " << nachname << '\n';
  std::cout << beruf << " " << netto << "€" << '\n';
  return 0;
}
