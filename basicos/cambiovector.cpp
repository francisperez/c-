#include <iostream>
using namespace std;

void cambiaValor(const char letras[], int ocupado, char letras_salida[], int &ocupado_salida) {
	letras_salida[0] = letras[0];
	ocupado_salida = 1;
	for (int i=1; i<ocupado; i++){
		if (letras[i] != letras[i-1])
			letras_salida[ocupado_salida] = letras[i];
			ocupado_salida++;
	}
}

void imprime_vector (const char v[], int util) {
	for (int i=0; i<util; i++)
		cout << v[i] << endl;
}


int main () {
	const int MAXIMO=100;
	char letras[MAXIMO]={'b','b','i','e','n','n','n'}, letras_salida[MAXIMO];
	int ocupado=7, ocupado_salida;

	cambiaValor(letras, ocupado, letras_salida, ocupado_salida);
	imprime_vector(letras_salida, ocupado_salida);
}
