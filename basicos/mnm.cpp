/* Dado un numero "y" sacar todos sus multiplos y sacarlos por pantalla en un rango [a,b]*/

#include <iostream>
using namespace std;
int main () {

	int x=0,a=0,b=0,mul=0,resto,i;
	cout << "Introduce el número del que quieres saber sus múltiplos "<< endl;
	cin >> x;

	cout << "Introduce los dos valores del rango donde quieres hallar los múltiplos de "<< x << endl;
	cin >> a >> b;
	for (i=a; i<=b; i=i+1) {//iniciamos en el primer rango introducido, condición que se salga del bucle en el segundo 					número introducido y se incrementa de uno en uno para comprobar todos los números del rango
	    resto = x%i;
		if (resto==0) {
			cout << "El número " << x << " es divisible por " << i << endl;
	    		mul = mul+1;
		}
	}
	
	cout << "El número de veces que se tiene múltiplos en el rango es de " << mul << endl;
}	    		
