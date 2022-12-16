#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {
    Usage(argc, argv);
    string fichero{argv[1]};
    string linea;
    ifstream archivo(fichero.c_str());
    if(archivo.fail()){
        cout << "No existe el archivo!" << endl;
    return 1;
    }
    string textolimpio{""};
    while (getline(archivo, linea)) {
        for (const auto &caracter_actual : linea) {
            if (isalpha(caracter_actual) or caracter_actual == ' ') { /// Quitamos todo lo que no sea espacios o letras
                textolimpio += caracter_actual;
            }
        }
        textolimpio += ' ';
        FicheroPalabrasOrdenadas(textolimpio);
    }
    archivo.close();
    return 0;
}
void FicherosAlfabeticamente(const  string& texto) {
  string palabra{""};
  for (const auto &caracter_actual : texto) { 
    if (caracter_actual == ' ') {
      string primera_letra;
      primera_letra = toupper(palabra.at(0));
      ofstream fichero_salida{(primera_letra + ".txt"), ios::app}; 
      fichero_salida << palabra << endl;
      palabra = "";
    } else {
      palabra += caracter_actual;

    }
  }
}
