#include <iostream>
#include "MySet.h"

using namespace std;

void procura(MySet<int> &s, int elem) {
	cout << "Procurando " << elem << " : " << (s.find(elem)!=s.end()) << endl;
}

void insere(MySet<int> &s, int elem) {
	cout << "Inserindo " << elem << " : " << (s.insert(elem).second) << endl;
}

template <class T>
void erase(MySet<T> &s, const T& elem) {
	cout << "Removendo: " << elem << " " << s.erase(elem) << endl;
	s.imprimeBFS();
	s.checkTree();
}


int main() {
	MySet<int> s;
	insere(s,1);
	insere(s,2);
	insere(s,10);
	insere(s,10); //repetidos..
	insere(s,10); //repetidos..
	insere(s,1);

	s.imprimeBFS();
	cout << endl;

	//qual sera o formato dessa arvore?
	//desenhe-a!
	MySet<char> s2;
	s2.insert('k');
	s2.insert('d');
	s2.insert('s');
	s2.insert('a');
	s2.insert('m');
	s2.insert('w');
	s2.insert('b');
	s2.insert('z');
	s2.insert('t');
	s2.insert('r');
	s2.insert('c');

	
	{
		MySet<char> s3 = s2;
		s3.imprimeBFS();
		
	}
	for(char c:s2) {
		MySet<char> s3 = s2;
		erase(s3,c);
	}
	{
		MySet<char> s3 = s2;
		erase(s3,'u');
	}
	MySet<char> s3 = s2;
	for(char c:s2) {
		erase(s3,c);
	}

}