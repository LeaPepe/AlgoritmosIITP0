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
	if (arg == "-") {
		iss = &cin;		// Establezco cin como flujo de entrada
	}
	else {
		ifs.open(arg.c_str(), ios::in);
		iss = &ifs;
	}
	// Verificamos que el stream este OK.
		if (!iss->good()) {
			cerr << "cannot open querry input"
				 << arg
				 << "."
				 << endl;
			exit(2);
		}
	
}

static void opt_data(string const &arg){
	
	idfs.open(arg.c_str(), ios::in);
	idss = &idfs;
	// Verificamos que el stream este OK.
	if (!idss->good()) {
		cerr << "cannot open data input"
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void opt_output(string const &arg){

	if (arg == "-") {
		oss = &cout;	// Establezco la salida estandar cout como flujo de salida
	} else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}
	// Verificamos que el stream este OK.
	if (!oss->good()) {
		cerr << "cannot open output file"
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void opt_help(string const &arg){
	cout << "tp0 -i [inputfile] -o [outputfile] -d [datafile](mandatory)"
	     << endl;
	exit(0);
}

void readData(istream& input, Array <Sensor> & sensores){
	string line;
	string token;
	float value;
	Sensor s;
	char delim;
	istringstream lineStream;
	//parseo de la primera linea (nombres)
	getline(input,line);			//obtengo linea del input
	lineStream.str(line);			// la stremeo
	while(getline(lineStream,token,',')){	//obtengo los valores separados por coma
		s = token;					//asigno el nombre al objeto sensor
		sensores.push_back(s);		//pusheo al array el nuevo objeto
	}
	line.clear();
	lineStream.clear();
	//parseo el resto de las lineas
	while(getline(input,line)){
		cout << "  ,  ";
		cout << line.size();
	}
	cout << "la funcion readData anda bien"<<endl;
}

void querryData(istream& input, Array <Sensor> & sensores,ostream& output){
	cout << "la funcion querryData anda bien"<<endl;
}

// ---- main ---- //
int main(int argc, char * const argv[]){
	Array <Sensor> sensores;
	Sensor s;
	//parseo de la entrada
	cmdline cmdl(options);
	cmdl.parse(argc, argv);
	// ahora puedo trabajar con con flujos iss idss oss
	readData(*idss,sensores);
	querryData(*iss,sensores,*oss);
	s = "CPU_sensor";
	s + 41.3 + 41.2 + 40.4;
	sensores.push_back(s);
	s.clear();
	s = "GPU_sensor";
	s + 40.2 + 41.0 + 43.2;
	sensores.push_back(s);
	cout << endl;
	for(int i=0;i<sensores.size();i++){
		cout << sensores[i] << endl;
	}
	return 0;
}