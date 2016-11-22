#include <iostream>
using namespace std;

void imprimeVector (const double v[], int util){
	cout << "Vector = [";
	for (int i=0; i<util; i++)
		cout << v[i] << ", ";
	cout << "]" << endl;
}

void mezclaVector (const double vector1[], int util_v1, const double vector2[], int util_v2, double mezcla[]){
	int i=0;

	for (i=0; i<util_v1; i++){
		mezcla[i]=vector1[i];
	}

	for (int j=0; j<util_v2; j++){
		mezcla[i++]=vector2[j];
	}


	

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


int main () {
	const int MAX=200;
	double vector1[MAX]={32,14,-8,27,4,7}, vector2[MAX]={2,78,-9,21,13,11}, mezcla[MAX]={};
	int util_v1=6, util_v2=6, util_mezcla=12;

	cout << "el vector 1 es = [32,14,-8,27,4,7] " << endl;
	cout << "el vector 2 es = [2,78,-9,21,13,11]" << endl;

	mezclaVector(vector1,util_v1,vector2,util_v2,mezcla);
	OrdSeleccion(mezcla,util_mezcla);
	imprimeVector(mezcla,util_mezcla);
}