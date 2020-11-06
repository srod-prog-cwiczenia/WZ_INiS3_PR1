#pragma once
class Zadania2 {
public:
	struct DaneOso { //klasa wewnętrzna
		string imie, nazwisko;
		unsigned int wiek;
		DaneOso(string imie_p, string nazwisko_p, unsigned int wiek_p) :
			imie(imie_p), nazwisko(nazwisko_p), wiek(wiek_p) {};
	};
	static void przekazywanieZmiennych();
	static void zadaniaZeWskaznikow();
	static void przeciazanieOperatorow();
protected:
	static int* losowaTabIntFactory(unsigned int& dlugosc_p, unsigned int zadanyRozmiar = 0);
};