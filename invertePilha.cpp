#include <iostream>
#include <cstring>

using namespace std;

//inverter uma pilha usando ate duas pilhas

int main(){
  MyStack<char> s, s1, s2;
  while(!s.empty()){
    s1.push(s.top());
    s.pop();
  }
  while(!s1.empty()){
    s2.push(s1.top());
    s1.pop();
  }

  while(!s2.empty()){
    s.push(s2.top());
    s2.pop();
  }

}
