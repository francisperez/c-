// minicalculadora con switch
#include <iostream>

using namespace std;
int main ()  {

double a,b,suma,resta,multiplicacion,division; // los números a introducir
char c;  // las letras de los menús

	cout << "Introduce dos números "<<endl;
	cin >> a >> b;
suma = a + b;
resta = a - b;
multiplicacion = a * b;
division = a / b;

	cout << "Pulsa s para sumarlos"<< endl; 
	cout << "Pulsa r para restarlos"<< endl; 
	cout << "Pulsa m para multiplicarlos"<< endl; 
	cout << "Pulsa d para dividirlos"<< endl; 
	cin >> c;
	switch (c) {
	case 's':
		cout << "Suma " << suma << endl; 
		break;
	case 'r':
		cout << "Resta " << resta << endl; 
		break;
	case 'm':
		cout << "Multiplicación " << multiplicacion << endl; 
		break;
	case 'd':
		cout << "División " << division << endl; 
		break;
	default:
		cout << "Respuesta no permitida"<< endl; 
	}
}	
