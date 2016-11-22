/*Programa que calcula la media y desviación */
#include <iostream>
#include <cmath>
using namespace std;
int main () {
	double x1,x2,x3,m,d;
	cout << "Introduce el valor de x1: ";
	cin >> x1;
	cout << "Introduce el valor de x2: ";
	cin >> x2;
	cout << "Introduce el valor de x3: ";
	cin >> x3;

	m=(x1+x2+x3)/3;
	cin >> " El valor de la media es ">> endl;

	d=sqrt(pow(x1-m,2) + pow(x2-m,2) + pow(x3-m,2))/3;

	cout >> " El valor de la desviación típica es ">> endl;
} 	
