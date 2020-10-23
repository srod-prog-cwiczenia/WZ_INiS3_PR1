#include "pch.h"
#include "ListaFormatowana.h"
ListaFormatowana::ListaFormatowana()
{
}
ListaFormatowana::ListaFormatowana(int ile) : Lista(ile)
{
	
}
ListaFormatowana::~ListaFormatowana()
{
}

string ListaFormatowana::formatuj(const string &txt_p)
{
	constexpr auto MAX_DLUGOSC_LINII = 50;
	constexpr auto ZNAK_CENTROWANIA = '-';
/* inna wersja (jeszcze z C):	
    #define	MAX_DLUGOSC_LINII 50
	#define ZNAK_CENTROWANIA '-'  */
	if (txt_p.length() > MAX_DLUGOSC_LINII) return txt_p;
	int ile = (MAX_DLUGOSC_LINII - (int)txt_p.length()) / 2;
	return string(ile, ZNAK_CENTROWANIA) + txt_p + string(ile, ZNAK_CENTROWANIA);
}
