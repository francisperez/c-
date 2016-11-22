#include <iostream>
using namespace std;

void calculaMaxMin (double &max, double &min) {
	double n=0;
	ff	or (int i=1; i<=5; i++){
		cin >> n;		
		
		if (i==1){
			max=n;
			min=n;
		}
		if (n>max)
			max=n;
		if (n<min) 
			min=n;
	}

}


int main () {
	double max, min;

	cout << "Introduce una secuencia de 5 valores  " << endl;
	calculaMaxMin(max,min);
	cout << " El valor máximo introducido es " << max << " y el valor mínimo " << min << endl;
}
