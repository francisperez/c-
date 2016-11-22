#include <iostream>
 using namespace std;

bool EsPrimo (int n){
	bool esprimo = false;
	int contador=0;

	for (int i=2; i<n; ++i){
		if (n%i==0)
			contador++;
	}
	if (contador==0)
		esprimo=true;
	return esprimo;
}

int totalPrimosIntervalo (int a, int b){
	int contador=0;
	for (int i=a; i<=b; i++){
		if (EsPrimo(i)==true)
		contador++;
	}
	return contador;
}

int main () {
	int a, b;
	cout << "Introduce el primer valor del rango " << endl;
	cin >> a;
	cout << "Introduce el segundo valor del rango " << endl;
	cin >> b;
	cout << "El número de veces que tiene valores primos dentro del rango indicado es de " << totalPrimosIntervalo(a,b) << endl;
}
