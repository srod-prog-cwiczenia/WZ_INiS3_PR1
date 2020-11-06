#include "pch.h"
#include "Zadania2.h"

void Zadania2::przekazywanieZmiennych()
{
  //TODO: uzupe³niæ!
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
