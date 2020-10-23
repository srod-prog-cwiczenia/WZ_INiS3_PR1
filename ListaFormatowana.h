#pragma once
#include "Lista.h"
class ListaFormatowana : public Lista
{
public:
	ListaFormatowana();
	ListaFormatowana(int ile);
	~ListaFormatowana();
private:
	string formatuj(const string &txt_p);

};

