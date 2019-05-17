#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "Wie breit soll der Dia sein?" << '\n';
  int breit;
  std::cin >> breit;
  //Prüfen auf illegale eingabe
  if (breit%2 == 0 || breit < 0) {
    std::cout << "Error: Please do not enter a round number!" << '\n';
  } else {
  //Ausgabe des Diamanten
    int counter = 0; //zaehler der die ebenen Zahl zählt

    //Oberes Stück:
    for (int i = 0; i < breit+1; i++) { //Tiefe Diamanten
      if (i%2 != 0) { //Erzeugt nur ungerade Anzahl an Sternen
        for (int l = 0; l < ((breit-1)/2)-counter; l++) {
          std::cout << " ";
        }
        for (int k = 0; k < i; k++) { //Breite Diamanten
          std::cout << "*";
        }
        counter = counter + 1;
        std::cout << '\n';
      }
    }

    //Unteres Stück:
    counter = 0;
    for (int i = 0; i < breit+1; i++) { //Tiefe Diamanten
      if (i%2 != 0) { //Erzeugt nur ungerade Anzahl an Sternen
        for (int l = 0; l < counter+1; l++) {
          std::cout << " ";
        }
        for (int k = breit-1; k > i; k--) { //Breite Diamanten (minus 1 damit symetrisch)
          std::cout << "*";
        }
        counter = counter + 1;
        std::cout << '\n';
      }
    }
  }
  return 0;
}
