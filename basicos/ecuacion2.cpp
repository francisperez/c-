//ejercicio 2.6
#include<iostream>
#include<cmath>

using namespace std;

int main () {

	double a,b,c,x1,x2,d;

	cout << "Introduce el valor de a " << endl;
	cin >> a;
	cout << "Introduce el valor de b " << endl;
	cin >> b;
	cout << "Introduce el valor de c " << endl;
	cin >> c;
	d=(pow(b,2) - 4*(a*c))/(2 * a);
	
	if (d<0) {
		cout << "Si el discriminante es negativo no tiene solución real" << endl;
	}
	else{
		if (a!=0) {
			x1=  b + sqrt(d)/(2 * a);
			x2=  b - sqrt(d)/(2 * a);

			cout << "El valor de x1 es: "<< x1 << endl;
			cout << "El valor de x2 es: "<< x2 << endl;
		
		
	
		}
		else {		
			x1= -c/b;		
			cout << "Si a vale 0 el valor de x es "<< x1 << endl;
		}
	}

}
			
		
		
