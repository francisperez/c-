#include <iostream>
using namespace std;

void reloj (int &horas, int &minutos, int &segundos){
	int numero=0, resultado=0;
	cin >> numero;
	resultado=numero/60;
	segundos=numero%60;

	if (resultado>=1)
		minutos=resultado;

	if (minutos>=60)
		horas=minutos/60;	

		
	


}
int main (){
	int horas, minutos, segundos;

	cout << "Introduce el número de segundos para saber el número de horas, minutos y segundos" << endl;
	reloj(horas,minutos,segundos);
	cout << "El numero de horas que hay es de " << horas << endl;
	cout << "El numero de minutos que hay es de " << minutos << endl;
	cout << "El numero de segundos que hay es de " << segundos << endl;
}	
