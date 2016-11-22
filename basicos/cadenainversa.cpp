#include <iostream>
using namespace std;

void imprimeVector (const char salida[], int util_salida){
	cout << "Vector = ";
	for (int i=0; i<util_salida; i++)
		cout << salida[i];
	cout << endl;
}

void leeTexto (char v[], int &util_v, const int MAX){
	bool salir=false;
	int i;

	cout << "Introduce la palabra o frase para invertir su contenido y un punto para salir" << endl;
	
	for (i=0; i<MAX && salir==false; i++){
		cin >> v[i];
		if (v[i]=='.')
			salir=true;
	}
	util_v=i-1;
}

void cambiaOrden (char v[], int util_v, char salida[], int &util_salida) { 
	int contador=0;
	util_salida=util_v;
	int j=util_v-1;
	

	for (int i=0; i<util_v; i++){
		salida[j]=v[i];
		j--;
	}


}


int main (){
	const int MAX=500;
	char cadena[MAX], salida [MAX];
	int util_v, util_salida;

leeTexto(cadena,util_v,MAX);
cambiaOrden(cadena, util_v, salida, util_salida);
imprimeVector(salida, util_salida);
}