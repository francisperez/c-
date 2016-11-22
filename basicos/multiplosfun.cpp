#include <iostream>
 using namespace std;

double media (double x1, double x2, double x3){

	return (x1+x2+x3)/3.0;
}

int main (){
	double d1,d2,d3;

	cout << "Introduce el primer valor: ";
	cin >> d1;
	cout << "Introduce el segundo valor: ";
	cin >> d2;
	cout << "Introduce el tercer valor: ";
	cin >> d3;

	cout << "media =" << media (d1,d2,d3) << endl;
}
