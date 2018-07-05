#include <iostream>
#include <algorithm>
#include "PPMImage.h"

#include "quadTree.h"

using namespace std;


Node * QuadTree::insert(const Color cor, Node * &root, Node *parent, const int quadrante){
  //essa funcao não faz uso de recursividade, ela insere diretamente no nodo quadrante corresponde ao pai
  if(!parent){ //esse escopo é acessado apenas uma vez, quando a arvore está vazia(logo nao tem "pai") e sera feito a primeira inserçõa; determindando assim a raiz da arvore
    root = new Node(cor); //assim tudo que se precisa fazer alocar root recebendo a cor desejada
    root->parent = parent; //definir o pai de root, que nesse caso será NULL
    size=1; //o tamanho da arvore agora passa a ser 1
    return root; //retorna a nodo recem criado
  } else{ //se a arvore ja tiver elementos... verefica-se primeiramente em qual quadrante o nodo deve ser inserido
    //determinando esse quadrante, basta ir diretamente no pai e inserir no nodo filho referente a tal quadrante, altualizar o pai do nodo recem criado, aumentar o tamanho da arvore e por fim retornar o nodo criado
    if(quadrante == 0){
      parent->zero = new Node(cor);
      parent->zero->parent = parent;
      size++;
      return parent->zero;
    } else if(quadrante == 1){
      parent->um = new Node(cor);
      parent->um->parent = parent;
      size++;
      return parent->um;
    } else if(quadrante == 2){
      parent->dois = new Node(cor);
      parent->dois->parent = parent;
      size++;
      return parent->dois;
    } else if(quadrante == 3){
      parent->tres = new Node(cor);
      parent->tres->parent = parent;
      size++;
      return parent->tres;
    }
  }
}

//chama a funcao auxiliar passando como parametro a raiz da QuadTree, a cor do nodo, o quadrante em que ele está e seu pai
Node * QuadTree::insert(const Color cor, const int quadrante, Node *pai){
  return insert(cor, root, pai, quadrante);
}

void QuadTree::imprime(const Node *ptr) const{
  if(!ptr) return; //verifica se o nodo não é nulo
  if(!ptr->zero && !ptr->um && !ptr->dois && !ptr->tres){ //se o nodo não tiver nenhum filho isso significa que é um quandrante unico entao assim ja podemos imprimi-lo
    cout << ptr->cor.toStr();
  } else { //se tal nodo tiver filhos devemos chamar recursivamente seus 4 filhos e seguir com a recursao ate chegar nas folhas de cada filho
    cout << "(";
    imprime(ptr->zero);
    imprime(ptr->um);
    imprime(ptr->dois);
    imprime(ptr->tres);
    cout << ")";
  }
}

void QuadTree::imprime(int size, int brilho) const {
  //primeiramente inserimos o tamnho size e o brilho max da imagem
  //depois chamamos a funcao auxiliar 4 vezes para cada um dos filhos da raiz
  cout << size << " " << brilho << "\n";
  cout << "(";
  imprime(root->zero);
  imprime(root->um);
  imprime(root->dois);
  imprime(root->tres);
  cout << ")";
  cout << endl;
}
