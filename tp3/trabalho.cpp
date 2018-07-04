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
#include "MyStack.h"

void geraQuadTree(QuadTree &set, PPMImage &img, int rows, int columns, int size, Node *ptr);
int checkDelim(const string &st, int index);
void leQuadrante(string st, int index, int size);
int converte(char c);

int main(int argc,char**argv) {

  if((string)argv[1] == "comprimir"){
    PPMImage img;
    cin >> img;

    QuadTree quad;

    Color corAux(0,0,0);

    Node *raiz = quad.insert(corAux,0,NULL);
    geraQuadTree(quad,img,0, 0, img.getRows(), raiz); //size inicial pode ser o numero de Rows
    //ou o numero de Columns pois eles sao iguais
    quad.imprime(img.getRows(), img.getMaxCol());

  } else if((string)argv[1] == "descomprimir"){
    int size, brilho;
		cin >> size >> brilho;

		char colInicial;
		cin >> colInicial;

		string st;
		cin >> st;

    cout << st.size() << endl;
		cout << st << endl;


    Color *cor = new Color[size];
    leQuadrante(st, 0, size);
  }


}

void geraQuadTree(QuadTree &set, PPMImage &img, int rows, int columns, int size, Node *ptr){
  Color cor;
  if(!img.isUniform(rows, columns, size, cor)){
    geraQuadTree(set, img, rows+size/2, columns+size/2, size/2, set.insert(cor, 0, ptr)); //quadrante = 0
    geraQuadTree(set, img, rows+size/2, columns, size/2 ,set.insert(cor, 1, ptr)); //quadrante = 1
    geraQuadTree(set, img, rows, columns, size/2, set.insert(cor, 2, ptr)); //quadrante = 2
    geraQuadTree(set, img, rows, columns+size/2, size/2, set.insert(cor, 3, ptr)); //quadrante = 3
  } else {
    set.insert(cor, 0, ptr);
  }
}

int checkDelim(const string &st, int index) {
	MyStack<char> s;
	for(int i=index; i<st.size(); i++) {
    //cout << st[i] << " " << i << endl;
		switch(st[i]) {
			case '(':
				s.push(st[i]);
				break;
			case ')':
				s.pop();
        if(s.empty()) {
        //cout << "return " << i << endl;
          return i+1;
        }
				break;
		}
	}
}

void leQuadrante(string st, int index, int size){

  int quad0 = checkDelim(st, index);
  int quad1 = checkDelim(st, quad0);
  int quad2 = checkDelim(st, quad1+1);
  int quad3 = checkDelim(st, quad2+1);

  leQuadrante(st, index+1,size/4);
  leQuadrante(st, quad1+1,size/4);
  leQuadrante(st, quad2+1,size/4);
  leQuadrante(st, quad3+1,size/4);

  if(size == 1) {
    cout << index << endl;
    return;
  }

}

int converte(char c){
  return c - '0';
}
