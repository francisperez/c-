/* Programa que te calcula la sumatoria de un número*/
#include <iostream>
using namespace std;
int main () {
	int i,n;
	double contador=0;

	cout << "Introduce el valor de n: " << endl;
	cin >> n;

	for (i=1; i<=n; i++)
		contador = contador + (1.0- i)/i;
	cout << "El valor de la sumatoria de n es: " << contador << endl;
}
