/*Teorema de pitágoras: hip es la raíz
de la suma de los catetos*/
#include <iostream>
#include <cmath>
using namespace std;
int main () {
	double cateto1, cateto2, hip;

	cout << "Introduce el primer cateto: ";
	cin >> cateto1;
	cout << "Introduce el segundo cateto: ";
	cin >> cateto2;

	hip = sqrt (pow(cateto1, 2)+cateto2*cateto2);

	cout << "La hipotenusa es: "<< hip << endl;
}
