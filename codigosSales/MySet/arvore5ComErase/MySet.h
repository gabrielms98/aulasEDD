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
		Node<T> *parent; //agora cada nodo armazena seu pai
};

template  <class T>
class MySet {
public:
	typedef MySetIterator<T> iterator;

	int size() const;
	MySet() : size_(0), root(NULL) {}

	pair<iterator,bool> insert(const T&elem); //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	iterator find(const T&elem); //por simplicidade, nao vamos deixar implementar um find constante...

	iterator end() {return iterator(NULL);}; 
	iterator begin() ;

	MySet(const MySet &other);
	MySet &operator=(const MySet &other);
	~MySet();

	void erase(Node<T> *position);
	void erase(iterator position); //remove o elemento apontado pelo iterador..
	int erase(const T&elem); //remove o elemento do conjunto e retorna a quantidade removida (sera 0 ou 1 para conjuntos)

	void checkTree() const; //funcao para verificar a integridade da arvore! (usada para debugging)

	void imprimeBFS() const;
	void imprimeDFS_pre() const;
	void imprimeDFS_in() const;
	void imprimeDFS_pos() const;
private:
	Node<T> *root;
	int size_;


	void checkTree(const Node<T> *root) const;
	//funcoes auxiliares...
	pair<iterator,bool> insert(const T&elem, Node<T> *&root,Node<T> *parent); 
	iterator find(const T&elem, Node<T> *root);

	void deleteNodes(Node<T> *root);
	Node<T> * copyNodes(const Node<T> *root, Node<T> *parent) const;

	void imprimeDFS_pre(const Node<T> *root) const;
	void imprimeDFS_in(const Node<T> *root) const;
	void imprimeDFS_pos(const Node<T> *root) const;
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

	MySetIterator operator++();
	MySetIterator operator++(int);

	MySetIterator operator--();
	MySetIterator operator--(int);
private:
	Node<T> *ptr;
};


//operador de pre-incremento
template<class T>
MySetIterator<T>  MySetIterator<T>::operator++() {
	if(ptr->right) { //pegue o menor elemento da sub-arvore direita
		ptr = ptr->right;
		while(ptr->left) ptr=ptr->left;
	} else { //mais dificil..temos que subir na arvore ate fazermos a primeira virada a direita
		while(ptr->parent && ptr->parent->right==ptr) ptr = ptr->parent;  //enquanto vou a esquerda para chegar a meu pai, suba...
		ptr = ptr->parent;	//vire a direita (subindo) uma vez

		//para que precisamos do "ptr->parent &&" no while?
		//O que acontece se incrementarmos um iterador para o ultimo elemento da arvore?
	}
	return *this;
}

//operador de pre-decremento
template<class T>
MySetIterator<T>  MySetIterator<T>::operator--() {
	//faca tudo que fez no operador ++, mas no sentido contrario (left --> right e vice-versa)!
	if(ptr->left) { 
		ptr = ptr->left;
		while(ptr->right) ptr=ptr->right;
	} else { 
		while(ptr->parent && ptr->parent->left==ptr) ptr = ptr->parent;  
		ptr = ptr->parent;	

		//para que precisamos do "ptr->parent &&" no while?
		//O que acontece se decrementarmos um iterador para o primeiro elemento?
		//O que acontece se decrementarmos um apontador para end()?		
	}
	return *this;
}



//operador de pos-incremento
template<class T>
MySetIterator<T>  MySetIterator<T>::operator++(int) {
	MySetIterator<T> old(*this);
	++(*this);
	return old;
}

//operador de pos-decremento
template<class T>
MySetIterator<T>  MySetIterator<T>::operator--(int) {
	MySetIterator<T> old(*this);
	--(*this);
	return old;
}

#include <cassert>

template  <class T>
void MySet<T>::checkTree(const Node<T> *node) const { //funcao para verificar a integridade da arvore! (usada para debugging)
	if(!root) return;
	if(node == this->root) {
		assert(root->parent==NULL);
	}
	if(node->left) {
		if(node->left->elem >= node->elem) cerr << node->left->elem << " " << node->elem << endl;
		assert(node->left->elem < node->elem);
		assert(node->left->parent == node);
		checkTree(node->left);
	}
	if(node->right) {
		assert(node->right->elem > node->elem);
		assert(node->right->parent == node);
		checkTree(node->right);
	}
}

template  <class T>
void MySet<T>::checkTree() const {
	checkTree(this->root);
}

template  <class T>
void MySet<T>::erase(Node<T> *ptr) {
	//lembrar de atualizar parent...
	//se for a raiz...
	if(ptr->left && ptr->right) { //tem dois filhos...
		Node<T> * menorFilhoDireito = ptr->right;
		while(menorFilhoDireito->left) menorFilhoDireito = menorFilhoDireito->left;
		ptr->elem = menorFilhoDireito->elem; //copia o elemento (pode ser mais eficiente evitar essa copia!)
		erase(menorFilhoDireito);
	} else if(!ptr->left && !ptr->right) { //sem filhos..
		if(ptr->parent) {
			if(ptr->parent->left == ptr) ptr->parent->left = NULL;
			else ptr->parent->right = NULL;
		} else { //e' a raiz!
			root = NULL;
		}
		delete ptr;
		size_--;	
	} else { //tem exatamente um filho
		Node<T> *filho = (ptr->left)?ptr->left:ptr->right; 
		Node<T> *pai = ptr->parent;
		if(!pai) { //se nao tem pai --> eh a raiz!
			root = filho;
		} else {
			if(pai->left==ptr) { //estamos removendo o filho da esquerda?
				pai->left = filho;
			} else { //removendo o filho da direita?
				pai->right = filho;
			}
		}
		filho->parent = pai; //atualiza ponteiro parent...
		delete ptr;
		size_--;	
	}
}

template  <class T>
void MySet<T>::erase(iterator position) {
	//lembrar de atualizar parent...
	erase(position.ptr);
}

template  <class T>
int MySet<T>::erase(const T&elem) {
	//lembrar de atualizar parent...
	iterator it = find(elem);
	if(it==end()) return 0;	
	erase(it); //o elemento existe no conjunto...
	return 1;
}

template  <class T>
typename MySet<T>::iterator MySet<T>::begin() {
	if(!root) return end();
	Node<T> *ptr = root;
	while(ptr->left) ptr = ptr->left;
	return iterator(ptr);
}


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
Node<T> * MySet<T>::copyNodes(const Node<T> *root, Node<T> *parent) const {
	if(root==NULL) { //caso base
		return NULL;
	}
	Node<T> *  ans = new Node<T>(root->elem);
	ans->parent = parent;
	ans->left = copyNodes(root->left,ans);
	ans->right = copyNodes(root->right,ans);
	

	return ans;
}

template  <class T>
MySet<T> & MySet<T>::operator=(const MySet &other,NULL) {
	if(this==&other) return *this; //testa auto-atribuicao...
	deleteNodes(root);
	root = copyNodes(other.root, NULL); //o pai da nova raiz sera NULL..
	size_ = other.size_;
	return *this;
}



template  <class T>
int MySet<T>::size() const {
	return size_; //exercicio: como calcular o tamanho de forma dinamica? (i.e., sem armazenar o inteiro "size" na classe)
}


//funcao auxiliar...
//exercicio: por que a raiz precisa ser passada por referencia?
template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::insert(const T&elem, Node<T> * &root, Node<T> *parent) { //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	if(!root) {
		root = new Node<T>(elem);
		root->parent = parent;
		size_++;
		return make_pair(iterator(root),true);
	} else {
		if(root->elem > elem) return insert(elem, root->left, root);
		else if (root->elem < elem) return insert(elem, root->right, root);
		else return make_pair(iterator(root),false);//igual..
	}
}

template  <class T>
pair<typename MySet<T>::iterator,bool> MySet<T>::insert(const T&elem) { //retorna um iterador para o elemento inserido (o valor booleano sera' true se o elemento nao existia no conjunto e falso caso ele ja exista (ou seja, o novo elemento nao foi inserido) ).
	return insert(elem,root, NULL);
}



//Aula: implemente a funcao find
//Quais funcoes IMPORTANTES estao faltando na nossa implementacao?









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




#include "MyQueue.h"


template  <class T>
void MySet<T>::imprimeBFS() const { //um nivel por vez..
	MyQueue<Node<T> *> q;
	MyQueue<Node<T> *> u;
	if(!root) return;
	u.push(root);

	int nivel = 0;
	while(!u.empty()) {
		q = u;
		u = MyQueue<Node<T> *>();

		cout <<  "Nivel " << nivel++ << " : ";
		while(!q.empty()) {
			Node<T> * p = q.front();
			q.pop();
			cout << p->elem << " ";
			if(p->left) u.push(p->left);  
			if(p->right) u.push(p->right);
		}
		cout << endl;
	}
	
}

/*
template  <class T>
void MySet<T>::imprimeBFS() const {
	MyQueue<Node<T> *> q;
	if(!root) return;
	q.push(root);

	while(!q.empty()) {
		Node<T> * p = q.front();
		q.pop();
		cout << p->elem << " ";
		if(p->left) q.push(p->left);  
		if(p->right) q.push(p->right);
	}
}
*/

template  <class T>
void MySet<T>::imprimeDFS_pre(const Node<T> *p) const {
	if(!p) return;
	cout << p->elem << " ";
	imprimeDFS_pre(p->left);
	imprimeDFS_pre(p->right);
} 

template  <class T>
void MySet<T>::imprimeDFS_in(const Node<T> *p) const {
	if(!p) return;	
	imprimeDFS_in(p->left);
	cout << p->elem << " ";
	imprimeDFS_in(p->right);
} 


template  <class T>
void MySet<T>::imprimeDFS_pos(const Node<T> *p) const {
	if(!p) return;
	imprimeDFS_pos(p->left);
	imprimeDFS_pos(p->right);
	cout << p->elem << " ";
} 


template  <class T>
void MySet<T>::imprimeDFS_pre() const {
	imprimeDFS_pre(root);
}

template  <class T>
void MySet<T>::imprimeDFS_in() const {
	imprimeDFS_in(root);
}

template  <class T>
void MySet<T>::imprimeDFS_pos() const {
	imprimeDFS_pos(root);
}





#endif