#include "pch.h"
#include "Lista.h"


Lista::Lista()
{
}

Lista::Lista(int ile)
{
	for (int i = 0; i < ile; i++)
		vec.push_back(to_string(i));
	    
	//zamiast powy¿szej linijki nie mo¿na niestety wstawiæ vec.push_back("" + i);
	//bo "(...)" jest interpretowany jako char * (³añcuch z C) a nie jako 
	//obiekt klasy string.
}

Lista::~Lista()
{
}

//string Lista::formatuj(string txt_p)
string Lista::formatuj(const string &txt_p)
{
	if (formatowanieCallback != NULL) {
		return formatowanieCallback(txt_p);
	} else {
		return txt_p; // brak formatowania
	}
}

void Lista::wypisanie()
{
	for (string txt : vec)
		cout << formatuj(txt) << endl; 
	/* a co zrobiæ jak wersja C++ (np. C++97) nie pozwala
	na u¿ycie powy¿szej konstrukcji? A to: :) */
	/*for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;   */ 
}

void Lista::setFormatowanieCallback(TFunkcjaFormatujaca fc)
{
	formatowanieCallback = fc;
}
