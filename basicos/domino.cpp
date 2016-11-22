/* Programa que te imprime todas las fichas del dominó sin repetirlas*/
#include <iostream>
using namespace std;
int main () {
	int i,j,ficha=0;


	for (i=0; i<=6; i++){
		cout << endl; //salto de linea

		for (j=0; j<=6; j++)
 		
			if (i>=j){ //si i es mayor o igual que j, que no repita los valores de i y j
				ficha++; //contador de fichas
				
				cout << " |" << i << " : " << j << "|" ;
			}

			
			
	}
	cout << endl;
	cout << "este es el número de fichas " << ficha << endl;



}
