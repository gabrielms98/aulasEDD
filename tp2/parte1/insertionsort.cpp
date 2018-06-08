#include <iostream>

using namespace std;

void insertionSort(int *v, int n) {
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
  cout << "Foram movidos " << cont << " elementos para inserir o número " << elemInserir << endl;
  v[j+1] = elemInserir;
  total+=cont;
  }
}

int main(){
  int v[6] = {5, 1, 8, 4, 1, 3};

  insertionSort(v, 6);

  for(int i=0; i<6; i++) cout << v[i] << ", ";
  cout << endl;
}
