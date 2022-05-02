#pragma once
#include "System.h"
#include <iostream>

class ZarzadzanieAutorami :public System
{
	void DodanieAutora(std::string f_imie, std::string f_nazwisko)
	{
		c_autor(f_imie, f_nazwisko);
	}
};
class c_autor :protected ZarzadzanieAutorami
{
private:
	std::string imie;
	std::string nazwisko;
public:
	c_autor()
	{

	}
	c_autor(std::string f_imie, std::string f_nazwisko)
	{
		imie = f_imie;
		nazwisko = f_nazwisko;
	}
};

