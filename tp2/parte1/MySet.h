#ifndef MY_SET_LIST_H
#define MY_SET_LIST_H

#include <algorithm> //classe pair esta aqui...
#include <iostream>
using namespace std;

template<class T>
class MySetIterator;

template  <class T>
class Node {
	public: //classe auxiliar.. vamos utiliza-la apenas neste arquivo (nao e' muito necessario ter encapsulamento)
		Node(const T &elem_) : elem(elem_),left(NULL), right(NULL), itemCount(1), subTreeSize(1) {}
		Node<T> *left, *right;
		long long int itemCount;
		long long int subTreeSize;
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

	void printInOrdem() const;
	int qntMov(const T &elem) const;

	MySet(const MySet &other);
	MySet &operator=(const MySet &other);
	~MySet();
private:
	Node<T> *root;
	int size_;


	//funcoes auxiliares...
	pair<iterator,bool> insert(const T&elem, Node<T> *&root);
	iterator find(const T&elem, Node<T> *root);

	void deleteNodes(Node<T> *root);
	Node<T> * copyNodes(const Node<T> *root) const;

	void printInOrdem(Node<T> *root) const;
};




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
MySet<T>::MySet(const MySet &other) {
	size_=0;
	root= NULL;
	*this = other; //vamos usar o operador de atribuicao..
}


template  <class T>
void MySet<T>::deleteNodes(Node<T> *root) {
	if(!root) return;
	deleteNodes(root->left);
	deleteNodes(root->right);
	delete root;
}

template  <class T>
MySet<T>::~MySet() {
	deleteNodes(root);
}


template  <class T>
Node<T> * MySet<T>::copyNodes(const Node<T> *root) const {
	if(root==NULL) { //caso base
		return NULL;
	}
	Node<T> *  ans = new Node<T>(root->elem);
	ans->left = copyNodes(root->left);
	ans->right = copyNodes(root->right);

	return ans;
}

template  <class T>
MySet<T> & MySet<T>::operator=(const MySet &other) {
	if(this==&other) return *this; //testa auto-atribuicao...
	root = copyNodes(other.root);
	size_ = other.size_;
}



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
		if(root->elem > elem) {
			root->subTreeSize++;
			return insert(elem, root->left);
		}	else if (root->elem < elem) {
			root->subTreeSize++;
			return insert(elem, root->right);
		} else {
			root->subTreeSize++;
			root->itemCount++;
			return make_pair(iterator(root),false);//igual...
		}
	}
}

template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::insert(const T&elem) { //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	return insert(elem,root);
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
	find(elem,root);
}

template<class T>
void MySet<T>::printInOrdem() const {
	printInOrdem(root);
}

template<class T>
void MySet<T>::printInOrdem(Node<T> *root) const{
  if(root == NULL) return;

  printInOrdem(root->left);
	cout << "[elem: " << root->elem << ", count: " <<  root->itemCount << ", subSz: " << root->subTreeSize << "]" << endl; //visita
  printInOrdem(root->right);
}

template<class T>
int MySet<T>::qntMov(const T&elem) const{
	int mov = 0;  //define a quantidade de movimentos com 0. É incrementado a partir das comparaçoes entre o elem e o elemento do ptr atual
	Node<T> *ptr = root; //inicializa o ptr como sendo o root
	while(ptr){ //enquanto tiver Node, percorra a arvore
		if(elem < ptr->elem){ //se o elemento for menor que a do Node atual, entao sabe-se que temos q "mover"
		//todos os elementos que estao a direita (ou seja, maiores que ele) do ptr e tambem mover o ptr
			if(ptr->right) mov += ptr->right->subTreeSize+ptr->itemCount; //se tiverem Nodes a direita os elemento movidos sao todos que estao na sub-arvore a direita + o ptr
			else mov+=ptr->itemCount; //se não houver Node a direita, move-se apenas o ptr
			ptr = ptr->left; //desloca o ptr para a o Node da esquerda pois elem < ptr->elem
			continue;  //pula o resto dos comandos e volta a executar o loop do inicio
		} else if(elem > ptr->elem){ //verifica se o elem é maior que o que esta no elemento de ptr
			ptr = ptr->right; //se o elemento é maior que ptr->elem, ainda não precisa mover nenhum numero. apenas desloca o ptr
			continue;
		} else if(elem == ptr->elem){
			//se o elemento é igual a um ja existente, apenas move todos os elementos que estao na sub-arvore a direita desse elemento
			if(ptr->right) mov+=ptr->right->subTreeSize;
			break;
		}
	}
	//cout << "Número de movimentos para inseir o " << elem << " é: " << mov << endl;
	return mov;
}


#endif
