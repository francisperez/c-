/*programa para crear un diccionario de inglés a español y viceversa, que permite
introducir palabras nuevas, buscar palabras, traducir e imprimir con uso de estructuras*/

#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

const int MAX_NUM_PALABRAS=1000; // se declara variable global pero solo por ahora

//diccionario español-ingles como una estructura
struct diccionario{
	string ingles[MAX_NUM_PALABRAS]; //entrada es un tipo de dato declarado en la estructura entrada
	string espanol [MAX_NUM_PALABRAS];
	int num_palabras; //utiles de vector 
};

/**
 * @brief Módulo que me inicializa una variable de tipo Diccionario.
 * @param diccionario &everest Variable diccionario en la que se guardarán los datos de entrada del módulo (E/S
 * @param  string ingles[] vector de string que quiero guardar en la variable everest.
 * @param string español[] vector de string que quiero guardar en la variable everest.
 * @param int num_palabras util de los vectores 
 * @post La variable everest, tendrá guardados todos los valores que le pase al módulo.
 */
void inicializarDiccionario(diccionario &everest, string ingles[], string espanol[], int num_palabras){
	everest.num_palabras=num_palabras;

	//tengo que copiar las entradas en español e ingles
    for(int i=0; i < everest.num_palabras; i++){
        everest.ingles[i] = ingles[i];
        everest.espanol[i] = espanol[i];
    }
} //entrada es un tipo de dato declarado en la estructura entrada
	string espanol [MAX_NUM_PALABRAS];
	int num_pal;

//get y set
//get
int getNumPalabras(const diccionario &everest){
	return everest.num_palabras;
}

string getIngles(const diccionario &everest, int posicion){
	return everest.ingles[posicion];
}

string getEspanol(const diccionario &everest, int posicion){
	return everest.espanol[posicion];
}

//set
void setNumpalabras(diccionario &everest, int num_palabras){
	everest.num_palabras=num_palabras;
}

void setIngles(diccionario &everest, string ingles[], int posicion){
	everest.ingles[posicion] = ingles[posicion];
}

void setEspanol(diccionario &everest, string espanol[], int posicion){
	everest.espanol[posicion] = espanol[posicion];
}
//-------------------------------------Hasta aquí la definición de estructuras set y get----------------------------------------

/**
 * @brief Módulo que introduce valores en los campos ingles y español y cuenta sus utiles
 * @param diccionario &everest Variable diccionario en la que se guardarán los datos de entrada del módulo (E/S
 * @post La variable everest, tendrá guardados todos los valores que le pase al módulo.
 */
void contenidoDiccionario(diccionario &everest){
	everest.espanol[0]="hola";
	everest.ingles[0]="hello";
	everest.espanol[1]="mesa";
	everest.ingles[1]="table";
	everest.espanol[2]="perro";
	everest.ingles[2]="dog";
	everest.espanol[3]="gato";
	everest.ingles[3]="cat";
	everest.espanol[4]="silla";
	everest.ingles[4]="chair";
	everest.espanol[5]="rojo";
	everest.ingles[5]="red";
	everest.espanol[6]="coche";
	everest.ingles[6]="car";

	everest.num_palabras=7;	
}

/**
 * @brief Módulo que busca palabras en los campos de la estructura español e ingles y devuelve un entero si lo encuentra y un -1 si no
 * @param diccionario &everest Variable diccionario en la que se buscan los ementos dentro de sus campos ingles y español(E)
 * @param int idioma entero que contien un valor 0 para el diccionario de español y un valor 1 para el dicionario en ingles
 * @post retornara la posición en la que se encuentra la palabra que busca o -1 si no se ecuentra.
 */
int buscarPalabra(const diccionario &everest, int idioma){
	string palabra;
	if (idioma==0){//estamos buscando la palabra es español
		cout << "Introduzca la palabra en Español" << endl;
		cin >> palabra;
		for (int i=0; i<getNumPalabras(everest); i++){
			if(palabra==getEspanol(everest,i))
				return i;
		
		}
		
	}
	else {
		cout << "Introduzca la palabra en Ingles" << endl;
		cin >> palabra;
		for (int i=0; i<getNumPalabras(everest); i++){
			if(palabra==getIngles(everest,i))
				return i;
		
		}
		
	}

	return -1;
}

/**
 * @brief Módulo que imprime el contenido de la estrucura diccionario
 * @param diccionario &everest Variable diccionario en la que se encuentra los valores de los campos a imprimir (E)
 * @post se imprimira por pantalla el contenido de la estructura.
 */

void imprimirDiccionario(const diccionario &everest){
	for (int i=0; i<getNumPalabras(everest); i++){
		cout << getEspanol(everest, i) << "\t\t" << getIngles(everest, i) << endl;
	}
}

/**
 * @brief Módulo que permite introducir palabra dentro de los vectores español e ingles
 * @param diccionario &everest Variable diccionario en la que se introducen las palabras dentro de los sus campos ingles y español
 * @param int idioma entero que contien un valor 0 para el diccionario de español y un valor 1 para el dicionario en ingles
 * @post la palabra estara introducida en los vectoes español e ingles y las utiles tendran +1
 */

void introducirPalabra(diccionario &everest, int idioma){

	if (idioma==0){//estamos buscando la palabra es español
		cout << "Introduzca la palabra en Español" << endl;
		cin >> everest.espanol[getNumPalabras(everest)]; //getpalabra son las utiles, en la posicion de retorno del ultimo util introducimos la palabra
		cout << "Introduzca la palabra en ingles" << endl;
		cin >> everest.ingles[getNumPalabras(everest)];
		everest.num_palabras++;
		
	}
	else {
		cout << "Introduzca la palabra en Ingles" << endl;
		cin >> everest.ingles[getNumPalabras(everest)]; //getpalabra son las utiles, en la posicion de retorno del ultimo util introducimos la palabra
		cout << "Introduzca la palabra en Español" << endl;
		cin >> everest.espanol[getNumPalabras(everest)];
		everest.num_palabras++;
		
		
	}
}


/**
 * @brief Módulo que muestra un menu
 * @param diccionario &everest Variable diccionario en la que se encuentra los campos necesarios para el menu
 * @post mostrará por pantalla un menu
 */
void MenuPrincipal(diccionario &everest){
	char c,a,b;
	int i;

	do{
		cout << "\n<<[[ Bienvenidos al diccionario de ESPAÑOL E INGLES]]>>"<< endl <<endl;
	    cout << "Esta usted en el menu principal"<< endl; 
	    cout << "Introduzca << 1 >> para buscar una palabra"<< endl; 
	    cout << "Introduzca << 2 >> para introducir una nueva palabra"<< endl;
	    cout << "Introduzca << 3 >> para ver los creditos"<< endl;
	    cout << "Introduzca << 4 >> para imprimir el diccionario"<< endl;
	    cout << "Introduzca << 0 >> para salir"<< endl;
	    cin >> c;
	    system("clear");//limpia la pantalla

	    switch (c) {
		case '1':
			do{
				cout << "Escoja el idioma de la palabra a buscar << E >> para Español e << I >> para Inglés" << endl; 
				cin >> a;
				if ((a=='e') || (a=='E') || (a=='i') || (a=='I')){
					if ((a=='e') || (a=='E')){
						i = buscarPalabra(everest, 0);
						if (i!=-1){//0 para diccionario español, el cero no hay declararlo porque es un valor no una variable
							cout << getEspanol(everest, i) << "\t\t" << getIngles(everest, i) << endl;
						}
						else
							cout << "la palabra no se encuentra en el diccionario" << endl;
					}

					if ((a=='i') || (a=='I')){
						i = buscarPalabra(everest, 1);//1 para diccionario inglés
						if (i!=-1){//0 para diccionario español, el cero no hay declararlo porque es un valor no una variable
							cout << getIngles(everest, i) << "\t\t" << getEspanol(everest, i) << endl;
						}
						else
							cout << "la palabra no se encuentra en el diccionario" << endl;
					}
				}
				else 
					cout <<"introduzca el carácter correcto" << endl;
			}while ((a!='e') && (a!='E') && (a!='i') && (a!='I'));

			break;
			
		case '2':
			do{
				cout << "Escoja el idioma de la palabra a introducir primero << E >> para Español e << I >> para Inglés" << endl; 
				cin >> a;
				if ((a=='e') || (a=='E') || (a=='i') || (a=='I')){
					if ((a=='e') || (a=='E')){
						introducirPalabra(everest, 0);
						
					}

					if ((a=='i') || (a=='I')){
						introducirPalabra(everest, 1);
					}
				}
				else 
					cout <<"introduzca el carácter correcto" << endl;
			}while ((a!='e') && (a!='E') && (a!='i') && (a!='I'));
		
			break;
		case '3':
			cout << "Programa realizado por Francisco Manuel Pérez Casares en el curso de 1º DAM del instituto Cristo Rey"<< endl; 
			break;

		case '4':
			imprimirDiccionario(everest);
			break;

		case '0':
			break;
		
		default:
			cout << "opcion incorrecta" << endl;
		}

	}while(c!='0');

}



int main () {
	diccionario nuevo;//nuevo es nombre de la variable de tipo diccionario
	contenidoDiccionario(nuevo);
	MenuPrincipal(nuevo);

}