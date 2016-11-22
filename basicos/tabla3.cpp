//tabla de cualquier número entero con do y while (bucles)
#include <iostream>
using namespace std;
int main () {
	int i=1,n;
	cout << "Introduce el número entero del que quieres saber su tabla" << endl;
	cin >> n;

	do {
	   cout << n << "x" << i << " = " << n * i << endl;
	   i = i + 1;
	}  while (i<=10);
}
