#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:

  /**
  * Initialize the Book
  */
  Book(std::string title, std::string author, std::string keywords);

  /**
  * Prints the Book
  */
  void print();

  /**
  * Getter Methoden
  */
  std::string getTitel();
  std::string getAuthor();
  std::string getKeywords();
private:
  std::string _title;
  std::string _author;
  std::string _keywords;
};

#endif
