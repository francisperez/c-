#include <iostream>
using namespace std;

int mcd (int a, int b){
	int  resto;
	resto = a % b;

	while (resto!=0) {
		a=b;
		b=resto;
		resto=a%b;
	}
	return b;
}

int mcdMcm (int a, int b){
	int mcm;
	mcm=(a*b)/mcd(a,b); // LLamamos a la función de hallar el mcd para poder hallar el mcm
	return mcm;
}

int main (){
	int a,b;
	cout << "Introduce dos números para hallar su M.C.D y su M.C.M" << endl;
	cin >> a >> b;

	cout << "El MCD es " << mcd(a,b) << " y el MCM es " << mcdMcm(a,b) << endl;
}
