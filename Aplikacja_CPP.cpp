﻿// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "Lista.h"
#include "ListaFormatowana.h"
#include "TMenu.h"

void podkreslenie() {
	cout << "-----------------------------------\n";
}
//zadanie: utworzyć tutaj klasę Zadania
//i wypełnić ją metodami statycznymi zadaniaZObiektow oraz zadaniaZeWskaznikow()
class Zadania {
private:
	//#define ROZMIAR_TAB_LOSOWEJ 10
	//static constexpr auto ROZMIAR_TAB_LOSOWEJ = 10; - przypuszczalnie już zbędna
public:
	static void zadaniaZObiektow() {
		//std::cout << "Hello World!\n"; 
		Lista li(10);
		li.wypisanie();
		podkreslenie();
		//Ćw : napisać to samo co wyżej ale używając new (podobnie jak w C#)
		Lista *li2 = new Lista(5); //gwiazdka oznacza że li2 jest ,,wskaźnikiem'' (=pointerem).
		li2->wypisanie(); // operator -> to operator 
		delete li2;
		/*przypomnijmy że w C# powyższa sekwencja kodu by wyglądała tak:
		  Lista li2 = new Lista(5);
		  li2.wypisanie();
		*/
		/*string txt;
		cin >> txt;*/
		podkreslenie();
		// a teraz użyjemy klasy potomnej ListaSformatowana
		ListaFormatowana *lf = new ListaFormatowana(5);
		lf->wypisanie();
		delete lf;
	}
	static void zadaniaZeWskaznikow() {
		cout << "TODO: zadanie ze wskaznikow\n";
		//zadanie pierwsze
		//napisać ilustrację działania wskaźnika na int,
		//tzn zaalokować wskaźnik, nadać mu wartość a potem zwolnić wskaźnik:
		{
			int* wskI = new(int);
			*wskI = 7;
			assert(*wskI == 7); //test poprawności alokacji 
			delete wskI;
		}
		//-------------------------
		//zadanie drugie: napisać kod który wskazuje na zmienną int i
		//i sprawdza (przez assert) czy ten wskaźnik faktycznie wskazuje na 7.
		{
			int i = 7;
			int* wskI = &i; //tu tworzymy wskazanie na zmienną i
			assert(*wskI == 7); //test poprawności wskazania
		}
		//zadanie trzecie (napisać sumowanie liczb w tablicy ale 
        //za pomocą wskaźników).
		{
			//TODO zadanie domowe: opracować przebieg
			//ale z generowaniem ''losowej'' tablicy o ''losowym''
			//rozmiarze np od 2 -- 100;
			int tab[] = { 30, 31, 20, 5 };
			int sigma = 0;
			for (int el : tab) sigma += el;
			cout << "Suma tablicy wyliczona klasycznie to: " << sigma << endl;
			// to samo ale na wskaźnikach:
			int* wskI = tab; //aby wskazać jawnie rzutowanie
			// to można użyć tej konstrukcji int *wskI = (int *)tab;
			int sigma2 = 0;
						
			for (int j = 0; j < sizeof(tab) / sizeof(tab[0]); j++) {
				sigma2 += *(wskI++);
			}
			cout << "Suma tablicy wyliczona wskaznikami to: " << sigma2 << endl;
		}
		{
			// zadanie czwarte:
			// mając daną deklarację dwuwymiarowej tablicy:
			int tab2[10][10]; 
			// uzupełnić ją iloczynami (klasyczne rozwiązanie - banalne)
			// ale używając technologii wskaźników:
			//int** wskI = (int **)tab2; //źle!!! bo tab2 to tak naprawdę int*
			int* wskI = (int *)tab2;
			for (int i = 0; i < 100; i++) {
				*(wskI++) = (i / 10 + 1) * (i % 10 + 1);
			}
			for (int i = 0; i < 10; (i++, cout << endl))
				for (int j = 0; j < 10; j++)
					cout << tab2[i][j] << "\t";

		}
	}
	static int* losowaTabIntFactory(unsigned int &dlugosc_p) {
		//TODO zadanie domowe: opracować przebieg
		//ale z generowaniem ''losowej'' tablicy o ''losowym''
		//rozmiarze np od 2 -- 100 (na początek o stałym rozmiarze)
		dlugosc_p = 10 + rand() % 100;
		int *tab = new int[dlugosc_p];
		for (int j = 0; j < dlugosc_p; j++)
			tab[j] = rand() % 1000;
		/*for (int j = 0; j < dlugosc_p; j++)
			cout << tab[j] << ", ";
		cout << endl;*/
		return tab;
		//delete[] tab;
	}
	static void sumowanieTablicyLosowej() {
		unsigned int rozmiarTab;
		int* tab = losowaTabIntFactory(rozmiarTab);
		auto sigma = 0;
		for (unsigned int j = 0; j < rozmiarTab; j++) {
			if (j) cout << ", ";
			cout << tab[j];
			sigma += tab[j];
		}
		cout << endl;
		cout << "Suma: " << sigma << endl;
		delete[] tab;
	}
};


int main() {
	srand(time(NULL));
	for(;;) {
		TMenu* mnu = new TMenu();
		mnu->addAll(3, "Zadania z obiektow",
		  "Zadania ze wskaźników", "Losowa tablica");
		auto opcja = mnu->wybierz();
		switch (opcja) {
		case 1:
			Zadania::zadaniaZObiektow();
			break;
		case 2:
			Zadania::zadaniaZeWskaznikow();
			break;
		case 3:
			Zadania::sumowanieTablicyLosowej();
			break;
		default:
			break;
		}
		delete mnu;
		if (!opcja) break;  //bardziej zrozumiale: if (opcja == 0) break;
	};
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
