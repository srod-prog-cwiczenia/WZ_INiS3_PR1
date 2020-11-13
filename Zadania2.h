#pragma once
class Zadania2 {
public:
	struct DaneOso { //klasa wewn�trzna
		string imie, nazwisko;
		unsigned int wiek;
		DaneOso(string imie_p, string nazwisko_p, unsigned int wiek_p) :
			imie(imie_p), nazwisko(nazwisko_p), wiek(wiek_p) {};
		/* prze�adowanie operatora negacji */
		bool operator! () {
			return imie.empty() && nazwisko.empty() && !wiek; 
			/*zamiast wiek == 0 mo�na napisa� po prostu !wiek, bo 
			int jest rzutowane do bool wed�ug schematu: 0 -> false, 
			wszystko inne r�ne od zera -> true */
		}
		/* prze�adowanie operatora rzutowania */
		operator string() {
			return imie + " " + nazwisko + " " + to_string(wiek);
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