#include <iostream>
#include "MyPriorityQueue.h"
#include "MyPQinvertida.h"

#ifndef MEDIANA_H
#define MEDIANA_H

using namespace std;

class Mediana{
public:
  void insere(const int);
  int getMediana();
  void print() const;

private:
  void testaDiff();

  MyPriorityQueue<int> m1;
  MyPriorityQueueDec<int> m2;
};

#endif
