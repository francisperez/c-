/* Programa que te dice el resultado factorial de un número introducido por el usuario*/
#include <iostream>
using namespace std;
int main () {

	int num=0,i;
	long double factor=1;//para que factor ocupe mas espacio en memoria
	cout << "Introduce el número del que quieras saber su valor factorial " << endl;
	cin >> num;

	for (i=1; i<=num; i++)
		factor = factor*i;

	cout << "El valor del factor del número introducido es: " << factor << endl;
}
