#include <iostream>
#include "Tetris.h"

using namespace std;

Tetris::Tetris(int colunas){
  jogo = new char*[colunas];     //cria uma martiz inicial com a qnt de colunas = "colunas" e altura =0
  for(int i=0; i<colunas; i++){
    jogo[i] = new char[1];
  }
  alturas = new int[colunas]; //set todas alturas iniciais para 0
  for(int j=0; j<colunas; j++){
    alturas[j] = 0;
  }

  ncolunas = colunas;
}


char Tetris::get(int c, int l) const{
  return jogo[c][l];
}

int Tetris::getAltura() const{
  int max = 0;    //cria variavel auxiliar com 0
  for(int i=0; i<getNumColunas(); i++){
    if(max<alturas[i]) //se max for menor significa que achamos um novo maior numero
      max = alturas[i];
  }
  return max;
}

int Tetris::getAltura(int c) const{
  return alturas[c];
}

void Tetris::removeColuna(int c){
  if(c >= 0 && c < getNumColunas())
    delete[] jogo[c];
}

void Tetris::removeLinhasCompletas(){
  int qnt = 0; //cria variavel auxiliar
  for(int i=0; i<getAltura()-1; i++){ //faz um for aninhado para caminha pela matriz
    for(int j=0; j<ncolunas; j++){
      if(jogo[i][j] != ' ') qnt++; //em uma linha, contamos qnts casas estao preenchidas...
    }
    if(qnt == ncolunas){ //se esse numero for do tamanho o n de colunas... faz outro for aninhado para copiar o elemento de cima de dele a partir da linha q deve ser excluida
      for(int x=i; x<getAltura()-2; x++){ //para na penultima linha para que a ultima n copie uma memoria nao alocada
        for(int y=0; y<ncolunas; y++){
          jogo[x][y] = jogo[x+1][y];
        }
      }
      for(int k=0; k<ncolunas; k++){ //manualmente a ultima linha se torna vazia
        jogo[getAltura()-1][k] = ' ';
      }
      qnt=0;
    }
  }
}

void Tetris::insert(char elem, int c, int l){
  jogo[c][l] = elem;
}


/*void Tetris::setAltura(int h){
  alturas = h;
}*/

int Tetris::getNumColunas() const{
  return ncolunas;
}

void Tetris::imprime(){
  for(int i=getAltura()-1; i>=0; i--){
    for(int j=0; j<ncolunas; j++){
    if(jogo[i][j] == 'Z' || jogo[i][j] == 'I' || jogo[i][j] == 'J' || jogo[i][j] == 'L' || jogo[i][j] == 'O' ||jogo[i][j] == 'S' || jogo[i][j] == 'T')
     cout << jogo[i][j];
    else cout << " ";
    }
    cout << endl;
  }
  for(int i=0; i<ncolunas; i++){
    cout << alturas[i];
  }
  cout << endl;
}

bool Tetris::adicionaForma(int coluna, int linha, char id, int rotacao){
  // essa funçao adiciona manualmente cada peça em cada uma de suas rotações
  // mas antes de adicionar ele chama a func criaEspaco() para poder alocar o espaço necessario para colocar a peça

  if(id == 'I'){
    if(rotacao == 0 || rotacao == 180){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna] = 'I';
      jogo[linha-1][coluna] = 'I';
      jogo[linha-2][coluna] = 'I';
      jogo[linha-3][coluna] = 'I';
    } else if(rotacao == 90 || rotacao == 270){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna] = 'I';
      jogo[linha][coluna+1] = 'I';
      jogo[linha][coluna+2] = 'I';
      jogo[linha][coluna+3] = 'I';
    }

  } else if(id == 'J'){
    if(rotacao == 0){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna] = 'J';
      jogo[linha][coluna+1] = 'J';
      jogo[linha][coluna+2] = 'J';
      jogo[linha][coluna+3] = 'J';
      jogo[linha-1][coluna+3] = 'J';
    } else if(rotacao ==90){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna+1] = 'J';
      jogo[linha-1][coluna+1] = 'J';
      jogo[linha-2][coluna+1] = 'J';
      jogo[linha-3][coluna+1] = 'J';
      jogo[linha-3][coluna] = 'J';
    } else if(rotacao == 180){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna] = 'J';
      jogo[linha-1][coluna] = 'J';
      jogo[linha-1][coluna+1] = 'J';
      jogo[linha-1][coluna+2] = 'J';
      jogo[linha-1][coluna+3] = 'J';
    } else if(rotacao == 270){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna] = 'J';
      jogo[linha-1][coluna] = 'J';
      jogo[linha-2][coluna] = 'J';
      jogo[linha-3][coluna] = 'J';
      jogo[linha][coluna+1] = 'J';
    }

  } else if(id == 'L'){
    if(rotacao == 0){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna] = 'L';
      jogo[linha][coluna+1] = 'L';
      jogo[linha][coluna+2] = 'L';
      jogo[linha][coluna+3] = 'L';
      jogo[linha-1][coluna] = 'L';
    } else if(rotacao == 90){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna] = 'L';
      jogo[linha][coluna+1] = 'L';
      jogo[linha-1][coluna+1] = 'L';
      jogo[linha-2][coluna+1] = 'L';
      jogo[linha-3][coluna+1] = 'L';
    } else if(rotacao == 180){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna+3] = 'L';
      jogo[linha-1][coluna] = 'L';
      jogo[linha-1][coluna+1] = 'L';
      jogo[linha-1][coluna+2] = 'L';
      jogo[linha-1][coluna+3] = 'L';
    } else if(rotacao == 270){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna] = 'L';
      jogo[linha-1][coluna] = 'L';
      jogo[linha-2][coluna] = 'L';
      jogo[linha-3][coluna] = 'L';
      jogo[linha-3][coluna+1] = 'L';
    }

  } else if(id == 'O'){
    criaEspaco(coluna, linha, id, rotacao);
    jogo[linha][coluna] = 'O';
    jogo[linha][coluna+1] = 'O';
    jogo[linha-1][coluna] = 'O';
    jogo[linha-1][coluna+1] = 'O';


  } else if(id == 'S'){
    if(rotacao == 0 || rotacao == 180){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna+1] = 'S';
      jogo[linha][coluna+2] = 'S';
      jogo[linha-1][coluna] = 'S';
      jogo[linha-1][coluna+1] = 'S';
    } else if(rotacao == 90 || rotacao == 270){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna] = 'S';
      jogo[linha-1][coluna] = 'S';
      jogo[linha-1][coluna+1] = 'S';
      jogo[linha-2][coluna+1] = 'S';
    }

  } else if(id == 'T'){
    if(rotacao == 0){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna] = 'T';
      jogo[linha][coluna+1] = 'T';
      jogo[linha][coluna+2] = 'T';
      jogo[linha-1][coluna+1] = 'T';

    } else if(rotacao == 90){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna+1] = 'T';
      jogo[linha-1][coluna] = 'T';
      jogo[linha-1][coluna+1] = 'T';
      jogo[linha-2][coluna+1] = 'T';

    } else if(rotacao == 180){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha-1][coluna] = 'T';
      jogo[linha-1][coluna+1] = 'T';
      jogo[linha-1][coluna+2] = 'T';
      jogo[linha][coluna+1] = 'T';

    } else if(rotacao == 270){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna] = 'T';
      jogo[linha-1][coluna] = 'T';
      jogo[linha-1][coluna+1] = 'T';
      jogo[linha-2][coluna] = 'T';

    }
  } else if(id == 'Z'){
    if(rotacao == 0 || rotacao == 180){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna] = 'Z';
      jogo[linha][coluna+1] = 'Z';
      jogo[linha-1][coluna+1] = 'Z';
      jogo[linha-1][coluna+2] = 'Z';
    } else if(rotacao == 90 || rotacao == 270){
      criaEspaco(coluna, linha, id, rotacao);
      jogo[linha][coluna+1] = 'Z';
      jogo[linha-1][coluna] = 'Z';
      jogo[linha-1][coluna+1] = 'Z';
      jogo[linha-2][coluna] = 'Z';
    }
  }

}

void Tetris::criaEspaco(int coluna, int linha, char id, int rotacao){
  /*char **newjogo;
  newjogo = new char*[ncolunas];
  for(int i=0; i<ncolunas; i++){
    newjogo[i] = new char[linha+1];
  }
  */
  if(id == 'I'){
    if(rotacao == 0 || rotacao == 180){
      if(getAltura(coluna) < linha){
        delete[] jogo[coluna];

        jogo[coluna] = new char[linha];

        alturas[coluna] = linha;
      }
    } else if(rotacao == 90 || rotacao == 270){
      if(getAltura() < linha){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];
        delete[] jogo[coluna+2];
        delete[] jogo[coluna+3];

        jogo[coluna] = new char[linha];
        jogo[coluna+1] = new char[linha];
        jogo[coluna=2] = new char[linha];
        jogo[coluna+3] = new char[linha];

        alturas[coluna] = linha;
      }
    }
  } else if(id == 'J'){
    if(rotacao == 0){
      if(getAltura(coluna) < linha || getAltura(coluna+1) < linha || getAltura(coluna+2) < linha || getAltura(coluna+3) < linha){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];
        delete[] jogo[coluna+2];
        delete[] jogo[coluna+3];

        jogo[coluna] = new char[linha];
        jogo[coluna+1] = new char[linha];
        jogo[coluna+2] = new char[linha];
        jogo[coluna+3] = new char[linha];

        alturas[coluna] = linha;
        alturas[coluna+1] = linha;
        alturas[coluna+2] = linha;
        alturas[coluna+3] = linha;
      }
    } else if(rotacao ==90){
      if(getAltura(coluna) < linha-3 || getAltura(coluna+1) < linha){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];

        jogo[coluna] = new char[linha-3];
        jogo[coluna+1] = new char[linha];

        alturas[coluna] = linha-3;
        alturas[coluna+1] = linha;
      }

    } else if(rotacao == 180){
      if(getAltura(coluna) < linha-1 || getAltura(coluna+1) < linha-1 || getAltura(coluna+2) < linha-1 || getAltura(coluna+3) < linha){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];
        delete[] jogo[coluna+2];
        delete[] jogo[coluna+3];

        jogo[coluna] = new char[linha];
        jogo[coluna+1] = new char[linha-1];
        jogo[coluna+2] = new char[linha-1];
        jogo[coluna+3] = new char[linha-1];

        alturas[coluna] = linha;
        alturas[coluna+1] = linha-1;
        alturas[coluna+2] = linha-1;
        alturas[coluna+3] = linha-1;
      }

    } else if(rotacao == 270){
      if(getAltura(coluna) < linha || getAltura(coluna+1) < linha-3){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];

        jogo[coluna] = new char[linha];
        jogo[coluna+1] = new char[linha];

        alturas[coluna] = linha;
        alturas[coluna+1] = linha;
      }
    }

  } else if(id == 'L'){
    if(rotacao == 0){
      if(getAltura(coluna) < linha-1 || getAltura(coluna+1) < linha-1 || getAltura(coluna+2) < linha-1 || getAltura(coluna+3) < linha){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];
        delete[] jogo[coluna+2];
        delete[] jogo[coluna+3];

        jogo[coluna] = new char[linha];
        jogo[coluna+1] = new char[linha];
        jogo[coluna+2] = new char[linha];
        jogo[coluna+3] = new char[linha];

        alturas[coluna] = linha;
        alturas[coluna+1] = linha;
        alturas[coluna+2] = linha;
        alturas[coluna+3] = linha;
      }
    } else if(rotacao == 90){
      if(getAltura(coluna) < linha || getAltura(coluna+1) < linha){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];

        jogo[coluna] = new char[linha];
        jogo[coluna+1] = new char[linha];

        alturas[coluna] = linha;
        alturas[coluna+1] = linha;
      }
    } else if(rotacao == 180){
      if(getAltura(coluna) < linha-1 || getAltura(coluna+1) < linha-1 || getAltura(coluna+2) < linha-1 || getAltura(coluna+3) < linha){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];
        delete[] jogo[coluna+2];
        delete[] jogo[coluna+3];

        jogo[coluna] = new char[linha-1];
        jogo[coluna+1] = new char[linha-1];
        jogo[coluna+2] = new char[linha-1];
        jogo[coluna+3] = new char[linha];

        alturas[coluna] = linha-1;
        alturas[coluna+1] = linha-1;
        alturas[coluna+2] = linha-1;
        alturas[coluna+3] = linha-1;
      }
    } else if(rotacao == 270){
      if(getAltura(coluna) < linha || getAltura(coluna+1) < linha-3){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];

        jogo[coluna] = new char[linha];
        jogo[coluna+1] = new char[linha-3];

        alturas[coluna] = linha;
        alturas[coluna+1] = linha-3;
      }
    }

  } else if(id == 'O'){
    if(getAltura(coluna) < linha || getAltura(coluna+1) < linha){
      delete[] jogo[coluna];
      delete[] jogo[coluna+1];

      jogo[coluna] = new char[linha];
      jogo[coluna+1] = new char[linha];
    }

  } else if(id == 'S'){
    if(rotacao == 0 || rotacao == 180){
      if(getAltura(coluna) < linha-1 || getAltura(coluna+1) < linha || getAltura(coluna+2) < linha){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];
        delete[] jogo[coluna+2];

        jogo[coluna] = new char[linha-1];
        jogo[coluna+1] = new char[linha];
        jogo[coluna+2] = new char[linha];

        alturas[coluna] = linha-1;
        alturas[coluna+1] = linha;
        alturas[coluna+2] = linha;
      }
    } else if(rotacao == 90 || rotacao == 270){
      if(getAltura(coluna) < linha || getAltura(coluna+1) < linha-1){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];

        jogo[coluna] = new char[linha];
        jogo[coluna+1] = new char[linha-1];

        alturas[coluna] = linha;
        alturas[coluna+1] = linha-1;
      }
    }

  } else if(id == 'T'){
    if(rotacao == 0 ){
      if(getAltura(coluna) < linha || getAltura(coluna+1) < linha || getAltura(coluna+2)){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];
        delete[] jogo[coluna+2];

        jogo[coluna] = new char[alturas[coluna]+2];
        jogo[coluna+1] = new char[alturas[coluna+1]+2];
        jogo[coluna+2] = new char[alturas[coluna+2]+2];

        alturas[coluna] = linha + 1;
        alturas[coluna+1] = linha + 1;
        alturas[coluna+2] = linha + 1;
      }
    } else if(rotacao == 90){
      if(getAltura(coluna) < linha || getAltura(coluna+1) < linha){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];

        jogo[coluna] = new char[alturas[coluna]+2];
        jogo[coluna+1] = new char[alturas[coluna+1]+3];

        alturas[coluna] = linha-1;
        alturas[coluna+1] = linha;

      }
    } else if(rotacao == 180){
      if(getAltura(coluna) < linha || getAltura(coluna+1) < linha || getAltura(coluna+2) < linha){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];
        delete[] jogo[coluna+2];

        jogo[coluna] = new char[alturas[coluna]+1];
        jogo[coluna+1] = new char[alturas[coluna+1]+2];
        jogo[coluna+2] = new char[alturas[coluna+2]+1];

        alturas[coluna] = linha;
        alturas[coluna+1] = linha + 1;
        alturas[coluna+2] = linha;
    } else if(rotacao == 270){
      if(getAltura(coluna) < linha || getAltura(coluna+1)){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];

        jogo[coluna] = new char[alturas[coluna]+3];
        jogo[coluna+1] = new char[alturas[coluna+1]+2];

        alturas[coluna] = linha;
        alturas[coluna+1] = linha-1;

      }
    }
  }
  } else if(id == 'Z'){
    if(rotacao == 0 || rotacao == 180){
      if(getAltura(coluna) < linha || getAltura(coluna+1) < linha || getAltura(coluna+2) < linha-1){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];
        delete[] jogo[coluna+2];

        jogo[coluna] = new char[linha];
        jogo[coluna+1] = new char[linha];
        jogo[coluna+2] = new char[linha-1];

        alturas[coluna] = linha;
        alturas[coluna+1] = linha;
        alturas[coluna+2] = linha-1;
      }
    } else if(rotacao == 90 || rotacao == 270){
      if(getAltura(coluna) < linha-1 || getAltura(coluna+1) < linha){
        delete[] jogo[coluna];
        delete[] jogo[coluna+1];

        jogo[coluna] = new char[linha-1];
        jogo[coluna+1] = new char[linha];

        alturas[coluna] = linha-1;
        alturas[coluna+1] = linha;
      }
    }
  }
}


Tetris &Tetris::operator=(Tetris &newjogo){
  //if(*this == newjogo) return this;

  for(int i=0; i<getAltura(); i++){
    delete[] this->jogo[i];
  }
  delete[] this->jogo;

  this->jogo = new char*[newjogo->ncolunas];
  for(int i=0; i<newjogo->ncolunas; i++){
    this->jogo[i] = new char[newjogo->alturas[i]];
  }

  for(int i=newjogo.getAltura()-1; i>=0; i--){
    for(int j=0; j<newjogo->ncolunas; j++){
    if(newjogo->jogo[i][j] == 'Z' || newjogo->jogo[i][j] == 'I' || newjogo->jogo[i][j] == 'J' || newjogo->jogo[i][j] == 'L' || newjogo->jogo[i][j] == 'O' ||newjogo->jogo[i][j] == 'S' || newjogo->jogo[i][j] == 'T')
      this->jogo[i][j] = newjogo->jogo[i][j];
    }
  }

  delete[] this->alturas;

  this->ncolunas = newjogo->ncolunas;
  this->alturas = new int[ncolunas];
  for(int i=0; i<newjogo->ncolunas; i++){
    this->alturas[i] = newjogo->alturas[i];
  }

  return *this;
}


/*
if(getAltura() < linha){
  for(int i=0; i<ncolunas; i++){
    if(alturas[i] < linha)
      delete[] jogo[i];
  }

  jogo[coluna] = new char[alturas[coluna]+1];
  jogo[coluna+1] = new char[alturas[coluna+1]+2];
  jogo[coluna+2] = new char[alturas[coluna+2]+1];

  alturas[coluna] = linha;
  alturas[coluna+1] = linha + 1;
  alturas[coluna+2] = linha;
}
*/
