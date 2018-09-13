#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cmdline.h>
#include <array.h>
#include <sensor.h>
#include <main.h>
using namespace std;

static istream *iss = NULL;	// Input Stream 
static ostream *oss = NULL;	// Output Stream
static istream *idss = NULL;
static fstream ifs; 		// Input File Stream
static fstream ofs;		// Output File Stream
static fstream idfs;	// Input data stream

static option_t options[] = {
	{1, "d", "data", NULL, opt_data, OPT_MANDATORY},
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

static void opt_input(string const &arg){
	// Si el nombre del archivos es "-", usaremos la entrada
	// estándar. De lo contrario, abrimos un archivo en modo
	// de lectura.
	//
	if (arg == "-") {
		iss = &cin;		// Establezco la entrada estandar cin como flujo de entrada
	}
	else {
		ifs.open(arg.c_str(), ios::in); // c_str(): Returns a pointer to an array that contains a null-terminated
										// sequence of characters (i.e., a C-string) representing
										// the current value of the string object.
		iss = &ifs;
	}

	// Verificamos que el stream este OK.
	//
	if (!iss->good()) {
		cerr << "cannot open querry input"
		     << arg
		     << "."
		     << endl;
		exit(2);
	}
}

static void opt_data(string const &arg){
	// Si el nombre del archivos es "-", usaremos la entrada
	// estándar. De lo contrario, abrimos un archivo en modo
	// de lectura.
	//
	idfs.open(arg.c_str(), ios::in); // c_str(): Returns a pointer to an array that contains a null-terminated
										// sequence of characters (i.e., a C-string) representing
										// the current value of the string object.
	idss = &idfs;
	// Verificamos que el stream este OK.
	//
	if (!idss->good()) {
		cerr << "cannot open data input"
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void opt_output(string const &arg){
	// Si el nombre del archivos es "-", usaremos la salida
	// estándar. De lo contrario, abrimos un archivo en modo
	// de escritura.
	//
	if (arg == "-") {
		oss = &cout;	// Establezco la salida estandar cout como flujo de salida
	} else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	// Verificamos que el stream este OK.
	//
	if (!oss->good()) {
		cerr << "cannot open output file"
		     << arg
		     << "."
		     << endl;
		exit(1);		// EXIT: Terminación del programa en su totalidad
	}
}

static void opt_help(string const &arg){

	cout << "tp0 -i [inputfile] -o [outputfile] -d [datafile](mandatory)"
	     << endl;
	exit(0);
}



void readData(istream* input, Array <Sensor> & sensores){
	cout << "la funcion readData anda bien"<<endl;
	char ch;
	string name;
	int count = 0;
	//parseo de nombres
	while(input >> ch != endl){		//mientras no haya salto de linea
		sensores.enlarge(1);		// agradndar vector
		while(ch != ','){			//mientras no sea coma
			name = name+ch;			//alargar nombre
			input >> ch;			//siguiente caracter
		}
		sensores[count].setID(name);//setear nombre
		name.clear();				//borrar string
		count++;
	}
	//parseo de numeros despues de primer salto de lineas
}

void querryData(istream* input, Array <Sensor> & sensores,ostream* output){
	cout << "la funcion querryData anda bien"<<endl;
}


// ---- main ---- //
int main(int argc, char * const argv[])
{
	Array <Sensor> sensores;
	//parseo de la entrada
	cmdline cmdl(options);
	cmdl.parse(argc, argv);
	// ahora puedo trabajar con con flujos iss idss oss
	readData(idss,sensores);
	querryData(iss,sensores,oss);
}

