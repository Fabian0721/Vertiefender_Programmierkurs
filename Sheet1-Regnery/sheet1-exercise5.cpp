#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "!Geben sie eine Schranke nach oben an:" << '\n';
  int schranke;
  std::cin >> schranke;
  int summe = 0;
  for (int i = 0; i < schranke; i++) {
    if (i % 5 == 0) {
      summe = summe + i;
    } else if (i % 3 == 0) {
        summe = summe + i;
    }

  }
  std::cout << "Die Summe Summe beträgt: " << summe << '\n';
  //Für 1000 beträgt die Summe 266333
  return 0;
}
