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
	/*zadanie: napisaæ metodê wypisanie(funktor) (obmyœleæ sposób przekazywania
	tego funktora przez parametr). Na razie funktor umieœcimy jako sta³¹ statyczn¹
	w klasie Lista
	przeksza³canie zawartoœci wektora zrealizowaæ przez 
	transform z modu³u <algorithm>
	*/
	void wypisanieZUzyciemFunktora();
	void setFormatowanieCallback(TFunkcjaFormatujaca fc);
private:
	virtual string formatuj(const string &txt_p);
};

