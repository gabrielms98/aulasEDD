#include <iostream>
#include "MySetList.h"

using namespace std;

void procura(MySet<int> &s, int elem) {
	cout << "Procurando " << elem << " : " << (s.find(elem)!=s.end()) << endl;
}

void insere(MySet<int> &s, int elem) {
	cout << "Inserindo " << elem << " : " << (s.insert(elem).second) << endl;
}


int main() {
	MySet<int> s;
	insere(s,1);
	insere(s,2);
	insere(s,10);
	insere(s,10); //repetidos..
	insere(s,10); //repetidos..
	insere(s,1);

	procura(s,1);
	procura(s,2);
	procura(s,10);
	procura(s,20);
	procura(s,-1);

	cout << "Removendo 2..." << endl;
	s.erase(2);

	procura(s,1);
	procura(s,2);
	procura(s,10);
	procura(s,20);
	procura(s,-1);
}