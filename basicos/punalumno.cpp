//
//  vectordeestructuras.cpp
//  
//
//  Created by Jaime Matas Bustos on 16/02/15.
//
//

#include <iostream>
#include <cstring>

using namespace std;


/**
 * DEFINICIÓN DE LA ESTRUCTURA ALUMNO
 * @version 1.0
 */
struct Alumno{
    string nombre;
    string apellido1;
    string apellido2;
    string DNI;
    int edad;
    string nombreasignaturas[6];
    double notas[6];
    int util;
};

/**
 * DECLARACIÓN E IMPLEMENTACIÓN DE LOS MÓDULOS ASOCIADOS A LA ESTRUCTURA ALUMNO

 * @brief Módulo que inicia una estructura de tipo alumno.
 * @param string nombre Variable que contiene el nombre del alumno. (E)
 * @param string apellido1 Variable que contiene el apellido1 del alumno y se guardara en la variable &student. (E)
 * @param string apellido2 Variable que contiene el apellido2 del alumno y se guardara en la variable &student.. (E)
 * @param string DNI Variable que contiene el DNI del alumno y se guardara en la variable &student.. (E)
 * @param int edad Variable que contiene la edad del alumno y se guardara en la variable &student.. (E)
 * @param double notas[] Un vector de caracteres que contienen las asignaturas del alumno . (E)
 * @param string nombreasignaturas[] Un vector de numero que contienen las notas del alumno . (E)
 * @param int util Variable que contiene el número de utiles del los dos vectores que le pasamos. (E)
 * @param Alumno &student devuelve el parametro que se le pida. (S)
 * @pre La estructura tiene que estar declarada
 * @post Al final de la ejecución, la estructura estará inicializada.
 * @version 1.0
 */
void inicializarAlumno(Alumno *student, string nombre, string apellido1, string apellido2, string DNI, int edad, double *notas, string nombresasignaturas[], int util ){
    
    student->nombre = nombre;
    student->apellido1 = apellido1;
    student->apellido2 = apellido2;
    student->DNI = DNI;
    student->edad = edad;
    student->util = util;
    
    //tengo que copiar los nombres de las asignaturas y sus notas
    for(int i=0; i < student->util; i++){
        student->notas[i] = notas[i];
        student->nombreasignaturas[i] = nombresasignaturas[i];
    }
}

//sets y gets

//get
string getNombre(const Alumno *student){
    return student->nombre;
}

string getApellido1(const Alumno *student){
    return student->apellido1;
}

string getApellido2(const Alumno *student){
    return student->apellido2;
}

string getDNI(const Alumno *student){
    return student->DNI;
}

int getEdad(const Alumno *student) {
    return student->edad;
}

int getUtiles(const Alumno *student){
    return student->util;
}

string getNombreAsignatura(const Alumno *student, int posicion){
    return student->nombreasignaturas[posicion];
}

double getNota(const Alumno *student, int posicion){
    return student->notas[posicion];
}

//set
void setNombre(Alumno *student, string nombre){
    student->nombre = nombre;
}

void setApellido1(Alumno *student, string apellido1){
    student->apellido1 = apellido1;
}

void setApellido2(Alumno *student, string apellido2){
    student->apellido2 = apellido2;
}

void setDNI(Alumno *student, string DNI){
    student->DNI = DNI;
}

void setEdad(Alumno *student, int edad){
    student->edad = edad;
}

void setUtiles(Alumno *student, int util){
    student->util = util;
}

void setNombreAsignatura(Alumno *student, string nombreasignaturas, int posicion){
    student->nombreasignaturas[posicion] = nombreasignaturas[posicion];
}

void setNota(Alumno *student, double notas[], int posicion){
    student->notas[posicion] = notas[posicion];
}


/**
 * DEFINICIÓN DE LA ESTRUCTURA CLASE
 * @version 1.0
 */

struct clase1DAM{
        Alumno dam1[21];
        int util_dam1;
};

/**
 * @brief Módulo que me inicializa una variable de tipo clase.
 * @param clase1DAM &clase Variable clase en la que se guardarán los datos de entrada del módulo (E/S
 * @param Alumno dam1[] vector de tipo Alumno que quiero guardar en la variable clase.
 * @param int util_dam1 utiles del vector de tipo Alumno.
 * @post La variable clase, tendrá guardados todos los valores que le pase al módulo.
 */
void inicializarClase1DAM (clase1DAM *clase, Alumno dam1[], int util_dam1){
    clase->util_dam1=util_dam1;

    //tengo que crear todos los campos del vector clase de 1ºdam, que es de tipo de dato alumno
    for (int i=0; i<util_dam1; i++)
         clase->dam1[i] = dam1[i];
}
//set y get

//get
int getUtilesDAM1(const clase1DAM *clase){
    return clase->util_dam1;
}
Alumno getDAM1(const clase1DAM &clase, int posicion){
    return clase.dam1[posicion];
}

//set
void setUtilesDAM1(clase1DAM &clase, int util_dam1){
    clase.util_dam1 = util_dam1;
}

void setDAM1(clase1DAM &clase, Alumno dam1[], int posicion){
    clase.dam1[posicion] = dam1[posicion];
}


//-------------------------Hasta aquí definición de estructuras; de set y get--------------------------------------------------------------

/**
 * @brief Módulo que imprime los elementos de la estructura.
 * @param const Alumno &student  . (E)
 * @post Al final de la ejecución, se imprimirá por pantalla el contenido del paramentro pasado.
 */
void imprimirAlumno(const Alumno &student){
    //Imprimo sus datos básicos
    cout << "Nombre: " << getNombre(student) << endl;
    cout << "Apellido1: " << getApellido1(student) << endl; 
    cout << "Calificaciones: " << endl;
    //Imprimo sus calificaciones
    for (int i=0; i < getUtiles(student); i++)
        cout << "\t" << getNombreAsignatura(student, i) << ": " << getNota(student,i) << endl;
}

/**
 * @brief Módulo que calcula la media de un elemento  de la estructura.
 * @param const Alumno &student  . (E)
 * @post Al final de la ejecución, se retornará la media del elemento de la estructura.
 */
double calcularMedia(const Alumno &student){
    double media=0;
        for (int i=0; i < getUtiles(student); i++){
            media = media + getNota(student, i);
        }
        media = media/getUtiles(student);

    return media;
}

/**
 * @brief Módulo que recoge los datos de cada uno de los alumnos de la estructura clase
 * @param clase1DAM &clase Variable clase en la que se guardarán los datos de entrada del módulo (E)
 * @param int util_dam1 utiles del vector de tipo Alumno.
 * @post La variable clase, tendrá guardados todos los valores que le pase al módulo.
 */

void recogerDatosAlumno(clase1DAM &clase, int util_alumno){
     string apellido2;
     string apellido1;
     string nombre;
     string dni;
     string nombreasignaturas[6];
     double notas[6];
     int util_notas;
     int edad;

     for (int i = 0; i < util_alumno; ++i){
        cout << "introduce el nombre del alumno: ";
        cin >> nombre;
        cout << "introduce el apellido1 del alumno: ";
        cin >> apellido1;
        cout << "introduce el apellido2 del alumno: ";
        cin >> apellido2;
        cout << "introduce el dni del alumno: ";
        cin >> dni;
        cout << "introduce la Edad del alumno: ";
        cin >> edad;
        cout << "de cuantas notas esta matriculado: ";
        cin >> util_notas;
            for (int j =0; j < util_notas; j++){ 
                cout <<"nombre de asignatura: ";
                cin >> nombreasignaturas[j];//se guardan los nombres de las asignaturas
                cout <<"Introduce la nota: ";
                cin >> notas[j]; // se guardan el valor de las notas
            }

        inicializarAlumno(clase.dam1[i], nombre, apellido1, apellido2, dni, edad, notas, nombreasignaturas, util_notas);
     }//en clase.dam1[i] es donde se guardan los datos de los alumnos
}

/**
 * @brief Módulo que busca en la clase dam1 la posicion en la encuentra un alumno buscacandolo por su nombre
 * @param const clase1DAM &clase Variable  donde se va a buscar el nombre (E)
 * @param int util_dam1 utiles del vector de tipo Alumno.
 * @post retunn posicion, que contendrá la posicion del alumno donde se encuentra el nombre a buscar.
 */
int BuscarAlumno(const clase1DAM &clase, int util_alumno){
   
    string nombre;
    cout << "introduce el nombre del alumno que quieres buscar: ";
    cin >> nombre;


    for (int i = 0; i<util_alumno; i++){
        if (nombre==clase.dam1[i].nombre) //si el nombre introducido es igual al nombre de uno de los alumnos guardados en clase.dam1 devuelve la posicion
        return i;
    }

    
}

/**
 * Programa de ejemplo de utilización del TIPO DE DATO ALUMNO
 */
int main(){
    
     
     clase1DAM clase;

     int util_alumno;

     cout<<"Cuantos alumnos hay matriculados en clase: " << endl;
     cin >> util_alumno;
     recogerDatosAlumno(clase, util_alumno);

     //este for se utiliza para imprimir cada alumno 
     for (int i=0; i<util_alumno; i++){
        imprimirAlumno(clase.dam1[i]);
        cout << "Media: " << calcularMedia(clase.dam1[i]) << endl;
     }
     cout << "la posición del alumno es: " << BuscarAlumno(clase, util_alumno) << endl;

}