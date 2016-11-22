//
//  vectordeestructuras.cpp
//  
//
//  Created by Jaime Matas Bustos on 16/02/15.
//
//

#include <iostream>
#include <cstring>
#include <stdlib.h>

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

struct Clase{
    Alumno dam1[21];
    int util_dam1;
};

/**
 * DECLARACIÓN E IMPLEMENTACIÓN DE LOS MÓDULOS ASOCIADOS A LA ESTRUCTURA ALUMNO
 */

/**
 * @brief Este modulo asigna a las variables de la estructura Alummno que le pasemos, los demás parámetros
 * @param string nombre es el valor que se le asignara a la variable nombre de la estructura alumno que le pasemos al modulo (E)
 * @param string apellido1 es el valor que se le asignara a la variable apellido1 de la estructura alumno que le pasemos al modulo (E)
 * @param string apellido2 es el valor que se le asignara a la variable apellido2 de la estructura alumno que le pasemos al modulo (E)
 * @param string DNI es el valor que se le asignara a la variable DNI de la estructura alumno que le pasemos al modulo (E)
 * @param int edad es el valor que se le asignara a la variable edad de la estructura alumno que le pasemos al modulo (E)
 * @param double notas[] es el valor que se le asignara a la variable notas[] de la estructura alumno que le pasemos al modulo (E)
 * @param string nombreasignaturas[] es el valor que se le asignara a la variable nombreasignaturas[] de la estructura alumno que le pasemos al modulo (E)
 * @param int util es el valor que se le asignara a la variable util de la estructura alumno que le pasemos al modulo (E)
 * @param Alumno &student la estructura alumno que le pasemos al modulo (E/S)
 * @pre Las variables que le pasemos al modulo tienen que ser del mismo tipo que las que vamos a modificar
 * @post La variable de tipo Alumno que pasemos, quedará ahora modificada con los nuevos valores
 * @version 1.0
 */
void inicializarAlumno(string nombre, string apellido1, string apellido2, string DNI, int edad, double notas[], string nombresasignaturas[], int util, Alumno *student){
    
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

///GETS///

/**
 * @brief Este múdulo devuelve el valor devariable nombre de la estructura Alumno que le pasemos
 * @param const Alumno &student Variable de la que nos devolverá el dato (E)
 * @version 1.0
 */
string getNombre(const Alumno *student){
    return student->nombre;
}

/**
 * @brief Este múdulo devuelelve el valor de la variable apellido1 de la estructura Alumno que le pasemos
 * @param const Alumno &student Variable de la que nos devolverá el dato (E)
 * @version 1.0
 */
string getApellido1(const Alumno *student){
    return student->apellido1;
}

/**
 * @brief Este múdulo devuelelve el valor de la variable apellido2 de la estructura Alumno que le pasemos
 * @param const Alumno &student Variable de la que nos devolverá el dato (E)
 * @version 1.0
 */
string getApellido2(const Alumno *student){
    return student->apellido2;
}

/**
 * @brief Este múdulo devuelelve el valor de la variable dni de la estructura Alumno que le pasemos
 * @param const Alumno &student Variable de la que nos devolverá el dato (E)
 * @version 1.0
 */
string getDNI(const Alumno *student){
    return student->DNI;
}

/**
 * @brief Este múdulo devuelelve el valor de la variable edad de la estructura Alumno que le pasemos
 * @param const Alumno &student Variable de la que nos devolverá el dato (E)
 * @version 1.0
 */
int getEdad(const Alumno *student){
    return student->edad;
}

/**
 * @brief Este múdulo devuelelve el valor de de la posicon que le pasemos de la variable nombreasignaturas[] de la estructura Alumno que le pasemos
 * @param const Alumno &student Variable de la que nos devolverá el dato (E)
 * @param int posicion Variable en la que indicaremos qúe posicion del vector queremos obtener (E)
 * @version 1.0
 */
string getNombreAsignatura(const Alumno *student, int posicion){
    return student->nombreasignaturas[posicion];
}

/**
 * @brief Este múdulo devuelelve el valor de de la posicon que le pasemos de la variable notas[] de la estructura Alumno que le pasemos
 * @param const Alumno &student Variable de la que nos devolverá el dato (E)
 * @param int posicion Variable en la que indicaremos qúe posicion del vector queremos obtener (E)
 * @version 1.0
 */
double getNotaAsignatura(const Alumno *student, int posicion){
    return student->notas[posicion];
}

/**
 * @brief Este múdulo devuelelve el valor de la variable util de la estructura Alumno que le pasemos
 * @param const Alumno &student Variable de la que nos devolverá el dato (E)
 * @version 1.0
 */
int getUtiles(const Alumno *student){
    return student->util;
}

//SETS///

/**
 * @brief Este múdulo asigna el valor que le pasemos a la variable nombre de  la estructura Alumno que le pasemos
 * @param Alumno &student Variable en la que guardaremos el dato (E/S)
 * @param string nombre Variable que asignaremos a la variable en la estructura (E/S)
 * @version 1.0
 */
void setNombre(Alumno *student, string nombre){
    student->nombre = nombre;
}


/**
 * @brief Este múdulo asigna el valor que le pasemos a la variable apellido1 de  la estructura Alumno que le pasemos
 * @param Alumno &student Variable en la que guardaremos el dato (E/S)
 * @param string apellido1 Variable que asignaremos a la variable en la estructura (E/S)
 * @version 1.0
 */
void setApellido1(Alumno *student, string apellido1){
    student->apellido1 = apellido1;
}

/**
 * @brief Este múdulo asigna el valor que le pasemos a la variable apellido2 de  la estructura Alumno que le pasemos
 * @param Alumno &student Variable en la que guardaremos el dato (E/S)
 * @param string apellido2 Variable que asignaremos a la variable en la estructura (E/S)
 * @version 1.0
 */
void setApellido2(Alumno *student, string apellido2){
    student->apellido2 = apellido2;
}

/**
 * @brief Este múdulo asigna el valor que le pasemos a la variable DNI de  la estructura Alumno que le pasemos
 * @param Alumno &student Variable en la que guardaremos el dato (E/S)
 * @param string DNI Variable que asignaremos a la variable en la estructura (E/S)
 * @version 1.0
 */
void setDNI(Alumno *student, string DNI){
    student->DNI = DNI;
}

/**
 * @brief Este múdulo asigna el valor que le pasemos a la variable edad de  la estructura Alumno que le pasemos
 * @param Alumno &student Variable en la que guardaremos el dato (E/S)
 * @param int edad Variable que asignaremos a la variable en la estructura (E/S)
 * @version 1.0
 */
void setEdad(Alumno *student, int edad){
    student->edad = edad;
}

/**
 * @brief Este múdulo asigna el valor que le pasemos a la variable util de  la estructura Alumno que le pasemos
 * @param Alumno &student Variable en la que guardaremos el dato (E/S)
 * @param int util Variable que asignaremos a la variable en la estructura (E/S)
 * @version 1.0
 */
void setUtiles(Alumno *student, int util){
    student->util = util;
}

/**
 * @brief Este múdulo asigna el vector con el nombre de las asignaturas que le pasemos al de la estructura Alumno que le pasemos
 * @param Alumno &student Variable en la que guardaremos el vector (E/S)
 * @param const string nombreasignaturas[] Vector del que copiaremos el nombre de las asignaturas (E)
 * @version 1.0
 */
void setNombreAsignaturas(Alumno *student, const string nombreasignaturas[]){
    
    for (int i=0; i<getUtiles(student);i++)
        student->nombreasignaturas[i]=nombreasignaturas[i];

}

/**
 * @brief Este múdulo asigna el vector con las notas que le pasemos al de la estructura Alumno que le pasemos
 * @param Alumno &student Variable en la que guardaremos el vector (E/S)
 * @param const double notas[] Vector del que copiaremos las notas de las asignaturas (E)
 * @version 1.0
 */
void setNotas(Alumno *student, const double notas[]){
    
    for (int i=0; i<getUtiles(student);i++)
        student->notas[i]=notas[i];

}

/**
 * @brief Este múdulo imprime por pantalla el contenido de la estructura Alumno que le pasemos
 * @param const Alumno &student Estructura que imprimiremos (E)
 * @version 1.0
 */
void imprimirAlumno(const Alumno *student){
    //Imprimo sus datos básicos
    cout << "DNI:" << getDNI(student) << endl;
    cout << "Apellido1: " << getApellido1(student) << ", " << getNombre(student) << endl;
    cout << "Calificaciones: " << endl;
    //Imprimo sus calificaciones
    for (int i=0; i < getUtiles(student); i++)
        cout << "\t" << getNombreAsignatura(student, i) << ": " << getNotaAsignatura(student,i) << endl;
}

/**
 * @brief Este múdulo pide al usuario el nombre de las asignaturas, y las va asignando en el vector que le pasemos
 * @param string asignaturas[] Vector en el que guardaremos el nombre de las asignaturas (E/S)
 * @post Al finalizar el modulo tendremos el vector con las asignaturas, y el util del vector por return
 * @version 1.0
 */
int modificaAsignaturas(string asignaturas[]){
    int util;
    string nombre; 

    do{
        cout << endl  << "Introduzca el numero de asignaturas: ";
        cin >> util;
    }while(util<0 || util>6);

    cout << "Vamos a almacenar el nombre de " << util << " asignaturas." << endl;
    for(int i=0;i<util;i++){
        cout << "Asignatura [" << i << "] :";
        cin >> nombre;
        asignaturas[i]=nombre;
    }

    cout << "Hemos acabado, gracias" << endl;

    return util;
}

/**
 * @brief Este múdulo pide al usuario la nota del alumno para cada asignatura, y las va asignando en el vector que le pasemos
 * pre El Alumno student debe terner los nombres de las asignaturas dentro de su vector
 * @param double notas[] Vector en el que guardaremos el nombre de las asignaturas (E/S)
 * @param  const Alumno &student Alumno del que leeremos las utiles y las asignaturas (E)
 * @version 1.0
 */
void modificaNotas(double notas[], const Alumno *student){
    
    double nota;

    for(int i=0;i<getUtiles(student);i++){
        cout << "Introduzca a nota de " << student->nombreasignaturas[i]  << " del alumno " << student->nombre << " " << student->apellido1 << " " << student->apellido2 << ": " << endl;
        cin >> nota;
        notas[i]=nota;
    }

    cout << "Hemos acabado, gracias" << endl;
}

/**
 * @brief Este múdulo devuelve la media de las notas del alumno que le pasemos por parametro
 * @param const Alumno &student Estructura de la que calcularemos la media (E)
 * @version 1.0
 */
 double mediaNotas(const Alumno *student){
    double media=0;


    for (int i=0; i < getUtiles(student); i++){
        media+=student->notas[i];
    }

    media=media/getUtiles(student);

    return media;
 }

/**
 * @brief Este múdulo asigna el valor que le pasemos a la variable util de  la estructura Clase que le pasemos
 * @param Clase &clase Variable en la que guardaremos el dato (E/S)
 * @param int util Variable que asignaremos a la variable en la estructura (E/S)
 * @version 1.0
 */
void setUtilClase(Clase *clase, int util){
    clase->util_dam1=util;
}

/**
 * @brief Este múdulo devuelelve el valor de la variable util de la estructura Clase que le pasemos
 * @param const Clase &clase Variable de la que nos devolverá el dato (E)
 * @version 1.0
 */
int getUtilClase(const Clase *clase){
    return clase->util_dam1;
}

/**
 * @brief Este modulo añade una estructura alumno a la siguiente posicion de vector de la estructura clase
 * @param Clase &clase Estructura donde guardaremos el alumno (E/S)
 * @param Alumno student Estructura que queremos meter en la estructura clase (E)
 */
 void insertaAlumno(Clase *clase, Alumno *student){
    clase->dam1[getUtilClase(clase)] = *student;
    setUtilClase(clase,getUtilClase(clase)+1);
 }

/**
 * @brief Este modulo devuelve la posción del vector en la que se encuentra el alumno que buscamos. Si no existe, devuelve -1
 * @brief const Clase &clase Estructura donde buscaremos (E)
 * @brief const string &criterio Criterio de busqueda (E)
 */
 int buscaAlumno(const Clase *clase, const string &criterio){
    int posicon=-1;

    for (int i=0; i<getUtilClase(clase); i++){
        if (clase->dam1[i].DNI==criterio)
            posicon=i;
    }

    return posicon;
 }

 /**
 * @brief Este modulo aplica los valores que le pasemos, al alumno que coincida con el dni
 * @param string nombre es el valor que se le asignara a la variable nombre de la estructura alumno que le pasemos al modulo (E)
 * @param string apellido1 es el valor que se le asignara a la variable apellido1 de la estructura alumno que le pasemos al modulo (E)
 * @param string apellido2 es el valor que se le asignara a la variable apellido2 de la estructura alumno que le pasemos al modulo (E)
 * @param string DNI es el valor que se le asignara a la variable DNI de la estructura alumno que le pasemos al modulo (E)
 * @param int edad es el valor que se le asignara a la variable edad de la estructura alumno que le pasemos al modulo (E)
 * @param double notas[] es el valor que se le asignara a la variable notas[] de la estructura alumno que le pasemos al modulo (E)
 * @param string nombreasignaturas[] es el valor que se le asignara a la variable nombreasignaturas[] de la estructura alumno que le pasemos al modulo (E)
 * @param int util es el valor que se le asignara a la variable util de la estructura alumno que le pasemos al modulo (E)
 * @param string criterio Criterio de busqueda para saber qué alumno vamos a modificar
* @param Clase &clase Clase que contiene el alumno que vamos a modificar
 * @pre Las variables que le pasemos al modulo tienen que ser del mismo tipo que las que vamos a modificar
 * @post La variable de tipo Alumno que pasemos, quedará ahora modificada con los nuevos valores
 * @version 1.0
 */
void modificaAlumno(string nombre, string apellido1, string apellido2, string DNI, int edad, double notas[], string nombresasignaturas[], int util, string criterio, Clase *clase){
    if(buscaAlumno(clase,criterio)!=-1){

        int alumno;
        alumno=buscaAlumno(clase,criterio);

        clase->dam1[alumno].nombre = nombre;
        clase->dam1[alumno].apellido1 = apellido1;
        clase->dam1[alumno].apellido2 = apellido2;
        clase->dam1[alumno].DNI = DNI;
        clase->dam1[alumno].edad = edad;
        clase->dam1[alumno].util = util;
        
        for(int i=0; i <getUtiles(&(clase->dam1[alumno])); i++){
            clase->dam1[alumno].notas[i] = notas[i];
            clase->dam1[alumno].nombreasignaturas[i] = nombresasignaturas[i];
        }
    }
}


/**
 * @brief Este modulo elimina del vector de la clase el alumno cuyo dni coincida con el criterio que le pasemos
 * @param Clase &clase Estructura de donde eliminaremos el alumno
 * @param string criterio Criterio para buscar al alumno
 */
void eliminaAlumno(Clase *clase, string criterio){

    if(buscaAlumno(clase,criterio)!=-1){

            int alumno;
            alumno=buscaAlumno(clase,criterio);
            
            for(int i=alumno+1; i <getUtilClase(clase); i++){
                   clase->dam1[i-1]=clase->dam1[i];
            }

            setUtilClase(clase,getUtilClase(clase)-1);
    }
}

/**
 * Programa de ejemplo de utilización del TIPO DE DATO ALUMNO
 */
int main(){
    Alumno *nestor, *alumno1, *alumno2, *alumno3;
    Clase *clase1DAM;
    
    string nombreasignaturas[6] = {"PROG", "BD", "SI", "LM", "ED", "FOL"};
    double calificaciones[6] = {7.5, 3.4, 5.1, 2.7, 10.0, 1.0};
    
    //RESERVAR DINÁMICAMENTE LA MEMORIA
    nestor = new Alumno;
    alumno1 = new Alumno;
    alumno2 = new Alumno;
    alumno3 = new Alumno;
    clase1DAM = new Clase;
    if(nestor == 0 || alumno1 == 0 || alumno2 == 0 || alumno3 == 0 || clase1DAM == 0){
        cerr << "El S.O. no tiene memoria suficiente. Se abortará la ejecución." << endl;
        exit(-1);
    }
    
    
    //1º) Inicializamos un alumno
    inicializarAlumno("Nestor","Suárez","Mesa","11111111D",32,calificaciones,nombreasignaturas,6,nestor);
    cout << "El nombre del Alumno es: " << getNombre(nestor) << endl;
    //2º) Cambiamos algún valor de su estructura
    setNombre(nestor, "Pepito");
    cout << "El nuevo nombre del Alumno es: " << getNombre(nestor) << endl;
    //3º) Imprimimos el alumno
    imprimirAlumno(nestor);
    
    //Y AHORA JUGAMOS CON UN VECTOR DE ALUMNOS
    Alumno dam1[21]; //declaramos a la clase de 1º de DAM del CES Cristo Rey
    int util_dam1 = 0; //inicialmente no tiene alumnos.
    
    //TOOOOOOMA SALVAJADAAAAAAA!! ME ASIGNA TODO AUTOMÁTICAMENTE CON UNA SENTENCIA!!!!!!!!!
    dam1[0] = *nestor;
    util_dam1++;
    //SERÁ VERDAD???????
    imprimirAlumno(&dam1[0]);
    cout << "PUES RESULTA QUE ES VERDAD... HACE UN CLON DE PEPITO Y LO GUARDA EN EL VECTOR" << endl;
    setNombre(&dam1[0],"Nestor");
    imprimirAlumno(nestor);
    imprimirAlumno(&dam1[0]);
    cout << "La media del alumno es " << mediaNotas(nestor) << endl;
    //soy más chulo que un ocho!! seguro que podré imprimir directamente el alumno, sin necesidad de ningún módulo imprimir:   cout << dam1[0] << endl; ERROR EN TIEMPO DE COMPILACIÓ

/////Prueba de la estructura CLASE

    inicializarAlumno("Pepe","Tal","de Cual","11111112F",24,calificaciones,nombreasignaturas,6,alumno1);
    setUtilClase(clase1DAM,0);
    insertaAlumno(clase1DAM,alumno1);

    inicializarAlumno("Perico","de los","Palotes","11116662F",22,calificaciones,nombreasignaturas,6,alumno2);
    insertaAlumno(clase1DAM,alumno2);

    inicializarAlumno("Fran","Villegas","Yeguas","26050552Q",23,calificaciones,nombreasignaturas,6,alumno3);
    insertaAlumno(clase1DAM,alumno3);


    imprimirAlumno(&(clase1DAM->dam1[0]));
    imprimirAlumno(&(clase1DAM->dam1[1]));
    imprimirAlumno(&(clase1DAM->dam1[2]));
    cout << "Utiles en este momento: " << getUtilClase(clase1DAM) << endl;
     
    cout << "El alumno con DNI 26050552Q se encuentra en la posicion: " << buscaAlumno(clase1DAM,"26050552Q") ;
        cout << " del vector dentro de la estructura Clase" << endl;


    modificaAlumno("Francis","Villegas","Yeguas","26050552Q",23,calificaciones,nombreasignaturas,6, "26050552Q" ,clase1DAM);
    imprimirAlumno(&(clase1DAM->dam1[2]));

    eliminaAlumno(clase1DAM,"11116662F");
    imprimirAlumno(&(clase1DAM->dam1[0]));
    imprimirAlumno(&(clase1DAM->dam1[1]));
    cout << "Utiles en este momento: " << getUtilClase(clase1DAM) << endl;
    
    //LIBERAR MEMORIA UTILIZADA
    delete nestor;
    delete alumno1;
    delete alumno2;
    delete alumno3;
    delete clase1DAM;
    nestor = alumno1 = alumno2 = alumno3 = 0;
    clase1DAM = 0;

}
