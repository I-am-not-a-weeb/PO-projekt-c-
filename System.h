#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "baza.h"
#include <fstream>
#include <memory>

using std::ios;

class System
{
private:
	
public:
	void Start()
	{

	}
	void Open(std::shared_ptr<bazaKsiazek>f_bazaK, std::shared_ptr<bazaCzasopism>f_bazaC, std::shared_ptr<bazaAutorow>f_bazaA, std::shared_ptr<bazaDrukarni>f_bazaD
		,std::shared_ptr<bazaUmow>f_bazaU, std::shared_ptr<sklep> f_skl,std::shared_ptr<std::fstream> f_fileK, std::shared_ptr<std::fstream> f_fileC
		,std::shared_ptr<std::fstream> f_fileA,std::shared_ptr<std::fstream> f_fileU, std::shared_ptr<std::fstream> f_fileD, std::shared_ptr<std::fstream> f_fileSklK
		,std::shared_ptr<std::fstream> f_fileSklC)
	{
		bazaKsiazek temp_bazaK;
		bazaAutorow temp_bazaA;
		bazaCzasopism temp_bazaC;
		bazaDrukarni temp_bazaD;
		bazaUmow temp_bazaU;

		sklep temp_sklep;

		float cena;
		std::string tempstr1, tempstr2;
		int tempid, tempida, temprodz;
		bool r;
		try {
			f_fileA->open("plikA.txt", ios::in);
			while (!f_fileA->eof())
			{
				*f_fileA >> tempid >> tempstr1 >> tempstr2;
				temp_bazaA.dodajAutoraWczyt(tempstr1, tempstr2, tempid);
			}
			f_fileA->close();

			f_fileK->open("plikK.txt", ios::in);
			while (!f_fileK->eof())
			{
				*f_fileK >> tempid >> tempida >> temprodz >> tempstr1;
				temp_bazaK.dodajKsiazke(tempstr1, temprodz, "TBD");
				temp_bazaK.getPtrLK()->dodajAutora(*temp_bazaA.getAutorById(tempida));
			}
			f_fileK->close();

			f_fileC->open("plikC.txt", ios::in);
			while (!f_fileC->eof())
			{
				*f_fileC >> tempid >> tempida >> temprodz >> tempstr1;
				temp_bazaC.dodajCzasopismo(tempstr1, temprodz, "TBD");
				temp_bazaC.getPtrLK()->przyznajAutora(*temp_bazaA.getAutorById(tempida));
			}
			f_fileC->close();

			f_fileD->open("plikD.txt", ios::in);
			while (!f_fileD->eof())
			{
				*f_fileD >> tempid >> temprodz >> tempstr1;
				temp_bazaD.wczytD(tempstr1, temprodz, tempid);
			}
			f_fileD->close();

			f_fileU->open("plikU.txt", ios::in);
			while (!f_fileU->eof())
			{
				*f_fileU >> tempid >> temprodz >> r >> tempida;
				if (r)temp_bazaU.wczyt(temp_bazaK.getPtrById(tempida), temprodz, tempid);
			}
			f_fileU->close();

			f_fileSklK->open("pliksklK.txt", ios::in);
			while (!f_fileSklK->eof())
			{
				*f_fileSklK >> tempid >> temprodz >> tempida >> cena;
				if (temprodz == temp_bazaK.getPtrById(tempida)->getRodzajInterwal())
					temp_sklep.wczytK(temp_bazaK.getPtrById(tempid), tempida, cena);
			}
			f_fileSklK->close();

			f_fileSklC->open("pliksklC.txt", ios::in);
			while (!f_fileSklC->eof())
			{
				*f_fileSklK >> tempid >> temprodz >> tempida >> cena;
				if (temprodz == temp_bazaC.getPtrById(tempida)->getRodzajInterwal())
					temp_sklep.wczytC(temp_bazaC.getPtrById(tempid), tempida, cena);
			}
			f_fileSklC->close();
			std::cout << std::endl << "Pomyslnie otworzono." << std::endl;
			system("pause");
		}
		catch (except es ) { std::cout << "Blad."; system("pause"); }
	}
	void Save(std::shared_ptr<bazaKsiazek>f_bazaK, std::shared_ptr<bazaCzasopism>f_bazaC, std::shared_ptr<bazaAutorow>f_bazaA,
		std::shared_ptr<bazaDrukarni>f_bazaD, std::shared_ptr<bazaUmow>f_bazaU, std::shared_ptr<sklep> f_skl,
		std::shared_ptr<std::fstream> f_fileK, std::shared_ptr<std::fstream> f_fileC, std::shared_ptr<std::fstream> f_fileA,
		std::shared_ptr<std::fstream> f_fileU, std::shared_ptr<std::fstream> f_fileD, std::shared_ptr<std::fstream> f_fileSklK, std::shared_ptr<std::fstream> f_fileSklC)
	{
		size_t temp_sum_ids = f_bazaA->getMaxID() + f_bazaC->getMaxID() + f_bazaD->getMaxID() + f_bazaK->getMaxID() + f_bazaU->getMaxID();

		f_fileK->open("plikK.txt", ios::out);
		f_fileA->open("plikA.txt", ios::out);
		f_fileD->open("plikD.txt", ios::out);
		f_fileU->open("plikU.txt", ios::out);
		f_fileC->open("plikC.txt", ios::out);
		f_fileSklK->open("pliksklK.txt",ios::out);
		f_fileSklC->open("pliksklC.txt", ios::out);

		*f_fileK << f_bazaK->dump();
		*f_fileA << f_bazaA->dump();
		*f_fileC << f_bazaC->dump();
		*f_fileD << f_bazaD->dump();
		*f_fileU << f_bazaU->dump();
		*f_fileSklK << f_skl->dumpK();
		*f_fileSklC << f_skl->dumpC();

		f_fileK->close();
		f_fileA->close();
		f_fileD->close();
		f_fileC->close();
		f_fileU->close();
		f_fileSklC->close();
		f_fileSklK->close();
	}
};
