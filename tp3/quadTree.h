#ifndef QUADTREE_H
#define QUADTREE_H

#include <iostream>
#include <algorithm>
#include "PPMImage.h"

class QuadIterator;

class Node{
public:
  Node(const Color rgb)
    : cor(rgb), zero(NULL), um(NULL), dois(NULL), tres(NULL), pai(NULL) {}
  Node *zero, *um, *dois, *tres;
  Node *pai;
  Color cor;
};


class QuadTree{
  friend class QuadIterator;
public:

int size() const;
void insert(const Color cor);

private:
  Node *root;

};




#endif
