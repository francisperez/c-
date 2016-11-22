#include <iostream>
#include <cmath>
using namespace std;

double calculaMedia (double vectorme[],int util_v){
	double med=0.0;
	int i=0;
	for (i=0; i<util_v; i++)
		med=med+vectorme[i]; //sumo y acumulo valores
	med=med/util_v;
	return med;
}
double mediaDesviacion (double vectorme[], int util_v){
	double desviacion=0.0;
	for (int i=0; i<util_v; i++)
		desviacion=desviacion + (fabs(vectorme[i]-calculaMedia(vectorme,util_v)));
	desviacion=desviacion/util_v;
	return desviacion;
}


int main (){
	const int MEDIA=20;
	double vectorme[MEDIA];
	double desviacion,med;
	int util_v;
	
	cout <<"Introduce cantidad de números de los que quieres calcular su media desviación" << endl;
	cin >> util_v;
	for (int i=0; i<util_v; i++){
		cout << "Introduce un número :" << endl;
		cin >> med;
		vectorme[i]=med;
	}
	calculaMedia(vectorme,util_v);
	desviacion= mediaDesviacion(vectorme,util_v);
	
	cout << "El valor de la media desviación es " << desviacion << endl;
	

}
