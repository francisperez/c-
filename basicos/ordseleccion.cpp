#include <iostream>
using namespace std;

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


void imprimeVector (const double v[], int util_v){
	cout << "Vector ordenado es = ";
	for (int i=0; i<util_v; i++)
		cout << v[i]<<", ";
	cout << endl;
}

int main (){
	const int MAX=100;
	double vector[MAX]={25,-9,4,18,-2,16,8,4};
	int util_v=8;

	cout << "El Vector inicial es = 25,-9,4,18,-2,16,8,4 " << endl;

	OrdSeleccion(vector,util_v);
	imprimeVector(vector,util_v);
}