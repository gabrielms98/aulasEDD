#ifndef MY_SET_LIST_H
#define MY_SET_LIST_H

#include <algorithm> //classe pair esta aqui...
using namespace std;

template<class T>
class MySetIterator;

template  <class T>
class Node {
	public: //classe auxiliar.. vamos utiliza-la apenas neste arquivo (nao e' muito necessario ter encapsulamento)
		Node(const T &elem_) : elem(elem_),left(NULL), right(NULL) {}
		Node<T> *left, *right;
		T elem;
};

template  <class T>
class MySet {
	typedef MySetIterator<T> iterator;
public:
	int size() const;
	MySet() : size_(0), root(NULL) {}

	pair<iterator,bool> insert(const T&elem); //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	iterator find(const T&elem); //por simplicidade, nao vamos deixar implementar um find constante...

	iterator end() {return iterator(NULL);}; //por enquanto nao vamos ter um metodo "begin()"

	~MySet();


private:
	Node<T> *root;
	int size_;


	//funcoes auxiliares...
	pair<iterator,bool> insert(const T&elem, Node<T> *&root); 
	iterator find(const T&elem, Node<T> *root);

	void destroy(Node<T> *root);

	Node<T> *createCopy(Node<T> *root) const;
};


Node<T> *createCopy(Node<T> *root) const {
	if(root==NULL) {
		return root;
	}
	Node<T> *newRoot = new Node<T>(root->elem);
	newRoot->left = createCopy(root->left);
	newRoot->right = createCopy(root->right);
	return newRoot;
}

template<class T>
void MySet<T>::destroy(Node<T> *root) {
	if(root==NULL) return;

	destroy(root->left);
	destroy(root->right);
	delete root;
}


template<class T>
MySet<T>::~MySet() {
	destroy(root);
	root = NULL;
	size = 0;
}






//por enquanto vamos desconsiderar os operadores ++ e -- em conjuntos...
//tais operadores serao "escondidos"
template<class T>
class MySetIterator {
	friend class MySet<T>;
public:
	MySetIterator(Node<T> *ptr_): ptr(ptr_) { }
	T &operator*() {return ptr->elem;}

	bool operator==(const MySetIterator &other) const {return ptr==other.ptr;}
	bool operator!=(const MySetIterator &other) const {return ptr!=other.ptr;}

private:
	Node<T> *ptr;
};







template  <class T>
int MySet<T>::size() const {
	return size_; //exercicio: como calcular o tamanho de forma dinamica? (i.e., sem armazenar o inteiro "size" na classe)
}


//funcao auxiliar...
//exercicio: por que a raiz precisa ser passada por referencia?
template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::insert(const T&elem, Node<T> * &root) { //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	if(!root) {
		root = new Node<T>(elem);
		size_++;
		return make_pair(iterator(root),true);
	} else {
		if(root->elem > elem) return insert(elem, root->left);
		else if (root->elem < elem) return insert(elem, root->right);
		else return make_pair(iterator(root),false);//igual..
	}
}

template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::insert(const T&elem) { //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	return insert(elem,root);
}





//Exercicio para a aula: implemente a funcao find
//Quais funcoes IMPORTANTES estao faltando na nossa implementacao?
//Implemente tais funcoes


template  <class T>
MySet<T>::iterator MySet<T>::find(const T&elem, Node<T> *t) {
	if(t==NULL) return end(); // return iterator(NULL);
	if(elem == t->elem) {
		return iterator(t);
	} else if(elem<t->elem) {
		return find(elem,t->left);
	} else {
		return find(elem,t->right);
	}
}

template  <class T>
MySet<T>::iterator MySet<T>::find(const T&elem) {
	return find(elem,root);
}









//funcao auxiliar...
template  <class T>
typename MySet<T>::iterator MySet<T>::find(const T&elem, Node<T> *root) { //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	if(!root) {		
		return iterator(NULL);
	} else {
		if(root->elem > elem) return find(elem, root->left);
		else if (root->elem < elem) return find(elem, root->right);
		else return iterator(root);//igual..
	}
}


template  <class T>
typename MySet<T>::iterator MySet<T>::find(const T&elem) {
	return find(elem,root);
}

#endif