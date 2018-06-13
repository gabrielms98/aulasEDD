#include <iostream>
#include <cstring>
#include "MySet.h"
#include <ctime>
#include <fstream>

using namespace std;

int insertionSort(long long int *v, int n);

int main(){
  string metodo;
  //cout << "Digite o método: ";
  //cin >> metodo;
  //cout << endl;

  long long int n = 1000000;
  //cout << "Digite a quantidade de elementos: ";
  //cin >> n;
  //cout << endl;

  ifstream in("1000000.txt");
  metodo = "ARVORE";
  long long int array[n];
  //cout << "Digite os elementos: ";
  for(int i=0; i<n; i++){
    in >> array[i];
    cout << array[i] << " ";
  }
  cout << endl;

  long long int contador=0;
  if(metodo == "ARVORE"){
    MySet<int> s;
    for(int j=0; j<n; j++){
      contador+=s.qntMov(array[j]);
      s.insert(array[j]);
    }
  } else if(metodo == "ORDENAR"){
    contador = insertionSort(array, n);
  }
  cout << "tamanho entrada: " << n << endl;
  cout << contador << endl;
}

int insertionSort(long long int *v, int n) {
  int total = 0;
  for (int i=1; i<n; i++) {
   // o arranjo entre as posicoes [0,i) ja esta ordenado
  int elemInserir = v[i];
  int j = i-1;
  int cont = 0;
  while( j>=0 && v[j] > elemInserir) {
    v[j+1] = v[j];
    j--;
    cont++;
  }
  //cout << "Foram movidos " << cont << " elementos para inserir o número " << elemInserir << endl;
  v[j+1] = elemInserir;
  total+=cont;
  }

  return total;
}
