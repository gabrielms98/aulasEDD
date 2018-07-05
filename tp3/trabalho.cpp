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
int checkDelim(const string st, int index);
void leQuadrante(PPMImage &img ,string st, int y, int x, int size);
int converte(char c);

int main(int argc,char**argv) {

  if((string)argv[1] == "comprimir"){ //recebe o parâmetro passado pela linha de comando
    PPMImage img; //cria um objeto do tipo PPMImage
    cin >> img; //recebe toda a imagem recebida como parametro e a armazena no objeto img

    QuadTree quad; //inicializa uma QuadTree para ser usa posteriormente

    Color corAux(0,0,0); //cria uma cor auxiliar para passar como parametro na funcao insert que se segue

    Node *raiz = quad.insert(corAux,0,NULL); //incializa a QuadTree inserindo manualmente sua raiz
    geraQuadTree(quad,img,0, 0, img.getRows(), raiz); //size inicial pode ser o numero de Rows
    //ou o numero de Columns pois eles sao iguais
    quad.imprime(img.getRows(), img.getMaxCol());

  } else if((string)argv[1] == "descomprimir"){
    PPMImage img;

    int size, brilho;
    cin >> size >> brilho;

    string st;
    cin >> st;

    leQuadrante(st, 0);
  }


}

void geraQuadTree(QuadTree &set, PPMImage &img, int rows, int columns, int size, Node *ptr){
  //tal funcao recebe por referencia uma quadtree e PPMImage
  //a partir da PPMImage e sua funcao isUniform é verificado se o quadrante recebido como parâmetro é unforme ou não
  //se não for uniforme chama-se recursivamene a funcao geraQuadTree para os quatro quadrantes subdivididos do quadrante inicial
  Color cor; //cria uma cor auxiliar que vai ser alterada por receferencia na funcao isUniform
  if(!img.isUniform(rows, columns, size, cor)){
    geraQuadTree(set, img, rows+size/2, columns+size/2, size/2, set.insert(cor, 0, ptr)); //quadrante = 0
    geraQuadTree(set, img, rows+size/2, columns, size/2 ,set.insert(cor, 1, ptr)); //quadrante = 1
    geraQuadTree(set, img, rows, columns, size/2, set.insert(cor, 2, ptr)); //quadrante = 2
    geraQuadTree(set, img, rows, columns+size/2, size/2, set.insert(cor, 3, ptr)); //quadrante = 3
  } else {
    //se o quadrante for uniforme basta inserir o nodo referente a tal quadrante
    set.insert(cor, 0, ptr);
  }
}

int checkDelim(const string st, int index) {
  //essa funcao verifica onde fica o ')' referente ao parenteses referente a posicao index
  if(st[index] != '(') return -1;
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

void leQuadrante(PPMImage &img, string st, int y, int x, int size){
  int quad0 = checkDelim(st, index);
  int quad1,quad2,quad3;
  if(st[quad0] != '(' && st[quad0]!=')'){
    processaCor(st[quad0], img, y, x); //FAZER
  } else {
    quad1 = checkDelim(st, quad0);
    quad2 = checkDelim(st, quad1);
    quad3 = checkDelim(st, quad2);

    leQuadrante(img, st, y+1, x+1, size/2);
    leQuadrante(img, st, y+1, x+1, size/2);
    leQuadrante(img, st, y+1, x+1, size/2);
    leQuadrante(img, st, y+1, x+1, size/2);
  }


}

int converte(char c){
  return c - '0';
}
