#include <iostream>
 using namespace std;

double buscaVector(const int v[], int util_v, int buscar){
	int i, posicion=-1;
	bool encontrado=false;
	for (i = 0; (i < util_v && !encontrado); i++){
		if (v[i]==buscar){
			posicion=i;
			encontrado=true;
		}	
	}	
		
	return posicion;
}


 int main () {
 	const int NUMEROS=20;
	int vector[NUMEROS]={5,25,13,18,14,4};
	int util_v=6, buscar;

	cout << "Indica el número que quieres buscar en el vector" << endl;
	cin >> buscar;

	cout << " El número se encuentra en " << buscaVector(vector,util_v,buscar) << endl;
 }