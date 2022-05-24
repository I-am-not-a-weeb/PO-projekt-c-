#pragma once
#include "System.h"
#include "ZarzadzaniePozycjamiIUmowanie.h"
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <vector>
#include <conio.h>
#include <memory>

class c_pozycja;
class c_ksiazka;
class c_czasopismo;

class c_umowa
{
private:
	int rodzaj = -1, id = -1;
	std::shared_ptr<c_ksiazka> pozK;
	std::shared_ptr<c_czasopismo> pozC;

public:
	c_umowa(std::shared_ptr<c_ksiazka> f_ksiazka,int f_rodzaj)
	{
		pozK = f_ksiazka;
		rodzaj = f_rodzaj;
	}
	c_umowa(std::shared_ptr<c_czasopismo> f_czasopismo, int f_rodzaj)
	{
		pozC = f_czasopismo;
		rodzaj = f_rodzaj;
	}
	int getRodzaj()
	{
		return rodzaj;
	}
	void zmienRodzaj(int f_rodzaj)
	{
		rodzaj = f_rodzaj;
	}
	/*void dodajKsiazke(std::shared_ptr<c_ksiazka> f_ksiazka)
	{
		pozK = f_ksiazka;
	}
	void dodajCzasopismp(std::shared_ptr<c_czasopismo> f_czasopismo)
	{
		pozC = f_czasopismo;
	}*/
	std::shared_ptr<c_ksiazka> getpozK()
	{
		return pozK;
	}
	std::shared_ptr<c_czasopismo> getpozC()
	{
		return pozC;
	}
};

class c_autor
{
private:
	std::string imie;
	std::string nazwisko;
	int id = -1;
	std::vector<c_umowa> vecUmowy;
public:
	c_autor()
	{
		imie = "null_str";
		nazwisko = "null_str";
	}
	c_autor(std::string f_imie, std::string f_nazwisko, int f_id)
	{
		imie = f_imie;
		nazwisko = f_nazwisko;
		id = f_id;
	}
	void dodajUmowe(c_umowa f_umowa)
	{
		vecUmowy.push_back(f_umowa);
	}
	std::string getImie()
	{
		return imie;
	}
	std::string getNazwisko()
	{
		return nazwisko;
	}
	std::string dump()
	{
		std::ostringstream out;
		out << id << "|" << imie << "|" << nazwisko << std::endl;
		return out.str();
	}
	friend bool operator==(c_autor l, c_autor r)
	{
		if (l.id == r.id) return 1; else return 0;
	}
};

class c_pozycja
{
protected:
	std::string tytul;
	c_autor autor = c_autor();
	std::string tekst;
	int id = -1;
public:
	inline static int count = -1;
	virtual int getRodzajInterwal() = 0;
	virtual c_autor getAutor() = 0;
	virtual std::string getTytul() = 0;
	virtual std::string getTekst() = 0;
	virtual int getId() = 0;
	virtual void przyznajTytul(std::string f_tytul) = 0;
	int getCount()
	{
		return count;
	}
};

class c_ksiazka :protected c_pozycja
{
protected:
	int rodzaj = -1;
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
		id = ++count;
	}
	c_ksiazka(const c_ksiazka& f_ksiazka)
	{
		autor = f_ksiazka.autor;
		tytul = f_ksiazka.tytul;
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
	std::string dump_t()
	{
		std::ostringstream out;
		out << id << "|" << tytul << "|" << rodzaj << "|" << tekst << std::endl;
		return out.str();
	}
	std::string dump()
	{
		std::ostringstream out;
		out << id << "|" << tytul << "|" << rodzaj << std::endl;
		return out.str();
	}
	friend bool operator==(c_ksiazka l, c_ksiazka r)
	{
		if (l.id == r.id) return 1; else return 0;
	}
	friend bool operator<(c_ksiazka l, c_ksiazka r)
	{
		if (l.tytul < r.tytul) return 1; else return 0;
	}
};

class c_czasopismo : protected c_pozycja
{
protected:
	int interwal = -1;
public:
	c_czasopismo()
	{

	}
	c_czasopismo(std::string f_tytul, int f_interwal, std::string f_tekst, int f_id)
	{
		tytul = f_tytul;
		interwal = f_interwal;
		tekst = f_tekst;
		id = ++count;
	}
	c_czasopismo(const c_czasopismo &f_czasopismo)
	{
		autor = f_czasopismo.autor;
		tytul = f_czasopismo.tytul;
		interwal = f_czasopismo.interwal;
		tekst = f_czasopismo.tekst;
		id = f_czasopismo.id;
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
	std::string dump_t()
	{
		std::ostringstream out;
		out << id << "|" << tytul << "|" << interwal << "|" << tekst << std::endl;
		return out.str();
	}
	std::string dump()
	{
		std::ostringstream out;
		out << id << "|" << tytul << "|" << interwal << std::endl;
		return out.str();
	}
	friend bool operator==(c_czasopismo l, c_czasopismo r)
	{
		if (l.id == r.id) return 1; else return 0;
	}
	friend bool operator<(c_czasopismo l, c_czasopismo r)
	{
		if (l.tytul < r.tytul) return 1; else return 0;
	}
};







