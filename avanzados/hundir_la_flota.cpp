#include <iostream>
using namespace std;

/* Usaremos dimensión 9x9, para un tablero de que 8x8, con la decoración por fuera */
const int DIM_FIL = 9;
const int DIM_COL = 9;


/**
 * @brief Módulo que recorre una matriz y crea un tablero correspondiente a caractéres de 9 x 9.
 * @param const unTablero[]  Una matriz  de caracteres . (E/S)
 * @param int util_col Variable que contiene el numero de caracteres de las columnas en la matriz. (E)
 * @param int util_fil Variable que contiene el numero de caracteres de las filas en la matriz. (E)
 * @post Al final de la ejecución, se devuelve al main el tablero ocupado por caractéres del jugador 1.
 */


void inicializarTablero1 (char unTablero[][DIM_COL][2], int util_col, int util_fil){
    //1º) Rellenamos la esquina oculta y visible
    unTablero[0][0][0] = '@';
    unTablero[0][0][1] = '@';
    //2º) Rellenamos la fila de arriba del tablero visible
    for (int i = 1; i <= util_col; i++)
        unTablero[0][i][0] = (char)(((int)'0')+i); //se guarda el número de columna como un char
    //3º) Rellenamos la fila de arriba del tablero oculto
    for (int i = 1; i <= util_col; i++)
        unTablero[0][i][1] = (char)(((int)'0')+i); //se guarda el número de columna como un char
    //4º) Rellenamos las letras de la primera fila del tablero visible
    for (int i = 1; i <= util_fil; i++)
        unTablero[i][0][0] = (char)(((int)'A')+(i-1));
    //4º) Rellenamos las letras de la primera fila del tablero oculto
    for (int i = 1; i <= util_fil; i++)
        unTablero[i][0][1] = (char)(((int)'A')+(i-1));
    //5º) Rellenamos la posición de los barcos representados con una letras en el tablero oculto
    unTablero[4][1][1] = 't';
    unTablero[3][2][1] = 't';
    unTablero[2][3][1] = 't';
    unTablero[2][5][1] = 'y';
    unTablero[2][8][1] = 'z';
    unTablero[1][8][1] = 'z';
    unTablero[4][4][1] = 'r';
    unTablero[4][5][1] = 'r';
    unTablero[4][6][1] = 'r';
    unTablero[4][7][1] = 'r';
    unTablero[6][1][1] = 's';
    unTablero[7][2][1] = 's';
    unTablero[8][3][1] = 's';
    unTablero[7][6][1] = 'u';
    unTablero[8][6][1] = 'u';
    
    // Relleno todo con interrogaciones en el tablero visible.
    for (int f = 1; f <= util_fil; f++) {
        for (int c = 1; c <= util_col; c++) {
            unTablero[f][c][0] = '?';
        }
    }

    // Relleno todo lo que no son barcos con el signo ~ en el tablero oculto.
    for (int f = 1; f <= util_fil; f++) {
        for (int c = 1; c <= util_col; c++) {
            if ((unTablero[f][c][1] != 't') && (unTablero[f][c][1] != 'y') && (unTablero[f][c][1] != 'z') && (unTablero[f][c][1] != 'r') && (unTablero[f][c][1] != 's') && (unTablero[f][c][1] != 'u')) {
            unTablero[f][c][1] = '~';
            }
        }
    }
}

/**
 * @brief Módulo que recorre una matriz y crea un tablero correspondiente a caractéres de 9 x 9.
 * @param const unTablero[]  Una matriz  de caracteres . (E/S)
 * @param int util_col Variable que contiene el numero de caracteres de las columnas en la matriz. (E)
 * @param int util_fil Variable que contiene el numero de caracteres de las filas en la matriz. (E)
 * @post Al final de la ejecución, se devuelve al main el tablero ocupado por caractéres del jugador 2.
 */

void inicializarTablero2 (char unTablero[][DIM_COL][2], int util_col, int util_fil){
    //1º) Rellenamos la esquina oculta y visible
    unTablero[0][0][0] = '@';
    unTablero[0][0][1] = '@';
    //2º) Rellenamos la fila de arriba del tablero visible
    for (int i = 1; i <= util_col; i++)
        unTablero[0][i][0] = (char)(((int)'0')+i); //se guarda el número de columna como un char
    //3º) Rellenamos la fila de arriba del tablero oculto
    for (int i = 1; i <= util_col; i++)
        unTablero[0][i][1] = (char)(((int)'0')+i); //se guarda el número de columna como un char
    //4º) Rellenamos las letras de la primera fila del tablero visible
    for (int i = 1; i <= util_fil; i++)
        unTablero[i][0][0] = (char)(((int)'A')+(i-1));
    //4º) Rellenamos las letras de la primera fila del tablero oculto
    for (int i = 1; i <= util_fil; i++)
        unTablero[i][0][1] = (char)(((int)'A')+(i-1));
    //5º) Rellenamos la posición de los barcos representados con una letras en el tablero oculto
    unTablero[3][8][1] = 't';
    unTablero[4][7][1] = 't';
    unTablero[5][6][1] = 't';
    unTablero[6][3][1] = 'y';
    unTablero[1][6][1] = 'z';
    unTablero[2][6][1] = 'z';
    unTablero[8][5][1] = 'r';
    unTablero[8][6][1] = 'r';
    unTablero[8][7][1] = 'r';
    unTablero[8][8][1] = 'r';
    unTablero[1][2][1] = 's';
    unTablero[2][3][1] = 's';
    unTablero[3][4][1] = 's';
    unTablero[4][1][1] = 'u';
    unTablero[5][1][1] = 'u';
    
    // Relleno todo con interrogaciones en el tablero visible.
    for (int f = 1; f <= util_fil; f++) {
        for (int c = 1; c <= util_col; c++) {
            unTablero[f][c][0] = '?';
        }
    }

    // Relleno todo lo que no son barcos con el signo ~ en el tablero oculto.
    for (int f = 1; f <= util_fil; f++) {
        for (int c = 1; c <= util_col; c++) {
            if ((unTablero[f][c][1] != 't') && (unTablero[f][c][1] != 'y') && (unTablero[f][c][1] != 'z') && (unTablero[f][c][1] != 'r') && (unTablero[f][c][1] != 's') && (unTablero[f][c][1] != 'u')) {
            unTablero[f][c][1] = '~';
            }
        }
    }
}

/**
 * @brief Módulo que imprime char de una matriz.
 * @param const char unTablero[]  Una matriz  de caracteres que quiero imprimir. (E)
 * @param int util_col Variable que contiene el numero de caracteres de las columnas en la matriz. (E)
 * @param int util_fil Variable que contiene el numero de caracteres de las filas en la matriz. (E)
 * @post Al final de la ejecución, se imprimirá por pantalla el contenido del vector.
 */
void imprimeTablero (const char unTablero[][DIM_COL][2], int util_col, int util_fil, bool oculto){
    int p = 0; //me indicará la profundidad del tablero que quiero imprimir
    if (oculto == true)
        p = 1; //es decir, quiere imprimir en modo prueba el tablero oculto
    else
        p = 0; //es decir, quiere imprimr el tablero que ve el jugador
    
    for (int f = 0; f <= util_fil; f++){
        for (int c = 0; c <= util_col; c++) {
            cout << unTablero[f][c][p] << " "; 
        }
        cout << endl;
    }
    cout << endl;
}
/**
 * @brief Módulo que lee char de un vector introducido por el usuario.
 * @param cchar v[]  Un vector de caracteres que quiero ordenar. (E/S)
 * @param int util_v Variable que me almacenará el número de filas utilizadas. (E/S)
 * @pre Char debe de ser lo suficientemente grande para cualquier nombre.
 * @post Al final de la ejecución, el vector contendrá el valor del char introducido.
 */

void leeTexto (char v[], int &util_v){
    bool salir=false;
    int i;
    
    for (i=0; salir==false; i++){
        cin >> v[i];
        if (v[i]=='.')
            salir=true;
    }
    util_v=i-1;
}

/**
 * @brief Módulo que imprime char de de un vector.
 * @param const char v[]  Un vector de caracteres que quiero imprimir. (E)
 * @param int util_v Variable que contiene el numero de caracteres utilizados en el vector. (E)
 * @post Al final de la ejecución, se imprimirá por pantalla el contenido del vector.
 */

void imprimeVector (const char v[], int util_v){
    for (int i=0; i<util_v; i++)
        cout << v[i];
    cout << endl;

}

/**
 * @brief Módulo que cambia una letra por un número.
 * @param char. (E)
 * @pre Char debe de ser un carácter de la "a" a la "h".
 * @post Al final de la ejecución, se devolverá un número entero.
 */

int cambioChar(char numero){
    if (numero=='a')
    return 1;
    if (numero=='b')
    return 2;
    if (numero=='c')
    return 3;
    if (numero=='d')
    return 4;
    if (numero=='e')
    return 5;
    if (numero=='f')
    return 6;
    if (numero=='g')
    return 7;
    if (numero=='h')
    return 8;
}



/**
 * @brief Módulo que lee recoje los valores introducidos por el usuario y comprueba en que lugar de la matriz se encuentran.
 * @param char unTablero[]  Una matriz de caracteres. (E/S)
 * @param util_fil Variable que me almacena el número de filas utilizadas. (E)
 * @param ut1il_col Variable que me almacena el número de columnas utilizadas. (E)
  * @param int cuenta_x1. Variable que contará el número de veces que se hunde un barco para poder salir de juego(E/S)
 * @pre los disparon han de corresponder con caracteres válidos (a hasta h ; y de 1 a 8)
 * @post Al final de la ejecución, el usario introducira un caracter valido en la matriz.
 */

void Disparos1(char unTablero[DIM_FIL][DIM_COL][2], int util_col, int util_fil, int &cuenta_x1){

    int disparo_letra, disparo_numero, contador=0;
    char disparo_letra_char;

    cin >> disparo_letra_char;
    disparo_letra=cambioChar(disparo_letra_char);
    cin >> disparo_numero;


    if (unTablero [disparo_letra][disparo_numero][1]=='~'){ //oculto
        unTablero [disparo_letra][disparo_numero][0]='-';   // asignamos al visible
        cout << "Agua" << endl;
    }
    else {
        unTablero [disparo_letra][disparo_numero][0]='*'; // asignamos al visible
        cout << "Tocado" << endl;
    }

    
    if (unTablero [disparo_letra][disparo_numero][1]=='y'){
        unTablero [2][5][0]='X';
        cout << "Hundido" << endl;
    }
    if ((unTablero[2][8][0] == '*') && (unTablero[1][8][0] == '*')){
        unTablero[2][8][0] = 'X';
        unTablero[1][8][0] = 'X';
        cout << "Hundido" << endl;
    }
    if ((unTablero[7][6][0] == '*') && (unTablero[8][6][0] == '*')){
        unTablero[7][6][0] = 'X';
        unTablero[8][6][0] = 'X';
        cout << "Hundido" << endl;
    }
    if ((unTablero[4][4][0] == '*') && (unTablero[4][5][0] == '*') && (unTablero[4][6][0] == '*') && (unTablero[4][7][0] == '*')){
        unTablero[4][4][0] = 'X';
        unTablero[4][5][0] = 'X';
        unTablero[4][6][0] = 'X';
        unTablero[4][7][0] = 'X';
        cout << "Hundido" << endl;
    }
    if ((unTablero[6][1][0] == '*') && (unTablero[7][2][0] == '*') && (unTablero[8][3][0] == '*')){
        unTablero[6][1][0] = 'X';
        unTablero[7][2][0] = 'X';
        unTablero[8][3][0] = 'X';
        cout << "Hundido" << endl;
    }
    if ((unTablero[4][1][0] == '*') && (unTablero[3][2][0] == '*') && (unTablero[2][3][0] == '*')){
        unTablero[4][1][0] = 'X';
        unTablero[3][2][0] = 'X';
        unTablero[2][3][0] = 'X';
        cout << "Hundido" << endl;
    }
    if (unTablero[disparo_letra][disparo_numero][0]=='X'){
        cuenta_x1++;
    }

 }

 /**
 * @brief Módulo que lee recoje los valores introducidos por el usuario y comprueba en que lugar de la matriz se encuentran.
 * @param char unTablero[]  Una matriz de caracteres. (E/S)
 * @param util_fil Variable que me almacena el número de filas utilizadas. (E)
 * @param ut1il_col Variable que me almacena el número de columnas utilizadas. (E)
 * @param int cuenta_x2. Variable que contará el número de veces que se hunde un barco para poder salir de juego(E/S)
 * @pre los disparon han de corresponder con caracteres válidos (a hasta h ; y de 1 a 8)
 * @post Al final de la ejecución, el usario introducira un caracter valido en la matriz.
 */

void Disparos2(char unTablero[DIM_FIL][DIM_COL][2], int util_col, int util_fil, int &cuenta_x2){

    int disparo_letra, disparo_numero, contador=0;
    char disparo_letra_char;

    cin >> disparo_letra_char;
    disparo_letra=cambioChar(disparo_letra_char);
    cin >> disparo_numero;


    if (unTablero [disparo_letra][disparo_numero][1]=='~'){
        unTablero [disparo_letra][disparo_numero][0]='-';
        cout << "Agua" << endl;
    }
    else {
        unTablero [disparo_letra][disparo_numero][0]='*';
        cout << "Tocado" << endl;
    }
    
    if (unTablero [disparo_letra][disparo_numero][1]=='y'){
        unTablero [6][3][0]='X';
        cout << "Hundido" << endl;
    }
    if ((unTablero[1][6][0] == '*') && (unTablero[2][6][0] == '*')){
        unTablero[1][6][0] = 'X';
        unTablero[2][6][0] = 'X';
        cout << "Hundido" << endl;
    }
    if ((unTablero[4][1][0] == '*') && (unTablero[5][1][0] == '*')){
        unTablero[4][1][0] = 'X';
        unTablero[5][1][0] = 'X';
        cout << "Hundido" << endl;
    }
    if ((unTablero[8][5][0] == '*') && (unTablero[8][6][1] == '*') && (unTablero[8][7][0] == '*') && (unTablero[8][8][0] == '*')){
        unTablero[8][5][0] = 'X';
        unTablero[8][6][0] = 'X';
        unTablero[8][7][0] = 'X';
        unTablero[8][8][0] = 'X';
        cout << "Hundido" << endl;
    }
    if ((unTablero[1][2][0] == '*') && (unTablero[2][3][0] == '*') && (unTablero[3][4][0] == '*')){
        unTablero[1][2][0] = 'X';
        unTablero[2][3][0] = 'X';
        unTablero[3][4][0] = 'X';
        cout << "Hundido" << endl;
    }
    if ((unTablero[3][8][0] == '*') && (unTablero[4][7][0] == '*') && (unTablero[5][6][0] == '*')){
        unTablero[3][8][0] = 'X';
        unTablero[4][7][0] = 'X';
        unTablero[5][6][0] = 'X';
        cout << "Hundido" << endl;
    }

    if (unTablero[disparo_letra][disparo_numero][0]=='X')
        cuenta_x2++;
    
}

int main (){
    const int MAX=100;
    char nombre1[MAX], nombre2[MAX], c;
    int util_n1, util_n2;
    char tableroJugador1 [DIM_FIL][DIM_COL][2];
    char tableroJugador2 [DIM_FIL][DIM_COL][2];
    int util_fil_jugador1 = 8, util_col_jugador1 = 8;
    int util_fil_jugador2 = 8, util_col_jugador2 = 8;

    bool terminar=false; //lo utilizamos para el do while donde se ejuega
    int contador=0;
    int cuenta_x1=0, cuenta_x2=0;

    // impresión de diversas opciones para el menu switch
    cout << "\n<<[[ Bienvenidos a hundir la flota]]>>"<< endl <<endl;
    cout << "Esta usted en el menu principal"<< endl; 
    cout << "Introduzca << 1 >> para jugar"<< endl; 
    cout << "Introduzca << 2 >> para ver los creditos"<< endl;
    cout << "Introduzca << 3 >> para ver las instrucciones del juego"<< endl;
    cout << "Introduzca cualquier otro carácter para salir del juego"<< endl;
    cin >> c;

    switch (c) {
    case '1':
        cout << "Por favor, introduzca el nombre de los jugadores, seguido de un punto para confirmar :" << endl;
        cout << "jugador 1:" << endl;
        leeTexto(nombre1,util_n1); 
        cout << "\njugador 2:" << endl;
        leeTexto(nombre2,util_n2);

        //jugador1
        inicializarTablero1 (tableroJugador1,util_col_jugador1,util_fil_jugador1);
        imprimeVector(nombre1,util_n1);
        imprimeTablero (tableroJugador1,util_col_jugador1,util_fil_jugador1,false);
  
        //jugador2
        inicializarTablero2 (tableroJugador2,util_col_jugador2,util_fil_jugador2);
        imprimeVector(nombre2,util_n2);
        imprimeTablero (tableroJugador2,util_col_jugador2,util_fil_jugador2,false);

        //juego
    
        do { 

        contador++;
        cout << "Número de ronda: " << contador << endl;
        //jugador1
        imprimeVector(nombre1,util_n1);
        cout << "Realiza un disparo: " << endl;
        Disparos1 (tableroJugador1,util_col_jugador1,util_fil_jugador1,cuenta_x1);
        imprimeTablero (tableroJugador1,util_col_jugador1,util_fil_jugador1,false);
        
        //jugador2
        imprimeVector(nombre2,util_n2);
        cout << "Realiza un disparo: " << endl;
        Disparos2 (tableroJugador2,util_col_jugador2,util_fil_jugador2, cuenta_x2);
        imprimeTablero (tableroJugador2,util_col_jugador2,util_fil_jugador2,false);
        
       
        if (cuenta_x1==6){
            cout << "¡¡ GANADOR EL JUGADOR 1 !!" << endl;
            terminar=true;
        }

         if (cuenta_x2==6){
            cout << "¡¡ GANADOR EL JUGADOR 2 !!" << endl;
            terminar=true;
        }

        }while(terminar==false); //Termina cuando el numero de barcos sea de 6

        
        break;
    case '2':
        cout << "Programa realizado por Francisco Manuel Pérez Casares en el curso de 1º DAM del instituto Cristo Rey"<< endl; 
        break;
    case '3':
        cout << "REGLAS BASICAS" << endl;
        cout << "Se utilizan 2 cuadrículas de 8x8. Cada una correspondiente a cada jugador en los cuales hay 6 barcos posicionados" <<endl<<endl;
        cout << "DISPAROS" << endl;
        cout << "Los disparos pueden terner 3 resultados:"<<endl;
        cout << "1.Agua: no se acertó con la posición de un barco se representa con << - >>" << endl;
        cout << "2.Tocado: se acertó con una posición de la cuadrícula en la que estaba parte de un barco se representa con << * >>." << endl;
        cout << "3.Hundido: se tocó un barco pero ya todas sus posiciones figuran como tocadas se representa con << X >>" << endl<<endl;
        cout << "¿QUIEN GANA?" << endl;
        cout << "Gana la partida el jugador que logre hundir primero los 6 barcos de su adversario." << endl;
        break;
    default:
        cout << "Ha decidido salir, hasta otra"<< endl; 
    }
}