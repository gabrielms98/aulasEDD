void leQuadrante(string st, int index, int size){
  if(index == st.size()-1) return;
  int novoIndex = checkDelim(st, index);

  cout << "P3\n";
  cout << size << " " << size << "\n";

  Color cor[size*size*3];

  char *c = new char[size];
  for(int i=index; i<st.size(); i++){
    if(st[i] == '('){
      int novoIndex = checkDelim(st, i);
      int contador =0;
      if(novoIndex - i < 14){
        int aux;
        for(int j=i,k=0; j<novoIndex; j++,k++){
          cout << st[j];
          if(st[j]!=',' && st[j]!='(' && st[j]!=')') c[k] = st[j];
          aux = k;
        }
        contador++;
        // cor[contador/size]

        cout << endl;
      }
    }
  }

}
