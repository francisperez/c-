#include <iostream>
using namespace std;

int main(){

	int numero, *puntero, **puntero2;

	numero=5;
	puntero=&numero;
	puntero2=&puntero;


	cout << "este es el numero  " << numero <<endl;
	cout << "este es el puntero=&numero  " << puntero <<endl;
	cout << "este es el **puntero  " << **puntero2 <<endl;


}