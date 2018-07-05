#include <iostream>
#include "../../materialListasEIteradores/Contiguidade/Generica_Com_Excecao/MyVec.h"
using namespace std;

//armazena elementos em uma lista
//ao realizar um pop() ou top(), procurar o elemento com maior prioridade
//O(n) -> percorrer toda lista para achar o elemento
//podemos armazenar no vetor um ponteiro para o elemento de maior prioridade
//podemos ordenar a lista para facilitar o pop e front, mas tem q orednar frequentemente a lista

//Solução: HEAP
//implementação bastante eficiente usando vector
//Propriedade: cada elemento possui dois filhos(no max), e possui valor/prioridade maior que ou igual a eles.
//filhos sao os elementos na pos: 2i+1 e 2i+2
//pai: (i-1)/2
//elemento de MAIOR prioiridade é o primeiro elemento
//apagar e inserir eh mais rapido em um heap do q em vector
//remover elemento -> MoveDown O(log(n))
//inserir -> MoveUp O(log(n))

#ifndef MYPRIORITYQUEUE_H
#define MYPRIORITYQUEUE_H

template<class T>
class MyPriorityQueue{
public:
  void push(const T&el);
  const T& top() const {return heap[0];}
  void pop();

  int size() const {return heap.size();}

  void print() const;

private:
  void moveUp(int pos);
  void moveDown(int pos);

  MyVec<T> heap;

};

template<class T>
void MyPriorityQueue<T>::moveDown(int i){
  if(i>=size()) return;

  int mf = 2*i+1; //mf = indice maior filho
  if(mf>=size()) return;
  if(mf+1 < size() && heap[mf+1]>heap[mf]) mf = mf+1;

  if(heap[mf] > heap[i]){
    swap(heap[mf], heap[i]);
    moveDown(mf);
  }
}

template<class T>
void MyPriorityQueue<T>::moveUp(int i){
  if(i==0) return;

  int pai = (i-1)/2;
  if(heap[i] > heap[pai]){
    swap(heap[i], heap[pai]);
    moveUp(pai);
  }

}

template<class T>
void MyPriorityQueue<T>::push(const T &el){
  heap.push_back(el);
  moveUp(heap.size()-1);
}

template<class T>
void MyPriorityQueue<T>::pop(){
  swap(heap[heap.size()-1],heap[0]); //pega o ultimo elemento do heap e coloca-o na primeira posicao
	heap.resize(heap.size()-1); //reduz o tamanho do heap
	moveDown(0); //restaura as propriedades de heap a partir da posicao 0
}

#endif
