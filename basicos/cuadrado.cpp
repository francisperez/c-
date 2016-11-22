/* Programa que te dice si el número introducido es un cuadrado perfeto*/
#include <iostream>
using namespace std;
int main () {
	int n,i,mul=0;
	bool cuadrado=true;
	
	
	cout << "Introduce un número entero positivo: " << endl;
	cin >> n;

	for (i=1; cuadrado; i++){ //iniciamos el bucle en uno que se incremente en uno y que entre si es un cuadrado perfecto
		
			mul=i*i; // multiplicamos cada número del rango por si mismo
		
			if (mul>=n) //si el resultado es igual o mayor al nḿero introducido es un cuadrado perfecto
				cuadrado=false;
				
	}
	if (mul==n)
		cout << "El número introducido es un cuadrado perfecto" << endl;
	else 
		cout << "El número introducido no es un cuadrado perfecto" << endl;
			
}
