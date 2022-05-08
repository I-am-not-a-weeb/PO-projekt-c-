#pragma once
#include "System.h"
#include "ZarzadzanieAutorami.h"
#include <Windows.h>
#include <string>
#include <memory>

class c_pozycja
{
protected:
	std::string tytul;
	c_autor autor = c_autor();
	std::string tekst;
	int id=-1;
public:
	virtual int getRodzajInterwal() = 0;
	virtual c_autor getAutor() = 0;
	virtual std::string getTytul() = 0;
	virtual std::string getTekst() = 0;
	virtual int getId() = 0;
	virtual void przyznajTytul(std::string f_tytul) = 0;
};

class c_ksiazka :protected c_pozycja
{
protected:
	int rodzaj = - 1;
public:
	c_ksiazka()
	{
		autor = c_autor();
	}
	c_ksiazka(std::string f_tytul, int f_rodzaj, std::string f_tekst, int f_id)
	{
		tytul = f_tytul;
		rodzaj = f_rodzaj;
		tekst = f_tekst;
		id = f_id;
	}
	c_ksiazka(const c_ksiazka &f_ksiazka)
	{
		autor = f_ksiazka.autor;
		tekst = f_ksiazka.tekst;
		rodzaj = f_ksiazka.rodzaj;
		id = f_ksiazka.id;
	}
	void przyznajTytul(std::string f_tytul)
	{
		tytul = f_tytul;
	}
	void dodajAutora(c_autor f_autor)
	{
		autor = f_autor;
	}
	int getRodzajInterwal()
	{
		return rodzaj;
	}
	c_autor getAutor()
	{
		return autor;
	}
	std::string getTytul()
	{
		return tytul;
	}
	std::string getTekst()
	{
		return tekst;
	}
	int getId()
	{
		return id;
	}
	friend bool operator==(c_ksiazka l, c_ksiazka r)
	{
		if (l.id == r.id) return 1; else return 0;
	}
};

class c_czasopismo : protected c_pozycja
{
protected:
	int interwal=-1;
public:
	c_czasopismo()
	{

	}
	c_czasopismo(std::string f_tytul,int f_interwal, std::string f_tekst, int f_id)
	{
		tytul = f_tytul;
		interwal = f_interwal;
		tekst = f_tekst;
		id = f_id;
	}
	void przyznajTytul(std::string f_tytul)
	{
		tytul = f_tytul;
	}
	void przyznajAutora(c_autor f_autor)
	{
		autor = f_autor;
	}
	int getRodzajInterwal()
	{
		return interwal;
	}
	c_autor getAutor()
	{
		return autor;
	}
	std::string getTytul()
	{
		return tytul;
	}
	std::string getTekst()
	{
		return tekst;
	}
	int getId()
	{
		return id;
	}
	friend bool operator==(c_czasopismo l, c_czasopismo r)
	{
		if (l.id == r.id) return 1; else return 0;
	}
};
__interface ZarzadzaniePozycjamiIUmowanie 
{
public:
	c_ksiazka dodajKsiazke(std::string f_tytul, int f_rodzaj, std::string f_tekst,int f_id)
	{
		return c_ksiazka(f_tytul, f_rodzaj, f_tekst, f_id);
	}
	c_czasopismo dodajCzasopismo(std::string f_tytul, int f_interwal, std::string f_tekst,int f_id)
	{
		return c_czasopismo(f_tytul, f_interwal, f_tekst, f_id);
	}
};