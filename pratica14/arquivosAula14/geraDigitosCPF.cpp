#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

int converte(char c);

int main(){

  int n;
  cin >> n;

  string cpf;
  for(int i=0; i<n; i++){
    int somaP=0;
    int somaS=0;
    int nPrimeiro=10;
    cin >> cpf;
    for(int j=0; j<9; j++){
      somaP+=converte(cpf[j])*nPrimeiro;
      //cout << converte(cpf[j]) << "*" << nPrimeiro << endl;
      nPrimeiro--;
    }
    //cout << somaP << endl;
    int primeiro = ((10*somaP) % 11)%10;
    int nSegundo =11;
    for(int k=0; k<9; k++){
      somaS+=converte(cpf[k])*nSegundo;
      //cout << converte(cpf[k]) << "*" << nSegundo << endl;
      nSegundo--;
    }
    somaS+=primeiro*2;
    //cout << somaS << endl;
    int segundo = (somaS*10)%11;

    cout << setfill('0') << setw(2) << primeiro*10+segundo << endl;

  }
}

int converte(char c){
  return c - '0';
}
