#include <iostream>
#include "Tetris.h"

using namespace std;

int main(){
  Tetris game(16);
  Tetris newjogo(4);
  // cout << game.getAltura() << endl;
  // cout << game.getAltura(1) << endl;
  // cout << game.get(0,0) << endl;
  //

  game.adicionaForma(0,1,'T',180);
  game.adicionaForma(3,1,'I',90);

  game.imprime();
  return 0;
}
