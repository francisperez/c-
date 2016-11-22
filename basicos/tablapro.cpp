/*Programa que obtenga diez tablas de multiplicar (1 al 10) con diez entradas cada una (1 al 10)*/
#include <iostream>
using namespace std;
int main () {

	int i,num;
	cout << "programa que imprime diez tablas" << endl;
	
	for (i=1; i<=10; i++){	
		
		for (num=0; num<=10; num++)
			
			cout << i << " x " << num << " = " << i*num << endl;
			
		
	}
}
