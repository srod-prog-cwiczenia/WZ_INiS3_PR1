#pragma once
class Lista
{
private:
	vector<string> vec;
public:
	Lista();     // konstruktor
	Lista(int ile); // jeszcze jeden konstruktor (przeci¹¿enie)
	~Lista();  // destruktor
	void wypisanie();
private:
	virtual string formatuj(const string &txt_p);
};

