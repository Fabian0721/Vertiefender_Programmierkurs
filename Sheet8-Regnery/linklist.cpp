#include "linklist.h"
#include <iostream>

Linklist::Linklist() {
  liste->first = nullptr;   // nullptr: Liste ist leer
  liste->count = 0;
  std::cout << "Leere Liste wurde erstellt!" << '\n';
}

void Linklist::add(int data) {
  //Neues Element erstellen
  element = new Node;
  element->value = data;
  //Eintragen in die Liste an letzter positionen
  Node* positionPtr = liste->first;
  for (int i = 1; i < liste->count; i++) { //Wandern an die letzte Position
        positionPtr = positionPtr->next;
  }
  if (positionPtr==0) { //Falls die Liste leer ist
        element->next = liste->first;
        liste->first = element;
        liste->count = liste->count + 1;
      } else { // Wenn elemente in der Liste sind
        element->next = positionPtr->next;
        positionPtr->next = element;
        liste->count = liste->count + 1;
      }
}


void Linklist::erase(int data) {
  //Sucht die Position der Daten in der Liste
  Node* sucher = liste->first;
   int position = 2;
   for (; data != sucher->value; position++) {
    sucher = sucher->next;
  }
  position = position -1;
  
  sucher = liste->first;
  for (int i = 2; i < position; i++) {
    sucher = sucher->next;
  }
   // Entferne Element an der ersten Position
   if (position==1) {
     p = liste->first;
     if (p!=0) {
       liste->first = p->next;
       liste->count = liste->count - 1;
     }
   }
   // entferne Element an der Position die nicht die erste ist.
   p = sucher->next;
   if (position!=1) {
     sucher->next = p->next;
     liste->count = liste->count - 1;
   }
   delete p;
 }

void Linklist::print() {
  Node* printer = liste->first;
    for (int i = 0; i < liste->count; i++) {
      std::cout << "element value: " << printer->value << '\n';
      printer = printer->next;
  }
}
