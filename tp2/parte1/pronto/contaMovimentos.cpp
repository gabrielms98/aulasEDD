#include <iostream>
#include <cstring>
#include "MySet.h"
#include <ctime>

using namespace std;

int insertionSort(long long int *v, int n);

int main(){
  string metodo;
  //cout << "Digite o método: ";
  cin >> metodo;
  //cout << endl;

  long long int n;
  //cout << "Digite a quantidade de elementos: ";
  cin >> n;
  //cout << endl;

  long long int array[n];
  //cout << "Digite os elementos: ";
  for(int i=0; i<n; i++){
    cin >> array[i];
  }
  //cout << endl;

  long long int contador=0;  //inicializa o contador da quantidade de movimentos com 0
  if(metodo == "ARVORE"){
    MySet<int> s; //cria uma estrutura de dados do tipo arvore binaria
    for(int j=0; j<n; j++){ //vai chamando a função de contar a qnt de movimentos para cada numero do array
      contador+=s.qntMov(array[j]); //o contador é incrementado a cada iteração do loop com o retorno obtido da funcao qntMov
      s.insert(array[j]); //insere tal numero na arvore
    }
  } else if(metodo == "ORDENAR"){
    contador = insertionSort(array, n); //é atribuido ao contador o numero retornado da funcao insertionSort
  }

  cout << contador << endl;  // imprimi o contador na tela
}

int insertionSort(long long int *v, int n) {
  int total = 0;
  for (int i=1; i<n; i++) {
   // o arranjo entre as posicoes [0,i) ja esta ordenado
  int elemInserir = v[i];
  int j = i-1;
  int cont = 0;
  while( j>=0 && v[j] > elemInserir) {
    v[j+1] = v[j]; //enquanto v[j] for maior que o elemInserir, mova para direita v[j]
    j--; //decremente j
    cont++; //incremente o contador de movimentos para inserir tal elemento
  }
  //cout << "Foram movidos " << cont << " elementos para inserir o número " << elemInserir << endl;
  v[j+1] = elemInserir;
  total+=cont; //total é igual a soma do contador de cada elemento a ser inserido
  }

  return total;
}
