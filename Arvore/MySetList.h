//Conjunto + Arvore Binaria de Pesquisa (ABP)

#ifndef MYSETLIST_H
#define MYSETLIST_H

#include <iostream>
#include <algorithm>

template<class T>
class MySetIterator;

template<class T>
class Node{
  Node(const T &el) : elem(el), left(NULL), right(NULL), parent(NULL) {}
  Node<T> *left, *right;
  Node<T> *parent;
  T elem;
};

template<class T>
class MySet{
typedef MySetIterator<T> iterator;

public:
  int size() const; //O(1)
  MySet() : size(0), root(NULL) {}

  ~MySet();

  pair<iterator, bool> insert(const T&elem); //O(h) sendo h = altura,h=O(log n)
  iterator find(const T&elem);

  iterator end() {return iterator(NULL);};

private:
  Node<T> *root;
  int size;

  pair<iterator, bool> insert(const T&elem, Node<T> *&root, Node<T> * &parent);
  iterator find(const T&elem, Node<T> *raiz)

  void destroy(Node<T> *root);

  Node<T> *createCopy(const Node<T> *root, Node<T>*parentOfCopy) const;

  void imprimiPreOrdem(Node<T> *root) const;
  void imprimiInOrdem(Node<T> *root) const;
  void imprimiPosOrdem(Node<T> *root) const;
};

template<class T>
class MySetIterator{
  friend class MySet<T>;

private:
  Node<T> *ptr;
};

//O(n)
template<class T>
void MySet<T>::destroy(Node<T> *root){
  if(root == NULL) return;

  destroy(root->left);
  destroy(root->right);
  delete root;
}

template<class T>
MySet<T>::~MySet(){
  destroy(root);
  root = NULL;
  size=0;
}

template<class T>
typename MySet<T>::iterator find(const T &el, const Node<T> *raiz){
  if(raiz == NULL) return end();
  if(el == raiz->elem) return iterator(raiz);
  else if(el > raiz->elem) return find(elem, raiz->right);
  else return find(elem, raiz->left);
}

template<class T>
typename MySet<T>::iterator MySet<T>::find(const T &el){
  return find(el, root);
}

//funcao find(T) iterativa
/*template<class T>
typename MySet<T>::iterator MySet<T>::find(const T &el){

}*/

template<class T>
pair<typename MySet<T>::iterator, bool> MySet<T>::insert(const T&el, Node<T> * &root, Node<T> * &parent){
  if(!root){
    root = new Node<T>(elem);
    root->parent = parent;
    size++;
    return make_pair(iterator(root), true);
  } else {
    if(root->elem > el) return insert(el, root->left, root);
    else if(root->elem < el) return insert(el, root->right, root);
    else return make_pair(iterator(root), false);
  }
}

template<class T>
pair<typename MySet<T>::iterator, bool> MySet<T>::insert(const T&el){
  return insert(el, root);
}

//O(n)
template<class T>
Node<T> * MySet<T>::createCopy(const Node<T> *root, Node<T>*parentOfCopy) const{
  if(root == NULL) return root;
  Node<T> *newRoot = new Node<T>(root->elem);
  newRoot->left = createCopy(root->left, newRoot);
  newRoot->right = createCopy(root->right, newRoot);

  return newRoot;
}

void MySet<T>::imprimiPreOrdem(Node<T> *root) const{
  if(root == NULL) return;

  cout << root->elem << endl; //visita

  imprimiPreOrdem(root->left);
  imprimiPreOrdem(root->right);

}

void MySet<T>::imprimiInOrdem(Node<T> *root) const{
  if(root == NULL) return;

  imprimiInOrdem(root->left);
  cout << root->elem << endl; //visita
  imprimiInOrdem(root->right);

}

void MySet<T>::imprimiPosOrdem(Node<T> *root) const{
  if(root == NULL) return;

  imprimiPosOrdem(root->left);
  imprimiPosOrdem(root->right);

  cout << root->elem << endl; //visita
}


/*
template<class T>
MySet<T>::iterator MySet<T>::find(const T &el){
  for(MyList2<T>::iterator it=elements.begin(); it!=elements.end(); it++){
    if(*it == el) return iterator(it);
  }
  return end();
}
*/



#endif
