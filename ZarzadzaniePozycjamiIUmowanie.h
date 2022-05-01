#pragma once
#include "System.h"
#include "ZarzadzanieAutorami.h"


class ZarzadzaniePozycjamiIUmowanie :public System
{
protected: 
public: 
	virtual void PrzyznanieAutora(c_autor f_autor) = 0;
};

class c_pozycja : protected ZarzadzaniePozycjamiIUmowanie
{
protected:
	std::string tytul;
	c_autor autor;
	std::string tekst;
public:
	virtual void PrzyznanieAutora(c_autor f_autor)
	{
		autor = f_autor;
	}
	virtual void ZmianaRodzajuInterwalu() = 0;
};

class c_Ksiazka : protected c_pozycja
{
private:
	int rodzaj = - 1;
public:
	c_Ksiazka()
	{

	}
	c_Ksiazka(int f_rodzaj)
	{
		rodzaj = f_rodzaj;
	}
	c_Ksiazka(int f_rodzaj,std::string f_tekst)
	{
		rodzaj = f_rodzaj;
		tekst = f_tekst;
	}
	void ZmianaRodzajuInterwalu(int f_rodzaj)
	{
		rodzaj = f_rodzaj;
	}
};

class c_Czasopismo : protected c_pozycja
{
private:
	bool interwal;
public:
	c_Czasopismo()
	{

	}
	c_Czasopismo(bool f_interwal)
	{
		interwal = f_interwal;
	}
	c_Czasopismo(bool f_interwal, std::string f_tekst)
	{
		interwal = f_interwal;
		tekst = f_tekst;
	}
	void ZmianaRodzajuInterwalu(bool f_interwal)
	{
		interwal = f_interwal;
	}
};