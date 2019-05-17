#include <iostream>
#include <string>

int convert_number(std::string number) {
  int erg = 0;
  for (int i = 0; i < number.size(); i++) {
     erg = (erg*10) + ((int)number[i]-48);
  }
  return erg;
}

int main(int argc, char const *argv[]) {
  std::string eingabe;
  std::cout << "Geben sie eine Zahl ein: " << '\n';
  std::cin >> eingabe;
  std::cout << convert_number(eingabe) << '\n';
  return 0;
}
