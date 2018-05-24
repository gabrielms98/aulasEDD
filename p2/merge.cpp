#include <iostream>
#include "../materialListasEIteradores/Contiguidade/Generica_Com_Excecao/MyVec.h"

using namespace std;


template<class T>
void merge(MyVec<T> &a, const MyVec<T> &b){
  int os = a.size();
  a.resize(os*2);

  for(int i=os-1; i>=0; i--){
    a[2*i] = a[i];
    a[2*i+1] = b[i];
  }
}

template<class T>
void merge2(MyVec<T> &a, const MyVec<T> &b){ //O(n^2)
  typename MyVec<T>::iterator itb = b.begin();

  //VALIDADE DO ITERADOR
  for(int i=0; i<b.size(); i++){
    a.insert(*itb, (a.begin()+2*i+1));
    itb++;
  }
}
