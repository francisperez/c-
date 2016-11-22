#include <iostream>
using namespace std;

// Inicio declaración de funciones
int Intercambio1 (int a, int b) {
	int auxiliar;
	auxiliar=a;
	a=b;
	b=auxiliar;
	return b;	
}

int Intercambio2 (int a, int b) {
	int auxiliar;
	auxiliar=a;
	a=b;
	b=auxiliar;
	return a;	
}
// Fin de declaración de funciones

int main () {
	int a=5, b=3;
	cout << "El valor inicial de a es " << a << " y de b " << b << endl;
	cout << "El valor intercambiado de a es " << Intercambio2(a,b) << " y de b " << Intercambio1(a,b) << endl;
}
