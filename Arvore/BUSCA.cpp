#include <iostream>
#include "../tp2/parte1/MySet.h"
#include <algorithm>

using namespace std;

// /----------BUSCA EM LARGURA----------/
//elementos sao visitados nivel a nive(normalmente comencando da raiz e descendo)
//conhecido como BFS: Breadth First Fearch
//muitas aplicaçoes(principalmente em arvores mais gerais)
//Acessa o elemento e dps todos os seus filhos
//algoritmo para BFS (não vazia)
//achar o caminho minimo de um labirinto
/*
Queue<Node *> q;
q.push(root);
while(!q.empty()){
  P = q.front();
  q.pop();
  Processe p;
  Insira od filhos de p na fila q;
}
*/

template<class T>
void MySet<T>::imprimeBFS() const{
  cout << "Imprimindo BFS" << endl;
  MyQueue<const Node<T> *> q;
  q.push(root);

  while(!q.empty()){
    const Node<T> *p = q.front();
    q.pop();
    if(!p) continue;
    cout << p->elem << " ";
    if(p->left) q.push(p->left);
    if(p->right) q.push(p->right);
  }
}

//Modificando para imprimir o nivel:
template<class T>
void MySet<T>::imprimeNivelBFS() const{
  cout << "Imprimindo BFS" << endl;
  MyQueue<pair<const Node<T> *, int>> q;
  q.push(make_pair(root, 0));
  int nivelAtual = -1;
  while(!q.empty()){
    pair<const Node<T>*, int> p = q.front();
    q.pop();
    if(nivelAtual!=p.second){
      cout << "Nivel " << nivelAtual << ": ";
      //cout...
    }

    // fazer o cout...
    if(p.first->left) q.push(make_pair(p.first->left, p.second+1));
    if(p.first->right) q.push(make_pair(p.first->right. p.second+1));
  }
}

// /----------BUSCA EM PROFUNDIDADE----------/
//busca recursiva
//conhecido como DFS: Depth First Search
//principalmente em arvores binarias
/*
Stack<Node *> q;
q.push(root);
while{
  P = q.front();
  q.pop();
  Processe p;
  Insira os filhos de p na fila q;
}

//recursiva...
dfs(Node *n){
  Se n for nulo; pare...
  Visite n;
  Visite os filhos de n recursivamente;
}
*/

// /---------PERCURSO---------/
// c++ não começa pela raiz, ele implementa em ordem crescente dos elementos
// para isso usamos busca "In-Ordem"
// implementaçaõ do iterador...
// agora cada nodo tem Node<T> * parent;

template<class T>
MySet<T>::iterator MySet<T>::begin(){
  Node<T> *ptr = root;
  if(empty()) return end();
  while(ptr->left) ptr = ptr->left;
  return iterator(ptr);
}

template<class T>
MySetIterator<T> MySetIterator<T>::operator++(int){ //O(1), mas no pior caso eh log n
  if(ptr->right == NULL){
    if(!ptr->parent || ptr->parent->left == ptr) ptr = ptr->parent;
    else {
      while(ptr-> parent && ptr == ptr->parent->right) ptr = ptr->parent;
      ptr = ptr->parent;
    }
  } else {
    ptr = ptr->right;
    while(ptr->left) ptr = ptr->left;
  }
  return *this;
}

/*
int i = 1;
i = i++ +i;
R: nao tem resposta
*/
