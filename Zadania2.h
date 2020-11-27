#pragma once
class Zadania2 {
public:
	struct DaneOso { //klasa wewnêtrzna
		string imie, nazwisko;
		unsigned int wiek;
		DaneOso(string imie_p, string nazwisko_p, unsigned int wiek_p) :
			imie(imie_p), nazwisko(nazwisko_p), wiek(wiek_p) {};
		/* prze³adowanie operatora negacji */
		bool operator! () const {
			return imie.empty() && nazwisko.empty() && !wiek; 
			/*zamiast wiek == 0 mo¿na napisaæ po prostu !wiek, bo 
			int jest rzutowane do bool wed³ug schematu: 0 -> false, 
			wszystko inne ró¿ne od zera -> true */
		}
		/* prze³adowanie operatora rzutowania */
		operator string() const {
			return imie + " " + nazwisko + " " + to_string(wiek);
		}
        /* prze³adowanie operatorów porównañ (== i !=) */
		bool operator == (const DaneOso& a) const {
			return a.imie == imie && a.nazwisko == nazwisko && a.wiek == wiek;
		}
		bool operator != (const DaneOso& a) const {
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
		/* TODO: prze³adowaæ operatory: < > <= >= dwoma konstrukcjami 
		(friend bool operator < (const DaneOso& a, const DaneOso& b),
		lub bool operator(const DaneOso& a), aktywowaæ tylko jedn¹ z nich 
		UWAGA: pola z obiektu this wy³uskujemy przez this-> */
	    /* przeci¹¿yæ + i += */
		friend bool operator < (const DaneOso& a, const DaneOso& b) {
			// taka postaæ prze³adowania jest wymagana gdy 
			// u¿ywamy DaneOso jako klucze np w mapowaniu przez std::map
			if (a.nazwisko < b.nazwisko) return true;
			if (a.nazwisko > b.nazwisko) return false;
			if (a.imie < b.imie) return true;
			if (a.imie > b.imie) return false;
			if (a.wiek < b.wiek) return true;
			return false;
		}
		/*bool operator < (const DaneOso& a) {
			//return (string)(*this) < (string)a; //- dlaczego 
			// nie przechodzi rzutowanie a na string - odpowiedŸ : 
			// brakowa³o const {} w prze³adowaniu rzutowania (string).
			if (nazwisko < a.nazwisko) return true;
			if (nazwisko > a.nazwisko) return false;
			if (imie < a.imie) return true;
			if (imie > a.imie) return false;
			if (wiek < a.wiek) return true;
			return false;
		}*/
		DaneOso operator + (const DaneOso& a) {
			return DaneOso(this->imie + " " + a.imie, 
				this->nazwisko + " " + a.nazwisko,
				this->wiek + a.wiek);
		}//TODO: napisaæ to samo ale z u¿yciem konstrukcji friend 
		DaneOso &operator += (const DaneOso& a) {
			this->imie += a.imie;
			this->nazwisko += a.nazwisko;
			this->wiek += a.wiek;
			return *this;
		}
	};  
	static void podkreslenie();
	static void przekazywanieZmiennych();
	static void zadaniaZeWskaznikow();
	static void przeciazanieOperatorow();
	static void zadaniaZObiektow();
	static void mapowanieOsoKwota();
	static void zadaniaZFunktorow();
protected:
	static int* losowaTabIntFactory(unsigned int& dlugosc_p, unsigned int zadanyRozmiar = 0);
	typedef map<DaneOso, double> TMapaOsoKwota;
};
