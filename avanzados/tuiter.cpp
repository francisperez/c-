//practica de tweeter creada por Francisco Manuel Pérez Casares

#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct Usuario{
	string login; //debe ser único en el sistema
	string Nombre;
	string Apellido1;
	string *tweets; //almacenará tantos tweets como el usuario haya escrito
	int dim_tweets;
	int util_tweets;
};

struct TablaUsuarios{
	Usuario** punteroapuntero;
	int totaltuplas;
	int utiltuplas;
};

//GET

string getLogin(Usuario *usuario){
	return usuario->login;
}
string getNombre(Usuario *usuario){
	return usuario->Nombre;
}
string getApellido1(Usuario *usuario){
	return usuario->Apellido1;
}
string* getTweets(Usuario *usuario){
	return usuario->tweets;
}
string getTweet(Usuario *usuario, int n){
	return usuario->tweets[n];
}
int getDimTweets(Usuario *usuario){
	return usuario->dim_tweets;
}
int getUtilTweets(Usuario *usuario){
	return usuario->util_tweets;
}
Usuario** getPunteroaPuntero(TablaUsuarios *usuarios){
	return usuarios->punteroapuntero;
}
int getTotalTuplas(TablaUsuarios *usuarios){
	return usuarios->totaltuplas;
}
int getUtilTuplas(TablaUsuarios *usuarios){
	return usuarios->utiltuplas;
}
Usuario* getUsuario (TablaUsuarios *usuarios, int numUsuario){ 
	return usuarios->punteroapuntero[numUsuario];
}
//SET 

void setLogin(Usuario *usuario, string login){
	usuario->login=login;
}
void setNombre(Usuario *usuario, string Nombre){
	usuario->Nombre=Nombre;
}
void setApellido1(Usuario *usuario, string Apellido1){
	usuario->Apellido1=Apellido1;
}
void setTweets(Usuario *usuario, string *tweets){
	usuario->tweets=tweets;
}
void setDimTweets(Usuario *usuario, int dim_tweets){
	usuario->dim_tweets=dim_tweets;
}
void setUtilTweets(Usuario *usuario, int util_tweets){
	usuario->util_tweets=util_tweets;
}
void setPunteroaPuntero(TablaUsuarios *usuarios, Usuario** punteroapuntero){
	usuarios->punteroapuntero=punteroapuntero;
}
void setTotalTuplas(TablaUsuarios *usuarios, int totaltuplas){
	usuarios->totaltuplas=totaltuplas;
}
void setUtilTuplas2(TablaUsuarios *usuarios, int utiltuplas){ //para borrar un usuario y que no se incremente
	usuarios->utiltuplas=utiltuplas;
}
void setUtilTuplas(TablaUsuarios *usuarios, int utiltuplas){
	usuarios->utiltuplas=getUtilTuplas(usuarios)+utiltuplas;
}
void setUsuario (TablaUsuarios *usuarios, Usuario *usuario){ 
	usuarios->punteroapuntero[getUtilTuplas(usuarios)] = usuario;
}
void setUnicoTweet(Usuario *usuario, string tweet){ //solo inserta un tweet
	usuario->tweets[getUtilTweets(usuario)]=tweet;
	setUtilTweets(usuario, getUtilTweets(usuario)+1);//incrementa el util tweet para la siguiente posicion
}
//*******************hasta aqui la declaracion de estructuras de get y de set************************


// declaracion de funciones:

/**
 * @brief Módulo que crea un vector dinámico de usuarios con todos sus campos
 * @param TablaUsuarios *&usuarios, estructura que contiene a los usuarios
 * @post se habrá creado un vector dinámico de usuarios 
 */
void crearTabla(TablaUsuarios *(&usuarios)){
	usuarios=new TablaUsuarios;
	usuarios->totaltuplas = 10;
	usuarios->utiltuplas = 0;
	// Apunta al vector dinámico del tamaño de totalTuplas.
	usuarios->punteroapuntero = new Usuario*[usuarios->totaltuplas];  // Reservamos memoria para el vector dinámico de los usuarios.
	for (int i=0; i<getTotalTuplas(usuarios); i++){
		usuarios->punteroapuntero[i] = new Usuario;  // Apuntamos, para cada uno de los usuarios, a su estructura de usuario
		usuarios->punteroapuntero[i]->dim_tweets = 10;    // Numero de vectores de string que vamos a reservar para cada usuario.
		usuarios->punteroapuntero[i]->tweets = new string[usuarios->punteroapuntero[i]->dim_tweets];  // reservamos la memoria para cada uno de los strings anteriores.
		usuarios->punteroapuntero[i]->util_tweets=0; // Establecemos el numero de tweets escritos a cero.
	}
}

/**
 * @brief Módulo que crea un usuario.
 * @param TablaUsuarios *&usuarios Variable usuarios en la que se guardarán los datos de entrada del módulo
 * @param string Nombre string que quiero guardar en la variable usuarios.
 * @param string login string que quiero guardar en la variable usuarios.
 * @param string Apellido1 string que quiero guardar en la variable usuarios.
 * @param string tweet puntero de tipo string que quiero guardar en la variable usuarios.
 * @param int util tweet entero que dice los utiles de tweet del vector tweet y guardamos en la variable usuarios
 * @param int dim tweet entero que dice la dimensión de tweet del vector tweet y guardamos en la variable usuarios
 * @post La variable setUsuario, tendrá guardados todos los valores que le hemos pasado al módulo.
 */
void crearUsuario(TablaUsuarios *(&usuarios), string Nombre, string login, string Apellido1, int util_tweets, int dim_tweets){
	Usuario *usuario;
	usuario = new Usuario;
	string * tweets = new string[dim_tweets];
	    if (usuario == 0){
        cerr << "El S.O. no pudo reservar memoria. Se abortará la ejecución." << endl;
        exit(-1);
    	}
    	if (tweets == 0){
        cerr << "El S.O. no pudo reservar memoria. Se abortará la ejecución." << endl;
        exit(-1);
    	}
	setNombre(usuario, Nombre);
	setLogin(usuario, login);
	setApellido1(usuario, Apellido1);
	setTweets(usuario, tweets);
	setUtilTweets(usuario, util_tweets);
	setDimTweets(usuario, dim_tweets);
	setUsuario(usuarios, usuario);
	setUtilTuplas(usuarios, 1);
}

/**
 * @brief Módulo que comprueba si un login es único o ya lo tiene un usuario
 * @param TablaUsuarios *&usuarios, estructura que contiene a los usuarios
 * @param string login, le pasamos el login de usuario
 * @post devolverá true, si se encuentra el login o false si no se encuentra.
 */
bool comprobarLogin(TablaUsuarios *(&usuarios), string login){
	Usuario *usuario;
	for (int i = 0; i<getUtilTuplas(usuarios); i++){
		usuario = getUsuario(usuarios, i);
		if (login==getLogin(usuario)){ // Si se encuentra un login igual.
			return true;
		}
	}
	return false; // No se ha encontrado ningún login igual.
}

/**
 * @brief Módulo que inserta un usuario en la variable usuarios
 * @param TablaUsuarios *&usuarios, estructura que contiene a los usuarios
 * @post insertará un usuario en la variable usuarios
 */
void insertarUsuarioTabla (TablaUsuarios *(&usuarios)){
	string login, nombre, apellido;
	do{
		cout << "Introduzca un login válido: " ;
		cin >> login;
	}while (comprobarLogin(usuarios, login));
	cout << "Introduzca su nombre: " ;
	cin >> nombre;
	cout << "Introduzca su primer apellido: " ;
	cin >> apellido;
	crearUsuario(usuarios, nombre, login, apellido, 0, 10);
}

/**
 * @brief Módulo que borra un vector dinámico de usuarios con todos sus campos
 * @param TablaUsuarios *&usuarios, estructura que contiene a los usuarios
 * @post se habrá borrado un vector dinámico de usuarios 
 */
void borrarTabla(TablaUsuarios *(&usuarios)){
	for (int i=0; i<getTotalTuplas(usuarios); i++){
		delete [] usuarios->punteroapuntero[i]->tweets;
		usuarios->punteroapuntero[i]->tweets=0;
		delete usuarios->punteroapuntero[i];
		usuarios->punteroapuntero[i]=0;
	}
	delete [] usuarios->punteroapuntero;
	usuarios->punteroapuntero=0;
}

/**
 * @brief Módulo que imprime un vector de usuarios
 * @param TablaUsuarios *&usuarios, estructura que contiene a los usuarios
 * @post se habrá impreso los usuarios y sus campos
 */
void imprimeTablaUsuario(TablaUsuarios *(&usuarios)){
	for (int i=0; i<getUtilTuplas(usuarios); i++){
		cout << "login: " << getLogin(usuarios->punteroapuntero[i]) << endl;
		cout << "nombre: " << getNombre(usuarios->punteroapuntero[i]) << endl;
		cout << "apellido1: " << getApellido1(usuarios->punteroapuntero[i]) << endl;

		for (int j=0; j<getUtilTweets(usuarios->punteroapuntero[i]); j++){
			cout << "\ttweet " << j << ": "<< getTweet(usuarios->punteroapuntero[i], j) << endl;
		}
	cout <<endl;
	}
}

/**
 * @brief Módulo que busca la posición del vector en la que se encuentra un usuario
 * @param TablaUsuarios *&usuarios, estructura que contiene a los usuarios
 * @param string login, campo por el que se busca al usuario
 * @post devuelve un entero, que es la posición del vector donde se encuentra el usuario
 */
int buscarPosicionUsuario(TablaUsuarios *(&usuarios), string login){
	Usuario *usuario;
	for (int i = 0; i<getUtilTuplas(usuarios); i++){
		usuario = getUsuario (usuarios, i);
			if (login==getLogin(usuario)){// Si se encuentra un login igual.
			return i;	
		}
	}
}

/**
 * @brief Módulo que inserta un tweet en un usuario
 * @param TablaUsuarios *&usuarios, estructura donde insertará el tweet
 * @post habrá insertado un tweet en un usuario de la estructura referenciada
 */
void insertarTweetUsuario(TablaUsuarios *(&usuarios)){
	string login;
	string tweet;
	Usuario *usuario, *usuario2;
	int n;

	do{
		cout << "Introduce tu login de usuario: ";
		cin >> login;
	}while (comprobarLogin(usuarios, login)==false); 
	
	n=buscarPosicionUsuario(usuarios, login);
	usuario=getUsuario(usuarios, n);
	cout << "tweet" << " :";
	cin.ignore(); //para que el string pueda contener espacios
	getline(cin, tweet);

	if(getDimTweets(usuario)>getUtilTweets(usuario)){ //si el tamaño de el vector es mayor que el de las utiles, inserto el tweet
		setUnicoTweet(usuario,tweet); //llama a modulo setunico tweet, que no es un puntero
	}
	else{ //si el tamaño de las utiles es mayor que la dimensión del vector, redimensiono el vector.
		int dimension;
		string *auxiliar;

		dimension=getDimTweets(usuario); 
		dimension=dimension*2;
		auxiliar=new string[dimension]; //creamos un vector con el doble de dimensión
			if (auxiliar == 0){
        		cerr << "El S.O. no pudo reservar memoria. Se abortará la ejecución." << endl;
        		exit(-1);
    		}

		for (int i=0; i<getUtilTweets(usuario); i++){ //copiamos los tweets en el nuevo vector
			auxiliar[i]=usuario->tweets[i];
		}
		delete [] usuario->tweets; //borro el antiguo vector
        usuario->tweets = 0;

        setDimTweets(usuario, dimension); //asigno la nueva dimension
       	setTweets(usuario, auxiliar); //asigno los punteros
       	setUnicoTweet(usuario, tweet); //asigno los tweets

	}
}

/**
 * @brief Módulo que imprime los tweets de un usuario
 * @param TablaUsuarios *&usuarios, estructura que contiene a los usuarios
 * @post los tweets del usuario se imprimirán
 */
void imprimirTweet(TablaUsuarios *(&usuarios)){
	string login;
	int n;
	Usuario *usuario;
	do{
		cout << "Introduce tu login de usuario: ";
		cin >> login;
	}while (comprobarLogin(usuarios, login)==false); 
	n=buscarPosicionUsuario(usuarios, login);
	usuario=getUsuario(usuarios, n);
	for (int j=0; j<getUtilTweets(usuarios->punteroapuntero[n]); j++){
		cout << "\ttweet " << j << ": "<< getTweet(usuarios->punteroapuntero[n], j) << endl;
	}
}

/**
 * @brief Módulo que ordena los usuarios por su login o por el número de tweets que tenga
 * @param TablaUsuarios *&usuarios, estructura que contiene a los usuarios
 * @post la estructura estará ordenada según el criterio elegido por el usuario.
 */
void ordenaUsuarios(TablaUsuarios *(&usuarios)){
	char opcion;
	int pos_min; //Va a almacenar el índice de la posición donde se ha encontrado el emento mas pequeño en el subsector desordenado.
	Usuario *aux;
		cout << "Inserte << l >> para ordenar los usuarios por su login" << endl;
		cout << "Inserte << t >> para ordenar los usuarios por su número de tweets" << endl;
		cin  >> opcion;
		for (int i=0; i<getUtilTuplas(usuarios)-1; i++){  //Recorre los componenetes del vector
			pos_min=i;
			for (int j=i+1; j<getUtilTuplas(usuarios); j++){ //Busca en la parte desordenada la posición del elemento mas pequeño
				if (opcion=='l' && usuarios->punteroapuntero[j]->login < usuarios->punteroapuntero[pos_min]->login){
					pos_min=j;
				}
				if (opcion=='t' && usuarios->punteroapuntero[j]->util_tweets < usuarios->punteroapuntero[pos_min]->util_tweets){
					pos_min=j;
				}
			}
		aux=usuarios->punteroapuntero[i];  
		usuarios->punteroapuntero[i]=usuarios->punteroapuntero[pos_min];
		usuarios->punteroapuntero[pos_min]=aux;
	}
}

/**
 * @brief Módulo que elimina un tweet concreto de un usuario
 * @param TablaUsuarios *&usuarios, estructura que contiene a los usuarios
 * @post el tweet estará eliminado y el vector de tweet tendra una posición menos
 */
void eliminarTweet(TablaUsuarios *(&usuarios)){
	string login;
	int n;
	Usuario *usuario;
	int tweet=0;
	do{
		cout << "Introduce tu login de usuario: ";
		cin >> login;
	}while (comprobarLogin(usuarios, login)==false); 
	n=buscarPosicionUsuario(usuarios, login);
	usuario=getUsuario(usuarios, n);
	cout << "dígame el número del tweet que desea eliminar: ";
	cin >> tweet;
	for(int i=tweet+1; i <getUtilTweets(usuario); i++){
        usuarios->punteroapuntero[n]->tweets[i-1]=usuarios->punteroapuntero[n]->tweets[i];
    }
    setUtilTweets(usuario,getUtilTweets(usuario)-1);
}

/**
 * @brief Módulo que elimina un usuario de la tabla de usuarios
 * @param TablaUsuarios *&usuarios, estructura que contiene a los usuarios
 * @post el usuario estará eliminado y el vector de usuarios tendra una posición menos
 */
void borrarUsuario(TablaUsuarios *(&usuarios)){
	string login;
	int n;
	Usuario *usuario;
	do{
		cout << "Introduce tu login de usuario: ";
		cin >> login;
	}while (comprobarLogin(usuarios, login)==false); 
	n=buscarPosicionUsuario(usuarios, login);
	usuario=getUsuario(usuarios, n);

	for (int i=n+1; i<getTotalTuplas(usuarios); i++){ //achicamos el vector en uno
		usuarios->punteroapuntero[i-1]=usuarios->punteroapuntero[i];
	}
	setUtilTuplas2(usuarios,getUtilTuplas(usuarios)-1);
}

/**
 * @brief Módulo que inserta unos usuario de ejemplo con sus respectivos tweets
 * @param TablaUsuarios *&usuarios, estructura que contiene a los usuarios
 * @post los usuarios estarán insertados
 */
void usuariosPredefinidos(TablaUsuarios *(&usuarios)){
	//primer usuario predefinido
	Usuario *francis=0;
	francis = new Usuario;
	    if (francis == 0){
        cerr << "El S.O. no pudo reservar memoria. Se abortará la ejecución." << endl;
        exit(-1);
    	}
    setLogin(francis, "@pintor");
    setNombre(francis, "francis");
    setApellido1(francis, "Pérez");
    setTweets(francis, new string[10]);
    setUtilTweets(francis,0);
    setDimTweets(francis, 10);
    setUnicoTweet(francis,"hola que haces");
    usuarios->punteroapuntero[0]->util_tweets++;
    setUnicoTweet(francis,"esto va fino");
    usuarios->punteroapuntero[0]->util_tweets++;
    setUnicoTweet(francis,"mira que bien");
    usuarios->punteroapuntero[0]->util_tweets++;
    setUnicoTweet(francis,"mira que bien");
    usuarios->punteroapuntero[0]->util_tweets++;
    setUnicoTweet(francis,"mira que bien");
    usuarios->punteroapuntero[0]->util_tweets++;
    setUnicoTweet(francis,"mira que bien");
    usuarios->punteroapuntero[0]->util_tweets++;
    setUnicoTweet(francis,"mira que bien");
    usuarios->punteroapuntero[0]->util_tweets++;
    setUnicoTweet(francis,"mira que bien");
    usuarios->punteroapuntero[0]->util_tweets++;
    setUnicoTweet(francis,"mira que bien");
    usuarios->punteroapuntero[0]->util_tweets++;
    setUnicoTweet(francis,"mira que bien");
    usuarios->punteroapuntero[0]->util_tweets++;
    usuarios->punteroapuntero[0]=francis;
    usuarios->utiltuplas++;

    	//segundo usuario predefinido
	Usuario *jaime=0;
	jaime = new Usuario;
	    if (jaime == 0){
        cerr << "El S.O. no pudo reservar memoria. Se abortará la ejecución." << endl;
        exit(-1);
    	}
    setLogin(jaime, "@profe");
    setNombre(jaime, "Jaime");
    setApellido1(jaime, "Matas");
    setTweets(jaime, new string[10]);
    setUtilTweets(jaime,0);
    setDimTweets(jaime, 10);
    setUnicoTweet(jaime,"Muy bien amiguitos");
    usuarios->punteroapuntero[1]->util_tweets++;
    setUnicoTweet(jaime,"¿Traeis impresas las transparencias?");
    usuarios->punteroapuntero[1]->util_tweets++;
    setUnicoTweet(jaime,"Tener fe en mi");
    usuarios->punteroapuntero[1]->util_tweets++;
    usuarios->punteroapuntero[1]=jaime;
    usuarios->utiltuplas++;

   	//tercer usuario predefinido
	Usuario *nestor=0;
	nestor = new Usuario;
	    if (nestor == 0){
        cerr << "El S.O. no pudo reservar memoria. Se abortará la ejecución." << endl;
        exit(-1);
    	}
    setLogin(nestor, "@canario");
    setNombre(nestor, "Nestor");
    setApellido1(nestor, "Suarez");
    setTweets(nestor, new string[10]);
    setUtilTweets(nestor,0);
    setDimTweets(nestor, 10);
    setUnicoTweet(nestor,"perdí la guagua");
    usuarios->punteroapuntero[2]->util_tweets++;
    setUnicoTweet(nestor,"que tal mullallo");
    usuarios->punteroapuntero[2]->util_tweets++;
    setUnicoTweet(nestor,"vayan por la sombrita");
    usuarios->punteroapuntero[2]->util_tweets++;
    usuarios->punteroapuntero[2]=nestor;
    usuarios->utiltuplas++;
}

/**
 * @brief Módulo que crea un menu
 * @param TablaUsuarios *nueva, estructura creada en el main()
 * @post el menu estará creado
 */
void MenuPrincipal(TablaUsuarios *nueva){
	char c;
	string login;

	do{
		cout << "\n<<[[ BIENVENIDO AL SIMULADOR DE FUNCIONAMIENTO DE UN SGBD RELACIONAL ]]>>"<< endl <<endl;
	    cout << "Esta usted en el menu principal"<< endl; 
	    cout << "Introduzca << 1 >> para crear una tabla de usuarios"<< endl; 
	    cout << "Introduzca << 2 >> para eliminar una tabla de usuarios"<< endl;
	    cout << "Introduzca << 3 >> para imprimir una tabla de usuarios"<< endl;
	    cout << "Introduzca << 4 >> para insertar un Usuario en una tabla de usuarios"<< endl;
	    cout << "Introduzca << 5 >> para eliminar un Usuario en una tabla de usuarios"<< endl;
	    cout << "Introduzca << 6 >> para buscar Usuario por Atributo Login en una tabla de usuarios"<< endl;
	    cout << "Introduzca << 7 >> para ordenar una tabla de usuarios por Atributo util_tweets o por atributo login"<< endl;
	    cout << "Introduzca << 8 >> para Insertar un Tweet en Usuario."<< endl;
	    cout << "Introduzca << 9 >> para Eliminar un Tweet de un Usuario."<< endl;
	    cout << "Introduzca << 0 >> para Imprimir los Tweets de un Usuario."<< endl;
	    cout << "Introduzca << s >> para salir"<< endl;
	    cin >> c;
	    system("clear");//limpia la pantalla
		
		switch (c){	

			case '1':
				crearTabla(nueva);
				usuariosPredefinidos(nueva);
				break;

			case '2':
				borrarTabla(nueva);
				break;

			case '3':
				imprimeTablaUsuario(nueva);
				break;

			case '4':
				insertarUsuarioTabla(nueva);
				break;

			case '5':
				borrarUsuario(nueva);
				break;

			case '6':
				cout << "introduce el login de un usuario para comprobar si se encuentra en la base de datos" <<endl;
				cin >> login;
				if (comprobarLogin(nueva, login)==false)
					cout <<"el usuario introducido no se encuentra en la base de datos" << endl;
				else
					imprimeTablaUsuario(nueva);
				break;

			case '7':
				ordenaUsuarios(nueva);
				break;

			case '8':
				insertarTweetUsuario(nueva);
				break;

			case '9':
				eliminarTweet(nueva);
				break;

			case '0':
				imprimirTweet(nueva);
				break;

			case 's':
				break;
			
			default:
				cout << "opcion incorrecta, vuelva a escoger una opción del menu, por favor" << endl;
		}

	}while(c!='s');
}

int main(){
	TablaUsuarios *nueva;
	MenuPrincipal(nueva);
}