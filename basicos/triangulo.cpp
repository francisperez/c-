#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Punto2d{
	private:
		double x;
		double y;

	public:
		//constructores
		Punto2d(); // por defecto
		//destrunctor
		~Punto2d();
		//get
		double getX();
		double getY();
		//set
		void setX(double x);
		void setY(double y);
		void printPunto();
};

Punto2d::Punto2d(){
	x=0.0;
	y=0.0;
}
Punto2d::~Punto2d(){
}
double Punto2d::getX(){
	return x;
}
double Punto2d::getY(){
	return y;
}
void Punto2d::setX(double x){
	this->x=x;
}
void Punto2d::setY(double y){
	this->y=y;
}
void Punto2d::printPunto(){
	cout << "x=" <<getX() << ", y=" << getY()<<endl;
}


class Triangulo2d{
	private:
		Punto2d p1;
		Punto2d p2;
		Punto2d p3;
		bool EsValido();
		string TipoTriangulo();
	public:
		//contructores
		Triangulo2d(); // por defecto
		//destructores
		~Triangulo2d();
		//get
		Punto2d getP1();
		Punto2d getP2();
		Punto2d getP3();
		//set
		void setP1(Punto2d p1);
		void setP2(Punto2d p2);
		void setP3(Punto2d p3);
		//imprimir
		void printTriangulo();
};

Triangulo2d::Triangulo2d(){}
Triangulo2d::~Triangulo2d(){}
Punto2d Triangulo2d::getP1(){
	return p1;
}
Punto2d Triangulo2d::getP2(){
	return p2;
}
Punto2d Triangulo2d::getP3(){
	return p3;
}
void Triangulo2d::setP1(Punto2d p1){
	this->p1=p1;
}
void Triangulo2d::setP2(Punto2d p2){
	this->p2=p2;
}
void Triangulo2d::setP3(Punto2d p3){
	this->p3=p3;
}
void Triangulo2d::printTriangulo(){
	string tipo;
	tipo=TipoTriangulo();
	cout << "p1---";p1.printPunto();
	cout << "p2---";p2.printPunto();
	cout << "p3---";p3.printPunto();
	cout <<tipo<<endl;
}
bool Triangulo2d::EsValido(){
	if ((p1.getX()==p2.getX())&&(p1.getX()==p3.getX())&&(p2.getX()==p3.getX()))
		return false;
	else
		return true;

}
string Triangulo2d::TipoTriangulo(){
	bool valido;
	double d1_d2, d1_d3, d2_d3; //distancia de cada punto con los otros dos puntos
	double dif_x1, dif_x2, dif_x3, dif_y1, dif_y2, dif_y3;
	//p1 con p2
	dif_x1=p2.getX()-p1.getX();
	dif_y1=p2.getY()-p1.getY();
	d1_d2=sqrt(pow(dif_x1,2) + pow(dif_y1,2));

	//p1 con p3
	dif_x2=p1.getX()-p3.getX();
	dif_y2=p1.getY()-p3.getY();
	d1_d3=sqrt(pow(dif_x2,2) + pow(dif_y2,2));
		
	//p2 con p3
	dif_x3=p3.getX()-p2.getX();
	dif_y3=p3.getY()-p2.getY();
	d2_d3=sqrt(pow(dif_x3,2) + pow(dif_y3,2));
	
	valido=EsValido();
	if(valido==true){
		if ((d1_d2==d1_d3)&&(d1_d2==d2_d3)&&(d1_d3==d2_d3))
			return "Es un triangulo equilatero";
		if ((d1_d2!=d1_d3)&&(d1_d2!=d2_d3)&&(d1_d3!=d2_d3))
			return "Es un triangulo escaleno";
		if ((d1_d2==d1_d3)!=(d2_d3) || (d1_d2==d2_d3)!=(d1_d3) || (d2_d3==d1_d3)!=(d1_d2))
			return "Es un triangulo isosceles";
	}
	else
		return "no es un triangulo válido";
}


int main(){
	Triangulo2d nuevo;
	Punto2d uno,dos,tres;
	
	uno.setX(1);
	uno.setY(0);
	dos.setX(-2);
	dos.setY(2);
	tres.setX(0);
	tres.setY(5);
	nuevo.setP1(uno);
	nuevo.setP2(dos);
	nuevo.setP3(tres);
	nuevo.printTriangulo();



}