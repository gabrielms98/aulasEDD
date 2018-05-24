//Conjunto + Arvore Binaria de Pesquisa (ABP)


#ifndef MYSETLIST_H
#define MYSETLIST_H

#include <iostream>
#include <algorithm>

template<class T>
class MySetIterator;

template<class T>
class Node{
  //Node;
  Node *left, *right;
};

template<class T>
class MySet{


private:
  Node<T> *root;
  int size;
};

template<class T>
class MySetIterator{
  friend class MySet<T>;

private:
  Node<T> *ptr;
};

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

template<class T>
pair<typename MySet<T>::iterator, bool> MySet<T>::insert(const T&el, Node<T> * &root){
  if(!root){
    root = new Node<T>(elem);
    size++;
    return make_pair(iterator(root), true);
  } else {
    if(root->elem > el) return insert(el, root->left);
    else if(root->elem < el) return insert(el, root->right);
    else return make_pair(iterator(root), false);
  }
}

template<class T>
pair<typename MySet<T>::iterator, bool> MySet<T>::insert(const T&el){
  return insert(el, root);
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
