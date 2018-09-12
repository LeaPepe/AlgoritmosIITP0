#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmdline.h>
#include <array.h>
#include <sensor.h>
#include <main.h>
using namespace std;

static istream *iss = 0;	// Input Stream 
static ostream *oss = 0;	// Output Stream
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
		exit(1);
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
	// Verificamos que el stream este OK.
	//
	if (!idfs.good()) {
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



void readData(fstream& file, Array <int> & sensores){
	cout << "la funcion readData anda bien";
}

void querryData(istream& input, Array <int> & sensores,ostream& output){
	cout << "la funcion querryData anda bien";
}


// ---- main ---- //
int main(int argc, char * const argv[])
{
	Array <int> sensores;
	//parseo de la entrada
	cmdline cmdl(options);
	cmdl.parse(argc, argv);
	//ahora se puede trabajar con iss y oss indistintamente si es archivo o teclado/pantalla
	readData(idfs,sensores);
	querryData(iss,sensores,oss);
}

