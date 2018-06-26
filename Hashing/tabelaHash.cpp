#include <iostream>

using namespace std;

//problema de tabela Hashing: acessar elementos em ordem
//e se a chave não for um inteiro?
//para isso temos a funcao hash (h):
//  - mapeia a chave(de qualquer tipo) em um dos "baldes" da tabela
//  - importante: se as chaves a e b sao iguais -> h(a)=h(b)
//  - ideal: "Espalha" as chaves de entrada de forma uniforme na tabela

//colisoes:
// - é quando se tem duas chaves distintas que sao mapeadas para o msm "balde" 
