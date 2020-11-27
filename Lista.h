#pragma once
class Lista
{
private:
	vector<string> vec;
	TFunkcjaFormatujaca formatowanieCallback = NULL;
public:
	Lista();     // konstruktor
	Lista(int ile); // jeszcze jeden konstruktor (przeci��enie)
	~Lista();  // destruktor
	void wypisanie();
	/*zadanie: napisa� metod� wypisanie(funktor) (obmy�le� spos�b przekazywania
	tego funktora przez parametr). Na razie funktor umie�cimy jako sta�� statyczn�
	w klasie Lista
	przeksza�canie zawarto�ci wektora zrealizowa� przez 
	transform z modu�u <algorithm>
	*/
	void wypisanieZUzyciemFunktora();
	void setFormatowanieCallback(TFunkcjaFormatujaca fc);
private:
	virtual string formatuj(const string &txt_p);
};

