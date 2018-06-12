#include <iostream>
#include <cstring>
#include <cstdlib>
#include "MyQueue.h"
#include "MyStack.h"

using namespace std;


// Insira aqui o codigo para a etapa 1....

//Voce pode adicionar includes como o abaixo...
//#include "MyStack.h"


void etapa1() {
	MyQueue<int> q;
  MyStack<int> s;
  int num;
  for(int i=0; i<6; i++){
    cin >> num;
    q.push(num);
    s.push(num);
  }

  for(int j=0; j<6; j++){
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;

  for(int k=0; k<6; k++){
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....

void etapa2() {
	MyStack<char> s;
	string st;
	cin >> st;

	for(int i=0; i<st.size(); i++){
	char c = st[i];
		switch(c) {
			case '(':
			case '[':
			case '{':
				s.push(c);
				break;
			case ')':
				if(s.empty() || s.top()!='('){
					cout << "Incosistente" << endl;
					return;
				}
				s.pop();
				break;
			case ']':
				if(s.empty() || s.top()!='['){
					cout << "Incosistente" << endl;
					return;
				}
				s.pop();
				break;
			case '}':
				if(s.empty() || s.top()!='{'){
					cout << "Incosistente" << endl;
					return;
				}
				s.pop();
				break;
		}
	}
	 if(s.empty()) cout << "Consistente" << endl;
	 else cout << "Incosistente" << endl;
}

//---------------------------------------

// Insira aqui o codigo para a etapa 3....


//#include "MedianaLenta.h" //use essa implementacao para fazer os primeiros testes (com o calculo lento da mediana...)
#include "Mediana.h" //descomente esta linha para utilizar sua classe mais eficiente!
void etapa3() {
	//descomente o codigo abaixo ao fazer a etapa 3
	Mediana mediana;

	int n,elem;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> elem;
		mediana.insere(elem);
		cout << mediana.getMediana() << " ";
	}
	cout << endl;
}

//---------------------------------------




int main() {
	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
	}
}
