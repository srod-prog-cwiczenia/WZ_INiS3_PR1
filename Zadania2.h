#pragma once
class Zadania2 {
public:
	struct DaneOso { //klasa wewn�trzna
		string imie, nazwisko;
		unsigned int wiek;
		DaneOso(string imie_p, string nazwisko_p, unsigned int wiek_p) :
			imie(imie_p), nazwisko(nazwisko_p), wiek(wiek_p) {};
		/* prze�adowanie operatora negacji */
		bool operator! () const {
			return imie.empty() && nazwisko.empty() && !wiek; 
			/*zamiast wiek == 0 mo�na napisa� po prostu !wiek, bo 
			int jest rzutowane do bool wed�ug schematu: 0 -> false, 
			wszystko inne r�ne od zera -> true */
		}
		/* prze�adowanie operatora rzutowania */
		operator string() const {
			return imie + " " + nazwisko + " " + to_string(wiek);
		}
        /* prze�adowanie operator�w por�wna� (== i !=) */
		bool operator == (const DaneOso& a) const {
			return a.imie == imie && a.nazwisko == nazwisko && a.wiek == wiek;
		}
		bool operator != (const DaneOso& a) const {
			//return a.imie != imie || a.nazwisko != nazwisko || a.wiek != wiek;
			return !(*this == a);
		}
		/*r�wnowa�nie mo�na napisa� to tak:*/
		/*friend bool operator == (const DaneOso& a, const DaneOso& b) {
			return a.imie == b.imie && a.nazwisko == b.nazwisko && a.wiek == b.wiek;
		}*/
		/*friend bool operator != (const DaneOso& a, const DaneOso& b) {
			return !(a == b);
		}*/
		/* TODO: prze�adowa� operatory: < > <= >= dwoma konstrukcjami 
		(friend bool operator < (const DaneOso& a, const DaneOso& b),
		lub bool operator(const DaneOso& a), aktywowa� tylko jedn� z nich 
		UWAGA: pola z obiektu this wy�uskujemy przez this-> */
	    /* przeci��y� + i += */
		friend bool operator < (const DaneOso& a, const DaneOso& b) {
			// taka posta� prze�adowania jest wymagana gdy 
			// u�ywamy DaneOso jako klucze np w mapowaniu przez std::map
			if (a.nazwisko < b.nazwisko) return true;
			if (a.nazwisko > b.nazwisko) return false;
			if (a.imie < b.imie) return true;
			if (a.imie > b.imie) return false;
			if (a.wiek < b.wiek) return true;
			return false;
		}
		/*bool operator < (const DaneOso& a) {
			//return (string)(*this) < (string)a; //- dlaczego 
			// nie przechodzi rzutowanie a na string - odpowied� : 
			// brakowa�o const {} w prze�adowaniu rzutowania (string).
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
		}//TODO: napisa� to samo ale z u�yciem konstrukcji friend 
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
