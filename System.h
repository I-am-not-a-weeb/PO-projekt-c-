#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "baza.h"
#include <fstream>
#include <memory>

class System
{
private:
	std::shared_ptr<bazaKsiazek> bazaK;
	std::shared_ptr<bazaCzasopism> bazaC;
	std::shared_ptr<bazaAutorow> bazaA;
	std::shared_ptr<bazaDrukarni> bazaD;
	std::shared_ptr<bazaUmow> bazaU;

public:
	void Start()
	{

	}
	void Open()
	{

	}
	void Save(std::shared_ptr<bazaKsiazek>f_bazaK, std::shared_ptr<bazaCzasopism>f_bazaC,		//funkcja zapisujaca caly stan systemu w plikach
		std::shared_ptr<bazaAutorow>f_bazaA,std::shared_ptr<bazaDrukarni>f_bazaD,				//plik all_data - wszystko z wszystkich baz
		std::shared_ptr<bazaUmow>f_bazaU,std::fstream &f_data_file ,std::fstream &f_fileK,									//plik id_data - po ile czego w czym jest
		std::fstream &f_fileC, std::fstream &f_fileA, std::fstream &f_fileD)					
	{
		std::fstream all_data, id_data;
		size_t temp_sum_ids = f_bazaA->getMaxID() + f_bazaC->getMaxID() + f_bazaD->getMaxID() + f_bazaK->getMaxID() + f_bazaU->getMaxID();

		if (!(f_fileK.is_open() || f_fileC.is_open() || f_fileA.is_open() || f_fileD.is_open()))
		{
			std::cout << "Blad otwarcia plikow. Nacisnij dowolny przycisk by kontynuowac." << std::endl;
			_getch();
			return;
		}
		f_data_file << f_bazaK->getMaxID() << " " << f_bazaC->getMaxID() << " " << f_bazaA->getMaxID() << " " << f_bazaD->getMaxID() << " " << f_bazaU->getMaxID() << std::endl;

		f_fileK << bazaK->dump();
		f_fileC << bazaC->dump();
		f_fileA << bazaA->dump();
		f_fileD << bazaD->dump();
	}
};
