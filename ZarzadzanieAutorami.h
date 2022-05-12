#pragma once
#include "System.h"
#include <iostream>
#include <Windows.h>
#include <sstream>

class c_autor
{
private:
	std::string imie;
	std::string nazwisko;
	int id=-1;
public:
	c_autor()
	{
		
	}
	c_autor(std::string f_imie, std::string f_nazwisko,int f_id)
	{
		imie = f_imie;
		nazwisko = f_nazwisko;
		id = f_id;
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
		out << id << " " << imie << " " << nazwisko << std::endl;
	}
	friend bool operator==(c_autor l, c_autor r)
	{
		if (l.id == r.id) return 1; else return 0;
	}
};

__interface ZarzadzanieAutorami 
{
	virtual c_autor DodajAutora(std::string f_imie, std::string f_nazwisko,int f_ID)
	{
		return c_autor(f_imie, f_nazwisko,f_ID);
	}
};


