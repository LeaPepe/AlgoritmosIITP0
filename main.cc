
	//#include <fstream>
	//#include <iomanip>
	//#include <iostream>
	//#include <sstream>
	#include <cstdlib>
	//#include <string>
	#include <cmdline.h>
	#include <array.h>
	#include <sensor.h>
	#include <main.h>

	//using namespace std;

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
		cout << "tp0 -i [inputfile] -o [outputfile] -d [datafile](mandatory)" << endl;
		exit(0);
	}


	void readData(istream& input, Array <Sensor> & sensores){
		// variables utilizadas
		string line,token;
		istringstream lineStr;
		Sensor sensorAux;
		
		// parseo de la primera linea (nombres)
		getline(input,line);					//obtengo linea del input
		lineStr.str(line);						// la streameo
		while(getline(lineStr,token,',')){		//obtengo los valores separados por coma
			sensorAux = token;					//asigno el nombre al objeto sensor auxiliar
			sensores.push_back(sensorAux);		//pusheo al array el nuevo objeto
		}
		
		// parseo del resto de las lineas (temperaturas)
		while(getline(input,line)){
			int count = 0;
			lineStr.clear();
			lineStr.str(line);
			while(getline(lineStr,token,',')){
				sensores[count]+atof(token.c_str());
				count++;
			}
		}
	}

	void querryData(istream& input, Array <Sensor> & sensores,ostream& output){
		
		string line,token;
		
		int pos;
		size_t min,max;
		char ch;
		bool good = false;
		
		// Leo el querry linea por linea y hago las consultas
		while(getline(input,line)){
			Sensor sAux;
			istringstream lineStr;
			lineStr.str(line);
			// leo primer variable (nombre)
			getline(lineStr,token,',');
			// leo minimo y maximo, checkeando si esta bien
			if(lineStr >> min &&
				lineStr >> ch && ch == ',' &&
				lineStr >> max){
					good = true;	
			} else {
				good = false;
			}
			// si no hay nombre en la consulta, se hace un promedio de los sensores
			if(good && token.empty()){		
				for (size_t i = 0; i < sensores[0].size(); i++){
					double valor=0;
					int count=0;
					for(size_t j=0;j<sensores.size();j++){
						valor += sensores[j].getData(i);
						count++;
					}
						valor = valor/count; 
						sAux + valor;	
				}
				sAux.querry(output,min,max);
			// si hay nombre en la consulta
			}else if(good){
				sAux = token;
				pos = sensores.linear_search(sAux);
				if(pos == -1){
					output << "UNKNOWN ID" << endl;
					continue;
				}
				sensores[pos].querry(output, min, max);
			}else{
				output << "BAD QUERRY" << endl;
			}
		}
	}

	// ---- main ---- //
	int main(int argc, char * const argv[]){
		Array<Sensor> sensores;
		
		//parseo de la entrada
		cmdline cmdl(options);
		cmdl.parse(argc, argv);
		
		// lectura de datos
		readData(*idss,sensores);
		
		// imprimo sensores en pantalla
		// cout << endl << "--- Sensores ---" << endl;
		// for(int i=0;i<sensores.size();i++){
			// cout << sensores[i] << endl;
		// }
		
		// querry
		querryData(*iss,sensores,*oss);	
		
		return 0;
	}
	