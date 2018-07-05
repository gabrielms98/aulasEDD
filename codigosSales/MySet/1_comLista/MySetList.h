#ifndef MY_SET_LIST_H
#define MY_SET_LIST_H

#include "MyList2NewIterator.h"
#include <algorithm> //classe pair esta aqui...
using namespace std;

template<class T>
class MySetIterator;

template  <class T>
class MySet {
	typedef MySetIterator<T> iterator;
public:
	int size() const;


	pair<iterator,bool> insert(const T&elem); //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	int erase(const T &elem); //retorna o numero de elementos apagados (devera ser 0 ou 1...)
	iterator find(const T&elem); //por simplicidade, nao vamos deixar implementar um find constante...

	iterator end() {return elements.end();}; //por enquanto nao vamos ter um metodo "begin()"
private:
	MyList2<T> elements;
};



//por enquanto vamos desconsiderar os operadores ++ e -- em conjuntos...
//tais operadores serao "escondidos"
template<class T>
class MySetIterator {
	friend class MySet<T>;
public:
	MySetIterator(typename MyList2<T>::iterator iter): it(iter) { }
	T &operator*() {return *it;}

	bool operator==(const MySetIterator &other) const {return it==other.it;}
	bool operator!=(const MySetIterator &other) const {return it!=other.it;}

private:
	typename MyList2<T>::iterator it;
};





template  <class T>
int MySet<T>::size() const {
	return elements.size();
}

template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::insert(const T&elem) { //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	iterator it = find(elem);
	if(it!=end()) return make_pair(it,false); //o elemento ja esta no conjunto... vamos simplesmente retornar um iterador para ele..

	//o elemento ainda nao esta no conjunto...
	elements.push_back(elem);
	typename MyList2<T>::iterator listIt = MyList2Iterator<T>(elements.dataLast); //crie um iterador de lista para o ultimo elemento da lista...
	return make_pair(iterator(listIt),true);
}

template  <class T>
int MySet<T>::erase(const T &elem) { //retorna o numero de elementos apagados (devera ser 0 ou 1...)
	iterator elementIt = find(elem); //procura pelo elemento na lista...
	if(elementIt==end()) return 0; // o elemento nao esta no conjunto...
	elements.erase(elementIt.it); //usa a funcao erase da classe lista...
	return 1;
}

template  <class T>
typename MySet<T>::iterator MySet<T>::find(const T&elem) {
	for(typename MyList2<T>::iterator it=elements.begin();it!=elements.end();it++) {
		if(*it==elem) return iterator(it); 
	}
	return end();
}

#endif