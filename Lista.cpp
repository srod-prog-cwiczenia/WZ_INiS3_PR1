#include "pch.h"
#include "Lista.h"


Lista::Lista()
{
}

Lista::Lista(int ile)
{
	for (int i = 0; i < ile; i++)
		vec.push_back(to_string(i));
	    
	//zamiast powy�szej linijki nie mo�na niestety wstawi� vec.push_back("" + i);
	//bo "(...)" jest interpretowany jako char * (�a�cuch z C) a nie jako 
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
	/* a co zrobi� jak wersja C++ (np. C++97) nie pozwala
	na u�ycie powy�szej konstrukcji? A to: :) */
	/*for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;   */ 
}
void Lista::wypisanieZUzyciemFunktora(void* wskNaFunktor)
/*void * to tak zwany wska�nik generyczny,
to znaczy wska�nik nie na ,,pustk�'' ;) ale na dowolny element
czyli de facto jest to adres pami�ci */
{
	struct FunLicznik { // to jest funktor, czyli funkcja
		//zdefiniowana jako klasa z prze�adowaniem operatora () i 
		//taki funktor mo�e posiada� stan
	private:
		unsigned int licznik;
	public:
		FunLicznik() : licznik(0) {};
		string operator ()(const string& txt_p) { 
			return to_string(++licznik) + ". " + txt_p; }
	};

	struct FunPusty { // to jest funktor ,,pusty'', celem pr�by 
		//rzutowania wska�nika generycznego
	public:
		FunPusty() {};
		string operator ()(const string& txt_p) {
			return "DUMMY";
		}
	};

	FunPusty* licznik = (FunPusty*)wskNaFunktor; // - tak ,,wy�uskujemy'' wska�nik na funktor
	//ale nie u�ywamy go dalej z uwagi na trudno�ci z rzutowaniem (nie dzia�a licznik)
/*	FunLicznik licz, licz2;
	cout << licz("aaa") << endl;
	cout << licz2("bbb") << endl;
	cout << licz("aaa") << endl;
	cout << licz2("bbb") << endl;
	cout << licz("aaa") << endl; */ //to by�o dla test�w by sprawdzi� dzia�anie funktora
	FunLicznik licz;
	for (string txt : vec)
		cout << licz(txt) << endl;

}
void Lista::setFormatowanieCallback(TFunkcjaFormatujaca fc)
{
	formatowanieCallback = fc;
}
