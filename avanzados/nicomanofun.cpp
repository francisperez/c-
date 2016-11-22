#include <iostream>
using namespace std;

/**
 * @brief Devuelve el impar de orden "n" en la tabla de los números impares
 * @param int n Indica el numéro de impar que que queremos devolver
 * @pre n > 0
 * @return int El número impar requerido
 */
int generarImpar(int n){
    return (2*n)-1;
}

/**
 * @brief Devuelve la posición del número impar por el que tengo que comenzar, que sigue la fórmula siguiente:
 *  posicion = 1 + 2 + 3 + ... + (a-1) + 1
 * @param int a Es el número del que quiero calcular el cubo
 * @pre a > 0
 * @return int La posición del número impar donde comenzar
 */
int posicionInicial(int a){
    int pos_inicial = 0;
    
    for(int i=1; i < a; i++)
        pos_inicial = pos_inicial + i;
    pos_inicial = pos_inicial + 1;
    
    return pos_inicial;
}

/**
 * @brief Devuelve la posición del número impar en el que tengo que terminar de sumar, que sigue la fórmula siguiente: pos_final = posicion inicial + a - 1
 * @param int a Es el número del que quiero calcular el cubo
 * @pre a > 0
 * @return int La posición del número impar donde terminar de sumar
 */
int posicionFinal(int a){
    int pos_final = posicionInicial(a) + a - 1;
    
    return pos_final;
}

int Nicomaco(int a){
    int resultado = 0;
    
    for(int i = posicionInicial(a); i <= posicionFinal(a); i++)
        resultado = resultado + generarImpar(i);
    
    return resultado;
}

int main(){
    int a = 0;
    int cubo = 0;
    
    //Entradas
    cout << "Bienvenido a Nicomaco. Introduzca el cubo que quiere calcular: " << endl;
    cin >> a;
    
    //Invoco al módulo Nicomaco
    cubo = Nicomaco(a);
    
    //Salida
    cout << "El cubo de " << a << " es " << cubo << endl;
}
