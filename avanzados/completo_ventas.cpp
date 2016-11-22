#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Cliente{
    private:
        string DNI;
        string nombre;
        int edad;

    public:
        //Constructores
        Cliente();
        Cliente(const Cliente &c);
        Cliente(string DNI, string nombre, int edad);
        //Destructor
        ~Cliente();
        //Los SETS
        void setDNI(string DNI);
        void setNombre(string nombre);
        void setEdad(int edad);
        void setCliente(string DNI, string nombre, int edad);
        //Los GETS
        string getDNI() const;
        string getNombre() const;
        int getEdad() const;

        //imprimir
        void print() const;

        //SOBRECARGA DE OPERADOR =
        Cliente& operator=(const Cliente &p);
        //SOBRECARGA DE OPERADOR <<
        friend ostream& operator<<(ostream &flujo, const Cliente &p); //clase amiga
        //SOBRECARGA DE OPERRADOR >>
        friend istream& operator>>(istream &flujo, Cliente &p); //clase amiga     
};

void Cliente::setDNI(string DNI){ 
    this->DNI = DNI; 
}

void Cliente::setNombre(string nombre){ 
    this->nombre = nombre; 
}

void Cliente::setEdad(int edad){ 
    this->edad = edad; 
}

void Cliente::setCliente(string DNI, string nombre, int edad){
    this->DNI = DNI;
    this->nombre = nombre; 
    this->edad = edad; 
}

string Cliente::getDNI() const{
    return this->DNI; 
}

string Cliente::getNombre() const{ 
    return this->nombre; 
}

int Cliente::getEdad() const{ 
    return this->edad; 
}

Cliente::Cliente(){
    this->DNI = "NULL";
    this->nombre = "NULL";
    this->edad = 0;
}

Cliente::Cliente(const Cliente &c){
    this->DNI = c.getDNI();
    this->nombre = c.getNombre();
    this->edad = c.getEdad();
}

Cliente::Cliente(string DNI, string nombre, int edad){
    this->DNI = DNI;
    this->nombre = nombre;
    this->edad = edad;
}

Cliente::~Cliente(){
    //no hace nada porque sólo tiene variables estáticas
    this->DNI = "NULL";
    this->nombre = "NULL";
    this->edad = 0;
}

void Cliente::print() const{
    cout << "\tImpresión de Cliente: " << endl;
    cout << "\tDNI: " << this->DNI << endl;
    cout << "\tNombre: " << this->nombre << endl;
    cout << "\tEdad: " << this->edad << endl;
    cout << endl;
}

ostream& operator<<(ostream &flujo, const Cliente &p){
    flujo << "\tImpresión de Cliente: " << endl;
    flujo << "\tDNI: " << p.getDNI() << endl;
    flujo << "\tNombre: " << p.getNombre() << endl;
    flujo << "\tEdad: " << p.getEdad() << endl;
    flujo << endl;
}

istream& operator>>(istream &flujo, Cliente &p){
    string  name,codigo;
    int anos;
    cout <<  "introduzca el DNI del cliente: ";
    flujo >>codigo;
    p.setDNI(codigo);
    cout << endl;
    cout <<  "introduzca el nombre del cliente: ";
    flujo >>name;
    p.setNombre(name);
    cout << endl;
    cout <<  "introduzca la edad del cliente: ";
    flujo >> anos;
    p.setEdad(anos);
    cout << endl;
}

Cliente& Cliente::operator=(const Cliente &p){
    this->DNI=p.getDNI();
    this->nombre=p.getNombre();
    this->edad=p.getEdad();
}
//-----------------------hasta aqui el cliente-----------------------------------------------------------

class Vendedor {
    private:
        string DNI;
        string nombre;
        int edad;
        Cliente *vector_clientes;
        int dim_actual;
        int utiles;

    public:
        //Funcionalidad Mínima
        Vendedor();
        Vendedor(const Vendedor& v);
        ~Vendedor();
        //Los SETS
        void setDNIVendedor(string DNI);
        void setNombreVendedor(string nombre);
        void setEdadVendedor(int edad);
        void setUtilesVendedor(int utiles);
        void setDimActualVendedor(int dim_actual);
        void setVectorClientes(Cliente *vector_clientes);
        void SetVendedor(string DNI, string nombre, int edad, Cliente *nuevo);
        //Los GETS
        string getDNIVendedor() const;
        string getNombreVendedor() const;
        int getEdadVendedor() const;
        int getUtilesVendedor() const;
        int getDim_ActualVendedor() const;
        Cliente getAtributos(int p)const;
        //imprimir
        void printVendedor() const;
        //SOBRECARGA DE OPERADOR =
        Vendedor& operator=(const Vendedor &v);
        //SOBRECARGA DE OPERADOR <<
        friend ostream& operator<<(ostream &flujo, const Vendedor &v);
        //SOBRECARGA DE OPERADOR >>
        friend istream& operator>>(istream &flujo, Vendedor &v);
        //SOBRECARGA DE OPERADOR []
        const Cliente& operator[](int i) const;
        //Funcionalidad Avanzada
        void vender(const Cliente &c);
        Cliente getCliente(int pos) const;
};

void Vendedor::setDNIVendedor(string DNI){ 
    this->DNI = DNI; 
}

void Vendedor::setNombreVendedor(string nombre){
    this->nombre = nombre; 
}

void Vendedor::setEdadVendedor(int edad){ 
    this->edad = edad; 
}

void Vendedor::setVectorClientes(Cliente *vector_clientes){
    this->vector_clientes=vector_clientes;
}

void Vendedor::SetVendedor(string DNI, string nombre, int edad, Cliente *vector_clientes){
    this->DNI = DNI; 
    this->nombre = nombre;
    this->edad = edad;
    this->vector_clientes=vector_clientes;
}

void Vendedor::setUtilesVendedor(int utiles){
    this->utiles=utiles;
}

void Vendedor::setDimActualVendedor(int dim_actual){
    this->dim_actual=dim_actual;
}

string Vendedor::getDNIVendedor() const{ 
    return this->DNI; 
}

string Vendedor::getNombreVendedor() const{ 
    return this->nombre; 
}

int Vendedor::getEdadVendedor() const{ 
    return this->edad; 
}

int Vendedor::getUtilesVendedor() const{ 
    return this->utiles; 
}

int Vendedor::getDim_ActualVendedor() const{ 
    return this->dim_actual; 
}

Cliente Vendedor::getAtributos(int p)const{
    return this->vector_clientes[p];
}

Vendedor::Vendedor(){
    this->DNI = "NULL";
    this->nombre = "NULL";
    this->edad = 0;
    this->dim_actual = 10;
    this->utiles = 0;
    this->vector_clientes = new Cliente[10];
    if (!this->vector_clientes){
        cerr << "Error en la creación del vector de clientes" << endl;
        exit(-1);
    }
}

Vendedor::Vendedor(const Vendedor &v){
    this->DNI = v.getDNIVendedor();
    this->nombre = v.getNombreVendedor();
    this->edad = v.getEdadVendedor();
    //ASIGNACIÓN DEL ARRAY CLIENTES
    //Borro
    //delete [] this->vector_clientes; //SOBRA PORQUE ESTÁS CONSTRUYENDO EL OBJETO Y NO HAY NADA RESERVADO!!
    //Reservo con el tamaño del array del vendedor que me pasan
    this->vector_clientes = new Cliente[v.getDim_ActualVendedor()];
    if (!this->vector_clientes){
        cerr << "Error en la creación del vector de clientes" << endl;
        exit(-1);
    }
    //Asigno las útiles y la dimensión
    this->dim_actual = v.getDim_ActualVendedor();
    this->utiles = v.getUtilesVendedor();
    //Copio los valores
    for (int i=0; i < this->dim_actual; i++)
        this->vector_clientes[i] = v.getCliente(i);
}

Vendedor::~Vendedor(){
    this->DNI = "NULL";
    this->nombre = "NULL";
    this->edad = 0;
    //Ahora hay que liberar la memoria reservada del vector clientes
}

Vendedor& Vendedor::operator=(const Vendedor &v){
    this->DNI = v.getDNIVendedor();
    this->nombre = v.getNombreVendedor();
    this->edad = v.getEdadVendedor();

    if (v.getDim_ActualVendedor() > this->dim_actual){ //redimensiono el vector_clientes
        Cliente *auxiliar;
        auxiliar=new Cliente[this->dim_actual*2]; //asignamos a la auxiliar un nuevo tamaño
        for(int i=0; i<this->utiles; i++)
            auxiliar[i]=this->vector_clientes[i];//copiamos el contenido del vector
        delete[]this->vector_clientes;//borramos
        this->vector_clientes=auxiliar;//reasignamos punteros


    }else{//borro y reservo el nuevo espacio y copio los valores
        //Primero borro
        delete [] this->vector_clientes;
        //Reservo con el tamaño del array del vendedor que me pasar
        this->vector_clientes = new Cliente[v.getDim_ActualVendedor()];
        if (!this->vector_clientes){
            cerr << "Error en la creación del vector de clientes" << endl;
            exit(-1);
        }
        //Asigno las útiles y la dimensión
        this->dim_actual = v.getDim_ActualVendedor();
        this->utiles = v.getUtilesVendedor();
        //Copio los valores
        for (int i=0; i < this->dim_actual; i++)
            this->vector_clientes[i] = v.getCliente(i);
    }
}

void Vendedor::printVendedor() const{
    cout << "Impresión de Vendedor: " << endl;
    cout << "DNI: " << this->DNI << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "Estos son los clientes que posee el vendedor:" <<endl;
        for(int i=0; i<this->utiles; i++){
            this->vector_clientes[i].print();
        }
    cout << endl;
}

ostream& operator<<(ostream &flujo, const Vendedor &v){
    flujo << "Impresión de Vendedor: " << endl;
    flujo << "DNI: " << v.getDNIVendedor() << endl;
    flujo << "Nombre: " << v.getNombreVendedor() << endl;
    flujo << "Edad: " << v.getEdadVendedor() << endl;
    flujo << "Estos son los clientes que posee el vendedor:" <<endl;
        for(int i=0; i<v.getUtilesVendedor(); i++){
            if(!v.getUtilesVendedor())
                v.getAtributos(i);
         }
    flujo << endl;
}

istream& operator>>(istream &flujo, Vendedor &v){
    string  name,codigo;
    int anos;
    cout <<  "introduzca el DNI del vendedor: ";
    flujo >>codigo;
    v.setDNIVendedor(codigo);
    cout << endl;
    cout <<  "introduzca el nombre del vendedor: ";
    flujo >>name;
    v.setNombreVendedor(name);
    cout << endl;
    cout <<  "introduzca la edad del vendedor: ";
    flujo >> anos;
    v.setEdadVendedor(anos);
    cout << endl;
}

const Cliente& Vendedor::operator[](int i) const{
    if(i<utiles)
        return vector_clientes[i];
    else
        cout << "En esa posición no hay ningún comprador" <<endl;
}

//Funcionalidad Avanzada
void Vendedor::vender(const Cliente &c){
    this->vector_clientes[utiles]=c;
    this->utiles=utiles+1;
}

Cliente Vendedor::getCliente(int pos) const{ //devuelve un cliente
    if(pos>=utiles)
        return vector_clientes[pos];   
}
//-----------------------hasta aqui el vendedor-----------------------------------------------------------
int main(){

    Vendedor pedro,lolo,maria;
    Cliente juan,andres;
    Cliente *pablo;

    //Prueba de puntero a cliente
    pablo=new Cliente;
    pablo->setCliente("456455","pablito",45);
    pablo->print();

    //Prueba del operator << de cliente
    juan.setDNI("12321213");
    juan.setNombre("juanillo");
    juan.setEdad(24);
    cout << juan;

    //Prueba de setcliente
    andres.setCliente("1321213","andres",54);
    cout << andres;

    pedro.setDNIVendedor("321213");
    pedro.setNombreVendedor("peter");
    pedro.setEdadVendedor(35);

    maria.SetVendedor("324234","mari",24,pablo);
    maria.printVendedor();
    
    //Prueba de operator = de vendedor
    lolo=pedro;
    //Prueba de operator << de vendedor
    cout << lolo;

    //Prueba de metodo getCliente
    pedro.getCliente(5);

    
    //Prueba del metodo vender que inserta un cliente en vendedor
    pedro.vender(juan);
    pedro.vender(andres);
    pedro.printVendedor();

    //Prueba de operator >> de cliente
    Cliente a;
    cin >> a;
    cout << a;
    //Prueba de operator >> de vendedor
    Vendedor b;
    cin >> b;
    cout << b; 


    //Prueba de operator []
    cout << "operator []" << endl;
    cout << "cliente de la posición(solo 0 o 1 que son los clientes que tengo en el vector): ";
    int r;
    cin >>r;
    cout << pedro[r] << endl;
}