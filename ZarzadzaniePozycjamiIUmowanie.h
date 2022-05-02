#pragma once
#include "System.h"
#include "ZarzadzanieAutorami.h"
#include <Windows.h>
#include <string>
class ZarzadzaniePozycjamiIUmowanie :public System
{
protected:
public:
	virtual c_ksiazka DodajKsiazke(std::string f_tytul, int f_rodzaj, std::string f_tekst) = 0;
	virtual c_czasopismo DodajCzasopismo(std::string f_tytul, bool f_interwal, std::string f_tekst)=0;
	virtual void ZmianaInterwaluRodzaju() = 0;
};

class c_pozycja :protected ZarzadzaniePozycjamiIUmowanie
{
protected:
	std::string tytul;
	c_autor autor;
	std::string tekst;
public:
	c_ksiazka DodajKsiazke(std::string f_tytul, int f_rodzaj, std::string f_tekst)
	{
		return c_ksiazka(f_tytul,f_rodzaj,f_tekst);
	}
	c_czasopismo DodajCzasopismo(std::string f_tytul, bool f_interwal, std::string f_tekst)
	{
		return c_czasopismo(f_tytul,f_interwal,f_tekst);
	}
	virtual void ZmianaInterwaluRodzaju();
};

class c_ksiazka :protected c_pozycja
{
protected:
	int rodzaj = - 1;
public:
	c_ksiazka()
	{

	}
	c_ksiazka(std::string f_tytul, int f_rodzaj, std::string f_tekst)
	{
		tytul = f_tytul;
		rodzaj = f_rodzaj;
		tekst = f_tekst;
	}
	void ZmianaInterwaluRodzaju(int f_rodzaj)
	{
		rodzaj = f_rodzaj;
	}
};

class c_czasopismo : protected c_pozycja
{
protected:
	bool interwal;
public:
	c_czasopismo()
	{

	}
	c_czasopismo(std::string f_tytul,bool f_interwal, std::string f_tekst)
	{
		tytul = f_tytul;
		interwal = f_interwal;
		tekst = f_tekst;
	}
	void ZmianaInterwaluRodzaju(bool f_interwal)
	{
		interwal = f_interwal;
	}

};