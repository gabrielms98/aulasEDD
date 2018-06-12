#include <iostream>
#include "Mediana.h"

using namespace std;

void Mediana::testaDiff(){
  int n = m1.size()-m2.size();

  if(n>1){
    m2.push(m1.top());
    m1.pop();
  } else if(n<-1){
    m1.push(m2.top());
    m2.pop();
  }
}

void Mediana::insere(int elem){
  testaDiff();

  if(m1.size()>m2.size()){
    m1.push(elem);
  } else if(m2.size()>m1.size()){
    m2.push(elem);
  } else if(m1.size()==m2.size()){
    m1.push(elem);
  }

}

int Mediana::getMediana(){
  testaDiff();

  if(m1.size()>m2.size()){
    return m1.top();
  } else if(m2.size()>m1.size()){
    return m2.top();
  } else{
    int n = (m1.top()+m2.top())/2;
    return n;
  }
}
