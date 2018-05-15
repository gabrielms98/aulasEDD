#include <iostream>

using namespace std;

#ifndef TETRIS_H
#define TETRIS_H

class Tetris{

public:
  Tetris(int);

  char get(int, int) const;
  int getNumColunas() const;
  int getAltura(int) const;
  int getAltura() const;
  char getEstado() const {return estado;}

  void setAltura(int, int);
  void insert(char, int, int);

  void removeColuna(int);
  void removeLinhasCompletas();

  bool adicionaForma(int, int, char, int);
  void imprime();

  void criaEspaco(int, int, char, int);

  Tetris &operator=(Tetris&);

private:
  int ncolunas;
  int *alturas;
  char estado;
  char **jogo;
};

#endif
