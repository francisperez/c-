/*
/////////////////PRIMERA PARTE : CREAR LAS CELDAS///////////////


 Crear una lista de celdas enlazadas;

 Cada celda es un struct, que contiene dos celdas:
 	celda 1) valor;
 	celda 2) puntero a la siguiente celda;*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Celda{
    double valor;
    Celda *siguiente;
};

Celda* createCelda (){
    //crea una celda dinamica que devuelve un puntero con la dirección donde se encuentra
    Celda *punterodecelda = 0;
    punterodecelda = new Celda;
    if (punterodecelda == 0){
        cerr << "El S.O. no pudo reservar memoria. Se abortará la ejecución." << endl;
        exit(-1);
    }
    cout << "Memoria de Celda Reservada Correctamente..." << endl;
    return punterodecelda;
}

void dropCelda (Celda *(&celda_que_quiero_borrar)){
    //elimina una celda
    delete celda_que_quiero_borrar;
    celda_que_quiero_borrar = 0;
    cout << "Memoria de Celda Eliminada Correctamente..." << endl;
}

void setValorCelda(Celda *celda, double nuevo_valor){
    //asigna un valor a la celda
    celda->valor = nuevo_valor;
}

void setCeldaSiguiente(Celda *celda, Celda *nueva_celda_siguiente){
    //asigna la direccion a la que apunta la celda
    celda->siguiente = nueva_celda_siguiente;
}

double getValorCelda(Celda *celda){
    // devuelve el valor de la celda
    return celda->valor;
}

Celda* getCeldaSiguiente(Celda *celda){
    //devuelve el puntero de la celda a la que apunta
    return celda->siguiente;
}

void printCelda(Celda *celda){
		// imprime lo siguiente: direccionCelda = {valor_celda, direccionAsiguienteCelda} : ej; 00FFx0123={6,3 , 00FFx6585}
    cout << celda << " = {" << getValorCelda(celda) << ", " << getCeldaSiguiente(celda) << "} ";
}


/////////////////SEGUNDA PARTE : CREAR UNA LISTA CON LAS CELDAS///////////////

//Creamos el siguiente struct:

struct ConjuntoCeldas{
    Celda *primera;
    Celda *ultima;
    int total_celdas;
};

// Desarrollamos los siguientes módulos:
	
ConjuntoCeldas* crearConjuntoCeldas (int numero_de_celdas){

    // Devuelve la direccion que apunta al struct ConjuntoCeldas
    // Dentro de este modulo se crean las celdas, y el struct de conjunto de celdas
    ConjuntoCeldas *miconjunto = 0;
    miconjunto = new ConjuntoCeldas;
    if (miconjunto == 0){
        cerr << "El S.O. no pudo reservar memoria. Se abortará la ejecución." << endl;
        exit(-1);
    }
    cout << "Memoria del Conjunto de Celdas correctamente reservada..." << endl;
    //Bucle: reservar memoria para la celda, inicializar a 0.0 su valor y asignarle los punteros.
    Celda *aux = 0;
    Celda *anterior; //ir guardando la dirección de la celda anterior
    //Primero creamos la primera celda de forma independiente porque hay que guardar su dirección en el conjunto
    aux = createCelda();
    setValorCelda(aux, 0.0);
    miconjunto->primera = aux;
    miconjunto->total_celdas++;
    //Después creamos las celdas de en medio
    while(miconjunto->total_celdas <= numero_de_celdas-2){ //la primera y la última las creamos fuera del bucle
        anterior = aux;
        aux = createCelda(); //creo la celda
        setValorCelda(aux, 0.0); //cambio su valor
        setCeldaSiguiente(anterior, aux); //la anterior apunta a la que acabo de crear
        miconjunto->total_celdas++; //aumento total celdas del conjunto
    }
    //Por último creamos la última
    anterior = aux;
    aux = createCelda();
    setValorCelda(aux, 0.0);
    setCeldaSiguiente(aux, NULL);
    setCeldaSiguiente(anterior, aux);
    miconjunto->ultima = aux;
    miconjunto->total_celdas++;
    
    //Devolvemos el puntero que apunta a la estructura ConjuntoCeldas
    return miconjunto;
}
	
void borrarConjuntoCeldas (ConjuntoCeldas *(&un_conjunto_a_borrar)){
    // Recorre el conjunto de celdas, borra las celdas del conjunto y despues pone todos los punteros a cero
    Celda *actual = un_conjunto_a_borrar->primera;
    Celda *siguiente = getCeldaSiguiente(actual);
    while (siguiente != NULL){
        siguiente = getCeldaSiguiente(actual);
        dropCelda(actual);
        actual = siguiente;
    }
    un_conjunto_a_borrar->primera = 0;
    un_conjunto_a_borrar->ultima = 0;
    un_conjunto_a_borrar->total_celdas = 0;
    
    //Y me borro a mí mismo
    delete un_conjunto_a_borrar;
    un_conjunto_a_borrar = 0;
}

void insertarCeldaConjuntoCelda(ConjuntoCeldas *un_conjunto){
	//incluye la celda en el conjunto.
	//actualiza el numero de celdas, si no hay suficientes celdas reservadas, reserva más

    Celda *ultima;
    Celda *siguiente;
    Celda *aux;
    ConjuntoCeldas *miconjunto = 0;

    aux = createCelda();
     cout << "hola";
    setValorCelda(aux, 4.0);
    cout << "hola";

    miconjunto->ultima->siguiente = aux;
    miconjunto->ultima = miconjunto->ultima->siguiente;
    aux->siguiente=NULL;
    miconjunto->total_celdas++;
    cout <<aux<<ultima;
}

	void printConjuntoCeldas(ConjuntoCeldas *conjunto_celdas_a_imprimir){
		// Imprime el estruct ConjuntoCeldas
        cout << "Primera Celda: " << conjunto_celdas_a_imprimir->primera << endl;
        cout << "Última Celda: " << conjunto_celdas_a_imprimir->ultima << endl;
        cout << "Total Celdas: " << conjunto_celdas_a_imprimir->total_celdas << endl;
        cout << "Conjunto de Celdas =  { " << endl;
        Celda *aux = conjunto_celdas_a_imprimir->primera;
        while (getCeldaSiguiente(aux) != NULL){
            printCelda(aux);
            aux = getCeldaSiguiente(aux);
            cout << endl;
        }
        //Nos falta imprimir la última
        printCelda(aux); //printCelda(conjunto_celdas_a_imprimir->ultima)
        //Cerramos el conjunto
        cout << " }"  << endl;
	}



int main(){
    cout << "***** DEMO DE USO DE LA ESTRUCTURA CELDA *****" << endl;
    Celda *unacelda = 0, *otracelda;
    unacelda = createCelda();
    otracelda = createCelda();
    
    setValorCelda(unacelda, 7.3);
    setValorCelda(otracelda, 5.1);
    setCeldaSiguiente(unacelda, otracelda);
    setCeldaSiguiente(otracelda, unacelda);
    
    printCelda(unacelda);
    cout << endl;
    printCelda(otracelda);
    cout << endl;
    
    dropCelda(unacelda);
    dropCelda(otracelda);
    
    int total_celdas = 0;
    cout << "***** DEMO DE USO DE LA ESTRUCTURA CONJUNTO DE CELDAS *****" << endl;
    cout << "Por favor introduce el número de celdas que tendrá tu conjunto: ";
    cin >> total_celdas;
    ConjuntoCeldas *miconjunto = 0;
    miconjunto = crearConjuntoCeldas(total_celdas);
    insertarCeldaConjuntoCelda(miconjunto);
    printConjuntoCeldas(miconjunto);
    //borrarConjuntoCeldas(miconjunto);

}