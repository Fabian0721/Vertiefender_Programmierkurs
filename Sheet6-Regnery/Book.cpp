#include "Book.h"
#include <string>
#include <iostream>

/*Book::Book (std::string title, std::string author, std::string keywords):_title(title), _author(author), _keywords(keywords)
 {}*/

 Book::Book(std::string title, std::string author, std::string keywords) {
   _title = title;
   _author = author;
   _keywords = keywords;
 }

 void Book::print() {
   std::cout << this->_title << '\n';
   std::cout << this->_author << '\n';
   std::cout << this->_keywords << '\n';
 }

 std::string  Book::getTitel() {
   return _title;
 }

 std::string Book::getAuthor() {
   return _author;
 }

 std::string Book::getKeywords() {
   return _keywords;
 }
