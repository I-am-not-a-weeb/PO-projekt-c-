#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "baza.h"

class System
{
private:
	shared_ptr<bazaKsiazek> bazaK;
	shared_ptr<bazaCzasopism> bazaC;
	shared_ptr<bazaAutorow> bazaA;
	shared_ptr<bazaDrukarni> bazaD;

public:
	void Start()
	{
		///baza
	}
	void Stop()
	{

	}
	void Save(bazaKsiazek &f_bazaK, bazaCzasopism &f_bazaC, bazaAutorow &f_bazaA, bazaDrukarni &f_bazaD)
	{
		*bazaK = f_bazaK;
		*bazaC = f_bazaC;
		*bazaA = f_bazaA;
		*bazaD = f_bazaD;

		bool is_continued = true;

		system("cls");
		std::cout << "1. Zapisaæ w pliku domyslnym (dane.txt)" << std::endl << "2. Zapisac w wybranym pliku poprzez podanie sciezki" << std::endl;
		char ch;
		while (is_continued)
		{
			ch = _getch();
			switch (ch)
			{
			case '1':
			{
				ofstream file;
				file.open("data.txt", ios::in);
				file << bazaK->dump() << "---" << endl << bazaC->dump() << "---" << endl << bazaA->dump() << "---" << endl << bazaD->dump();
				is_continued = false;
			}
			case '2':
			{
				ofstream file;
				std::string path;
				cout << "Wpisz sciezke: ";
				cin >> path;
				file.open(path, ios::in);
				if (!file.is_open())
				{
					cout << endl << "Nie otwarto pliku.";
					break;
				}
				file << bazaK->dump() << "---" << endl << bazaC->dump() << "---" << endl << bazaA->dump() << "---" << endl << bazaD->dump();
				is_continued = false;
			}
			default:
			{
				cout << "Brak opcji.";
			}
			}
			_getch();
		}
	}
	
};
