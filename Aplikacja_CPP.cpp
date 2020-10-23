// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "Lista.h"
#include "ListaFormatowana.h"

void podkreslenie() {
	cout << "-----------------------------------\n";
}
//zadanie: utworzyć tutaj klasę Zadania
//i wypełnić ją metodami statycznymi zadaniaZObiektow oraz zadaniaZeWskaznikow()
class Zadania {
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
	}
};


int main()
{//zadanie : dorobić proste menu:
	for(;;) {
		cout << "1. Zadania z obiektow\n";
		cout << "2. Zadania ze wskaźników\n";
		cout << "0. Wyjście\n";
		string opcja;
		cin >> opcja;
		if (opcja.empty() || opcja[0] == '0') break;
		switch (opcja[0]) {
		case '1':
			Zadania::zadaniaZObiektow();
			break;
		case '2':
			Zadania::zadaniaZeWskaznikow();
			break;
		default:
			break;
		}
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
