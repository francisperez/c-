/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 	/
+												     	+
+  Clase Polinomio										   	+
+ 													+
+  Created by Fran Villegas on 18/05/2015								+
+													+
/ * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Polinomio{
	private:
		float *coef;
		int grado;
		int max_grado;
	public:
		// Constructores
		Polinomio();
		// Destructor
		~Polinomio();
		// Sets
		inline void setGrado(int grado) {this->grado=grado;}
		inline void setMaxGrado(int max_grado) {this->max_grado=max_grado;}
		void setCoeficiente(int i, float nuevo_coef);
		// Gets
		inline int getGrado() const {return grado;}
		inline int getMaxGrado() const {return max_grado;}
		// Print : Para imprimir el polinomio
		void print();
		void sumaPolinomios(Polinomio poli, Polinomio poli_dos);
};
Polinomio::Polinomio(){
	max_grado=5;
	grado=-1;
	// Reserva de memoria del vector de coeficientes
	coef=new float[max_grado+1];
	if (coef==0){
		cerr << "No hay memoria suficiente. Se abortará la ejecución del programa." << endl;
		exit(-1);
	}
	// Inicialización del vector de coeficientes;
	for (int i=0; i<=max_grado;i++ ){
		coef[i]=0.0;
	}

	//cout << endl << "*********Debug: Llamada al constructor." << endl << endl;
}

Polinomio::~Polinomio(){
	//cout << endl << "*********Debug: Llamada al destructor." << endl << endl;
	delete [] coef;
}

/**
 * @brief Método de la clase Polinomio que cambia el coeficiente de un monomio.
 * @param int i Grado del monomio que voy a cambiar.
 * @param float nuevo_coef Nuevo Coeficiente que le vamos a establecer al monomio de grado i.
 * @pre El Polinomio debe estar construido (el vector de coeficientes debe estar reservado).
 * @post Se puede ver alterado el grado del Polinomio en función del estado inicial del mismo y del monomio
 *      que se esté modificando.
 */
void Polinomio::setCoeficiente(int i, float nuevo_coef){
    if (i >= 0){
        if (i <= grado){
            if(nuevo_coef != 0) //i > 0 && i <= grado && nuevo_coef != 0
                coef[i] = nuevo_coef;
            else{ // i > 0 && i <= grado && nuevo_coef == 0
                if (i != grado) //i != grado
                    coef[i] = nuevo_coef;
                else{ // i == grado
                    coef[i] = 0;
                    // Buscar en el polinomio el primer coeficiente distinto de 0
                    // porque ese será el nuevo grado de mi polinomio
                    bool encontrado = false;
                    for(int j = grado-1; (j >= 0) && (!encontrado); j--){
                        if (coef[j] != 0){
                            encontrado = true;
                            setGrado(j);
                        }
                    }
                    if (!encontrado){
                        setGrado(0);
                        cerr << "Warning: Su polinomio es p(x) = 0" << endl;
                    }
                }
            }
        }
        else{ //i > grado
            if (i <= max_grado){
                coef[i] = nuevo_coef;
                setGrado(i);
            }
            else{ // i > grado && i > max_grado
                cerr << "Debug:Se duplicará la memoria." << endl;
                // Reservo nueva memoria
                float* aux = new float[i+1];
                if (!aux){
                    cerr << "Error: El S.O. no dispone de memoria suficiente." << endl;
                    exit(-1);
                }
                // Copio los datos antiguos en la nueva memoria
                for(int j = 0; j <= grado; j++)
                    aux[j] = coef[j];
                // Borro la antigua memoria
                delete [] coef;
                // Asigno el nuevo puntero a coef
                coef = aux;
                aux = 0;
                //Ahora tranquilamente, ya tengo espacio para hacer la asignación del coeficiente
                coef[i] = nuevo_coef;
                setGrado(i);
                max_grado = i+1;
            }
        }
    
    }
    else
        cerr << "Warning: No existen monomios con grado negativo." << endl;
}

/*
static char *super[] = {"\xe2\x81\xb0", "\xc2\xb9", "\xc2\xb2",
    "\xc2\xb3", "\xe2\x81\xb4", "\xe2\x81\xb5", "\xe2\x81\xb6",
    "\xe2\x81\xb7", "\xe2\x81\xb8", "\xe2\x81\xb9"};
static char *sub[] = {"\xe2\x82\x80", "\xe2\x82\x81", "\xe2\x82\x82",
    "\xe2\x82\x83", "\xe2\x82\x84", "\xe2\x82\x85", "\xe2\x82\x86",
    "\xe2\x82\x87", "\xe2\x82\x88", "\xe2\x82\x89"};

  //  printf (super[i]);
*/
void Polinomio::print(){
	cout << "El grado actual de mi polinomio es : " << this->getGrado() << endl;
	cout << "El gradao máximo premitido para mi polinomio es: " << max_grado << endl;
	cout << "Mi puntero al verctor de coeficientes apunta a la siguente dirección de memoria: " << coef << endl;
	if(grado!=-1){
		cout << "\n\tp(x)= " ;
		for (int i=grado; i>=0; i--){
			if (i==0 && coef[i]!=0)
				cout << coef[i];
			else
				if (i==1&&coef[i]!=0)
					cout << coef[i] << "x" << " + ";
			else 
				if (coef[i]!=0)
					cout << coef[i] << "x^" << i << " + ";
		}
		cout << endl;
	}
	else{
		cout << "\n\tEl Polinomio no tiene valores. Es un polinomio vacío." << endl;
	}
}

void Polinomio::sumaPolinomios(Polinomio poli, Polinomio poli2){
	if(this->grado>poli.grado||this->grado==poli.grado){
		//resultado.setGrado(this->grado);
		for (int i=0;i<=poli.grado;i++){
			poli2.setCoeficiente(i,poli.coef[i]+this->coef[i]);
		}
		for (int i=poli.grado+1;i<=this->grado;i++){
			poli2.setCoeficiente(i,this->coef[i]);
		}
		poli2.print();
	}
	else
		if(poli.grado>this->grado){
			for (int i=0;i<=this->grado;i++){
				poli2.setCoeficiente(i,poli.coef[i]+this->coef[i]);
			}
			for (int i=this->grado+1;i<=poli.grado;i++){
				poli2.setCoeficiente(i,poli.coef[i]);
			}
			poli2.print();

		}
		else
			if (poli.grado==-1 && this->grado==-1){
				poli2=poli;
			}
			else
				if(poli.grado==-1 || this->grado==-1){
					if(poli.grado!=-1){
						poli2=poli;
					}
					else
						poli2.coef=this->coef;
						poli2.grado=this->grado;
						poli2.max_grado=this->max_grado;
				}

}


int main(){
	system("clear");
	Polinomio p;
	p.setCoeficiente(0,5);
	p.setCoeficiente(1,9.8);
	p.setCoeficiente(3,2.34);
	p.setCoeficiente(4,-6);
	p.setCoeficiente(5,12);

	p.print();

	cout << endl << "Agregamos más coeficientes al polinomio..." << endl << endl;

	p.setCoeficiente(6,17);
	p.setCoeficiente(7,1.7);

	p.print();

	cout << endl << "Ahora ponemos a 0 la posicion 7 y 3" << endl << endl;

	p.setCoeficiente(7,0);
	p.setCoeficiente(3,0);


	p.print();

	cout << endl << "Declaramos un nuevo polinomio, y lo sumamos al que ya tenemos." << endl << endl;
	Polinomio p_dos, p_tres;
	p_dos.setCoeficiente(4,4);
	p_dos.setCoeficiente(2,7.12);
	p_dos.setCoeficiente(5,-6);
	p_dos.print();
	cout << endl << "El resultado de la suma es: " << endl << endl;
	p.sumaPolinomios(p_dos,p_tres);
	//p_tres.print();




}


