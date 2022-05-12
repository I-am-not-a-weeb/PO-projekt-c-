#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "baza.h"
//#include

class System
{
public:
	void Start()
	{

	}
	void Stop()
	{

	}
	void Save()
	{
		system("cls");
		std::cout << "1. Zapisaæ w pliku domyslnym (dane.txt)" << std::endl << "2. Zapisac w wybranym pliku poprzez podanie sciezki" << std::endl;
		char ch = _getch();
	}
	
};
