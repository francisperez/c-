#include <iostream>
using namespace std;

void escogePares (const int v[], int util, int v2[], int &util2) {
	util2=0;
	for (int i=0; i<util; i++){
		if (v[i]%2==0){
			v2[util2]=v[i];
			util2++;
		}
	}
}


void imprimeVector (const int v[], int util) {
	for (int i=0; i<util; i++)
		cout << v[i] << endl;
}


int main () {
	const int MAX=100;
	int pares[MAX]={8,1,3,2,4,3,8}, pares_final[MAX];
	int ocupa_inicio=7, ocupa_final;

	escogePares(pares,ocupa_inicio, pares_final, ocupa_final);

	imprimeVector(pares_final, ocupa_final);
}