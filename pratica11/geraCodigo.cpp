#include <iostream>
#include <cstdlib>
#include <string>
#include "MyMap.h"

using namespace std;

int main(){
  string st;
  MyMap<string, int> m;
  MyMap<int, string> m1;
  int i=0;
  while(cin >> st){
    bool achou = false;
    for(int j=0; j<m.size(); j++){
      if(m1[j] == st) achou = true;
    }
    if(!achou) {
      m.insert(make_pair(st, i));
      m1.insert(make_pair(i, st));
      i++;
    }
    cout << st << " " << m[st] << endl;
  }
}
