#include <iostream>
#include "MyPriorityQueue.h"
#include "MyPQinvertida.h"

#ifndef MEDIANA_H__
#define MEDIANA_H__

using namespace std;

class Mediana{
public:
  void insere(int elem);
  int getMediana();
  void print() const;

private:
  void testaDiff();

  MyPriorityQueue<int> m1;
  MyPriorityQueueDec<int> m2;
};

#endif
