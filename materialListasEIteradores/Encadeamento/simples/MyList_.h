#ifndef MyList_H__
#define MyList_H__

#include <iostream>
#include <string>
#include <ostream>


//Excessao usada pela classe MyList
class MyListException {
private:
	std::string msg;
public:
	MyListException (const std::string &msg0): msg(msg0) { }
	const std::string & what() const { return msg; }
};



template<class T>
class Node;

template<class T>
class Node { //a classe Node sera "escondida" quando trabalharmos com iteradores
	public: //classe basicamente utilizada apenas aqui...
					//usada apenas para armazenar dados --> ok deixar tudo public

		Node(const T&elem): data(elem), next(NULL) {}
		T data;
		Node<T> *next;
};

template<class T>
class MyList {
public:
	//decidimos utilizar o typedef com o objetivo de "abstrair" o conceito de iterador (a utilidade disso sera vista posteriormente)
	typedef Node<T> * iterator; //define um iterador, um tipo utilizado para percorrer uma estrutura de dados e "apontar" para os items armazenados nela


	template<class T2>
	friend std::ostream& operator<<(std::ostream &, const MyList<T2> &);

	//construtores/destrutures/etc
	MyList();
	MyList(int n, const T&init=T());

	//destrutor
	~MyList() { destroy(); };

	//Construtor de copia
	MyList(const MyList &);
	MyList & operator=(const MyList &);

	//funcoes de acesso
	void push_back(const T&);
	void push_front(const T&);
	void insert(const T&,iterator nodeBefore); //insere o primeiro argumento APOS o nodo apontado pelo segundo elemento
																					//isso sera melhorado no futuro (quando estudarmos iteradores)
	iterator erase(iterator elem); //remove o elemento apontado por Elem
														//retorna o (apontador) para o elemento apos o removido

	iterator begin() {return dataFirst;} //Exercicio: e se tivermos uma lista constante, como itera-la para, por exemplo, imprimir os elementos?
	iterator end() {return NULL;} //retorna um apontador para um nodo que estaria APOS o final da lista
	iterator  next(iterator curr);
	T& deref(iterator curr); //Retorna o elemento da lista apontado por curr (faz uma "derreferencia")

	//versoes constantes dos 4 metodos acima
	const iterator begin() const {return dataFirst;} //Exercicio: e se tivermos uma lista constante, como itera-la para, por exemplo, imprimir os elementos?
	const iterator end() const {return NULL;} //retorna um apontador para um nodo que estaria APOS o final da lista
	const iterator next(const Node<T> *curr) const;
	const T& deref(const iterator curr) const; //Retorna o elemento da lista apontado por curr

	void clear();

	//Exercicio: implementar as duas funcoes abaixo supondo que nao ha um membro de dados dataSize (o calculo do tamanho da lista seria dinamico)
	bool empty() const {return size() == 0;};
	int size() const {return dataSize;}; // na STL List, a funcao size() calcula o tamanho da lista dinamicamente (exercicio: qual a ordem de complexidade?)

private:
	Node<T> *dataFirst, * dataLast;
	int dataSize; //quantos elementos ha na lista?

	void create();
	void destroy();
	void destroy(iterator it);
};

template<class T>
MyList<T>::MyList(){
	create();
}

template<class T>
MyList<T>::MyList(int n, const T&init){
	dataFirst = dataLast = new Node<T>(init);
	dataSize = 1;
}

template<class T>
MyList<T>::MyList(const MyList &node){
	create();
	*this = node;
}

template<class T>
MyList<T> & MyList<T>::operator=(const MyList &other){
	if(this == &other) return *this;
	clear(); //PARA NÃO TER VAZAMENTO

	if(other.dataFirst == NULL){
		dataFirst = dataLast = NULL;
	} else {
		Node<T> *curr = other.dataFirst;
		while(curr!=NULL){
			push_back(curr->data);
			curr = curr->next;
		}
	}
	return *this;
}

template<class T>
void MyList<T>::push_back(const T& elem){
	if(dataFirst == NULL){
		dataFirst = dataLast = new Node<T>(elem);
	} else {
		dataLast->next = new Node<T>(elem);
		dataLast = dataLast->next;
	}
	dataSize++;
}

template<class T>
void MyList<T>::push_front(const T& elem){
	if(dataFirst == NULL){
		dataFirst = dataLast = new Node<T>(elem);
	} else {
		iterator newNode = new Node<T>(elem);
		newNode->next = dataFirst;
		dataFirst = newNode;
	}
	dataSize++;
}

template<class T>
void MyList<T>::insert(const T&,iterator nodeBefore){

}


#endif
