#include "Library.h"
#include "Book.h"
#include <vector>
#include <string>
#include <iostream>

void Library::addBook(Book newBook) {
  _Libra.push_back(newBook);
}

void Library::searchTitle(std::string title) {
  bool hit = false;
  for (int i = 0; i < _Libra.size(); i++) {
    if (_Libra[i].getTitel() == title) {
      _Libra[i].print();
      hit = true;
    }
  }
  if (hit == false) {
    std::cout << "Ihr Titel wurde nicht gefunden" << '\n';
  }
}

void Library::searchKeyword(std::string keyword) {
  bool hit = false;
  for (int i = 0; i < _Libra.size(); i++) {
    if(_Libra[i].getKeywords().find(keyword)!=std::string::npos) {
      _Libra[i].print();
      hit = true;
    }
  }
  if (hit == false) {
    std::cout << "Kein Title enthält das gesuchte Keyword" << '\n';
  }

}
