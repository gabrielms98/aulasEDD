#include <iostream>
#include "MySet.h"
#include "MyQueue.h"
#include <fstream>

using namespace std;

int main(){
  MySet<int> q;
  char c;
  int size;
  ofstream out("bd.txt");
  ifstream in("bd.txt");

  int *n;
  if(in.eof()) out << 0 << endl;

  while(!in.eof()){
    in >> size;
    cout << size << endl;
    n = new int[size];
    for(int i=1; i<size; i++){
      in >> n[i];
      cout << n[i] << endl;
    }
  }
  int k;

  cout << "Digite c e k: ";
  cin >> c >> k;

  if(c == 'C'){
    q.insert(k);
    bool achou=false;
    int j;
    for(int i=0; i!=out.eof(); i++){
      if(n[i]==k) achou = true;
    }
    if(!achou) out << k << " ";
  } else {
    for(MySet<int>::iterator it=q.begin(); it != q.end(); it++){
      if((*it)==k){
        if((++it) == q.end()) cout << "FALHA" << endl;
        else cout << (*++it) << endl;
        return 0;
      }
      cout << "FALHA" << endl;
    }

  }

}
