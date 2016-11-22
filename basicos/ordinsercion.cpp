#include <iostream>
using namespace std;

void OrdInsercion (double v[], int util_v){
	int izda, i;
	double valor;  //El candidato que tengo insertar ordenado que es siempre el primero de la parte desordenada

	for (izda=1; izda<util_v; izda++){
		valor=v[izda];

		for (i=izda; i>0 && valor < v[i-1]; i--) //Bucle que compone en el subvector ordenado e intercambiando los elementos necesarios, hasta que encuentra el sitio apropiado para valor
			v[i]=v[i-1];
		v[i]=valor; //Cuando encuentra la posición concreta mete en v[i] el valor
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

	OrdInsercion(vector,util_v);
	imprimeVector(vector,util_v);
}