#include <iostream>
 using namespace std;

double buscaBinaria(const double v[], int util_v, double buscar){
	int izq=0;
	int dch=util_v-1;
	int centro=(izq+dch)/2;

	while ((izq<=dch) && (v[centro] !=buscar)) {
		if (buscar < v[centro])
			dch=centro-1;  //Descarto la parte derecha porque ahí no está
		else
			izq=centro+1;  //Descarto la parte izquierda porque ahí no está
			centro=(izq+dch)/2;
	}
	if (dch>izq)
		return -1; //No encontrado
	else
		return centro; //Lo hemos encontrado
}

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

 int main () {
 	const int NUMEROS=20;
	double vector[NUMEROS]={5,25,13,18,14,4};
	int util_v=6;
	double buscar;

	OrdBurbuja(vector,util_v);

	cout << "Indica el número que quieres buscar en el vector" << endl;
	cin >> buscar;

	cout << " El número se encuentra en " << buscaBinaria(vector,util_v,buscar) << endl;
 }