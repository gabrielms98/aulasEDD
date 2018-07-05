#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(int argc, char**argv) {
	int n= atoi(argv[1]);
	cerr << "Gerando " << n << " strings em ordem crescente" << endl;
	for(int i=0;i<n;i++) {
		cout << setfill('0') << setw(8) << i << "\n";
	}
}