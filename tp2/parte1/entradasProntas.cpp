#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

int main(){
  long long int *array;
  ofstream out5("5.txt");
  ofstream out10("10.txt");
  ofstream out100("100.txt");
  ofstream out1000("1000.txt");
  ofstream out10000("10000.txt");
  ofstream out1000000("1000000.txt");

  
  array = new long long int[5];
  srand(time(NULL));
  for(int i=0; i<5; i++){
    array[i] = rand() % 4000000000 - 2000000000;
    out5 << array[i] << " ";
  }
  delete[] array;

  array = new long long int[10];
  srand(time(NULL));
  for(int i=0; i<10; i++){
    array[i] = rand() % 4000000000 - 2000000000;
    out10 << array[i] << " ";
  }
  delete[] array;

  array = new long long int[100];
  srand(time(NULL));
  for(int i=0; i<100; i++){
    array[i] = rand() % 4000000000 - 2000000000;
    out100 << array[i] << " ";
  }
  delete[] array;

  array = new long long int[1000];
  srand(time(NULL));
  for(int i=0; i<1000; i++){
    array[i] = rand() % 4000000000 - 2000000000;
    out1000 << array[i] << " ";
  }
  delete[] array;

  array = new long long int[10000];
  srand(time(NULL));
  for(int i=0; i<10000; i++){
    array[i] = rand() % 4000000000 - 2000000000;
    out10000 << array[i] << " ";
  }
  delete[] array;

  array = new long long int[1000000];
  srand(time(NULL));
  for(int i=0; i<100000; i++){
    array[i] = rand() % 4000000000 - 2000000000;
    out1000000 << array[i] << " ";
  }
  delete[] array;

  return 0;
}
