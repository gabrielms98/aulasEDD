#include <iostream>
#include "MySet.h"

using namespace std;

void procura(MySet<int> &s, int elem) {
	cout << "Procurando " << elem << " : " << (s.find(elem)!=s.end()) << endl;
}

void insere(MySet<char> &s, char elem) {
	cout << "Inserindo " << elem << " : " << (s.insert(elem).second) << endl;
}


int main() {
	MySet<char> s;
	insere(s,'e');
	insere(s,'i');
	insere(s,'c');
	insere(s,'b'); 
	insere(s,'d'); 
	insere(s,'h'); 
	insere(s,'l'); 
	insere(s,'a'); 
	insere(s,'j'); 
	insere(s,'m'); 


	MySet<char>::iterator it = s.begin();
	for(;it!=s.end();++it){
		cout << *it << endl;
	}
	

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
	s2.imprimeBFS();
	cout << endl;



}