#include <iostream>
#include <stdlib.h>
using namespace std;
int main (){
	char ass='h';
	int a;
	for (int i=0; i<3; i++)
		cout << "muajajaja"<< endl;

	cin >> a;
	system ("clear");
	cout << " \033[1;31meste texto es rojo\033[0m\n ";
	cout << "\033[3;32meste texto es verde cursiva\033[0m " " y lo demas del color de la consola \n " ;
	cout << "\033[1;33meste texto es amarillo\033[0m\n ";
	cout << "\033[1;34meste texto es azul\033[0m\n ";
	cout << "\033[1;35meste texto es morado\033[0m\n ";
	cout << "\033[1;36meste texto es turqusa\033[0m\n ";
	cout << "\033[1;37meste texto es blanco\033[0m\n ";
	cout << "\033[1;38meste texto es no se sabe\033[0m\n ";
	cout << "\033[1;39meste texto es no se sabe\033[0m\n ";
	cout << "\033[1;30meste texto es negro\033[0m\n ";
	cout << " \033[1;31m lo que sea \033[0m\n ";
	cout << "\033[1;31m" << ass << "\033[0m" << std::endl;

	  

	system("pwd");


}
