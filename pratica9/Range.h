#ifndef RANGE_H
#define RANGE_H

#include <iostream>

using namespace std;

class Nodo{
public:
  Nodo(const int elem) : data(elem), next(NULL) {}

  int data;
  Nodo *next;
};

class IteratorRange{
  friend class Range;

public:
  IteratorRange(Nodo *node): ptr(node) {}

  int &operator*() {return ptr->data;}
  const int &operator*() const {return ptr->data;}

  bool operator==(const IteratorRange &other) const {return ptr==other.ptr;}
  bool operator!=(const IteratorRange &other) const {return ptr!=other.ptr;}

  IteratorRange operator++();
  // IteratorRange operator--();

  IteratorRange operator++(int);
  // IteratorRange operator--(int);

private:
  Nodo *ptr;
};

class Range{
public:

  friend IteratorRange;
  typedef IteratorRange iterator;

  Range(int, int);
  Range(const Range&);

  Range &operator=(const Range&);

  iterator begin() {return iterator(dataFirst);};
  iterator end() {return iterator(NULL);};

  void push_back(int elem);

  void clear();

private:
  void create();
  void destroy();
  void destroy(Nodo *elem);

  Nodo *dataFirst, *dataLast;
  int dataSize;
};

IteratorRange IteratorRange::operator++(){
  ptr = ptr->next;
  return ptr;
}

IteratorRange IteratorRange::operator++(int){
  IteratorRange oldIt= *this;
  ptr = ptr->next;
  return oldIt;
}

void Range::create(){
  dataFirst = dataLast  = NULL;
  dataSize = 0;
}

void Range::destroy(Nodo *elem){
  if(elem == NULL) return;
  destroy(elem->next);
  delete elem;
}

void Range::destroy(){
  dataSize = 0;
  destroy(dataFirst);
}

void Range::clear(){
  destroy();
  create();
}

Range::Range(int x, int y){
  create();
  dataSize = y-x;
  for(int i=x; i<=y; i++) push_back(i);
}

Range::Range(const Range &other){
  create();
  *this = other;
}

Range & Range::operator=(const Range &other){
  if(this==&other) return *this;
	clear(); //Exercicio: por que precisamos disso?

  if(other.dataFirst == NULL) {
  	dataFirst = dataLast = NULL;
  } else {
   Nodo *curr = other.dataFirst;
		while(curr!=NULL) { //equivalente a "while(curr)"
		  push_back(curr->data);
			curr = curr->next; //avance para o proximo nodo
		}
  }
	return *this;

}

void Range::push_back(int elem){
  if(dataFirst==NULL) { //caso especial: lista inicialmente vazia
    dataFirst = dataLast = new Nodo(elem);
  } else {
    dataLast->next = new Nodo(elem);
    dataLast = dataLast->next;
  }
  dataSize++;
}

#endif
