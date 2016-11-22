#include <iostream>
using namespace std;


void imprimeVector (const double v[], int util){
	cout << "Vector = ";
	for (int i=0; i<util; i++)
		cout << v[i];
	cout << endl;
}

void OrdSeleccion (double v[], int util_v){
	int pos_min; //Va a almacenar el índice de la posición donde se ha encontrado el emento mas pequeño en el subsector desordenado.
	double aux;

	for (int i=0; i<util_v-1; i++){  //Recorre los componenetes del vector
		pos_min=i;
		for (int j=i+1; j<util_v; j++){ //Busca en la parte desordenada la posición del elemento mas pequeño
			if (v[j] < v[pos_min]){
				pos_min=j;
			}
		}

		aux=v[i];  // Intercambia el valor de la posición del elemento mas pequeño encontrado en paso anterior y sustituirlo con el primer elemento del subventor desordenado
		v[i]=v[pos_min];
		v[pos_min]=aux;
	}
}
int esModa (const double v[], int util){
	int moda_actual=0, moda_general=0;
	int devuelve;
	for (int i=0; i<util; i++){
		for (int j=i; j<util; j++){
			if (v[i]==v[j])
				moda_actual++;
		}		
		if (moda_actual>moda_general){
			moda_general=moda_actual;
			devuelve=v[i];
		}	 	
		moda_actual=0;
	}
	return devuelve;
}


int main (){
	const int MAX=200;
	double vector[MAX]={2,5,6,7,4,5,2,2,1,3},moda[MAX];
	int util_v=10;

	OrdSeleccion(vector,util_v);
	imprimeVector(vector,util_v);
	cout << "Es moda: " << esModa(vector,util_v) << endl;
}
