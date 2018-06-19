#include <iostream>
#include <cstdlib>
#include <string>
#include "MySet.h"
#include "MyVecNewIterator.h"

using namespace std;

int main(int argc, char **argv){
  int total =0;
  int unicas=0;

  if(string(argv[1]) == string("myvec")){
    MyVec<string> palavra;
    string st;
    while(cin >> st){
      bool tem = false;
      for(int i=0; i<palavra.size(); i++){
        if(palavra[i] == st) {
          tem = true;
          break;
        }
      }
      if(!tem) unicas++;
      palavra.push_back(st);
      total++;
    }
  } else if(string(argv[1]) == string("myset")){
    MySet<string> p;
    string st;
    while(cin >> st){
      MySet<string>::iterator it = p.find(st);
      if(it == NULL){
        p.insert(st);
        unicas++;
      }
      total++;
    }
  }

  cout << total << " " << unicas << endl;

  return 0;
}
