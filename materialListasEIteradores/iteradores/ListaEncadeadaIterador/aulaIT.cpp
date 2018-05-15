#include <iostream>
#include <cstring>
#include "MyList2NewIterator.h"

using namespace std;

int main(){

  MyList2<string> l;

  l.push_back("teste");
  l.push_back("abc");
  l.push_back("def");
  l.push_back("hello");

  MyList2<string>::iterator it;
  for(it=l.begin(); it!=l.end(); it++){
    cout << *it << endl;
  }

  cout << l << endl;
}
