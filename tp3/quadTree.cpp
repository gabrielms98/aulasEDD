#include <iostream>
#include <algorithm>
#include "PPMImage.h"

#include "quadTree.h"

using namespace std;


Node * QuadTree::insert(const Color cor, Node * &root, Node *parent, const int quadrante){
  if(!parent){
    root = new Node(cor);
    root->parent = parent;
    size=1;
    return root;
  } else{
    if(quadrante == 0){
      parent->zero = new Node(cor);
      parent->zero->parent = parent;
      size++;
      return parent->zero;
    } else if(quadrante == 1){
      parent->um = new Node(cor);
      parent->um->parent = parent;
      size++;
      return parent->um;
    } else if(quadrante == 2){
      parent->dois = new Node(cor);
      parent->dois->parent = parent;
      size++;
      return parent->dois;
    } else if(quadrante == 3){
      parent->tres = new Node(cor);
      parent->tres->parent = parent;
      size++;
      return parent->tres;
    }
  }
}

Node * QuadTree::insert(const Color cor, const int quadrante, Node *pai){
  return insert(cor, root, pai, quadrante);
}

void QuadTree::imprime(const Node *ptr) const{
  if(!ptr) return;
  if(!ptr->zero && !ptr->um && !ptr->dois && !ptr->tres){
    cout << ptr->cor.toStr();
  } else {
    cout << "(";
    imprime(ptr->zero);
    imprime(ptr->um);
    imprime(ptr->dois);
    imprime(ptr->tres);
    cout << ")";
  }
}

void QuadTree::imprime(int size, int brilho) const {
  cout << size << " " << brilho << "\n";
  cout << "(";
  imprime(root->zero);
  imprime(root->um);
  imprime(root->dois);
  imprime(root->tres);
  cout << ")";
  cout << endl;
}
