/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Iker Martin Gamez
 * @date Dic 16th 2022
 * @brief Max Vowel Word
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int CounterVocals(string word);
void Usage(int argc, char *argv[]);
void Usage(int argc, char *argv[]){
    if(argc != 2) {
        cout <<argv[0] <<": Falta el nombre del fichero" <<endl;
        cout <<"Pruebe" << argv[0] <<": --help para más información" <<endl;
        exit(EXIT_SUCCESS);
    }
    string parameter{argv[1]};
    if(parameter == "--help"){
        const string kHelperText = "Este programa busca la palabra que más \ 
    vocales tenga en el fichero que se le pase como parámetro por línea \
    y son impresas en el segundo fichero";
    cout << kHelperText << endl;
    exit(EXIT_SUCCESS);
    }
}
int CounterVocals(string word)
{
  int counter = 0;
  for(int i = 0; i < word.size(); i++)
  {
    if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U')
    {
      counter++;
    }
  }
  return counter;
}
int main(int argc, char *argv[])
{
  Usage(argc, argv);
  ifstream fichero("text1.txt");
  vector <string> words;
  string word;
  while(fichero >> word)
  {
    words.push_back(word);
  }
  string maxpos = words[0];
  for(int i = 1; i < words.size(); i++)
  {
    if(CounterVocals(words[i]) > CounterVocals(maxpos))
    {
      maxpos = words[i];
    }
  }
  ofstream file("text2.txt");
  file << maxpos << endl;
  fichero.close();
  file.close();
  return 0;
}