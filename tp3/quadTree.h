#ifndef QUADTREE_H
#define QUADTREE_H

#include <iostream>
#include <algorithm>
#include "PPMImage.h"

class QuadIterator;

class Node{
public:
  Node(const Color rgb) //contrutor de Node recebe uma cor
    : cor(rgb), zero(NULL), um(NULL), dois(NULL), tres(NULL), parent(NULL) {}
  Node *zero, *um, *dois, *tres; //os quatro filhos do nodo são ordenados de acordo com seu nome
  Node *parent; //nodo pai
  Color cor; //cor que o nodo representa
};


class QuadTree{
  friend class QuadIterator;
public:
  QuadTree() : root(NULL), size(0) {}

  Node *insert(const Color cor, const int quadrante, Node *pai); //a funcao insert insere diretamente no pai recebido como parametro
  //e retorna o nodo que foi inserido

  void imprime(int size, int brilho) const; //recebe o tamanho x ou y da imagem e imprimi na forma comprimida desejada pelo trabalho

private:
  //funcoes auxiliares
  Node *insert(const Color cor, Node * &root, Node *parent, const int quadrante);
  void imprime(const Node *ptr) const;

  Node *root;
  int size;
};




#endif
