#pragma once
#include "System.h"
#include <iostream>

class ZarzadzanieAutorami :public System
{

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
	c_autor(std::string fimie, std::string fnazwisko)
	{
		imie = fimie;
		nazwisko = fnazwisko;
	}
};

