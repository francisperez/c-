/* programa que calcula raices cuadrasa*/
#include <iostream>
#include <cmath>
using namespace std;
int main () {
	double a,b,c,x1,x2;
	cout << "Introduce el valor de a ";
	cin >> a;
	cout << "Introduce el valor de b ";
	cin >> b;
	cout << "Introduce el valor de c ";
	cin >> c;

	x1=  b + sqrt(pow(b,2) - 4*(a*c))/(2 * a);
	x2=  b - sqrt(pow(b,2) - 4*(a*c))/(2 * a);

	cout << "el resultado de x1 es " << x1 << endl;
	cout << "el resultado de x2 es " << x2 << endl;
}
