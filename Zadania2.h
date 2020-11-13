#pragma once
class Zadania2 {
public:
	struct DaneOso { //klasa wewnêtrzna
		string imie, nazwisko;
		unsigned int wiek;
		DaneOso(string imie_p, string nazwisko_p, unsigned int wiek_p) :
			imie(imie_p), nazwisko(nazwisko_p), wiek(wiek_p) {};
		/* prze³adowanie operatora negacji */
		bool operator! () {
			return imie.empty() && nazwisko.empty() && !wiek; 
			/*zamiast wiek == 0 mo¿na napisaæ po prostu !wiek, bo 
			int jest rzutowane do bool wed³ug schematu: 0 -> false, 
			wszystko inne ró¿ne od zera -> true */
		}
		/* prze³adowanie operatora rzutowania */
		operator string() {
			return imie + " " + nazwisko + " " + to_string(wiek);
		}
        /* prze³adowanie operatorów porównañ (== i !=) */
		bool operator == (const DaneOso& a) {
			return a.imie == imie && a.nazwisko == nazwisko && a.wiek == wiek;
		}
		bool operator != (const DaneOso& a) {
			//return a.imie != imie || a.nazwisko != nazwisko || a.wiek != wiek;
			return !(*this == a);
		}
		/*równowa¿nie mo¿na napisaæ to tak:*/
		/*friend bool operator == (const DaneOso& a, const DaneOso& b) {
			return a.imie == b.imie && a.nazwisko == b.nazwisko && a.wiek == b.wiek;
		}*/
		/*friend bool operator != (const DaneOso& a, const DaneOso& b) {
			return !(a == b);
		}*/
	};
	static void podkreslenie();
	static void przekazywanieZmiennych();
	static void zadaniaZeWskaznikow();
	static void przeciazanieOperatorow();
	static void zadaniaZObiektow();
protected:
	static int* losowaTabIntFactory(unsigned int& dlugosc_p, unsigned int zadanyRozmiar = 0);
};