﻿// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "Lista.h"
#include "ListaFormatowana.h"
#include "Zadania2.h"
#include "TMenu.h"

//zadanie: utworzyć tutaj klasę Zadania
//i wypełnić ją metodami statycznymi zadaniaZObiektow oraz zadaniaZeWskaznikow()
class Zadania : public Zadania2 {
private:
	//#define ROZMIAR_TAB_LOSOWEJ 10
	//static constexpr auto ROZMIAR_TAB_LOSOWEJ = 10; - przypuszczalnie już zbędna
     /*
	 zadanie: dodać tzw. ,,parametr domyślny'' w postaci 
	 liczby unsigned int która podaje żądany rozmiar tablicy
	 */
	public:
	static void sumowanieTablicyLosowej() {
		unsigned int rozmiarTab;
		int* tab = losowaTabIntFactory(rozmiarTab, 13);
		auto sigma1 = 0;
		for (unsigned int j = 0; j < rozmiarTab; j++) {
			if (j) cout << ", "; /* aby nie było przecinka przez pierwszą liczbą */
			cout << tab[j];
			sigma1 += tab[j];
		}
		auto sigma2 = 0;
		int* tabWsk = tab;
		cout << endl;
		for (unsigned int j = 0; j < rozmiarTab; j++) {
			if (j) cout << ", "; /* aby nie było przecinka przez pierwszą liczbą */
			cout << *tabWsk;
			sigma2 += *tabWsk++; //ostrożnie - ++ ma być zawsze w ostatniej linijce!
		}
		cout << endl;
		cout << "Suma obliczona standarowo: " << sigma1 << endl;
		cout << "Suma obliczona wskaźnikami: " << sigma2 << endl;
		delete[] tab;
	}
};

int main() {
	srand((unsigned int)time(NULL));
	for(;;) {
		TMenu* mnu = new TMenu();
		mnu->addAll(8, "Zadania z obiektow",
		  "Zadania ze wskaźników", "Losowa tablica", 
			"Sposoby przekazywania parametrów", 
			"Przeładowywanie (=przeciążanie) operatorów - testy", 
			"test mapowania DaneOso -> double ", 
			"Zadania z pojęcia funktorów", 
			"Zadania z szablonów");
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
		case 4:
			Zadania::przekazywanieZmiennych();
			break;
		case 5:
			Zadania::przeciazanieOperatorow();
			break;
		case 6:
			Zadania::mapowanieOsoKwota();
			break;
		case 7:
			Zadania::zadaniaZFunktorow(); 
			break;
		case 8:
			Zadania::zadaniaZSzablonow();
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
