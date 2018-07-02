#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//Observacoes:
//-- Atencao: C++11 e' necessario para compilar este codigo

#include "PPMImage.h" //nao modifique a classe PPMImage!!!

//--------------------------------
//Implemente seu trabalho a partir daqui... (crie outros arquivos .h/.cpp se necessario)
#include "quadTree.h"



int main(int argc,char**argv) {

if(argv[1] == "comprimir"){
  QuadTree quadSet;
  string st;
  cin >> st;

  int m, n, brilho;
  cin >> m >> n >> brilho;

  int r, g, b;
  while(cin >> r >> g >> b){
    Color cor(r, g, b);
    quadSet.insert(cor);
    
  }
}

}
