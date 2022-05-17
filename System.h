#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "baza.h"

class System
{
private:
	std::shared_ptr<bazaKsiazek> bazaK;
	std::shared_ptr<bazaCzasopism> bazaC;
	std::shared_ptr<bazaAutorow> bazaA;
	std::shared_ptr<bazaDrukarni> bazaD;

public:
	void Start()
	{
		///baza
	}
	void Open()
	{
		std::ifstream file;
		file.open("data.txt");
		std::string line;
		while (!file.eof())
		{
			if (std::getline(file, line));
			//line =													algorytym zbierania danych z linijki
		}

	}
	void Save(bazaKsiazek &f_bazaK, bazaCzasopism &f_bazaC, bazaAutorow &f_bazaA, bazaDrukarni &f_bazaD)
	{
		*bazaK = f_bazaK;
		*bazaC = f_bazaC;
		*bazaA = f_bazaA;
		*bazaD = f_bazaD;

		bool is_continued = true;

		system("cls");
		std::cout << "1. Zapisaæ w pliku domyslnym (data.txt)" << std::endl << "2. Zapisac w wybranym pliku poprzez podanie sciezki" << std::endl;
		char ch;
		while (is_continued)
		{
			ch = _getch();
			switch (ch)
			{
			case '1':
			{
				std::ofstream file;
				file.open("data.txt", std::ios::in);
				file << bazaK->dump() << "---" << std::endl << bazaC->dump() << "---" << std::endl << bazaA->dump() << "---" << std::endl << bazaD->dump();
				is_continued = false;
			}
			case '2':
			{
				std::ofstream file;
				std::string path;
				std::cout << "Wpisz sciezke: ";
				std::cin >> path;
				file.open(path, std::ios::in);
				if (!file.is_open())
				{
					std::cout << std::endl << "Nie otwarto pliku.";
					break;
				}
				file << bazaK->dump() << "---" << std::endl << bazaC->dump() << "---" << std::endl << bazaA->dump() << "---" << std::endl << bazaD->dump();
				is_continued = false;
			}
			default:
			{
				std::cout << "Brak opcji.";
			}
			}
			_getch();
		}
	}
	
};
