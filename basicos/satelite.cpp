#include <iostream>
using namespace std;
int main () {
	int dato;

	do {
	   cin >> dato;
	   cout << "Recibido: " << dato << endl;
	}  while (dato >=0);
	cout << "Fin transmisión" << endl;
}
