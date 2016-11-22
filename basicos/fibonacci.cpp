#include <iostream>
using namespace std;

/*
 * @brief Módulo que imprime la serie de Fibonacci por pantalla, y suma el valor total.
 * @param int n Total de números de la serie que se quieren imprimir y que se quieren sumar.
 * @return int Devuelve la suma total de los "n" primeros términos
 * @pre n >= 0
 * @ver 1.0
 * @author Vanessa
 */
int FibonacciIterativo(int n){
	int suma = 0; //variable que acumulará la suma total
	int fn_ant; //variable que guarda siempre el valor anterio de Fibonacci: f(n-1)
	int fn_ant_ant; //variable que guarda siempre el valor anterior del anterior de Fibonacci: f(n-2)
	int f_act;
	
	//Casos básicos
	if (n >= 0){
		cout << " 1 ";
		suma += 1;
	}
	
	if (n >= 1){
		cout << "1 ";
		suma += 1;
	}	
	
	//Bucle que construye a partir de n >= 2
	fn_ant_ant = 1; //cuando n=0
	fn_ant = 1; //cuando n=1
	for (int i = 2; i <= n; i++){
		f_act = fn_ant + fn_ant_ant;
		//imprimimos el siguiente valor de la serie
		cout << f_act << " ";
		//acumulamos la suma 
		suma+= fn_ant + fn_ant_ant;
		//actualizar los valores para la siguiente iteración	
		fn_ant_ant = fn_ant; 
		fn_ant = f_act;
	}
	
	return suma;
}

/*
 * @brief Módulo que imprime la serie de Fibonacci por pantalla.
 * @param int n Total de números de la serie que se quieren imprimir y que se quieren sumar.
 * @return int Devuelve el término "n" de la serie de Fibonacci
 * @pre n >= 0
 * @ver 1.0
 * @author Luis
 */
int FibonacciRecursivo(int n){
	int valor = 0;
	//Casos base
	if ((n == 0) || (n == 1))
		valor = 1;
	else //n > 1 es el caso general	
		valor = FibonacciRecursivo(n-1) + FibonacciRecursivo(n-2);
	
	//Vamos a imprimir el valor por pantalla
	cout << valor << " ";
	//Devolvemos el valor calculado
	return valor;		
}		

int main(){
	int n = 0;
	int suma = 0;
	
	cout << "Bienvenidos a Fibonacci" << endl;
	do{
		cout << "Introduzca el valor n hasta el que desea imprimir y calcular su suma: ";
		cin >> n;
	}while (n < 0);
	
	suma = FibonacciIterativo(n);
	cout << endl << "La suma total es:  " << suma << endl; 	
	
	cout << "Y ahora la versión recursiva!!!" << endl;
	cout << "Fibonacci(" << n << ") = "<< FibonacciRecursivo(n) << endl; 
}
