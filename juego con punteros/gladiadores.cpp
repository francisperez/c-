#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;


//--------------------------------------CLASE PERSONAJE-------------------------------------------------------------
class Personaje{
	protected:
		int fuerza;
		int destreza;
		int resistencia;
		int p_vida;
		double precio;
		string nombre;
		string id_personaje;
		double valoracion_actual;
		bool transferible;

	public:
		//CONSTRUCTORES
		Personaje();
		Personaje(const Personaje &p);
		Personaje(int fuerza,int destreza,int resistencia,int p_vida,double precio,string nombre,string id_personaje, double valoracion_actual, bool transferible);
		//DESTRUCTOR
		virtual ~Personaje();
		//SET
		inline void setFuerza(int fuerza){this->fuerza=fuerza;};
		inline void setDestreza(int destreza){this->destreza=destreza;};
		inline void setResistencia(int resistencia){this->resistencia=resistencia;};
		inline void setPVida(int p_vida){this->p_vida=p_vida;};
		inline void setPrecio(double precio){this->precio=precio;};
		inline void setNombre(string nombre){this->nombre=nombre;};
		inline void setIDPersonaje(string id_personaje){this->id_personaje=id_personaje;};
		inline void setValoracionActual(double valoracion_actual){this->valoracion_actual=valoracion_actual;};
		inline void setTransferible(bool transferible){this->transferible=transferible;};
		//GET
		inline int getFuerza()const {return this->fuerza;};
		inline int getDestreza()const {return this->destreza;};
		inline int getResistencia()const {return this->resistencia;};
		inline int getPVida()const {return this->p_vida;};
		inline double getPrecio()const {return this->precio;};
		inline string getNombre()const {return this->nombre;};
		inline string getIDPersonaje()const {return this->id_personaje;};
		inline double getValoracionActual()const {return this->valoracion_actual;};
		inline bool getTransferible()const {return this->transferible;};
		//METODOS
		int enteroAleatorio();
		void imprimirPersonajes();
		virtual void atacar(){ cout <<"ataca"<<endl;};
		virtual void defender(){ cout <<"defiende"<<endl;};
		virtual void calcularValoracionActual(){ cout <<"ya la calculare"<<endl;};
		//SOBRECARGA DE OPERADOR <<
    	friend ostream& operator<<(ostream &flujo, const Personaje &p); //clase amiga
    	//SOBRECARGA DE OPERADOR =
    	Personaje& operator=(const Personaje &p); 
    	virtual void crearPersonaje();
};

Personaje::Personaje(){
	this->fuerza=0;
	this->destreza=0;
	this->resistencia=0;
	this->p_vida=0;
	this->precio=0.0;
	this->nombre="NULL";
	this->id_personaje="NULL";
	this->valoracion_actual=0.0;
	this->transferible=false;
}

Personaje::Personaje(const Personaje &p){
	this->fuerza=p.getFuerza();
	this->destreza=p.getDestreza();
	this->resistencia=p.getResistencia();
	this->p_vida=p.getPVida();
	this->precio=p.getPrecio();
	this->nombre=p.getNombre();
	this->id_personaje=p.getIDPersonaje();
	this->valoracion_actual=p.getValoracionActual();
	this->transferible=p.getTransferible();
}

Personaje::Personaje(int fuerza,int destreza,int resistencia,int p_vida,double precio,string nombre,string id_personaje,double valoracion_actual, bool transferible){
	this->fuerza=fuerza;
	this->destreza=destreza;
	this->resistencia=resistencia;
	this->p_vida=p_vida;
	this->precio=precio;
	this->nombre=nombre;
	this->id_personaje=id_personaje;
	this->valoracion_actual=valoracion_actual;
	this->transferible=transferible;
}

Personaje::~Personaje(){
	this->fuerza=0;
	this->destreza=0;
	this->resistencia=0;
	this->p_vida=0;
	this->precio=0.0;
	this->nombre="NULL";
	this->id_personaje="NULL";
	this->valoracion_actual=0.0;
	this->transferible=false;
}

void Personaje::imprimirPersonajes(){
    cout << "Impresión del Personaje: " << endl;
	cout << "\tNombre: " << this->nombre << endl;
	cout << "\tIdentificador: " << this->id_personaje << endl;
	cout << "\tDestreza: " << this->destreza << endl;
	cout << "\tResistencia: " << this->resistencia << endl;
	cout << "\tPuntos de Vida: " << this->p_vida << endl;
	cout << "\tPrecio: " << this->precio << endl;
	cout << "\tValoracion actual: " << this->valoracion_actual << endl;
	cout << "\tTransferible: " << this->transferible << endl;
    cout << endl;
}

int Personaje::enteroAleatorio(){

}

ostream& operator<<(ostream &flujo, const Personaje &p){
    flujo << "Impresión del Personaje: " << endl;
	flujo << "\tNombre: " << p.getNombre() << endl;
	flujo << "\tIdentificador: " <<p.getIDPersonaje() << endl;
	flujo << "\tDestreza: " <<p.getDestreza() << endl;
	flujo << "\tResistencia: " <<p.getResistencia() << endl;
	flujo << "\tPuntos de Vida: " <<p.getPVida()<< endl;
	flujo << "\tPrecio: " <<p.getPrecio() << endl;
	flujo << "\tValoracion actual: " << p.getValoracionActual() << endl;
	flujo << "\tTransferible: " << p.getTransferible() << endl;
    flujo << endl;
}

Personaje& Personaje::operator=(const Personaje &p){
	this->fuerza=p.getFuerza();
	this->destreza=p.getDestreza();
	this->resistencia=p.getResistencia();
	this->p_vida=p.getPVida();
	this->precio=p.getPrecio();
	this->nombre=p.getNombre();
	this->id_personaje=p.getIDPersonaje();
	this->valoracion_actual=p.getValoracionActual();
	this->transferible=p.getTransferible();
}
void Personaje::crearPersonaje(){
		int fuerza, destreza, vida, resistencia;
		string nombre, id;
		double precio;

		cout << "\nIntroduzca el identificador del personaje: ";
		cin >> id;this->setIDPersonaje(id);
		cout <<"\nIntroduzca el nombre del personaje: ";
		cin  >>nombre;this->setNombre(nombre);
		cout << "\nIntroduzca la fuerza del pesonaje[0-100]: ";
		cin >> fuerza;this->setFuerza(fuerza);
		cout <<"\nIntroduzca la destreza del personaje[0-100]: ";
		cin  >>destreza;this->setDestreza(destreza);
		cout << "\nIntroduzca la resistencia del personaje [0-100]: ";
		cin >> resistencia;this->setResistencia(resistencia);
		cout <<"\nIntroduzca los puntos de vida del personaje [1000-5000]: ";
		cin  >>vida;this->setPVida(vida);
		cout <<"\nIntroduzca el precio del personaje[1000-5000]: ";
		cin  >>precio;this->setPrecio(precio);
	}


class Picaro: public Personaje{
	private:
		int energia;

	public:
		//CONSTRUCTORES
		Picaro():Personaje(){this->energia=0;};
		Picaro(int fuerza,int destreza,int resistencia,int p_vida,double precio,string nombre,string id_personaje,double valoracion_actual, bool transferible):Personaje(fuerza,destreza,resistencia,p_vida,precio,nombre,id_personaje,valoracion_actual,transferible){
			this->energia=energia;};
		//DESTRUCTOR
		~Picaro(){this->energia=0;};
		//SET
		inline void setEnergia(int energia){this->energia=energia;};
		//GET
		inline int getEnergia()const {return this->energia;};
		//SOBRECARGA DE OPERADOR <<
    	friend ostream& operator<<(ostream &flujo, const Picaro &pi); 
    	//SOBRECARGA DE OPERADOR =
    	Picaro& operator=(const Picaro &pi);
    	//metodos
    	void crearPersonaje();
};

ostream& operator<<(ostream &flujo, const Picaro &pi){
    flujo << "Impresión del Personaje: " << endl;
	flujo << "\tNombre: " << pi.getNombre() << endl;
	flujo << "\tIdentificador: " <<pi.getIDPersonaje() << endl;
	flujo << "\tDestreza: " <<pi.getDestreza() << endl;
	flujo << "\tResistencia: " <<pi.getResistencia() << endl;
	flujo << "\tPuntos de Vida: " <<pi.getPVida()<< endl;
	flujo << "\tPrecio: " <<pi.getPrecio() << endl;
	flujo << "\tValoracion actual: " << pi.getValoracionActual() << endl;
	flujo << "\tTransferible: " << pi.getTransferible() << endl;
	flujo << "\tEnergia: " <<pi.getEnergia() << endl;
    flujo << endl;
}

Picaro& Picaro::operator=(const Picaro &pi){
	this->fuerza=pi.getFuerza();
	this->destreza=pi.getDestreza();
	this->resistencia=pi.getResistencia();
	this->p_vida=pi.getPVida();
	this->precio=pi.getPrecio();
	this->nombre=pi.getNombre();
	this->id_personaje=pi.getIDPersonaje();
	this->valoracion_actual=pi.getValoracionActual();
	this->transferible=pi.getTransferible();
	this->energia=pi.getEnergia();
}
void Picaro::crearPersonaje(){
		int fuerza, destreza, vida, resistencia, energia;
		string nombre, id;
		double precio;

		cout << "\nIntroduzca el identificador del personaje: ";
		cin >> id;this->setIDPersonaje(id);
		cout <<"\nIntroduzca el nombre del personaje: ";
		cin  >>nombre;this->setNombre(nombre);
		cout << "\nIntroduzca la fuerza del pesonaje[0-100]: ";
		cin >> fuerza;this->setFuerza(fuerza);
		cout <<"\nIntroduzca la destreza del personaje[0-100]: ";
		cin  >>destreza;this->setDestreza(destreza);
		cout <<"\nIntroduzca la enegia del personaje[0-100]: ";
		cin  >>energia;this->setEnergia(energia);
		cout << "\nIntroduzca la resistencia del personaje [0-100]: ";
		cin >> resistencia;this->setResistencia(resistencia);
		cout <<"\nIntroduzca los puntos de vida del personaje [1000-5000]: ";
		cin  >>vida;this->setPVida(vida);
		cout <<"\nIntroduzca el precio del personaje[1000-5000]: ";
		cin  >>precio;this->setPrecio(precio);
	}



class Guerrero: public Personaje{
	private:
		int furia;

	public:
		//CONSTRUCTORES
		Guerrero():Personaje(){this->furia=0;};
		Guerrero(int fuerza,int destreza,int resistencia,int p_vida,double precio,string nombre,string id_personaje,double valoracion_actual, bool transferible):Personaje(fuerza,destreza,resistencia,p_vida,precio,nombre,id_personaje,valoracion_actual,transferible){
			this->furia=furia;};
		//DESTRUCTOR
		~Guerrero(){this->furia=0;};
		//SET
		inline void setFuria(int furia){this->furia=furia;};
		//GET
		inline int getFuria()const {return this->furia;};
		//SOBRECARGA DE OPERADOR <<
    	friend ostream& operator<<(ostream &flujo, const Guerrero &gue); 
    	//SOBRECARGA DE OPERADOR =
    	Guerrero& operator=(const Guerrero &gue);
    	//metodos
    	void crearPersonaje();
};

ostream& operator<<(ostream &flujo, const Guerrero &gue){
    flujo << "Impresión del Personaje: " << endl;
	flujo << "\tNombre: " << gue.getNombre() << endl;
	flujo << "\tIdentificador: " <<gue.getIDPersonaje() << endl;
	flujo << "\tDestreza: " <<gue.getDestreza() << endl;
	flujo << "\tResistencia: " <<gue.getResistencia() << endl;
	flujo << "\tPuntos de Vida: " <<gue.getPVida()<< endl;
	flujo << "\tPrecio: " <<gue.getPrecio() << endl;
	flujo << "\tValoracion actual: " << gue.getValoracionActual() << endl;
	flujo << "\tTransferible: " << gue.getTransferible() << endl;
	flujo << "\tFuria: " <<gue.getFuria() << endl;
    flujo << endl;
}

Guerrero& Guerrero::operator=(const Guerrero &gue){
	this->fuerza=gue.getFuerza();
	this->destreza=gue.getDestreza();
	this->resistencia=gue.getResistencia();
	this->p_vida=gue.getPVida();
	this->precio=gue.getPrecio();
	this->nombre=gue.getNombre();
	this->id_personaje=gue.getIDPersonaje();
	this->valoracion_actual=gue.getValoracionActual();
	this->transferible=gue.getTransferible();
	this->furia=gue.getFuria();
}

void Guerrero::crearPersonaje(){
		int fuerza, destreza, vida, resistencia, furia;
		string nombre, id;
		double precio;

		cout << "\nIntroduzca el identificador del personaje: ";
		cin >> id;this->setIDPersonaje(id);
		cout <<"\nIntroduzca el nombre del personaje: ";
		cin  >>nombre;this->setNombre(nombre);
		cout << "\nIntroduzca la fuerza del pesonaje[0-100]: ";
		cin >> fuerza;this->setFuerza(fuerza);
		cout <<"\nIntroduzca la destreza del personaje[0-100]: ";
		cin  >>destreza;this->setDestreza(destreza);
		cout <<"\nIntroduzca la enegia del personaje[0-100]: ";
		cin  >>furia;this->setFuria(furia);
		cout << "\nIntroduzca la resistencia del personaje [0-100]: ";
		cin >> resistencia;this->setResistencia(resistencia);
		cout <<"\nIntroduzca los puntos de vida del personaje [1000-5000]: ";
		cin  >>vida;this->setPVida(vida);
		cout <<"\nIntroduzca el precio del personaje[1000-5000]: ";
		cin  >>precio;this->setPrecio(precio);
	}


class Mago : public Personaje{
	private:
		int mana;

	public:
		//CONSTRUCTORES
		Mago():Personaje(){this->mana=0;};
		Mago(int fuerza,int destreza,int resistencia,int p_vida,double precio,string nombre,string id_personaje,double valoracion_actual, bool transferible):Personaje(fuerza,destreza,resistencia,p_vida,precio,nombre,id_personaje,valoracion_actual,transferible){
			this->mana=mana;};
		//DESTRUCTOR
		~Mago(){this->mana=0;};
		//SET
		inline void setMana(int mana){this->mana=mana;};
		//GET
		inline int getMana()const {return this->mana;};
		//SOBRECARGA DE OPERADOR <<
    	friend ostream& operator<<(ostream &flujo, const Mago &ma);
    	//SOBRECARGA DE OPERADOR =
    	Mago& operator=(const Mago &ma);
    	//METODOS
    	void crearPersonaje();
};

ostream& operator<<(ostream &flujo, const Mago &ma){
    flujo << "Impresión del Personaje: " << endl;
	flujo << "\tNombre: " << ma.getNombre() << endl;
	flujo << "\tIdentificador: " <<ma.getIDPersonaje() << endl;
	flujo << "\tDestreza: " <<ma.getDestreza() << endl;
	flujo << "\tResistencia: " <<ma.getResistencia() << endl;
	flujo << "\tPuntos de Vida: " <<ma.getPVida()<< endl;
	flujo << "\tPrecio: " <<ma.getPrecio() << endl;
	flujo << "\tValoracion actual: " << ma.getValoracionActual() << endl;
	flujo << "\tTransferible: " << ma.getTransferible() << endl;
	flujo << "\tMana: " <<ma.getMana() << endl;
    flujo << endl;
}

Mago& Mago::operator=(const Mago &ma){
	this->fuerza=ma.getFuerza();
	this->destreza=ma.getDestreza();
	this->resistencia=ma.getResistencia();
	this->p_vida=ma.getPVida();
	this->precio=ma.getPrecio();
	this->nombre=ma.getNombre();
	this->id_personaje=ma.getIDPersonaje();
	this->valoracion_actual=ma.getValoracionActual();
	this->transferible=ma.getTransferible();
	this->mana=ma.getMana();
}

void Mago::crearPersonaje(){
		int fuerza, destreza, vida, resistencia, mana;
		string nombre, id;
		double precio;

		cout << "\nIntroduzca el identificador del personaje: ";
		cin >> id;this->setIDPersonaje(id);
		cout <<"\nIntroduzca el nombre del personaje: ";
		cin  >>nombre;this->setNombre(nombre);
		cout << "\nIntroduzca la fuerza del pesonaje[0-100]: ";
		cin >> fuerza;this->setFuerza(fuerza);
		cout <<"\nIntroduzca la destreza del personaje[0-100]: ";
		cin  >>destreza;this->setDestreza(destreza);
		cout <<"\nIntroduzca la enegia del personaje[0-100]: ";
		cin  >>mana;this->setMana(mana);
		cout << "\nIntroduzca la resistencia del personaje [0-100]: ";
		cin >> resistencia;this->setResistencia(resistencia);
		cout <<"\nIntroduzca los puntos de vida del personaje [1000-5000]: ";
		cin  >>vida;this->setPVida(vida);
		cout <<"\nIntroduzca el precio del personaje[1000-5000]: ";
		cin  >>precio;this->setPrecio(precio);
	}




//---------------------------------------------CLASE JUGADOR-------------------------------------------------

class Jugador{
	private:
		string id;
		string login;
		string password;
		double dinero;
		Personaje** lista_personaje;
		int utiles_personajes;
		int total_personajes;
		int batallas_ganadas;
		int batallas_perdidas;
		Personaje** resultados_busqueda_personaje;
		int utiles_busqueda_personaje;
		int total_busqueda_personaje;

	public:
		//CONSTRUCTORES
		Jugador();
		Jugador(const Jugador &j);
		Jugador(string id,string login,string password,double dinero,Personaje** lista_personaje,int total_personajes,int batallas_ganadas,int batallas_perdidas, Personaje** resultados_busqueda_personaje, int utiles_busqueda_personaje);
		//DESTRUCTOR
		~Jugador();
		//SET
		inline void setID(string id){this->id=id;};
		inline void setLogin(string login){this->login=login;};
		inline void setPassword(string password){this->password=password;};
		inline void setDinero(double dinero){this->dinero=dinero;};
		inline void setListaPersonaje(Personaje** lista_personaje){this->lista_personaje=lista_personaje;};
		inline void setTotalPersonajes(int total_personajes){this->total_personajes=total_personajes;};
		inline void setUtilesPersonajes(int utiles_personajes){this->utiles_personajes=utiles_personajes;};
		inline void setBatallasGanadas(int batallas_ganadas){this->batallas_ganadas=batallas_ganadas;};
		inline void setBatallasPerdidas(int batallas_perdidas){this->batallas_perdidas=batallas_perdidas;};
		inline void setResultadoBusquedaPersonaje(Personaje** resultados_busqueda_personaje){this->resultados_busqueda_personaje=resultados_busqueda_personaje;};
		inline void setUtilesBusquedaPersonaje(int utiles_busqueda_personaje){this->utiles_busqueda_personaje=utiles_busqueda_personaje;};
		inline void setTotalesBusquedaPersonaje(int total_busqueda_personaje){this->total_busqueda_personaje=total_busqueda_personaje;};
		//GET
		inline string getID()const {return this->id;};
		inline string getLogin()const {return this->login;};
		inline string getPassword()const {return this->password;};
		inline int getDinero()const {return this->dinero;};
		inline Personaje* getListaPersonajes(int n)const {return this->lista_personaje[n];};
		inline Personaje** getListaPersonajes()const {return this->lista_personaje;};
		inline int getTotalPersonajes()const {return this->total_personajes;};
		inline int getUtilesPersonajes()const {return this->utiles_personajes;};
		inline int getBatallasGanadas()const {return this->batallas_ganadas;};
		inline int getBatallasPerdidas()const {return this->batallas_perdidas;};
		inline Personaje** getResultadosBusquedaPersonaje()const {return this->resultados_busqueda_personaje;};
		inline int getUtilesBusquedaPersonaje()const {return this->utiles_busqueda_personaje;};
		inline int getTotalesBusquedaPersonaje()const {return this->total_busqueda_personaje;};
		//SOBRECARGA DE OPERADOR <<
    	friend ostream& operator<<(ostream &flujo, const Jugador &j);
    	//SOBRECARGA DE OPERADOR =
    	Jugador& operator=(const Jugador &j);
    	//METODOS
    	void crearJugador();
    	void imprimirJugador();
    	void insertarPersonaje(Personaje *p);
    	void comprarPersonajeBasico();
    	void buscarPersonajeNombre(string nombre);
    	void buscarPersonajeID(string id);
    	void buscarPersonajeResistencia(int resistencia);
    	void buscarPersonajePrecio(double precio);
    	void buscarPersonajeVida(int vida);
    	void buscarPersonajeFuerza(int fuerza);
    	void buscarPersonajeTransferible(bool transferible);
    	void buscarPersonajeValoracion(double valoracion);
    	void buscarPersonajeDestreza(int destreza);
    	void comprarPersonajeJugador(Jugador *j);
    	void venderPersonajeMercado(Personaje *p);
    	void venderPersonajeAJugador(Personaje *p, Jugador *j);
    	void eliminarPersonaje(Personaje *p);
    	void ImprimiryBorrarResultadoBusqueda();

};

Jugador::Jugador(){
	this->id="NULL";
	this->login="NULL";
	this->password="NULL";
	this->dinero=25000;
	this->lista_personaje=new Personaje*[total_personajes];
	this->total_personajes=10;
	this->batallas_ganadas=0;
	this->batallas_perdidas=0;
	this->utiles_busqueda_personaje=0;
	this->total_busqueda_personaje=10;
	this->resultados_busqueda_personaje=new Personaje*[total_busqueda_personaje];

}

Jugador::Jugador(const Jugador &j){
	this->id=j.getID();
	this->login=j.getLogin();
	this->password=j.getPassword();
	this->dinero=j.getDinero();
	this->lista_personaje=new Personaje*[total_personajes];
	this->total_personajes=j.getTotalPersonajes();
	this->utiles_personajes=j.getUtilesPersonajes();
	this->batallas_ganadas=j.getBatallasGanadas();
	this->batallas_perdidas=j.getBatallasPerdidas();
	this->resultados_busqueda_personaje=new Personaje*[total_busqueda_personaje];
	this->utiles_busqueda_personaje=j.getUtilesBusquedaPersonaje();
	this->resultados_busqueda_personaje=j.getResultadosBusquedaPersonaje();
	for(int i=0; i<this->utiles_personajes; i++){
		this->lista_personaje[i]=j.lista_personaje[i];
	}
	for (int k=0; k<this->utiles_busqueda_personaje; k++){
		this->resultados_busqueda_personaje[k]=j.resultados_busqueda_personaje[k];
	}
}

Jugador::Jugador(string id,string login,string password,double dinero,Personaje** lista_personaje,int total_personajes,int batallas_ganadas,int batallas_perdidas, Personaje** resultados_busqueda_personaje, int utiles_busqueda_personaje){
	this->id=id;
	this->login=login;
	this->password=password;
	this->dinero=dinero;
	this->lista_personaje=lista_personaje;
	this->total_personajes=total_personajes;
	this->batallas_ganadas=batallas_ganadas;
	this->batallas_perdidas=batallas_perdidas;
	this->resultados_busqueda_personaje=resultados_busqueda_personaje;
	this->utiles_busqueda_personaje=utiles_busqueda_personaje;
	this->total_busqueda_personaje=total_busqueda_personaje;
}

Jugador::~Jugador(){
	delete[] this->lista_personaje;
	delete[] this->resultados_busqueda_personaje;
	this->id="NULL";
	this->login="NULL";
	this->password="NULL";
	this->dinero=0.0;
	this->total_personajes=0;
	this->batallas_ganadas=0;
	this->batallas_perdidas=0;
	this->utiles_busqueda_personaje=0;
	this->total_busqueda_personaje=0;
}

ostream& operator<<(ostream &flujo, const Jugador &j){
	flujo << "ID :" << j.getID() << endl;
	flujo << "Login :" << j.getLogin()<< endl;
	flujo << "Dinero :" <<j.getDinero()<< endl;
	flujo << "Batallas ganadas :" <<j.getBatallasGanadas()<< endl;
	flujo << "Batallas perdidas :" <<j.getBatallasPerdidas()<< endl;
	flujo << "Numero de personajes que tiene :" <<j.getUtilesPersonajes()<< endl;
	for(int i=0; i<j.getUtilesPersonajes(); i++){
		 j.lista_personaje[i]->imprimirPersonajes();
	}

    flujo << endl;
}

Jugador& Jugador::operator=(const Jugador &j){
	this->id=j.getID();
	this->login=j.getLogin();
	this->password=j.getPassword();
	this->dinero=j.getDinero();
	this->lista_personaje=new Personaje*[total_personajes];
	this->total_personajes=j.getTotalPersonajes();
	this->batallas_ganadas=j.getBatallasGanadas();
	this->batallas_perdidas=j.getBatallasPerdidas();
	for(int i=0; i<this->utiles_personajes; i++){
			this->lista_personaje[i]=j.lista_personaje[i];
	}
}

void Jugador::crearJugador(){
	string login,password,id;
	cout <<"\nIntroduce tu id: ";
	cin >> id; this->setID(id);
	cout <<"\nIntroduce tu login: ";
	cin >> login; this->setLogin(login);
	cout <<"\nIntroduce tu password: ";
	cin >> password; this->setPassword(password);
}

void Jugador::imprimirJugador(){
	cout << "ID :" << this->id << endl;
	cout << "Login :" << this->login << endl;
	cout << "Dinero :" <<this->dinero << endl;
	cout  << "Batallas ganadas :" << this->batallas_ganadas<< endl;
	cout  << "Batallas perdidas :" <<this->batallas_perdidas<< endl;
	cout  << "Numero de personajes que tiene :" <<this->utiles_personajes<< endl;
    cout << endl;
}

void Jugador::insertarPersonaje(Personaje *p){

	if(this->utiles_personajes>this->total_personajes){
		int dimension;
		Personaje** auxiliar;

		dimension=this->utiles_personajes; 
		dimension=dimension*2;
		auxiliar=new Personaje*[dimension]; //creamos un vector con el doble de dimensión
			if (auxiliar == 0){
        		cerr << "El S.O. no pudo reservar memoria. Se abortará la ejecución." << endl;
        		exit(-1);
    		}
    	for (int k=0; k<this->utiles_personajes; k++){ 
			auxiliar[k]=this->lista_personaje[k];
		}
		delete [] this->lista_personaje; //borro el antiguo vector
        this->lista_personaje = 0;
        this->lista_personaje=auxiliar;
        auxiliar=0;
        this->lista_personaje[utiles_personajes]=p;
		this->utiles_personajes = utiles_personajes+1;
	}else{
		this->lista_personaje[utiles_personajes]=p;
		this->utiles_personajes = utiles_personajes+1;
	}
}

void Jugador::eliminarPersonaje(Personaje *p){
	bool esta=false;
	int posicion;

	for(int i=0; i<this->utiles_personajes; i++){
		if (this->lista_personaje[i]->getIDPersonaje()==p->getIDPersonaje()){
			esta=true;
			posicion=i;
		}	
	}
	if(esta==true){
		//borramos
		this->lista_personaje[posicion]=0;
		this->lista_personaje[posicion]=this->lista_personaje[this->utiles_personajes-1];
		this->lista_personaje[this->utiles_personajes-1]=0;
		this->utiles_personajes--;

		
	}else
		cout << "El jugador no existe en el sistema, por tanto no se puede eliminar" << endl;
}
void Jugador::ImprimiryBorrarResultadoBusqueda(){
		for(int j=0; j<this->utiles_busqueda_personaje; j++)
			cout << *this->resultados_busqueda_personaje[j];

		for(int k=0; k<this->utiles_busqueda_personaje; k++)
			this->resultados_busqueda_personaje[k]=0;
	//	delete [] this->resultados_busqueda_personaje;
}

void Jugador::buscarPersonajeNombre(string nombre){	
	this->utiles_busqueda_personaje=0;
	for(int i=0; i<this->utiles_personajes; i++){
		if(this->lista_personaje[i]->getNombre()==nombre){
			this->resultados_busqueda_personaje[this->utiles_busqueda_personaje]=this->lista_personaje[i];
			utiles_busqueda_personaje++;
		}	
	}
	ImprimiryBorrarResultadoBusqueda();	
}
void Jugador::buscarPersonajeID(string id){
		this->utiles_busqueda_personaje=0;
		for(int i=0; i<this->utiles_personajes; i++){
			if(this->lista_personaje[i]->getIDPersonaje()==id){
				this->resultados_busqueda_personaje[this->utiles_busqueda_personaje]=this->lista_personaje[i];
				utiles_busqueda_personaje++;
			}
		}
		ImprimiryBorrarResultadoBusqueda();	
}
void Jugador::buscarPersonajeFuerza(int fuerza){
		this->utiles_busqueda_personaje=0;
		for(int i=0; i<this->utiles_personajes; i++){
			if(this->lista_personaje[i]->getFuerza()==fuerza){
				this->resultados_busqueda_personaje[this->utiles_busqueda_personaje]=this->lista_personaje[i];
				utiles_busqueda_personaje++;
			}
		}
		ImprimiryBorrarResultadoBusqueda();	
}
void Jugador::buscarPersonajeResistencia(int resistencia){
		this->utiles_busqueda_personaje=0;
		for(int i=0; i<this->utiles_personajes; i++){
			if(this->lista_personaje[i]->getFuerza()==resistencia){
				this->resultados_busqueda_personaje[this->utiles_busqueda_personaje]=this->lista_personaje[i];
				utiles_busqueda_personaje++;
			}
		}
		ImprimiryBorrarResultadoBusqueda();	
}
void Jugador::buscarPersonajeDestreza(int destreza){
		this->utiles_busqueda_personaje=0;
		for(int i=0; i<this->utiles_personajes; i++){
			if(this->lista_personaje[i]->getDestreza()==destreza){
				this->resultados_busqueda_personaje[this->utiles_busqueda_personaje]=this->lista_personaje[i];
				utiles_busqueda_personaje++;
			}
		}
		ImprimiryBorrarResultadoBusqueda();	
}
void Jugador::buscarPersonajeVida(int vida){
		this->utiles_busqueda_personaje=0;
		for(int i=0; i<this->utiles_personajes; i++){
			if(this->lista_personaje[i]->getPVida()==vida){
				this->resultados_busqueda_personaje[this->utiles_busqueda_personaje]=this->lista_personaje[i];
				utiles_busqueda_personaje++;
			}
		}
		ImprimiryBorrarResultadoBusqueda();	
}
void Jugador::buscarPersonajeValoracion(double valoracion){
		this->utiles_busqueda_personaje=0;
		for(int i=0; i<this->utiles_personajes; i++){
			if(this->lista_personaje[i]->getValoracionActual()==valoracion){
				this->resultados_busqueda_personaje[this->utiles_busqueda_personaje]=this->lista_personaje[i];
				utiles_busqueda_personaje++;
			}
		}
		ImprimiryBorrarResultadoBusqueda();	
}
void Jugador::buscarPersonajePrecio(double precio){
		this->utiles_busqueda_personaje=0;
		for(int i=0; i<this->utiles_personajes; i++){
			if(this->lista_personaje[i]->getPrecio()==precio){
				this->resultados_busqueda_personaje[this->utiles_busqueda_personaje]=this->lista_personaje[i];
				utiles_busqueda_personaje++;
			}
		}
		ImprimiryBorrarResultadoBusqueda();	
}
void Jugador::buscarPersonajeTransferible(bool transferible){
		this->utiles_busqueda_personaje=0;
		for(int i=0; i<this->utiles_personajes; i++){
			if(this->lista_personaje[i]->getTransferible()==transferible){
				this->resultados_busqueda_personaje[this->utiles_busqueda_personaje]=this->lista_personaje[i];
				utiles_busqueda_personaje++;
			}
		}
		ImprimiryBorrarResultadoBusqueda();	
}



void Jugador::comprarPersonajeJugador(Jugador *j){
	string nombre;
	cout << "dime el nombre del personaje que quieres comprar de " <<j->getLogin() << endl;
	cin >> nombre;
	Personaje *nuevo;
	int n;
	double suma,resta;

	for(int i=0; i<j->getUtilesPersonajes(); i++){ //recorrermos el vector buscando el personaje a comprar, si está lo asignamos a la variable creada
		if(nombre==j->lista_personaje[i]->getNombre())
			nuevo=j->lista_personaje[i];
	}

	cout<<*nuevo;

	if(this->getDinero()>nuevo->getPrecio()) //insertamos el personaje en nuestro vector si tenemos dinero para comprarlo
		this->insertarPersonaje(nuevo);
	else
		cout<<"no tienes dinero para comprar el personaje" <<endl;

	resta=this->getDinero() - nuevo->getPrecio();
	suma=j->getDinero() + nuevo->getPrecio();
	this->setDinero(resta);
	j->setDinero(suma);

	j->eliminarPersonaje(nuevo);
}

void Jugador::venderPersonajeAJugador(Personaje *p, Jugador *j){
	cout<< *p;
	double suma, resta;

	if(j->getDinero()>p->getPrecio())
		j->insertarPersonaje(p);
	else
		cout<<"no tiene dinero para comprar tu personaje" <<endl;
	resta=j->getDinero()- p->getPrecio();
	suma=this->getDinero()+p->getPrecio();
	this->setDinero(suma);
	j->setDinero(resta);

	this->eliminarPersonaje(p);
}



//-------------------------------------CLASE GLADIATOR----------------------------------------------------------------
class Gladiator{
	private:
		Jugador** lista_jugadores;
		int utiles_jugadores;
		int total_jugadores;
		Jugador** lista_resultados_busqueda;
		int utiles_busqueda;
		int total_busqueda;
		Personaje** mercado;
		int util_mercado;
		int total_mercado;
		double dinero_total;

	public:
		//CONSTRUCTORES
		Gladiator();//defecto
		Gladiator(const Gladiator &g);//copia
		Gladiator(Jugador** lista_jugadores, int utiles_jugadores, int total_jugadores,Jugador** lista_resultados_busqueda,int utiles_busqueda);//parametros
		//DESTRUCTOR
		~Gladiator();
		//SET
		inline void setListaJugadores(Jugador** lista_jugadores){this->lista_jugadores=lista_jugadores;};
		inline void setUtilesJugadores(int utiles_jugadores){this->utiles_jugadores=utiles_jugadores;};
		inline void setTotalJugadores(int total_jugadores){this->total_jugadores=total_jugadores;};
		inline void setListaResultadosBusqueda(Jugador** lista_resultados_busqueda){this->lista_resultados_busqueda=lista_resultados_busqueda;};
		inline void setUtilesBusqueda(int utiles_busqueda){this->utiles_busqueda=utiles_busqueda;};
		inline void setTotalBusqueda(int total_busqueda){this->total_busqueda=total_busqueda;};
		inline void setMercado(Personaje** mercado){this->mercado=mercado;};
		inline void setTotalMercado(int total_mercado){this->total_mercado=total_mercado;};
		inline void setUtilMercado(int util_mercado){this->util_mercado=util_mercado;};
		inline void setDineroTotal(int dinero_total){this->dinero_total=dinero_total;};
		//GET
		inline Jugador** getListaJugadores()const {return this->lista_jugadores;};
		inline int getTotalJugadores()const {return this->total_jugadores;};
		inline int getUtilesJugadores()const {return this->utiles_jugadores;};
		inline Jugador** getListaResultadosBusqueda()const {return this->lista_resultados_busqueda;};
		inline int getUtilesBusqueda()const {return this->utiles_busqueda;};
		inline int getTotalBusqueda()const {return this->total_busqueda;};
		inline Personaje** getMercado()const {return this->mercado;};
		inline int getTotalMercado()const {return this->total_mercado;};
		inline int getUtilMercado()const {return this->util_mercado;};
		inline double getDineroTotal()const {return this->dinero_total;};
		//METODOS
		void Bienvenida();
		void Menu();
		void Instrucciones();
		bool autenticacion(string login, string password);
		void leerFichero(string ruta);
		void guardarFichero(string ruta);
		void anadirJugador(Jugador* j);
		void eliminarJugador();
		Jugador* buscarJugador(string login);
		bool buscarJugadorporDinero(double dinero);
		void batallaporEquipos(Jugador* j1, Jugador* j2);
		void batalla1vs1(Jugador* j1, Jugador* j2);
		void informeTopCarteraPersonajes();
		void informetopPlayerRatio();
		void informeLooser();
		void informeBusinessMan();
		void introducirPersonajeMercado(Personaje *p);
		void eliminarPersonajeMercado();
		//SOBRECARGA DE OPERADOR <<
    	friend ostream& operator<<(ostream &flujo, const Gladiator &g);
    	//SOBRECARGA DE OPERADOR =
    	Gladiator& operator=(const Gladiator &g);
};
Gladiator::Gladiator(){	
	this->total_jugadores=10;
	this->utiles_jugadores=0;
	this->lista_jugadores=new Jugador*[total_jugadores];
	this->utiles_busqueda=0;
	this->total_busqueda=10;
	this->lista_resultados_busqueda=new Jugador*[total_busqueda];
	this->total_mercado=10;
	this->util_mercado=0;
	this->mercado=new Personaje*[total_mercado];
	
}

Gladiator::Gladiator(const Gladiator &g){	
	this->total_jugadores=g.getTotalJugadores();
	this->utiles_jugadores=g.getUtilesJugadores();
	this->lista_jugadores=new Jugador*[total_jugadores];
	this->utiles_busqueda=g.getUtilesBusqueda();
	this->total_busqueda=g.getTotalBusqueda();
	this->lista_resultados_busqueda=new Jugador*[total_busqueda];
	this->total_mercado=g.getTotalMercado();
	this->util_mercado=g.getUtilMercado();
	this->mercado=new Personaje*[total_mercado];

	for(int i=0; i<this->utiles_jugadores; i++){
		this->lista_jugadores[i]=g.lista_jugadores[i];
	}

	for(int j=0; j<this->utiles_busqueda; j++){
		this->lista_resultados_busqueda[j]=g.lista_resultados_busqueda[j];
	}

	for(int k=0; k<this->total_mercado; k++){
		this->mercado[k]=g.mercado[k];
	}
}

Gladiator::Gladiator(Jugador** lista_jugadores, int utiles_jugadores, int total_jugadores,Jugador** lista_resultados_busqueda,int utiles_busqueda){	
	this->total_jugadores=total_jugadores;
	this->lista_jugadores=lista_jugadores;
	this->utiles_busqueda=utiles_busqueda;
	this->lista_resultados_busqueda=lista_resultados_busqueda;
	this->utiles_jugadores=utiles_jugadores;
	this->mercado=mercado;
	this->total_mercado=total_mercado;
}

Gladiator::~Gladiator(){
	delete [] this->lista_jugadores;
	delete [] this->lista_resultados_busqueda;
	delete [] this->mercado;
	this->total_jugadores=0;
	this->utiles_jugadores=0;
	this->utiles_busqueda=0;
	this->total_mercado=0;
}

ostream& operator<<(ostream &flujo, const Gladiator &g){
	flujo << "Numero de jugadores en el sistema" << g.getUtilesJugadores() << endl;
	for(int i=0; i<g.getUtilesJugadores(); i++){
		g.lista_jugadores[i]->imprimirJugador();
	}
	flujo <<endl;
}

Gladiator& Gladiator::operator=(const Gladiator &g){
	this->total_jugadores=g.getTotalJugadores();
	this->utiles_jugadores=g.getUtilesJugadores();
	this->lista_jugadores=new Jugador*[total_jugadores];
	this->utiles_busqueda=g.getUtilesBusqueda();
	this->lista_resultados_busqueda=new Jugador*[utiles_busqueda];
	this->mercado=new Personaje*[total_mercado];

	for(int i=0; i<this->utiles_jugadores; i++){
		this->lista_jugadores[i]=g.lista_jugadores[i];
	}

	for(int j=0; j<this->utiles_busqueda; j++){
		this->lista_resultados_busqueda[j]=g.lista_resultados_busqueda[j];
	}

	for(int k=0; k<this->total_mercado; k++){
		this->mercado[k]=g.mercado[k];
	}
}

void Gladiator::Instrucciones(){
	cout <<"NORMAS BASICAS:" <<endl;
	cout <<"\t1.Cada jugador tirara el dado una vez por cada personaje de su grupo y se le aplicará la habilidad del personaje automaticamente"<<endl;
	cout <<"\t2.En las batallas 1 vs 1, tan solo se tirara el dado una vez" <<endl;

	cout <<"DINERO:" <<endl;
	cout <<"\t1.Cada jugador comienza el juego con 74.000$, dinero para comprar 1 personajes diferente de cada categoria"<<endl;
	cout <<"\t2.Se ganan 50$, cada vez que se gana una pelea GRUPOvsGRUPO y 20$, cuando se gana un combate 1vs1"<<endl;


	cout <<"MODO DE JUEGO:" <<endl;
	cout <<"\t1.GRUPO vs GRUPO: Cada jugador, pelea con 3 personajes diferentes contra otro jugador con el mismo numero de personajes" <<endl;
	cout <<"\t2.UNO vs UNO: Cada jugador, lucha con un 1 personaje a escoger de entre los que tenga en su equipo" <<endl;

	cout <<"PERSONAJES:" <<endl;
	cout <<"\t1.Existen 3 tipos diferentes de personajes:"<<endl;
	cout <<"\t\t> MAGOS: Tienen la habilidad de Mana, cuando se activa dobla el Ataque del personaje que la innvoca" <<endl;
	cout <<"\t\t> GUERREROS: Tienen la habilidad de Furia, cuando se activa dobla la Defensa del personaje que la innvoca" <<endl;
	cout <<"\t\t> PICAROS: Tienen la habilidad de Energia, cuando se activa dobla la Destreza del personaje que la innvoca" <<endl;
	cout <<"\t2.Hay 5 categorias diferentes ordenadas por precio de adquisicion:"<<endl;
	cout <<"\t\t> 1ª CATEGORIA: precio 20.000, puntos de vida 5.000, ataque 500, defensa 500, destreza 500" <<endl;
	cout <<"\t\t> 2ª CATEGORIA: precio 17.000, puntos de vida 4.200, ataque 420, defensa 420, destreza 500" <<endl;
	cout <<"\t\t> 3ª CATEGORIA: precio 15.000, puntos de vida 3.500, ataque 350, defensa 350, destreza 500" <<endl;
	cout <<"\t\t> 4ª CATEGORIA: precio 12.000, puntos de vida 3.000, ataque 300, defensa 300, destreza 500" <<endl;
	cout <<"\t\t> 5ª CATEGORIA: precio 10.000, puntos de vida 2.500, ataque 250, defensa 250, destreza 500" <<endl;
	cout <<"\t3. Se pueden crear personajes escogiendo su especialidad y categoria" <<endl;
	cout <<"\t4. Se pueden escoger personajes ya creados" <<endl;
	cout <<"\t5. Se pueden ver los personajes ya definidos en la opcion del menu" <<endl;
}

bool Gladiator::autenticacion(string login, string password){
	for(int i=0; i<this->utiles_jugadores; i++){
		if ((this->lista_jugadores[i]->getLogin()==login)&&(this->lista_jugadores[i]->getPassword()==password))
			return true;
		else
			return false;
	}
}

bool Gladiator::buscarJugadorporDinero(double dinero){
	for(int i=0; i<this->utiles_jugadores; i++){
		if ((this->lista_jugadores[i]->getDinero()==dinero))
			return true;
		else
			return false;
	}
}

Jugador* Gladiator::buscarJugador(string login){
	this->utiles_busqueda=0;
	for(int i=0; i<this->utiles_jugadores; i++){
		if (this->lista_jugadores[i]->getLogin()==login){
			this->lista_resultados_busqueda[this->utiles_busqueda]=this->lista_jugadores[i];
			utiles_busqueda++;
			return this->lista_jugadores[i];
		}
	}
}

void Gladiator::anadirJugador(Jugador *j){
	bool esta=false;

	for(int i=0; i<this->utiles_jugadores; i++){
		if (this->lista_jugadores[i]->getID()==j->getID())
			esta=true;
	}
	if(esta==false){
		if(this->utiles_jugadores>this->total_jugadores){
			int dimension;
			Jugador** auxiliar;

			dimension=this->utiles_jugadores; 
			dimension=dimension*2;
			auxiliar=new Jugador*[dimension]; //creamos un vector con el doble de dimensión
				if (auxiliar == 0){
	        		cerr << "El S.O. no pudo reservar memoria. Se abortará la ejecución." << endl;
	        		exit(-1);
	    		}
	    	for (int k=0; k<this->utiles_jugadores; k++){ 
				auxiliar[k]=this->lista_jugadores[k];
			}
			delete [] this->lista_jugadores; //borro el antiguo vector
	        this->lista_jugadores = 0;
	        this->lista_jugadores=auxiliar;
	        auxiliar=0;
	        this->lista_jugadores[utiles_jugadores]=j;
			this->utiles_jugadores = utiles_jugadores+1;
		}else{
			this->lista_jugadores[utiles_jugadores]=j;
			this->utiles_jugadores = utiles_jugadores+1;
		}
	}else
		cout << "El jugador esta ya en el sistema" <<endl;
	
}

void Gladiator::eliminarJugador(){
	string identificador;
	cout << "introduce el identificador del jugador que quieres borrar: ";
	cin >>identificador;
	bool esta=false;
	int posicion;

	for(int i=0; i<this->utiles_jugadores; i++){
		if (this->lista_jugadores[i]->getID()==identificador){
			esta=true;
			posicion=i;
		}	
	}
	if(esta==true){
		this->lista_jugadores[posicion]=0;
		this->lista_jugadores[posicion]=this->lista_jugadores[this->utiles_jugadores-1];
		this->lista_jugadores[this->utiles_jugadores-1]=0;
		this->utiles_jugadores--;
		
	}else
		cout << "El jugador no existe en el sistema, por tanto no se puede eliminar" << endl;
}

void Gladiator::introducirPersonajeMercado(Personaje *p){

	if(this->util_mercado>this->total_mercado){
		int dimension;
		Personaje** auxiliar;

		dimension=this->util_mercado; 
		dimension=dimension*2;
		auxiliar=new Personaje*[dimension]; //creamos un vector con el doble de dimensión
			if (auxiliar == 0){
        		cerr << "El S.O. no pudo reservar memoria. Se abortará la ejecución." << endl;
        		exit(-1);
    		}
    	for (int k=0; k<this->util_mercado; k++){ 
			auxiliar[k]=this->mercado[k];
		}
		delete [] this->mercado; //borro el antiguo vector
        this->mercado = 0;
        this->mercado=auxiliar;
        auxiliar=0;
        this->mercado[util_mercado]=p;
		this->util_mercado = util_mercado+1;
	}else{
		this->mercado[util_mercado]=p;
		this->util_mercado = util_mercado+1;
	}
}


void Gladiator::eliminarPersonajeMercado(){
	bool esta=false;
	int posicion;
	string identificador;
	cout << "Intruduzca el identificador del personaje a eliminar ";
	cin >> identificador;

	for(int i=0; i<this->util_mercado; i++){
		if (this->mercado[i]->getIDPersonaje()==identificador){
			esta=true;
			posicion=i;
		}	
	}
	if(esta==true){
		//borramos personaje de mercado
		this->mercado[posicion]=0;
		this->mercado[posicion]=this->mercado[this->util_mercado-1];
		this->mercado[this->util_mercado-1]=0;
		this->util_mercado--;

		
	}else
		cout << "El jugador no existe en el sistema, por tanto no se puede eliminar" << endl;
}
void Gladiator::informeTopCarteraPersonajes(){
	double** cartera;
	int dimesion=this->utiles_jugadores;
	cartera=new double*[dimesion];

	for(int i=0; i<this->utiles_jugadores; i++){
		for(int j=0; j<this->lista_jugadores[i]->getUtilesPersonajes(); j++){
			**cartera=this->lista_jugadores[i]->getListaPersonajes(j)->getPrecio();
		}
	}

}

void Gladiator::Bienvenida(){
string login, contrasena;
bool entra=false;
	do{
		system("clear");
		cout <<endl; 
		cout <<endl;

		cout <<"  /$$$$$$  /$$        /$$$$$$  /$$$$$$$  /$$$$$$  /$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$$  /$$$$$$$$  /$$$$$$ " << endl;
		cout <<" /$$__  $$| $$       /$$__  $$| $$__  $$|_  $$_/ /$$__  $$| $$__  $$ /$$__  $$| $$__  $$| $$_____/ /$$__  $$" << endl;
		cout <<"| $$   __/| $$      | $$    $$| $$    $$  | $$  | $$    $$| $$    $$| $$    $$| $$    $$| $$      | $$   __/" << endl;
		cout <<"| $$ /$$$$| $$      | $$$$$$$$| $$  | $$  | $$  | $$$$$$$$| $$  | $$| $$  | $$| $$$$$$$/| $$$$$   |  $$$$$$ " << endl;
		cout <<"| $$|_  $$| $$      | $$__  $$| $$  | $$  | $$  | $$__  $$| $$  | $$| $$  | $$| $$__  $$| $$__/     _ ___  $$" << endl;
		cout <<"| $$    $$| $$      | $$  | $$| $$  | $$  | $$  | $$  | $$| $$  | $$| $$  | $$| $$    $$| $$       /$$    $$" << endl;
		cout <<"|  $$$$$$/| $$$$$$$$| $$  | $$| $$$$$$$/ /$$$$$$| $$  | $$| $$$$$$$/|  $$$$$$/| $$  | $$| $$$$$$$$|  $$$$$$/" << endl;
		cout <<"  ______/ |________/|__/  |__/|_______/ |______/|__/  |__/|_______/   ______/ |__/  |__/|________/  ______/ " << endl;
		                                                                                                            
		cout <<endl; 
		cout <<endl;                                                                                                        
		                                                                                                            
		cout <<"                              /$$$$$$$  /$$$$$$$$        " << endl;                                                        
		cout <<"                             | $$__  $$| $$_____/        " << endl;                                                        
		cout <<"                             | $$    $$| $$             " << endl;                                                         
		cout <<"                             | $$  | $$| $$$$$         " << endl;                                                          
		cout <<"                             | $$  | $$| $$__/         " << endl;                                                          
		cout <<"                             | $$$$$$$/| $$$$$$$$     " << endl;                                                           
		cout <<"                            |_______/ |________/      " << endl;                                                          
		                                                                                                             
		cout <<endl; 
		cout <<endl;                                                                                                        
		                                                                                                            
		cout <<"  /$$$$$$  /$$$$$$$  /$$$$$$  /$$$$$$  /$$$$$$$$ /$$$$$$        /$$$$$$$  /$$$$$$$$ /$$     /$$         " << endl;    
		cout <<" /$$__  $$| $$__  $$|_  $$_/ /$$__  $$|__  $$__//$$__  $$      | $$__  $$| $$_____/|  $$   /$$/        " << endl;     
		cout <<"| $$   __/| $$    $$  | $$  | $$   __/   | $$  | $$    $$      | $$    $$| $$          $$ /$$/        " << endl;      
		cout <<"| $$      | $$$$$$$/  | $$  |  $$$$$$    | $$  | $$  | $$      | $$$$$$$/| $$$$$        $$$$/        " << endl;       
		cout <<"| $$      | $$__  $$  | $$    ____  $$   | $$  | $$  | $$      | $$__  $$| $$__/         $$/        " << endl;        
		cout <<"| $$    $$| $$    $$  | $$   /$$    $$   | $$  | $$  | $$      | $$    $$| $$          | $$        " << endl;         
		cout <<"|  $$$$$$/| $$  | $$ /$$$$$$|  $$$$$$/   | $$  |  $$$$$$/      | $$  | $$| $$$$$$$$    | $$     " << endl;            
		cout <<"  ______/ |__/  |__/|______/  ______/    |__/    ______/       |__/  |__/|________/    |__/    " << endl;             
		                                                                                                            
		cout <<endl; 
		cout <<endl;
		cout <<"\n\t\t\tINTRODUZCA SU LOGIN: " ; 
		cin >>login;
		cout <<"\n\t\t\tINTRODUZCA SU PASSWORD: "; 
		cin >>contrasena;
		entra=autenticacion(login,contrasena);
		if(entra==false)
			cout <<"login o password incorrecto, vuelva a loguearse" <<endl;
	}while(entra!=true);
}

void Gladiator::Menu(){
	Gladiator *t;
	t=new Gladiator;
	Jugador *administrador;
	administrador=new Jugador;
	administrador->setLogin("admin");
	administrador->setPassword("hispano");
	administrador->setID("francis");

	Personaje *ola;
	ola=new Personaje;
	ola->setPrecio(25);
	administrador->insertarPersonaje(ola);

	t->anadirJugador(administrador);
	t->Bienvenida();
	char c, a, b, d, e, f, g;

	string id,nombre,opcion;
	int fuerza, resistencia, destreza, vida;
	double valoracion, precio;
	bool transferible;


	system("clear");
	

	do{
		cout << "\n\n\t<<[[ BIENVENIDO AL COLISEO DE LUCHA GLADIATOR CRISTO REY ]]>>"<< endl <<endl;
	    cout << "\n\t1)Administración del Sistema"<< endl; 
	    cout << "\n\t2)Acciones del Jugador en el Coliseo"<< endl;
		cout << "\n\tPulse << s >> para salir del juego" <<endl;

	    cin >> c;
	    system("clear");//limpia la pantalla
		
		switch (c){	

			case '1':
			system("clear");
		do{
			cout << "\n\n\t<<[[ ADMINISTRACION DEL SISTEMA ]]>>"<< endl <<endl;
		    cout << "\n\t1)Importar Datos al Sistema desde Fichero *.conf"<< endl; 
		    cout << "\n\t2)Exportar Datos del Sistema a Fichero *.conf"<< endl;
		    cout << "\n\t3)Ranking"<< endl;
		    cout << "\n\t4)Personajes"<< endl;
		    cout << "\n\t5)Jugadores"<< endl;
			cout << "\n\tPulse << v >> para volver" <<endl;

		    cin >> b;
		    system("clear");//limpia la pantalla
			
			switch (b){	

				case '1':
					break;

				case '2':
					break;

				case '3':
				system("clear");
		do{
			cout << "\n\n\t<<[[ RANKING ]]>>"<< endl <<endl;
		    cout << "\n\t1)Ranking Top3 Jugador por Cartera de Personajes"<< endl; 
		    cout << "\n\t2)Ranking Top3 Jugador por Ratio"<< endl;
		    cout << "\n\t3)Ranking Jugador Looser & Bussines Man"<< endl;
			cout << "\n\tPulse << v >> para volver" <<endl;

		    cin >> d;
		    system("clear");//limpia la pantalla
			
			switch (d){	

				case '1':
					break;

				case '2':
					break;

				case '3':
					break;

				case 'v':
					break;
				
				default:
					cout << "opcion incorrecta, vuelva a escoger una opción del menu, por favor" << endl;
			}

		}while(d!='v');
					break;

				case '4':
						system("clear");
		do{
			cout << "\n\n\t<<[[ PERSONAJES ]]>>"<< endl <<endl;
		    cout << "\n\t1)Agregar Nuevo Personaje al Sistema"<< endl; 
		    cout << "\n\t2)Eliminar Personaje del Sistema"<< endl;
		    cout << "\n\t3)Buscar Personaje en el Sistema"<< endl;
		    cout << "\n\t4)Modificar Datos Personaje en el Sistema"<< endl;
		    cout << "\n\t5)Consultar Estado y Valoración Actual de un Personaje en el Sistema"<< endl;
			cout << "\n\tPulse << v >> para volver" <<endl;

		    cin >> e;
		    system("clear");//limpia la pantalla
			
			switch (e){	

				case '1':
						system("clear");
		do{
			cout << "\n\n\t<<[[ CREACION DE PERSONAJE ]]>>"<< endl <<endl;
		    cout << "\n\t1)El personaje elegido es un Picaro"<< endl; 
		    cout << "\n\t2)El personaje elegido es un Guerreo"<< endl;
		    cout << "\n\t3)El personaje elegido es un Mago"<< endl;
			cout << "\n\tPulse << v >> para volver" <<endl;

		    cin >> g;
		    system("clear");//limpia la pantalla
			
			switch (g){	

				case '1':
				Picaro *nuevo;
				nuevo=new Picaro;
				nuevo->crearPersonaje();
				t->introducirPersonajeMercado(nuevo);
					break;

				case '2':
				Guerrero *nuevo1;
				nuevo1=new Guerrero;
				nuevo1->crearPersonaje();
				t->introducirPersonajeMercado(nuevo1);
					break;

				case '3':
				Mago *nuevo2;
				nuevo2=new Mago;
				nuevo2->crearPersonaje();
				t->introducirPersonajeMercado(nuevo2);
					break;

				case 'v':
					break;
				
				default:
					cout << "opcion incorrecta, vuelva a escoger una opción del menu, por favor" << endl;
			}

		}while(g!='v');
					break;

				case '2':
				t->eliminarPersonajeMercado();
					break;

				case '3':
	cout<<"Escribe el criterio por el que quieres realizar la busqueda entre los siguientes:" <<endl;
	cout<<"\n-id \n-nombre \n-fuerza \n-resistencia \n-destreza \n-vida \n-valoracion \n-transferible \n-precio \n"<<endl;
	cin >>opcion;
	if(opcion=="nombre"){
		cout <<"Introduce el nombre del personaje a buscar:" <<endl;
		cin >>nombre;
		for(int i=0; i<t->utiles_jugadores; i++)
			t->lista_jugadores[i]->buscarPersonajeNombre(nombre);

	}
	if(opcion=="id"){
		cout <<"Introduce el id del personaje a buscar:" <<endl;
		cin >>id;
		for(int i=0; i<t->utiles_jugadores; i++)
			t->lista_jugadores[i]->buscarPersonajeID(id);
	}
	if(opcion=="fuerza"){
		cout<<"Escribel la fuerza del personaje a buscar: ";
		cin>>fuerza;
		for(int i=0; i<t->utiles_jugadores; i++)
			t->lista_jugadores[i]->buscarPersonajeFuerza(fuerza);
	}
	if(opcion=="resistencia"){
		cout<<"Escribel la resistencia del persnoaje a buscar: ";
		cin>>resistencia;
		for(int i=0; i<t->utiles_jugadores; i++)
			t->lista_jugadores[i]->buscarPersonajeResistencia(resistencia);
	}
	if(opcion=="destreza"){
		cout<<"Escribel la destreza del personaje a buscar: ";
		cin>>destreza;
		for(int i=0; i<t->utiles_jugadores; i++)
			t->lista_jugadores[i]->buscarPersonajeDestreza(destreza);
	}
	if(opcion=="vida"){
		cout<<"Escribel los puntos de vida del personaje a buscar: ";
		cin>>vida;
		for(int i=0; i<t->utiles_jugadores; i++)
			t->lista_jugadores[i]->buscarPersonajeVida(vida);
	}
	if(opcion=="valoracion"){
		cout<<"Escribel la valoracion actual del personaje a buscar: ";
		cin>>valoracion;
		for(int i=0; i<t->utiles_jugadores; i++)
			t->lista_jugadores[i]->buscarPersonajeValoracion(valoracion);
	}
	if(opcion=="precio"){
		cout<<"Escribel el precio del personaje a buscar: ";
		cin>>precio;
		for(int i=0; i<t->utiles_jugadores; i++)
			t->lista_jugadores[i]->buscarPersonajePrecio(precio);
	}
	if(opcion=="transferible"){
		cout<<"Escribe 0 para buscar los personajes transeribles y 1 los no transeribles: ";
		cin>>transferible;
		for(int i=0; i<t->utiles_jugadores; i++)
			t->lista_jugadores[i]->buscarPersonajeTransferible(transferible);
	}
					break;

				case '4':
					break;

				case '5':
				cout <<*t;
					break;

				case 'v':
					break;
				
				default:
					cout << "opcion incorrecta, vuelva a escoger una opción del menu, por favor" << endl;
			}

		}while(e!='v');
					break;

				case '5':
				system("clear");
		do{
			cout << "\n\n\t<<[[ JUGADORES ]]>>"<< endl <<endl;
		    cout << "\n\t1)Agregar Nuevo Jugador al Sistema"<< endl; 
		    cout << "\n\t2)Eliminar Jugador del Sistema"<< endl;
		    cout << "\n\t3)Buscar Jugador en el Sistema"<< endl;
		    cout << "\n\t4)Modificar Datos Jugador del Sistema"<< endl;
			cout << "\n\tPulse << v >> para volver" <<endl;

		    cin >> f;
		    system("clear");//limpia la pantalla
			
			switch (f){	

				case '1':
				Jugador *nuevo2;
				nuevo2=new Jugador;
				nuevo2->crearJugador();
				t->anadirJugador(nuevo2);
					break;

				case '2':
				t->eliminarJugador();
				cout<<*t;
					break;

				case '3':
					break;
				case 'v':
					break;
				
				default:
					cout << "opcion incorrecta, vuelva a escoger una opción del menu, por favor" << endl;
			}

		}while(f!='v');
					break;

				case 'v':
					break;
				
				default:
					cout << "opcion incorrecta, vuelva a escoger una opción del menu, por favor" << endl;
			}

		}while(b!='v');
				break;

			case '2':
			system("clear");
		do{
			cout << "\n\n\t<<[[ ACCIONES DEL JUGADOR EN EL COLISEO ]]>>"<< endl <<endl;
		    cout << "\n\t1)Batalla 1 vs 1"<< endl; 
		    cout << "\n\t2)Batalla Por Equipos"<< endl;
		    cout << "\n\t3)Comprar Personaje Básico"<< endl;
		    cout << "\n\t4)Comprar Personaje a Jugador"<< endl;
		    cout << "\n\t5)Transferir Personaje a Mercado"<< endl;
			cout << "\n\t5)Transferir Personaje a Mercado"<< endl;
			cout << "\n\t6)Vender Personaje a Jugador" <<endl;
			cout << "\n\t7)Ver las instrucciones del juego" <<endl;
			cout << "\n\tPulse << v >> para volver" <<endl;

		    cin >> a;
		    system("clear");//limpia la pantalla
			
			switch (a){	

				case '1':
					break;

				case '2':
					break;

				case '3':
					break;

				case '4':
					break;

				case '5':
					break;

				case '6':
					break;

				case '7':
					Instrucciones();
					break;

				case 'v':
					break;
				
				default:
					cout << "opcion incorrecta, vuelva a escoger una opción del menu, por favor" << endl;
			}

		}while(a!='v');
				break;

			case 's':
				break;
			
			default:
				cout << "opcion incorrecta, vuelva a escoger una opción del menu, por favor" << endl;
		}

	}while(c!='s');




}


int main(){
	Gladiator *p;
	p=new Gladiator;
	p->Menu();

	/*Personaje *u,*i,*f,*y;
	u=new Personaje;
	i=new Personaje;
	f=new Personaje;
	y=new Personaje;

	Jugador *k,*l,*r, *administrador;
	k=new Jugador;
	l=new Jugador;
	r=new Jugador;
	administrador=new Jugador;
	

	f->setNombre("orsino");
	f->setPrecio(5000);

	y->setNombre("orsino");
	y->setPrecio(6000);

	u->setNombre("Danarius");
	u->setIDPersonaje("Dan");
	u->setFuerza(500);		
	u->setDestreza(500);
	u->setResistencia(500);
	u->setPVida(5000);
	u->setPrecio(20000);

	i->setNombre("Caballero Alistair");
	i->setIDPersonaje("Ali");
	i->setFuerza(500);		
	i->setDestreza(500);
	i->setResistencia(500);
	i->setPVida(5000);
	i->setPrecio(20000);

	k->setID("cheetos");		
	k->setLogin("fran");	
	k->setPassword("algo");	
	k->setDinero(74000);
	k->setBatallasPerdidas(2);	
	k->setBatallasGanadas(8);
	

	l->setID("gamba");		
	l->setLogin("jesus");	
	l->setPassword("algo");	
	l->setDinero(74000);
	l->setBatallasPerdidas(2);	
	l->setBatallasGanadas(8);

	r->setID("coki");		
	r->setLogin("marcos");	




	k->insertarPersonaje(u);
	k->insertarPersonaje(i);
	cout << *k;

	l->insertarPersonaje(f);
	l->insertarPersonaje(y);
	cout << *l;
	
	
/*
	k->comprarPersonajeJugador(l);
	cout <<*k;
	cout <<*l;

	k->venderPersonajeAJugador(i,l);
	cout <<*k;
	cout <<*l;

	

	t->anadirJugador(k);
	t->anadirJugador(l);
	t->anadirJugador(administrador);
	t->anadirJugador(r);
	t->anadirJugador(k);
	t->anadirJugador(l);
	t->anadirJugador(r);



	cout << *t;
	t->eliminarJugador(r);
	cout << *t;
*/




}