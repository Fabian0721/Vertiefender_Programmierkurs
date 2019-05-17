#ifndef LINKLIST_H
#define LINKLIST_H

class Linklist {
public:
  //Konstruktor
  Linklist();
  //Fügt einen Wert hinzu
  void add(int data);
  //Entfernt alle Nods mit den gegebenen Daten
  void erase(int data);
  //Druckt die Liste ins terminal
  void print();
  //Destruktor
  //~Linklist();

private:
  //Einzelnes Element
  struct Node {
    int value; //Wert des Elements
    Node* next; //Zeiger auf nächstes Element
  };
  //Einzelne Liste (start von ihr)
  struct Root {
    int count;          // Anzahl Elemente in der Liste
    Node* first; // Zeiger auf erstes Element der Liste
  };

  Root* liste = new Root; //Liste wird als Dynamische Variable erstellt auf dem Heap
  Node* element;  //Element
  Node* p; //zu löschendes Element

};
#endif
