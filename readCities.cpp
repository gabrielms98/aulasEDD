#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
  ifstream in("cidades.txt");
  ofstream out("lista.txt");

  if(in.is_open()) cout << "aberto" << endl;

  /*while(!in.eof()){
    string cidade;
    getline(in, cidade);
    //in.ignore();
    out << "'" << cidade << "'" << "," << endl;
  }*/
  int linha =0;
  while(!in.eof()){
    string cidade;
    getline(in, cidade);
    char *c;
    int n = cidade.size();
    cout << n << endl;
    c = new char[n];
    for(int i=0; i<n-1; i++){
      if(cidade[i] == '\n') break;
      c[i] = cidade[i];
    }
    out << '"';
    for(int j=0; j<n-1; j++){
      out << c[j];
    }
    out << '", ';
    linha++;
    delete []c;
  }

  cout << "LINHAS: " << linha << endl;
  out.close();
  in.close();

  return 0;
}
