#ifndef LIBARY_H
#define LIBARY_H

#include "Book.h"
#include <vector>
#include <string>

class Library {
public:

  /**
  * Fügt ein neues Buch hinzu
  */
  void addBook(Book newBook);
  /**
  * Sucht nach einem Buchtitel
  */
  void searchTitle(std::string title);
  /**
  * Sucht nach einem Keyword
  */
  void searchKeyword(std::string keyword);

private:
  std::vector<Book> _Libra;

};

#endif
