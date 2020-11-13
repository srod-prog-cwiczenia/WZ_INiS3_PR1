#include "pch.h"
#include "Zadania2.h"
#include "ListaFormatowana.h"

void Zadania2::podkreslenie() {
	cout << "-----------------------------------\n";
}

void Zadania2::przekazywanieZmiennych()
{
  //TODO: przetestowaæ trzy sposoby przekazywania parametrów:
	//przez wartoœæ (int p), przez zmienn¹ (int &p) i przez
	//wskaŸnik (int *p)
	class Parametry {
	public:
		static void f1(int p) { //przez wartoœæ - ju¿ w jêzyku C
			p += 7;
		}; 
		static void f2(int& p) { //przez zmienn¹ - tylko C++
			p += 7;
		}
		static void f3(int* p) {//przez wska¿nik - jêzyk C, i to tam by³a jedyna metoda na przekazanie zmiennej
			*p += 7;
		}
	};
	for (int k = 0; k < 3; k++) {
		int p = 1;
		string opis;
		switch (k) {
		case 0:
			Parametry::f1(p);
			opis = "Przez wartoœæ: ";
			break;
		case 1:
			Parametry::f2(p);
			opis = "Przez zmienn¹: ";
			break;
		case 2:
			Parametry::f3(&p);
			opis = "Przez wskaŸnik: ";
			break;
		}
		cout << opis << p << endl;
	}
}

void Zadania2::zadaniaZeWskaznikow() {
	cout << "TODO: zadanie ze wskaznikow\n";
	//zadanie pierwsze
	//napisaæ ilustracjê dzia³ania wskaŸnika na int,
	//tzn zaalokowaæ wskaŸnik, nadaæ mu wartoœæ a potem zwolniæ wskaŸnik:
	{
		int* wskI = new(int);
		*wskI = 7;
		assert(*wskI == 7); //test poprawnoœci alokacji 
		delete wskI;
	}
	//-------------------------
	//zadanie drugie: napisaæ kod który wskazuje na zmienn¹ int i
	//i sprawdza (przez assert) czy ten wskaŸnik faktycznie wskazuje na 7.
	{
		int i = 7;
		int* wskI = &i; //tu tworzymy wskazanie na zmienn¹ i
		assert(*wskI == 7); //test poprawnoœci wskazania
	}
	//zadanie trzecie (napisaæ sumowanie liczb w tablicy ale 
	//za pomoc¹ wskaŸników).
	{
		//TODO zadanie domowe: opracowaæ przebieg
		//ale z generowaniem ''losowej'' tablicy o ''losowym''
		//rozmiarze np od 2 -- 100;
		int tab[] = { 30, 31, 20, 5 };
		int sigma = 0;
		for (int el : tab) sigma += el;
		cout << "Suma tablicy wyliczona klasycznie to: " << sigma << endl;
		// to samo ale na wskaŸnikach:
		int* wskI = tab; //aby wskazaæ jawnie rzutowanie
		// to mo¿na u¿yæ tej konstrukcji int *wskI = (int *)tab;
		int sigma2 = 0;

		for (int j = 0; j < sizeof(tab) / sizeof(tab[0]); j++) {
			sigma2 += *(wskI++);
		}
		cout << "Suma tablicy wyliczona wskaznikami to: " << sigma2 << endl;
	}
	{
		// zadanie czwarte:
		// maj¹c dan¹ deklaracjê dwuwymiarowej tablicy:
		int tab2[10][10];
		// uzupe³niæ j¹ iloczynami (klasyczne rozwi¹zanie - banalne)
		// ale u¿ywaj¹c technologii wskaŸników:
		//int** wskI = (int **)tab2; //Ÿle!!! bo tab2 to tak naprawdê int*
		int* wskI = (int*)tab2;
		for (int i = 0; i < 100; i++) {
			*(wskI++) = (i / 10 + 1) * (i % 10 + 1);
		}
		for (int i = 0; i < 10; (i++, cout << endl))
			for (int j = 0; j < 10; j++)
				cout << tab2[i][j] << "\t";

	}
}

void Zadania2::przeciazanieOperatorow()
{
	/*zadanie : utworzyæ strukturê DaneOso (jako klasê wewnêtrzn¹ klasy Zadania2) 
	* w której 
	* bêd¹ dane typu: imie, nazwisko, wiek.
	* Przeci¹¿yæ odpowiednio operatory porównania < > oraz ! i ==.
	*
	* Temat na nastêpne zajêcia: A potem przeczytaæ albo omówiæ dlaczego stosujemy 
	* przeci¹¿enie postaci operator()
	*/
	DaneOso oso1("Adam", "Kowalski", 25);
	DaneOso oso2 = { "Anna", "Nowak", 20 };
	DaneOso* oso3 = new DaneOso("Andrzej", "Kowalski", 30);
	delete oso3;
	/* jeœli nie chcemy ,,panowaæ'' sami nad usuwaniem wskaŸnika
	przez delete to mo¿emy u¿yæ np. auto_ptr (s¹ to tak zwane "smart pointers": */
	auto_ptr<DaneOso> oso4(new DaneOso("Andrzej", "Kowalski", 30));
	//...i nie trzeba ju¿ wskŸnika oso4 zwalniaæ 
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
	for (int j = 0; j < dlugosc_p; j++)
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
	//Æw : napisaæ to samo co wy¿ej ale u¿ywaj¹c new (podobnie jak w C#)
	Lista* li2 = new Lista(5); //gwiazdka oznacza ¿e li2 jest ,,wskaŸnikiem'' (=pointerem).
	li2->wypisanie(); // operator -> to operator 
	delete li2;
	/*przypomnijmy ¿e w C# powy¿sza sekwencja kodu by wygl¹da³a tak:
	  Lista li2 = new Lista(5);
	  li2.wypisanie();
	*/
	/*string txt;
	cin >> txt;*/
	podkreslenie();
	// a teraz u¿yjemy klasy potomnej ListaSformatowana
	ListaFormatowana* lf = new ListaFormatowana(5);
	lf->wypisanie();
	delete lf;
}

