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

void geraQuadTree(QuadTree &set, PPMImage &img, int x, int y);


int main(int argc,char**argv) {

  if((string)argv[1] == "comprimir"){
    QuadTree quadSet;
    PPMImage img;
    cin >> img;

    QuadTree quadTree;
    //geraQuadTree(quadTree,img,img.getRows(), img.getColumns());
    

  }


}

void geraQuadTree(QuadTree &set, PPMImage &img, int x, int y){

}
