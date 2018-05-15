#ifndef MyVec_H__
#define MyVec_H__

#include <iostream>
#include <string>
#include <ostream>
#include <cassert>


//Excessao usada pela classe MyVec
class MyVecException {
private:
	std::string msg;
public:
	MyVecException (const std::string &msg0): msg(msg0) { }
	const std::string & what() const { return msg; }
};


template<class T>
class MyVec {
public:
	template<class T2>
	friend std::ostream& operator<<(std::ostream &, const MyVec<T2> &);

	//construtores/destrutures/etc
	MyVec();
	MyVec(int n, const T& init=T());

	//destrutor
	~MyVec() { destroy(); };

	//Construtor de copia
	MyVec(const MyVec &);
	MyVec & operator=(const MyVec &);

	//funcoes de acesso
	T &operator[](int pos) {return data[pos];}
	const T &operator[](int pos) const {return data[pos];}
	void push_back(const T&);
	void pop_back() { assert(dataSize!=0); dataSize--; }

	//modifica o numero de elementos no vetor
	//se newSize > dataSize --> novos elementos terao valor padrao
	//se newSize <= dataSize --> capacidade do vetor nao sera alterada
	void resize(int newSize);
	void insert(const T&,int pos);
	void clear();

	bool empty() const {return size() == 0;};
	int size() const {return dataSize;};

private:
	T *data;
	int dataSize; //quantos elementos ha na lista?
	int dataCapacity; //quantos elementos atualmente cabem na lista?

	void create();
	void destroy();
	void resizeCapacity(int newCapacity); //modifica a capacidade do vetor (nao faz nada se nova capacidade for menor!)
};

template<class T>
void MyVec<T>::create(){
	dataSize = 0;
	dataCapacity = 1;
	data = new T[1];
}

template<class T>
void MyVec<T>::destroy(){
	dataSize = 0;
	dataCapacity = 0;
	delete[] data;
}

template<class T>
void MyVec<T>::resizeCapacity(int newCapacity){
	if(newCapacity <=dataCapacity) return;
	T *aux = new T[newCapacity];
	for(int i=0; i<dataSize; i++){
		aux[i] = data[i];
	}
	delete[] data;
	data = new T[newCapacity];
	for(int i=0; i<dataSize; i++){
		data[i] = aux[i];
	}
	dataCapacity = newCapacity;
}

template<class T>
MyVec<T>::MyVec(){
	create(); //contrutor padrao chama a funcao create
}

template<class T>
MyVec<T>::MyVec(const MyVec &vetor){
	delete[] data;
	data = new T[vetor.dataCapacity]; //recria o array data com o tamanho passado do vetor recebido como parametro
	for(int i=0; i<vetor.dataSize; i++){
		data[i] = vetor.data[i]; //copia os valores de vetor para o array datas
	}
	dataSize = vetor.dataSize;
	dataCapacity = vetor.dataCapacity;
}

template<class T>
void MyVec<T>::push_back(const T& elem){
	if(dataSize == dataCapacity){ //verifica se tem espaco pra colocar o elemento
		if(dataCapacity = 0) resizeCapacity(1);
		else resizeCapacity(2*dataCapacity);
	}
	data[dataSize] = elem; //coloca o elemento na posicao no final do array
	dataSize++; //incremente dataSize
}

template<class T>
void MyVec<T>::resize(int n){
	T *aux = new T[dataSize]; //cria array auxxiliar
	for(int i=0; i<dataSize; i++){
		aux[i] = data[i]; //copia os valores de data para o array aux
	}
	delete[] data; //delete data e cria novamente com o tamanho desejado
	data = new T[n];
	for(int i=0; i<dataSize; i++){
		data[i] = aux[i]; //copia de volta os valores para o novo array data
	}
	dataCapacity = n;
}

template<class T>
void MyVec<T>::insert(const T& elem,int pos){
	if(dataSize == dataCapacity){ //verifica se tem espaço pra inserir um novo elemento
		if(dataCapacity == 0) resizeCapacity(1); //aumenta o array para 1 se ele for vazio
		else resizeCapacity(2*dataCapacity); //dobra o tamanho do array para colocar mais numeros
	}
	for(int i=dataSize; i>pos; i--){ //loop para pegar todos os elementos dps da posicao desejada e mover para frente
		data[i] = data[i-1];
	}
	data[pos] = elem; //coloca o elemnteo na posicao desejada
}

template<class T>
void MyVec<T>::clear(){
	for(int i=0; i < dataSize; i++){
		data[i] = T();  //utiliza o contrutor de template T para "inicializar" a variavel com valor padrao do seu tipo
	}
	dataSize = 0;
}






#endif
