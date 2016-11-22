#include <iostream>
using namespace std;

void OrdBurbuja (double v[], int util_v){
	bool cambio=true;
	for (int izda=0; izda<util_v && cambio==true; izda++) { //Recorremos el vector
		cambio=false;  //Si no se cambia nada el vector esta ordenado

		for (int i=util_v-1; i>izda; i--)
			if (v[i]<v[i-1]) {
				cambio=true; // Si en alguna pasada no se entra en el if cambio sera=false y se terminará el bucle externo

				double aux=v[i]; //Intercambiamos
				v[i]=v[i-1];
				v[i-1]=aux;
			}
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

	OrdBurbuja(vector,util_v);
	imprimeVector(vector,util_v);
}