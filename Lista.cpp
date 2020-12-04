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
void Lista::wypisanieZUzyciemFunktora(void* wskNaFunktor)
/*void * to tak zwany wskaŸnik generyczny,
to znaczy wskaŸnik nie na ,,pustkê'' ;) ale na dowolny element
czyli de facto jest to adres pamiêci */
{
	struct FunLicznik { // to jest funktor, czyli funkcja
		//zdefiniowana jako klasa z prze³adowaniem operatora () i 
		//taki funktor mo¿e posiadaæ stan
	private:
		unsigned int licznik;
	public:
		FunLicznik() : licznik(0) {};
		string operator ()(const string& txt_p) { 
			return to_string(++licznik) + ". " + txt_p; }
	};

	struct FunPusty { // to jest funktor ,,pusty'', celem próby 
		//rzutowania wskaŸnika generycznego
	public:
		FunPusty() {};
		string operator ()(const string& txt_p) {
			return "DUMMY";
		}
	};

	FunPusty* licznik = (FunPusty*)wskNaFunktor; // - tak ,,wy³uskujemy'' wskaŸnik na funktor
	//ale nie u¿ywamy go dalej z uwagi na trudnoœci z rzutowaniem (nie dzia³a licznik)
/*	FunLicznik licz, licz2;
	cout << licz("aaa") << endl;
	cout << licz2("bbb") << endl;
	cout << licz("aaa") << endl;
	cout << licz2("bbb") << endl;
	cout << licz("aaa") << endl; */ //to by³o dla testów by sprawdziæ dzia³anie funktora
	FunLicznik licz;
	for (string txt : vec)
		cout << licz(txt) << endl;

}
void Lista::setFormatowanieCallback(TFunkcjaFormatujaca fc)
{
	formatowanieCallback = fc;
}
