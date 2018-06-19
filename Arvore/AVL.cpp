#include <iostream>
#include "../tp2/parte1/MySet.h"

//Uma AVL é uma ABP onde para cada nodo a altura de suas sub-arvores direita
//e esquerda deiferem em no max 1.


//funçao para verificar se uma arvore é AVL
template<class T>
int Node<T>::altura(const Node<T> *root) const{
  if(root == NULL) return 0;
  return 1 + max(altura(root->right), altura(root->left));
}

template<class T>
bool MySet<T>::checkIfAVL(const Node<T> *root, int &h, bool printFB) const{
  // if(root==NULL) return true;
  // int fb = altura(root->right)-altura(root->left);
  // if(printFB) cerr << root->elem << " " << fb << endl;
  // if(abs(fb)>1) return false;
  // return checkIfAVL(root->right, h, printFB) && checkIfAVL(root->left, h, printFB);

  //outro jeito de fazer
  //mais rapido pq n chama  func altura
  //para cada nodo chama func uma vez só
  if(!root) {
    h = -1;
    return true;
  }
  bool isL, isR;
  int hL, hR;
  isL = checkIfAVL(root->left, hL);
  isR = checkIfAVL(root->right, hR);

  h = 1 + max(hL, hR);
  return (abs(hL-hR) <=1) && isL && isR;
}

//4 casos especiais de inserçao de elemento e manter a arvore AVL
//  1- insercao de nodo na sub-arvore direita filho direito
//    S: ROTACIONAR (nao precisamos preocupar com o resto da arvore pois a sua altura geral n ira mudar)
//  2- insercao de nodo na sub-arvore esquerda filho direito
//    S: ROTACAO DUPLA
//ex: ir mostrando a inserçao e balanceamento da AVL (S, T, X, E, B, M, G, N, J, Q, Z)
/*
                      S

                      S
                        T

                      S
                        T
                          X
                    left(S)
                      T
                    S   X

                      T
                    S   X
                  E

                      T
                    S   X
                  E
                B

                      T
                  E       X
                B   S
                ...
*/
