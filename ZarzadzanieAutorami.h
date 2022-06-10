#pragma once
#include "System.h"
#include "ZarzadzaniePozycjamiIUmowanie.h"
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <vector>
#include <conio.h>
#include <memory>
#include "except.h"

class c_umowa;
class c_pozycja;
class c_ksiazka;
class c_czasopismo;
class c_autor;

class c_autor
{
private:
	std::string imie;
	std::string nazwisko;
	int id = -1;
	std::vector<c_umowa> vecUmowy;
	std::vector<std::shared_ptr<c_ksiazka>> vecK;
	std::vector<std::shared_ptr<c_czasopismo>> vecC;
public:
	c_autor()
	{
		imie = "null_str";
		nazwisko = "null_str";
	}
	c_autor(std::string f_imie, std::string f_nazwisko, int f_id)
	{
		if (f_imie.size() < 3 || f_nazwisko.size() < 3) throw except("Nieprawidlowe dane\n" + f_imie + "\n" + f_nazwisko);
		imie = f_imie;
		nazwisko = f_nazwisko;
		id = f_id;
	}
	std::shared_ptr<c_umowa> dodajUmowe(std::shared_ptr<c_umowa> f_umowa)
	{
		vecUmowy.push_back(*f_umowa);
		return f_umowa;
	}
	std::shared_ptr<c_ksiazka> dodajKsiazke(std::shared_ptr<c_ksiazka> f_ksiazka)
	{
		vecK.push_back(f_ksiazka);
		return f_ksiazka;
	}
	std::shared_ptr<c_czasopismo> dodajCzasopismo(std::shared_ptr <c_czasopismo> f_czasopismo)
	{
		vecC.push_back(f_czasopismo);
		return f_czasopismo;
	}
	std::string getImie()
	{
		return imie;
	}
	std::string getNazwisko()
	{
		return nazwisko;
	}
	int getId()
	{
		return id;
	}
	std::shared_ptr<c_autor> getPtr()
	{
		return std::shared_ptr<c_autor>(this);
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
	c_ksiazka(std::string f_tytul, int f_rodzaj, int f_id)
	{
		tytul = f_tytul;
		rodzaj = f_rodzaj;
		tekst = "TBD";
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
private:
	std::string interwal_str(bool f_interwal)
	{
		if (f_interwal == 1) return "Miesiecznik"; else return "Tygodnik";
	}
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
		out << id << "|" << tytul << "|" << interwal_str(interwal) << "|" << tekst << std::endl;
		return out.str();
	}
	std::string dump()
	{
		std::ostringstream out;
		out << id << "|" << tytul << "|" << interwal_str(interwal) << std::endl;
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

class c_umowa
{
private:
	int rodzaj = -1, id = -1;
	std::shared_ptr<c_ksiazka> pozK;
	std::shared_ptr<c_czasopismo> pozC;

public:
	c_umowa(std::shared_ptr<c_ksiazka> f_ksiazka, int f_rodzaj)
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
	void dodajKsiazke(std::shared_ptr<c_ksiazka> f_ksiazka)
	{
		pozK = f_ksiazka;
	}
	void dodajCzasopismp(std::shared_ptr<c_czasopismo> f_czasopismo)
	{
		pozC = f_czasopismo;
	}
	std::shared_ptr<c_ksiazka> getpozK()
	{
		return pozK;
	}
	std::shared_ptr<c_czasopismo> getpozC()
	{
		return pozC;
	}
	std::string dump()
	{
		std::stringstream out;
		if (pozC != nullptr)
		{
			out << id << " " << rodzaj << " " << pozC.get()->getId();
			return out.str();
		}
		if (pozK != nullptr)
		{
			out << id << " " << rodzaj << " " << pozK.get()->getId();
			return out.str();
		}
	}
};

class amK
{
	std::shared_ptr<c_ksiazka> ptrK;
	int ilosc;
public:
	amK(std::shared_ptr<c_ksiazka> f_ksiazka,int f_ilosc)
	{
		ptrK = f_ksiazka;
		ilosc = f_ilosc;
	}
	std::shared_ptr<c_ksiazka> getPtr()
	{
		return ptrK;
	}
	int getIlosc()
	{
		return ilosc;
	}
	int zmienIlosc(int delta)			//+= ilosc
	{
		ilosc += delta;
		return ilosc;
	}
	std::string wypis()
	{
		std::ostringstream out;
		out << ptrK->getId() << " " << ptrK->getTytul() << " " << ptrK->getRodzajInterwal()<< " " << ilosc << std::endl;
		return out.str();
	}
	std::string dump()
	{
		std::ostringstream out;
		out << ptrK->getId() << " " << ptrK->getRodzajInterwal() << std::endl;
		return out.str();
	}
};
class amC
{
	std::shared_ptr<c_czasopismo> ptrC;
	int ilosc;
public:
	amC(std::shared_ptr<c_czasopismo> f_czasopismo, int f_ilosc)
	{
		ptrC = f_czasopismo;
		ilosc = f_ilosc;
	}
	std::shared_ptr<c_czasopismo> getPtr()
	{
		return ptrC;
	}
	int getIlosc()
	{
		return ilosc;
	}
	int zmienIlosc(int delta)		//+= ilosc
	{
		ilosc += delta;
		return ilosc;
	}
	std::string wypis()
	{
		std::ostringstream out;
		out << ptrC->getId() << " " << ptrC->getTytul() << " " << ptrC->getRodzajInterwal() << " " << ilosc << std::endl;
		return out.str();
	}
	std::string dump()
	{
		std::ostringstream out;
		out << ptrC->getId() << " " << ptrC->getRodzajInterwal() << std::endl;
		return out.str();
	}
};

class magazyn
{
	std::vector<amK> mag_ksiazka;
	std::vector<amC> mag_czasopismo;
public:
	void dodruk_k(std::shared_ptr<amK> f_amksiazka, int f_ilosc)
	{
		f_amksiazka->zmienIlosc(f_ilosc);
	}
	void dodruk_c(std::shared_ptr<amC> f_amczasopismo, int f_ilosc)
	{
		f_amczasopismo->zmienIlosc(f_ilosc);
	}
	std::string wypis()
	{
		std::ostringstream out;
		out << "Ksiazki:" << std::endl;
		for (std::vector<amK>::iterator i = mag_ksiazka.begin(); i != mag_ksiazka.end(); i++)
		{
			out << i->wypis();
		}
		out << "Czasopisma:" << std::endl;
		for (std::vector<amC>::iterator i = mag_czasopismo.begin(); i != mag_czasopismo.end(); i++)
		{
			out << i->wypis();
		}
	}
	std::string dumpK()
	{
		std::ostringstream out;
		for (std::vector<amK>::iterator i = mag_ksiazka.begin(); i != mag_ksiazka.end(); i++)
		{
			out << i->dump();
		}
		return out.str();
	}
};
class sklep
{
	std::vector<amK> sklK;
	std::vector<amC> sklC;
public:
	
};