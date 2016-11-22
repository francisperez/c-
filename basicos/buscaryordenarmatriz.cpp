
#include <iostream>
using namespace std;

//SÓLO DE FORMA PEDAGÓGICA PARA ESTE EJEMPLO NOS PERMITIMOS ESTAS DOS VARIABLES GLOBALES.
//JAMÁS USEIS VARIABLES GLOBALES. EN ESTE CASO DEJAMOS PASARLO PORQUE SON CONSTANTES.
const int DIM_FIL = 20;
const int DIM_COL = 30;

/**
 * @brief Módulo que va pidiendo por pantalla al usuario valores, y los va almacenando en una matriz.
 * @param char m[][DIM_COL] Una matriz de caracteres donde guardar los caracteres del usuario. (E)
 * @param int util_fil Variable que me almacenará el número de filas utilizadas. (E/S)
 * @param int util_col Variable que me almacenará el número de columnas utilizadas. (E/S)
 * @pre La matriz debe estar declarada.
 * @post Al final de la ejecución, la matriz contendrá todos los datos del usuario que ha ido introduciendo.
 * Y tendremos guardado en util_fil y util_col los elementos utilizados en cada dimensión.
 */
void rellenarMatrizUsuario(char m[][DIM_COL], int &util_fil, int &util_col){

    cout << "Por favor especifique la cantidad de filas y columnas que quiere usar." << endl;
    
    //Filtro para las columnas que utilizará el usuario
    do {
        cout << "Número de Columnas (debe estar entre 1 y " << DIM_COL << "): ";
        cin >> util_col;
    } while ((util_col < 1) && (util_col > DIM_COL));
    
    //Filtro para las filas que utilizará el usuario
    do {
        cout << "Número de Filas (debe estar entre 1 y " << DIM_FIL << "): ";
        cin >> util_fil;
    } while ((util_fil < 1) && (util_fil > DIM_FIL));
    
    //Comenzamos a rellenar la matriz con los datos del usuario (RELLENO POR FILAS)
    cout << "Comenzamos a rellenar la matriz: " << endl;
    for (int f = 0; f < util_fil; f++){ //fijo la fila
        for (int c = 0; c < util_col; c++){ //y por cada fila varío las columnas
            cout << "m[" << f << "][" << c << "] = ";
            cin >> m[f][c];
        }
    }
}


/**
 * @brief Módulo que imprime la matriz que le pase.
 * @param const char m[][DIM_COL] Una matriz de caracteres que quiero imprimir. (E)
 * @param int util_fil Variable que me almacenará el número de filas utilizadas. (E)
 * @param int util_col Variable que me almacenará el número de columnas utilizadas. (E)
 * @pre La matriz debe estar declarada y rellenar con valores, por lo que util_fil y util_col deben ser > 0.
 * @post Al final de la ejecución, la matriz estará imprimida por la pantalla del usuario.
 */
void imprimeMatriz(const char m[][DIM_COL], int util_fil, int util_col){
    cout << endl;
    for (int f = 0; f < util_fil; f++) {
        for (int c = 0; c < util_col; c++){
            cout << m[f][c] << " ";
        }
        cout << endl; //para bajarme de fila
    }
    cout << endl;
}

/**
 * @brief Módulo que busca en la matriz un valor introducido por el usuario.
 * @param const char m[][DIM_COL] Una matriz de caracteres que quiero imprimir. (E)
 * @param int util_fil Variable que me almacenará el número de filas utilizadas. (E)
 * @param int util_col Variable que me almacenará el número de columnas utilizadas. (E)
 * @pre La matriz debe estar declarada y rellenar con valores, por lo que util_fil y util_col deben ser > 0.
 * @post Al final de la ejecución, encontrará el elemento indicado por el usuario.
 */
void buscarElementoenMatriz(const char m[][DIM_COL], int util_fil, int util_col){  // busqueda secuencial para una matriz
    int f, c, fil_encontrado, col_encontrado;
    bool encontrado=false;
    char buscar;

    cout << "Introduzca el elemento a buscar:" << endl;
    cin >> buscar;

    for (f=0; !encontrado && (f<util_fil); f++){
        for (c=0; !encontrado && (c<util_col); c++){
            if (m[f][c]==buscar){
                encontrado=true;
                fil_encontrado=f;
                col_encontrado=c;  
            }  
        }
    }
    if(encontrado==true) 
        cout << "Encontrado en la posición:" << "\nm["<< fil_encontrado << "]" <<"[" << col_encontrado << "]"<< endl;
    else
        cout << "Elemento no encontrado" << endl;        
}


/**
 * @brief Módulo que ordena alfabéticamente una matriz de acuerdo al codigo ASCILL.
 * @param cchar m[][DIM_COL] Una matriz de caracteres que quiero ordenar. (E/S)
 * @param int util_fil Variable que me almacenará el número de filas utilizadas. (E)
 * @param int util_col Variable que me almacenará el número de columnas utilizadas. (E)
 * @pre La matriz debe estar declarada y rellenar con valores, por lo que util_fil y util_col deben ser > 0.
 * @post Al final de la ejecución, la matriz estará ordenada.
 */
void ordenarMatrizAlfabeticamente(char m[][DIM_COL], int util_fil, int util_col){
   int f,c,i,j,menor;
   cout << "\nEsta es la matriz ordenada";

    for (f=0; f<util_fil; f++){
        for (c=0; c<util_col; c++){
            for (i=0; i<util_fil; i++){
                for (j=0; j<util_col; j++){
                    if (m[f][c]<m[i][j]){
                        menor=m[f][c];
                        m[f][c]=m[i][j];
                        m[i][j]=menor;
                    }
                }
            } 
        }
    }    
}

int main(){
    char mimatriz[DIM_FIL][DIM_COL]; //declaro la matriz
    int util_fil = 0;
    int util_col = 0;

    
    cout << "Bienvenido a mi programa para hacer cosas sobre Matrices..." << endl;
    rellenarMatrizUsuario(mimatriz, util_fil, util_col);
    imprimeMatriz(mimatriz, util_fil, util_col); //OJO CON EL ORDEN A LA HORA DE PASAR LOS PARÁMETROS
    buscarElementoenMatriz(mimatriz, util_fil,util_col);
    ordenarMatrizAlfabeticamente(mimatriz,util_fil,util_col);
    imprimeMatriz(mimatriz, util_fil, util_col);
    
    return 0;
}
