#include <iostream>
#include <stdlib.h>

using namespace std;

class Polinomio{
	private:
		float *coef;
		int grado;
		int max_grado;
	public:
		//constructores 
		Polinomio();
		//constructor que crea un espacio para un polinomio con el tamaño justo de grado indicado
		Polinomio(int max_g);
		//contructor por copia
		Polinomio(const Polinomio &p);
		//destructor
		~Polinomio();
		//sets
		void setGrado(int grado);
		void setMaxGrado(int max_grado);
		void setCoeficiente2(int i, float nuevo_coef);
		void setCoeficiente(int i, float nuevo_coef);
		//gets
		int getGrado()const;
		int getMaxGrado()const;
		float getCoeficiente(int i)const;
		//método de impresión
		void print();
		//método sumar
		void sumaPolinomios2(Polinomio &p1, Polinomio &p2);
		Polinomio sumaPolinomios(Polinomio &p1);
		void sumarPolinomios3(Polinomio &p);
		Polinomio operator+( const Polinomio &pol) const;
		//metodo operador =
		Polinomio& operator=(const Polinomio &p);
		//operator <<
		friend ostream& operator<<(ostream &flujo, const Polinomio &p); //clase amiga
		//operator >>
		friend istream& operator>>(istream &flujo, Polinomio &p); //clase amiga
		//operator []
		const float& operator[](int i) const;
};
	//prototipos de clases externas
//ostream& operator<<(ostream &flujo, const Polinomio &p);

//definicion de clases
void Polinomio::setGrado(int grado){
	this->grado=grado;// el this es un puntero al objeto
} 
void Polinomio::setMaxGrado(int max_grado){
	this->max_grado=max_grado;
}
int Polinomio::getGrado()const {
	return grado;
}
int Polinomio::getMaxGrado()const {
 	return max_grado;
 }
float Polinomio::getCoeficiente(int i)const{
	return coef[i];
}

Polinomio::Polinomio(){ //al constructor y destructor no se le pone void delante
	max_grado=5;
	//resercva de memoria del vector de coeficientes
	coef= new float[max_grado+1];
		if (coef==0){
			cerr <<"No hay memoria suficiente.Abortamos la ejecución del programa" << endl;
		exit (-1);
		}
	//inicializacion del vector de coeficientes
	for (int i=0; i<max_grado+1; i++)
		coef[i]=0.0;
	
	grado=-1; //se inicia a -1 por cosas de los polinomios no te lies ahora
	
	cout << "debug: llamada al constructor" << endl;
}

Polinomio::Polinomio(int max_g){
	if (max_g==0){
		cerr << "se abortará la ejecucion"<<endl;
		exit (-1);
	}
	max_grado=max_g;
	grado=0;
	coef=new float[max_grado+1];
	if (coef==0){
		cerr <<"No hay memoria suficiente.Abortamos la ejecución del programa" << endl;
		exit (-1);
	}
	
	for (int i=0; i<max_grado+1; i++)
		coef[i]=0.0;
	grado=-1; 
	
	cout << "debug: llamada al constructor por parametros" << endl;
}

Polinomio::Polinomio(const Polinomio &p){
	this->max_grado=p.getMaxGrado();
	this->grado=p.getGrado();
	this->coef= new float[this->max_grado+1];
	if (coef==0){
		cerr <<"No hay memoria suficiente.Abortamos la ejecución del programa" << endl;
		exit (-1);
		}
	for(int i=0; i<this->max_grado; i++)
		coef[i]=p.coef[i];
	grado=-1;
	cout << "llamada al constructor por copia" << endl;
}

Polinomio::~Polinomio(){
	delete [] coef;
	coef=0;
	grado=0;
	max_grado=0;

	cout << "debug: llamada al destructor" << endl;
}

void Polinomio::print(){
	cout << "El grado actual de mi Polinomio es: " << grado << endl;
	cout << "El grado máximo de mi Polinomio es: " << max_grado << endl;
	cout << "Mi puntero al vector de coeficientes es: " << coef << endl;
	cout << "p(x)= ";

	for (int i=grado; i>=0; i--){
		cout << coef[i] << "x^" << i << " + ";
	}
	cout << endl;
}

void Polinomio::setCoeficiente(int i, float nuevo_coef){
	if(i>=0){ //si el indice del coeficiente es valido
		if(i>max_grado){ //si necesitamos mas espacio
			float *auxiliar;
			auxiliar=new float[i+1]; // Reservamos nueva memoria
			for (int j=0; j<=grado; ++j)// Copiamos coeficientes a nueva memoria
				auxiliar[j]=coef[j];
			delete[] coef; //liberamos la memoria antigua
			coef=auxiliar; //reasignamos el puntero de coeficientes
			for (int j=grado+1; j<=i; ++j) //ponemos a cero el resto de los nuevos coeficientes
				coef[j]=0.0;
			max_grado=i; //asignamos el nuevo maximo grado de este polinomio
		}
		coef[i]=nuevo_coef; //asignamos el nuevo coeficiente

		//actualizamos el grado
		if(nuevo_coef!=0.0 && i>grado)//si el coeficiente no es 0 y el indice del coeficiente es mayor al antiguo
			grado=i; //lo actualizamos al valor i
		else
			if(nuevo_coef==0.0 && i==grado)	//si el coeficiente es 0.0 y el indice del coeficiente es igual al grado
			while(coef[grado]==0.0 && grado>0) //actualizamos el grado con el primer termino cuyo coeficiente no sea cero
				grado--;	
	}

}
/*
void Polinomio::setCoeficiente2(int i, float nuevo_coef){
	if(i>=0){
		if(i<grado)
			coef[i]=nuevo_coef;
		if(i>=grado){
			if(i>grado){
				if(i<=max_grado){
					coef[i]=nuevo_coef;
					grado=i;
				}else{
				float *auxiliar;
				auxiliar=new float[i+1]; // Reservamos nueva memoria
				for (int j=0; j<=grado; ++j)// Copiamos coeficientes a nueva memoria
					auxiliar[j]=coef[j];
				delete[] coef; //liberamos la memoria antigua
				coef=auxiliar; //reasignamos el puntero de coeficientes
				auxiliar=0;
			    coef[i] = nuevo_coef;
	            grado=i;
	            max_grado = i+1;
				}
			}
		}
		if(i==grado){
			coef[i]=0;
			for(int j=grado-1; j>=0; j--)
				if(coef[j]=!0)
					grado=j;
		}
	}
}
*/
/*
Polinomio Polinomio::sumaPolinomios2(Polinomio p1, Polinomio p2){
	cout << "entra" << endl;
	Polinomio p3;

	if(p1.grado>=p2.grado){
		p3.grado=p1.grado;
		p2.grado=p1.grado;
	}
	else{
		p3.grado=p2.grado;
		p1.grado=p2.grado;
	}

	for(int i=0; i<=p3.grado; i++){
		if((p1.coef[i]>0) && (p2.coef[i]>0))
			p3.coef[i]=p1.coef[i]+p2.coef[i];
		if((p1.coef[i]>0) && (p2.coef[i]==0))
			p3.coef[i]=p1.coef[i];
		else
			p2.coef[i];
		if((p1.coef[i]==0) && (p2.coef[i]==0))
			p3.coef[i]=0;
	}
	return p3;
}
*/
void Polinomio::sumaPolinomios2(Polinomio &p1, Polinomio &p2){
	int nuevo_grado;
	int nuevo_grado_mas_grande;
	bool grande_p1=false;

	if (p1.getGrado()>=p2.getGrado()){
		nuevo_grado_mas_grande=p1.getGrado();
		grande_p1=true;
	}
	else{
		nuevo_grado_mas_grande=p2.getGrado();
		grande_p1=false;
	}

	//aumentar el tamaño del vector si fuese necesario y no hace falta copiar su contenido puesto que se va a pisar
	if (this->getGrado()<nuevo_grado_mas_grande){
		float *auxiliar= new float[nuevo_grado_mas_grande + 1];
	    if (auxiliar==0){
        	cerr << "Error en la reserva de memoria del Polinomio. Se abortará la ejecución!" << endl;
            exit(-1);
        }
        delete []coef;
        this->setMaxGrado(nuevo_grado_mas_grande);//max_grado = nuevo_grado_mas_grande
        coef = auxiliar;
    }


	//copio el vector mas grande
	if(grande_p1==true){
		for (int i=0; i<nuevo_grado_mas_grande; i++)
			this->setCoeficiente(i,p1.getCoeficiente(i)+p2.getCoeficiente(i));

	}

	//copio al vector mas grande y sumo el mas pequeño
	else{
		for (int i=0; i<=nuevo_grado_mas_grande; i++)
			this->setCoeficiente(i,p2.getCoeficiente(i) + p1.getCoeficiente(i));		
	}
}

void Polinomio::sumarPolinomios3(Polinomio &p){
	int nuevo_grado_mas_grande;

	if (this->getGrado()>=p.getGrado()){
		nuevo_grado_mas_grande=this->getGrado();
		for (int i=0; i<=nuevo_grado_mas_grande; i++)
			this->setCoeficiente(i,this->getCoeficiente(i)+ p.getCoeficiente(i));
	}
	else{
		nuevo_grado_mas_grande=p.getGrado();
		this->grado=p.getGrado();
		for (int i=0; i<=nuevo_grado_mas_grande; i++)
			this->setCoeficiente(i,p.getCoeficiente(i)+this->getCoeficiente(i));	
	}
}

Polinomio Polinomio::sumaPolinomios(Polinomio &pol){
	int max_g;

	if(this->getGrado()>pol.getGrado())
		max_g=this->getGrado();
	else
		max_g=pol.getGrado();
	
	Polinomio res(max_g);//invoco al constructor por parametros
	for(int i=0; i<=max_g; i++){
		res.setCoeficiente(i,this->getCoeficiente(i)+pol.getCoeficiente(i));
	}
	return res;
}
Polinomio Polinomio::operator+(const Polinomio &pol)const{
	int max_g;

	if(this->getGrado()>pol.getGrado())
		max_g=this->getGrado();
	else
		max_g=pol.getGrado();
	
	Polinomio res(max_g);//invoco al constructor por parametros
	for(int i=0; i<=max_g; i++){
		res.setCoeficiente(i,this->getCoeficiente(i)+pol.getCoeficiente(i));
	}
	return res;
}

Polinomio& Polinomio::operator=(const Polinomio &p){
	if(&p!=this){
		delete [] this->coef;
		this->max_grado=p.getMaxGrado();
		this->grado=p.getGrado();
		this->coef= new float[this->max_grado+1];
		if (coef==0){
			cerr <<"No hay memoria suficiente.Abortamos la ejecución del programa" << endl;
			exit (-1);
			}
		for(int i=0; i<=this->max_grado; i++)
			this->coef[i]=p.coef[i];
	}
	return *this;
}

ostream& operator<<(ostream &flujo, const Polinomio &p){
	flujo << "El grado actual de mi Polinomio es: " << p.getGrado() << endl;
	flujo << "El grado máximo de mi Polinomio es: " << p.getMaxGrado() << endl;
	flujo << "Mi puntero al vector de coeficientes es: "<< p.coef << endl;
	flujo << "p(x)= ";

	for (int i=p.getGrado(); i>=0; i--)
		flujo << p.getCoeficiente(i) << "x^" << i << " + ";
	
	flujo << endl;
}

istream& operator>>(istream &flujo, Polinomio &p){
	int g;
	float d;

	do{
		flujo >>d>>g;
		if(g>=0)
			p.setCoeficiente(g,d);

	}while(g>=0);

}

const float& Polinomio::operator[](int i) const{
	if((i>=0) && (i<=grado))
		return coef[i];
	else
		cout << "El grado es mas grande o el indice es negativo" <<endl;
}


int main (){
	Polinomio p1, p2, p3,p4,p5;
	//p.setCoeficiente2(6,2.3);
	//p.setCoeficiente2(2,4.8);
	//p1.setCoeficiente2(5,4.9);

	p2.setCoeficiente(3,5.1);
	p2.setCoeficiente(5,4.4);
	p2.setCoeficiente(8,2.2);
	p1.setCoeficiente(7,1.6);
	p1.setCoeficiente(4,4.8);
	p1.setCoeficiente(2,1.2);
	//p.setGrado(5);
	//p.setMaxGrado(10);
	p2.print();
	p1.print();

	//suma de polinomios
	cout << endl;
	cout << "esta es la suma de los polinomios  p3 = p1.sumar(p2)" << endl;
	p3=p1.sumaPolinomios(p2);
	p3.print();

	cout << endl;
	cout << "esta es la suma de los polinomios p3.sumar2(p1,p2)" << endl;
	p3.sumaPolinomios2(p1,p2);
	p3.print();

	cout << endl;
	cout << "esta es la suma de los polinomios  p1.sumar3(p2)" << endl;
	p1.sumarPolinomios3(p2);
	p1.print();

	cout << endl;
	cout << "esta es la suma de los polinomios con sobrecarga como función interna" << endl;
	p4=p1+p2;
	p4.print();

	cout << endl;
	cout << "esta es la asignación con la sobrecarga de operator =" << endl;
	p5=p2;
	p5.print();

	cout << endl;
	cout << "esta es la sobrecarga del operator <<" << endl;
	cout << p3;

	cout << endl;
	cout <<"esta es la sobrecarga del operator >>" << endl;
	cout <<"introduce polinomio coeficiente grado con 0 -1 para terminar: ";
	cin >> p1;
	cout <<"Polinomio=" <<p1;

	cout <<endl;
	cout <<"esta es la sobrecarga del operator []" <<endl;
	cout << "introuce la posición: ";
	int r;
	cin >>r;
	cout << p4[r] << endl;

}