#include "pch.h"
#include "Zadania2.h"
#include "ListaFormatowana.h"

void Zadania2::podkreslenie() {
	cout << "-----------------------------------\n";
}

void Zadania2::przekazywanieZmiennych()
{
  //TODO: przetestowa� trzy sposoby przekazywania parametr�w:
	//przez warto�� (int p), przez zmienn� (int &p) i przez
	//wska�nik (int *p)
	class Parametry {
	public:
		static void f1(int p) { //przez warto�� - ju� w j�zyku C
			p += 7;
		}; 
		static void f2(int& p) { //przez zmienn� - tylko C++
			p += 7;
		}
		static void f3(int* p) {//przez wska�nik - j�zyk C, i to tam by�a jedyna metoda na przekazanie zmiennej
			*p += 7;
		}
	};
	for (int k = 0; k < 3; k++) {
		int p = 1;
		string opis;
		switch (k) {
		case 0:
			Parametry::f1(p);
			opis = "Przez warto��: ";
			break;
		case 1:
			Parametry::f2(p);
			opis = "Przez zmienn�: ";
			break;
		case 2:
			Parametry::f3(&p);
			opis = "Przez wska�nik: ";
			break;
		}
		cout << opis << p << endl;
	}
}

void Zadania2::zadaniaZeWskaznikow() {
	cout << "TODO: zadanie ze wskaznikow\n";
	//zadanie pierwsze
	//napisa� ilustracj� dzia�ania wska�nika na int,
	//tzn zaalokowa� wska�nik, nada� mu warto�� a potem zwolni� wska�nik:
	{
		int* wskI = new(int);
		*wskI = 7;
		assert(*wskI == 7); //test poprawno�ci alokacji 
		delete wskI;
	}
	//-------------------------
	//zadanie drugie: napisa� kod kt�ry wskazuje na zmienn� int i
	//i sprawdza (przez assert) czy ten wska�nik faktycznie wskazuje na 7.
	{
		int i = 7;
		int* wskI = &i; //tu tworzymy wskazanie na zmienn� i
		assert(*wskI == 7); //test poprawno�ci wskazania
	}
	//zadanie trzecie (napisa� sumowanie liczb w tablicy ale 
	//za pomoc� wska�nik�w).
	{
		//TODO zadanie domowe: opracowa� przebieg
		//ale z generowaniem ''losowej'' tablicy o ''losowym''
		//rozmiarze np od 2 -- 100;
		int tab[] = { 30, 31, 20, 5 };
		int sigma = 0;
		for (int el : tab) sigma += el;
		cout << "Suma tablicy wyliczona klasycznie to: " << sigma << endl;
		// to samo ale na wska�nikach:
		int* wskI = tab; //aby wskaza� jawnie rzutowanie
		// to mo�na u�y� tej konstrukcji int *wskI = (int *)tab;
		int sigma2 = 0;

		for (int j = 0; j < sizeof(tab) / sizeof(tab[0]); j++) {
			sigma2 += *(wskI++);
		}
		cout << "Suma tablicy wyliczona wskaznikami to: " << sigma2 << endl;
	}
	{
		// zadanie czwarte:
		// maj�c dan� deklaracj� dwuwymiarowej tablicy:
		int tab2[10][10];
		// uzupe�ni� j� iloczynami (klasyczne rozwi�zanie - banalne)
		// ale u�ywaj�c technologii wska�nik�w:
		//int** wskI = (int **)tab2; //�le!!! bo tab2 to tak naprawd� int*
		int* wskI = (int*)tab2;
		for (int i = 0; i < 100; i++) {
			*(wskI++) = (i / 10 + 1) * (i % 10 + 1);
		}
		for (int i = 0; i < 10; (i++, cout << endl))
			for (int j = 0; j < 10; j++)
				cout << tab2[i][j] << "\t";

	}
}

int* Zadania2::losowaTabIntFactory(unsigned int& dlugosc_p, unsigned int zadanyRozmiar)
{
	//generowanie ''losowej'' tablicy o ''losowym''
	//rozmiarze np od 10 -- 110 
	if (zadanyRozmiar) {
		dlugosc_p = zadanyRozmiar;
	}
	else {
		dlugosc_p = 10 + rand() % 100;
	}
	int* tab = new int[dlugosc_p];
	for (unsigned int j = 0; j < dlugosc_p; j++)
		tab[j] = rand() % 1000;
	/*for (int j = 0; j < dlugosc_p; j++)
		cout << tab[j] << ", ";
	cout << endl;*/
	return tab;
	//delete[] tab;
}

void Zadania2::zadaniaZObiektow() {
	//std::cout << "Hello World!\n"; 
	Lista li(10);
	li.wypisanie();
	podkreslenie();
	//�w : napisa� to samo co wy�ej ale u�ywaj�c new (podobnie jak w C#)
	Lista* li2 = new Lista(5); //gwiazdka oznacza �e li2 jest ,,wska�nikiem'' (=pointerem).
	li2->wypisanie(); // operator -> to operator 
	delete li2;
	/*przypomnijmy �e w C# powy�sza sekwencja kodu by wygl�da�a tak:
	  Lista li2 = new Lista(5);
	  li2.wypisanie();
	*/
	/*string txt;
	cin >> txt;*/
	podkreslenie();
	// a teraz u�yjemy klasy potomnej ListaSformatowana
	ListaFormatowana* lf = new ListaFormatowana(5);
	lf->wypisanie();
	delete lf;
	/*TODO: 1. zdefiniowa� typ funkcyjny (,,wska�nik na funkcj�") 
	funkcji formatuj�cej string -> string [DONE]
	2. Wprowadzi� zmienn� (pole klasy Lista) funkcyjn� tego typu
	i inicjowa� je w klasie Lista. [DONE]
	3. Gdy b�dzie ustawione to pole to je uruchamia� [DONE]
	4. Zaimplementowa� to do formatowania listy �a�cuch�w z klasy 
	Lista*/
	cout << "\nFormatowanie z uzyciem callbacka:\n";
	Lista li3(10);
	li3.setFormatowanieCallback([](const string& txt_p) -> string {
		return txt_p + ".";
		});
	li3.wypisanie();
	podkreslenie();
}
void Zadania2::mapowanieOsoKwota()
{
	/*
	* 
	zadanie : zadeklarowa� obiekt typu map kt�ry mapuje DaneOso na kwot�.
	Doda� dane testowe i oprogramowa� sczytywanie kwoty 
	dla podanej osoby ,,z r�ki''.
	*/
	/*funkcja lokalna (zwana ,,lambda funkcj�'') do wydrukowania zawarto�ci mapy  */
	auto wypisanieMapyOsoKwota = [] (const TMapaOsoKwota & map) -> void {
		for (const auto &ele : map) {
			cout << (string)ele.first << " -> " << ele.second << endl;
		}
	};
	TMapaOsoKwota mapOsoKw;
	DaneOso tabOso[3] = { {"Anna", "Kowalska", 25}, {"Adam", "Kowalski", 26},
		{"Dorota", "Nowak", 20 } };
	double kw = 0.0;
	for (const auto &oso : tabOso)
		mapOsoKw[oso] = (kw += 1000.0);
	wypisanieMapyOsoKwota(mapOsoKw);
	for (;;) {
		string imie, nazwisko;
		unsigned int wiek;
		cout << "Imie: ";
		cin >> imie;
		if (imie.empty()) break;
		cout << "Nazwisko: ";
		cin >> nazwisko;
		if (nazwisko.empty()) break;
		cout << "Wiek: ";
		cin >> wiek;
		if (!wiek) break;
		DaneOso oso = { imie, nazwisko, wiek };
		if (mapOsoKw.find(oso) != mapOsoKw.end())
			cout << mapOsoKw[oso] << endl;
		else
			cout << "Nie ma takiej osoby w mapie\n";
	}
	//wypisanieMapyOsoKwota(mapOsoKw);
}

void Zadania2::zadaniaZFunktorow()
{
	struct FunLicznik { // to jest funktor, czyli funkcja
	//zdefiniowana jako klasa z prze�adowaniem operatora () i 
	//taki funktor mo�e posiada� stan
	private:
		unsigned int licznik;
	public:
		FunLicznik() : licznik(0) {};
		string operator ()(const string& txt_p) {
			return to_string(++licznik) + ". " + txt_p;
		}
	};
	FunLicznik licz;
	Lista li(10);
	li.wypisanieZUzyciemFunktora(&licz);
}

void Zadania2::zadaniaZSzablonow()
{
	/*utworzy� szablon na trzymanie dw�ch (a potem wi�cej - ,,stos'')
	element�w dowolnego typu.*/
	TPara<string> p2("Ala", "As");
	cout << p2.getX() << " i " << p2.getY() << endl;

	TPara<unsigned int> i2(7, 13);
	cout << i2.getX() << " i " << i2.getY() << endl;
	/*zadanie: napisa� szablon TStos kt�rego interface
	jest w Zadania2 jako TStosInteface */
	//przyk�adowa konkretyzacja:
	TStos<int> iStack;
	iStack.push(13);
}

void Zadania2::przeciazanieOperatorow()
{
	/*zadanie : utworzy� struktur� DaneOso (jako klas� wewn�trzn� klasy Zadania2)
	* w kt�rej
	* b�d� dane typu: imie, nazwisko, wiek.
	* Przeci��y� odpowiednio operatory por�wnania < > oraz ! i ==.
	*
	* Temat na nast�pne zaj�cia: A potem przeczyta� albo om�wi� dlaczego stosujemy
	* przeci��enie postaci operator()
	*/
	DaneOso oso1("Adam", "Kowalski", 25);
	DaneOso oso2 = { "Anna", "Nowak", 20 };
	DaneOso* oso3 = new DaneOso("Andrzej", "Kowalski", 30);
	delete oso3;
	/* je�li nie chcemy ,,panowa�'' sami nad usuwaniem wska�nika
	przez delete to mo�emy u�y� np. auto_ptr (s� to tak zwane "smart pointers": */
	auto_ptr<DaneOso> oso4(new DaneOso("Andrzej", "Kowalski", 30));
	//...i nie trzeba ju� wsk�nika oso4 zwalnia� 
//testy negacji
	assert(!!oso1 && !!oso2); /*!! - pierwszy wykrzyknik od lewej to boolowska
							  negacja, drugi wykrzyknik to prze�adowana negacja na DaneOso*/
	assert(!DaneOso("", "", 0));
//testy rzutowania:
	cout << (string)oso1 << endl;
	cout << (string)oso2 << endl;
//testy operator�w por�wna�:
	assert(!(oso1 == oso2));
	assert(DaneOso("Adam", "Nowak", 23) == DaneOso("Adam", "Nowak", 23));
	assert(oso1 != oso2);
	assert(!(DaneOso("Adam", "Nowak", 23) != DaneOso("Adam", "Nowak", 23)));
//testy operator�w sumy:
	cout << (string)(oso1 + oso2) << endl;
//test +=:
	DaneOso oso5 = oso1;
	oso5 += oso2;
	cout << (string)oso5;
	cout << "Testy przesz�y prawid�owo." << endl;
}
