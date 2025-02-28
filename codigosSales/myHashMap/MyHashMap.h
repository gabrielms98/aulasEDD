#ifndef MY_HASH_MAP_H
#define MY_HASH_MAP_H


//tamanho (numero de linhas) da tabela hash... (numero pequeno para facilitar a visualizacao)
const int TABLE_SIZE = 10;

#include <algorithm> //contem a classe pair...


#include "MyList2NewIterator.h"
#include "MyVecNewIterator.h"

template <class KEY, class VALUE, class HASH>
class MyHashMap {
public:
	MyHashMap();
	void set(const KEY &k,  const VALUE &v);

	//algumas das funcoes abaixo (count, getValue, imprime) deveriam ser const.... mas como nossa classe MyList2 nao possui iteradores constantes (isso foi feito por simplicidade)--> nao podemos fazer isso....
	//
	int count(const KEY &k) ; //quantos elementos com a chave dada a tabela possui? (0 se nenhum, 1 se contem o elemento -- nao armazenamos elementos duplicados)
	int size() const  { return numElems; }; //quantos elementos ha no nosso hashmap?
	VALUE &getValue(const KEY &k) ; //retorna o valor associado a chave k...
	void imprime() ; //usada para visualizar o conteudo da tabela...
private:
	MyVec<MyList2<std::pair<KEY,VALUE> > > table;
	int numElems;
	HASH funcaoHash; //functor representando a funcao hash que vamos usar na classe...
};


#include <iostream>

template <class KEY, class VALUE, class HASH>
void MyHashMap<KEY,VALUE,HASH>::imprime()  {
	std::cout << "Size: " << size() << std::endl;
	for(int i=0;i<TABLE_SIZE;i++) {
		std::cout << "Bucket " << i << " : ";
		for(typename MyList2<std::pair<KEY,VALUE> >::iterator it = table[i].begin();it!=table[i].end();it++) {
			std::cout <<  "(" << (*it).first << "," << (*it).second << ");";
		}
		std::cout << std::endl;
	}
}

template <class KEY, class VALUE, class HASH>
MyHashMap<KEY,VALUE,HASH>::MyHashMap() {
	numElems = 0;
	table.resize(TABLE_SIZE);
}

template <class KEY, class VALUE, class HASH>
void MyHashMap<KEY,VALUE,HASH>::set(const  KEY &k, const VALUE &v) {
	int hash = funcaoHash(k)%TABLE_SIZE; //chame a funcao hash (na verdade functor) para calcular o hash da chave
	for(typename MyList2<std::pair<KEY,VALUE> >::iterator it = table[hash].begin();it!=table[hash].end();it++) { //procure pela chave no balde adequado da tabela...
		if((*it).first == k) { //encontramos a chave?
			(*it).second = v; //atribua o novo valor da chave...
			return;
		}
	}
	//se nao retornamos --> a chave nao se encontra na tabela... --> adicione-a ao final da lista
	std::pair<KEY,VALUE> elemento(k,v); //elemento (par chave-valor) a ser inserido na tabela..
	table[hash].push_back(elemento);
	numElems++; //efetivamente adicionamos um novo elemento...
}


template <class KEY, class VALUE, class HASH>
int MyHashMap<KEY,VALUE,HASH>::count(const KEY &k) {
	int hash = funcaoHash(k)%TABLE_SIZE; //chame a funcao hash (na verdade functor) para calcular o hash da chave
	for(typename MyList2<std::pair<KEY,VALUE> >::iterator it = table[hash].begin();it!=table[hash].end();it++) { //procure pela chave no balde adequado da tabela...
		if((*it).first == k) { //encontramos a chave?
			return 1;
		}
	}
	//se nao retornamos --> a chave nao se encontra na tabela
	return 0;
}

template <class KEY, class VALUE, class HASH>
VALUE &MyHashMap<KEY,VALUE,HASH>::getValue(const KEY &k)  {
	int hash = funcaoHash(k)%TABLE_SIZE; //chame a funcao hash (na verdade functor) para calcular o hash da chave
	for(typename MyList2<std::pair<KEY,VALUE> >::iterator it = table[hash].begin();it!=table[hash].end();it++) { //procure pela chave no balde adequado da tabela...
		if((*it).first == k) { //encontramos a chave?
			return (*it).second; //retorna o valor...
		}
	}
	//se nao retornamos --> a chave nao se encontra na tabela
	//isso e' um erro de execucao.
	//o usuario da classe deveria testar antes se a chave se encontra na tabela
	//uma solucao melhor consiste em retornar um iterador (nesse caso, se a chave nao se encontrar retornariamos um iterador para end())
	//mas isso foge do escopo desta aula... (onde estamos focando em uma implementacao simples)
}

#endif