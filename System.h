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
	/*std::shared_ptr<bazaKsiazek> bazaK;
	std::shared_ptr<bazaCzasopism> bazaC;
	std::shared_ptr<bazaAutorow> bazaA;
	std::shared_ptr<bazaDrukarni> bazaD;
	std::shared_ptr<bazaUmow> bazaU;*/
public:
	void Start()
	{

	}
	void Open()
	{

	}
	bool Save(std::shared_ptr<bazaKsiazek>f_bazaK, std::shared_ptr<bazaCzasopism>f_bazaC, std::shared_ptr<bazaAutorow>f_bazaA,
		std::shared_ptr<bazaDrukarni>f_bazaD, std::shared_ptr<bazaUmow>f_bazaU, std::shared_ptr<sklep> f_skl,
		std::unique_ptr<std::fstream> f_fileK, std::unique_ptr<std::fstream> f_fileC, std::unique_ptr<std::fstream> f_fileA,
		std::unique_ptr<std::fstream> f_fileU, std::unique_ptr<std::fstream> f_fileD, std::unique_ptr<std::fstream> f_fileSklK, std::unique_ptr<std::fstream> f_fileSklC)
	{
		size_t temp_sum_ids = f_bazaA->getMaxID() + f_bazaC->getMaxID() + f_bazaD->getMaxID() + f_bazaK->getMaxID() + f_bazaU->getMaxID();

		if (!(f_fileK->is_open() || f_fileC->is_open() || f_fileA->is_open() || f_fileD->is_open() || f_fileU->is_open() 
			|| f_fileSklC->is_open() || f_fileSklK->is_open()))
		{
			throw except("Blad otwarcia plikow.");
		}
		*f_fileK << f_bazaK->dump();
		*f_fileA << f_bazaA->dump();
		*f_fileC << f_bazaC->dump();
		*f_fileD << f_bazaD->dump();
		*f_fileU << f_bazaU->dump();
		*f_fileSklK << f_skl->dumpK();
	}
};
