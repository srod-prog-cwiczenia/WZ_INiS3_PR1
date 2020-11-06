#include "pch.h"
#include "Zadania2.h"

void Zadania2::przekazywanieZmiennych()
{
  //TODO: uzupe�ni�!
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
