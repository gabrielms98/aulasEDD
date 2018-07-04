#ifndef QUADTREE_H
#define QUADTREE_H

#include <iostream>
#include <algorithm>
#include "PPMImage.h"

class QuadIterator;

class Node{
public:
  Node(const Color rgb)
    : cor(rgb), zero(NULL), um(NULL), dois(NULL), tres(NULL), parent(NULL) {}
  Node *zero, *um, *dois, *tres;
  Node *parent;
  Color cor;
};


class QuadTree{
  friend class QuadIterator;
public:
  QuadTree() : root(NULL) {}

  int getSize() const {return size;}
  Node *insert(const Color cor, const int quadrante, Node *pai);

  void imprime(int size, int brilho) const;
  void print() const;

private:
  Node *insert(const Color cor, Node * &root, Node *parent, const int quadrante);
  void imprime(const Node *ptr) const;
  void print(const Node *ptr) const;

  Node *root;
  int size;
};




#endif
