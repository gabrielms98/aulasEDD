#include <iostream>
#include <cstdlib>

using namespace std;

//Arvore B, sao arvores onde cada nodo tem n elementos
//Arvore B de ordem m,
//  -raiz possui pelo menos 2 filhos
//  -cada nodo inteiro contem k-1 chaves e k ponteiros para subarvores
//  -cada folha contem k-1 chaves, onde m/2<=k<=m
//  -todas as folhas estao no mesmo nivel (logo, esta balanceada)
//Numero de filhos é um a mais doq cabe em cada nodo

//INSERÇÃO:  O(logm n)
//  -sempre se insere nas folhas
//  -3 casos:
//    -chave inserida em uma folha COM espaço
//    -chave inserida em uma folha SEM espaço - divida o nodo em 2, mova um dos elementos
//      da metade do vetor que foi dividido para um nodo acima e reorganize os ponteiros
//    -caso especial da situaçao 2, onde a raiz esta cheia - raiz dividida em 2 (arvore cresce)
