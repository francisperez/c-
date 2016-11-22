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
		//GET
		inline string getID()const {return this->id;};
		inline string getLogin()const {return this->login;};
		inline string getPassword()const {return this->password;};
		inline int getDinero()const {return this->dinero;};
		inline Personaje** getListaPersonajes()const {return this->lista_personaje;};
		inline int getTotalPersonajes()const {return this->total_personajes;};
		inline int getUtilesPersonajes()const {return this->utiles_personajes;};
		inline int getBatallasGanadas()const {return this->batallas_ganadas;};
		inline int getBatallasPerdidas()const {return this->batallas_perdidas;};
		inline Personaje** getResultadosBusquedaPersonaje()const {return this->resultados_busqueda_personaje;};
		inline int getUtilesBusquedaPersonaje()const {return this->utiles_busqueda_personaje;};
		//SOBRECARGA DE OPERADOR <<
    	friend ostream& operator<<(ostream &flujo, const Jugador &j);
    	//SOBRECARGA DE OPERADOR =
    	Jugador& operator=(const Jugador &j);
    	//METODOS
    	void insertarPersonaje(Personaje *p);
    	void comprarPersonajeBasico();
    	Personaje* buscarPersonaje(string nombre);
    	void comprarPersonajeJugador(Jugador *j);
    	void venderPersonajeMercado(Personaje *p);
    	void venderPersonajeAJugador(Personaje *p, Jugador *j);




};
Jugador::Jugador(){
	this->id="NULL";
	this->login="NULL";
	this->password="NULL";
	this->dinero=0.0;
	this->lista_personaje=new Personaje*[total_personajes];
	this->total_personajes=0;
	this->batallas_ganadas=0;
	this->batallas_perdidas=0;
	this->resultados_busqueda_personaje=new Personaje*[utiles_busqueda_personaje];
	this->utiles_busqueda_personaje=0;
}

Jugador::Jugador(const Jugador &j){
	this->id=j.getID();
	this->login=j.getLogin();
	this->password=j.getPassword();
	this->dinero=j.getDinero();
	this->lista_personaje=new Personaje*[total_personajes];
	this->total_personajes=j.getTotalPersonajes();
	this->batallas_ganadas=j.getBatallasGanadas();
	this->batallas_perdidas=j.getBatallasPerdidas();
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

void Jugador::insertarPersonaje(Personaje *p){
	this->lista_personaje[utiles_personajes]=p;
	this->utiles_personajes=utiles_personajes+1;
}

//-------------------------------------CLASE GLADIATOR----------------------------------------------------------------
class Gladiator{
	private:
		Jugador** lista_jugadores;
		int utiles_jugadores;
		int total_jugadores;
		Jugador** lista_resultados_busqueda;
		int utiles_busqueda;
		Personaje** mercado;
		int total_mercado;

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
		inline void setMercado(Personaje** mercado){this->mercado=mercado;};
		inline void setTotalMercado(int total_mercado){this->total_mercado=total_mercado;};
		//GET
		inline Jugador** getListaJugadores()const {return this->lista_jugadores;};
		inline int getTotalJugadores()const {return this->total_jugadores;};
		inline int getUtilesJugadores()const {return this->utiles_jugadores;};
		inline Jugador** getListaResultadosBusqueda()const {return this->lista_resultados_busqueda;};
		inline int getUtilesBusqueda()const {return this->utiles_busqueda;};
		inline Personaje** getMercado()const {return this->mercado;};
		inline int getTotalMercado()const {return this->total_mercado;};
		//METODOS
		void Bienvenida();
		void Menu();
		void Instrucciones();
		bool autenticacion(string login, string password);
		void leerFichero(string ruta);
		void guardarFichero(string ruta);
		void anadirJugador(Jugador* j);
		bool eliminarJugador(Jugador* j);
		Jugador* buscarJugador(string login);
		bool comprobarUsuario(string login);
		bool buscarJugadorporDinero(double dinero);
		void batallaporEquipos(Jugador* j1, Jugador* j2);
		void batalla1vs1(Jugador* j1, Jugador* j2);
		void informeTopCarteraPersonajes();
		void informetopPlayerRatio();
		void informeLooser();
		void informeBusinessMan();
		//SOBRECARGA DE OPERADOR <<
    	friend ostream& operator<<(ostream &flujo, const Gladiator &g);
    	//SOBRECARGA DE OPERADOR =
    	Gladiator& operator=(const Gladiator &g);
};
Gladiator::Gladiator(){	
	this->total_jugadores=0;
	this->utiles_jugadores=0;
	this->lista_jugadores=new Jugador*[total_jugadores];
	this->utiles_busqueda=0;
	this->lista_resultados_busqueda=new Jugador*[utiles_busqueda];
}

Gladiator::Gladiator(const Gladiator &g){	
	this->total_jugadores=g.getTotalJugadores();
	this->utiles_jugadores=g.getUtilesJugadores();
	this->lista_jugadores=new Jugador*[total_jugadores];
	this->utiles_busqueda=g.getUtilesBusqueda();
	this->lista_resultados_busqueda=new Jugador*[utiles_busqueda];

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
		flujo << g.lista_jugadores[i] << endl;
	}
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
	cout <<"\t1.GRUPO vs GRUPO: Cada jugador, pelea con 4 personajes diferentes contra otro jugador con el mismo numero de personajes" <<endl;
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

bool Gladiator::comprobarUsuario(string login){
	for(int i=0; i<this->utiles_jugadores; i++){
		if (this->lista_jugadores[i]->getLogin()==login)
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
	if(comprobarUsuario(j->getLogin()))
		cout << "El nombre del jugador ya existe en el sistema" << endl;
	else
		this->lista_jugadores[utiles_jugadores]=j;
		this->utiles_jugadores = utiles_jugadores+1;
	


}

void Gladiator::Bienvenida(){
char c;
	
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
		cout <<"\t\t\tPULSE <<J>> PARA CONTINUAR" <<endl; 
		cout <<endl; 
		cout <<endl;
	cin >> c;
	}while(c!='j');
}

void Gladiator::Menu(){
	char c;
	system("clear");
	

	do{
		cout << "\n<<[[ MENU PRINCIPAL ]]>>"<< endl <<endl;
	    cout << "Introduzca << i >> para ver las instrucciones"<< endl; 
	    cout << "Introduzca << p >> para ver los personajes disponibles"<< endl;
	    cout << "Introduzca << r >> para registrarte en el juego"<< endl;
	    cout << "Introduzca << l >> para logarte"<< endl;
	    cout << "Introduzca << j >> para jugar 1 vs 1"<< endl;
	    cout << "Introduzca << g >> para pelear grupo vs grupo"<< endl;
	    cout << "Introduzca << d >> para ver el dinero disponible."<< endl;
	    cout << "Introduzca << v >> para ver su grupo de personajes"<< endl;
	    cout << "Introduzca << e >> para eliminar un personaje de su grupo de heroes."<< endl;
	    cout << "Introduzca << k >> para insertar un personaje en su grupo de heroes."<< endl;
	    cout << "Introduzca << c >> para crear un personaje nuevo"<< endl;
	    cout << "Introduzca << s >> para salir"<< endl;
	    cin >> c;
	    system("clear");//limpia la pantalla
		
		switch (c){	

			case 'i':
			Instrucciones();
				break;

			case 'p':
				break;

			case 'r':
				break;

			case 'l':
				break;

			case 'j':
				break;

			case 'g':
				break;

			case 'd':
				break;

			case 'v':
				break;

			case 'e':
				break;

			case 'k':
				break;

			case 'c':
				break;

			case 's':
				break;
			
			default:
				cout << "opcion incorrecta, vuelva a escoger una opción del menu, por favor" << endl;
		}

	}while(c!='s');

}


int main(){
	Personaje *u,*i;
	u=new Personaje;
	i=new Personaje;

	Jugador *k;
	k=new Jugador;

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
	k->setDinero(74.000);
	k->setBatallasPerdidas(2);	
	k->setBatallasGanadas(8);
	k->setUtilesPersonajes(0);	

	k->insertarPersonaje(u);
	k->insertarPersonaje(i);
	cout << *k;

	


	Gladiator *t;
	t=new Gladiator;
	t->anadirJugador(k);
	t->anadirJugador(k);

	t->Bienvenida();
	t->Menu();


}