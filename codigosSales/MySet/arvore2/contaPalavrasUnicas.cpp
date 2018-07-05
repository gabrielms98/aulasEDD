#include <iostream>
#include "MySet.h"
using namespace std;



int main() {
	MySet<string> s;
	string st;
	while(cin >> st) { //nao tratamos palavras que foram quebradas em multiplas linhas
		s.insert(st); //exercicio: como fazer com que o programa ignore diferencas devido a letras maiusculas/minusculas?
	}
	cout  << "Numero de palavras unicas: " << s.size() << endl;
}