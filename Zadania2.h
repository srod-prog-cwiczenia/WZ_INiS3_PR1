#pragma once
class Zadania2 {
public:
	struct DaneOso { //klasa wewnêtrzna
		string imie, nazwisko;
		unsigned int wiek;
		DaneOso(string imie_p, string nazwisko_p, unsigned int wiek_p) :
			imie(imie_p), nazwisko(nazwisko_p), wiek(wiek_p) {};
		bool operator! () {
			return !imie.empty() || !nazwisko.empty() || wiek; 
			/*zamiast wiek != 0 mo¿na napisaæ po prostu wiek, bo 
			int jest rzutowane do bool wed³ug schematu: 0 -> false, 
			wszystko inne ró¿ne od zera -> true */
		}
	};
	static void podkreslenie();
	static void przekazywanieZmiennych();
	static void zadaniaZeWskaznikow();
	static void przeciazanieOperatorow();
	static void zadaniaZObiektow();
protected:
	static int* losowaTabIntFactory(unsigned int& dlugosc_p, unsigned int zadanyRozmiar = 0);
};