#include<iostream>
#include<fstream>
#include<string>
#include <vector>

#include "Nagłówek.h"

/**  Funkcja main, punkt wyjścia do wykonywania programu

@param  argc liczba parametrow przy uruchomieniu programu
@param  argv tablica wskaznikow na lancuchy uzytych przy uruchomienieu programu

@return jeśli program wykonał się prawidłowo zwracane jest 0
*/
int main(int argc, const char* argv[])
{
	string osoby, opis, wyjsciowy;
	string napis;
	if (argc == 7)
	{
		for (int i = 0; i < argc - 1; i++)
		{
			napis = argv[i];
			if(napis == "-inper")
				osoby= argv[i + 1];
			else if(napis== "-insub")
				opis = argv[i + 1];
			else if(napis == "-out")
				wyjsciowy= argv[i + 1];
		}
	}
	else
	{
		cout << "Potrzebne parametry do poprawnego wlaczenia programu\n-inper \tplik z osobami \n-insub \tplik z ocenami \n-out \tplik wyjsciowy\n"<< endl;
		return 0;
	}
	menu(osoby, opis, wyjsciowy);
}
