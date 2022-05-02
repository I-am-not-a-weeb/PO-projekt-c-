#pragma once
#include "System.h"
#include <iostream>
#include <Windows.h>

class ZarzadzanieAutorami :public System
{
	c_autor DodajAutora(std::string f_imie, std::string f_nazwisko)
	{
		return c_autor(f_imie, f_nazwisko);
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

