#pragma once
class Lista
{
private:
	vector<string> vec;
	TFunkcjaFormatujaca formatowanieCallback = NULL;
public:
	Lista();     // konstruktor
	Lista(int ile); // jeszcze jeden konstruktor (przeci¹¿enie)
	~Lista();  // destruktor
	void wypisanie();
	void setFormatowanieCallback(TFunkcjaFormatujaca fc);
private:
	virtual string formatuj(const string &txt_p);
};

