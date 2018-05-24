#include <iostream>

using namespace std;

class Nodo{
public:
  Nodo(int val): data(val), next(NULL){}
  int data;
  Nodo *next;
};

void print(Nodo *begin){
  if(!begin){
    cout << endl;
    return;
  }
  cout << begin->data << "->";
  print(begin->next);
}

Nodo *ordenaLista(Nodo *begin){
  if(!begin) return begin;

  Nodo *begin2 = begin;
  //chegar na segunda metade da lista
  while(begin2->next!=NULL &&  begin2->data <= begin2->next->data){
    begin2 = begin2->next;
  }

  //desconectar a segunda metade
  Nodo *last = begin2;
  begin2 = begin2->next;
  if(begin2==NULL){
    return begin;
  }
  last->next = NULL;
  //agr temos duas listas... 1a começa em begin e a oura começa em begin2

  //agora precisamos ordenar a lista usando as duas metades
  Nodo *result;
  if(begin->data < begin2->data){
    result = begin;
    begin = begin->next;
  } else {
    result = begin2;
    begin2 = begin2->next;
  }
  last = result;
  while(begin || begin2){
    if(begin2 == NULL || (begin!=NULL && begin->data <= begin2->data)){
      last->next = begin;
      begin = begin->next;
    } else {
      last->next = begin2;
      begin2 = begin2->next;
    }
    last = last->next;
  }
  return result;

}

int main(){
  Nodo *l = new  Nodo(1);
  l->next = new Nodo(2);
  l->next->next = new Nodo(3);
  l->next->next->next = new Nodo(4);
  l->next->next->next->next = new Nodo(5);
  l->next->next->next->next->next = new Nodo(2);
  l->next->next->next->next->next->next = new Nodo(2);
  ordenaLista(l);
  print(l);

}
