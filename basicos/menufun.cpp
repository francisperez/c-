#include <iostream>
using namespace std;

int suma(int num1, int num2){
	int resultado;
	resultado=num1+num2;
	return resultado;
}

int resta(int num1, int num2){
	int resultado;
	resultado=num1-num2;
	return resultado;
}

int multiplicacion(int num1, int num2){
	int resultado;
	resultado=num1*num2;
	return resultado;
}

void menu (char &letra){
	cout << " Presiona -s- para sumar dos números" << endl;
	cout << " Presiona -r- para restar dos números" << endl;
	cout << " Presiona -m- para multiplicar dos números" << endl;
	cin >> letra;
}

int main () {
	char opcion;
	int num1,num2;

	cout << "introduce dos numeros enteros" << endl;
	cin >> num1 >> num2;
	menu(opcion);

	if (opcion=='s')
		cout <<	suma(num1,num2) <<endl;
	if (opcion=='r')
		cout <<	resta(num1,num2) <<endl;
	if (opcion=='m')
		cout <<	multiplicacion(num1,num2) <<endl;
}	
