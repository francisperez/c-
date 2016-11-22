#include <iostream>
using namespace std;

void imprimeVector (const char v[], int util_v){
	cout << "Vector = ";
	for (int i=0; i<util_v; i++)
		cout << v[i];
	cout << endl;
}

void leeTexto (char v[], int &util_v, const int DIM){
	bool salir=false;
	int i;

	cout << "Introduce la palabra o frase que quieras averiguar si es un palíndromo y un punto para salir" << endl;
	
	for (i=0; i<DIM && salir==false; i++){
		cin >> v[i];
		if (v[i]=='.')
			salir=true;
	}
	util_v=i-1;
}

bool Palindromo (const char v[], int util_v){
	bool es_palindromo=false;
	int inicio=0, final=util_v-1, contador=0;

	if (util_v%2==0){ // La palabra es par

	} 

	else {   // La palabra es impar
		
		for (int i=inicio; inicio!=final; i++){ 
			if (v[inicio]==v[final]){
				es_palindromo=true;
			}

			else{
				contador++;
			}
			inicio++;
			final--;

		}
	}
	if (contador==0)
		es_palindromo=true;
	else
		es_palindromo=false;

	return es_palindromo;
}


int main () {
	const int DIM=20000;
	char texto[DIM]={};
	int util_texto;

	leeTexto(texto,util_texto,DIM);
	//imprimeVector(texto,util_texto);

	if (Palindromo(texto,util_texto)==true)
		cout << "Es palindromo" << endl;
	else
		cout << "No es palindromo" << endl;
}