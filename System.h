#pragma once
#include <iostream>
#include <conio.h>
//#include <Windows.h>
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
		//
		std::shared_ptr<bazaKsiazek> temp_bazaK(new bazaKsiazek, [](bazaKsiazek*) {});
		std::shared_ptr<bazaAutorow> temp_bazaA(new bazaAutorow,[](bazaAutorow*){});
		std::shared_ptr<bazaCzasopism> temp_bazaC(new bazaCzasopism, [](bazaCzasopism*) {});
		std::shared_ptr<bazaDrukarni> temp_bazaD(new bazaDrukarni, [](bazaDrukarni*) {});
		std::shared_ptr<bazaUmow> temp_bazaU(new bazaUmow, [](bazaUmow*) {});

		std::shared_ptr<sklep> temp_sklep(new sklep, [](sklep*) {});

		*f_bazaK = bazaKsiazek();
		*f_bazaA = bazaAutorow();

		float cena;

		char chtstr[100];
		std::string tempstr1, tempstr2;
		int tempid, tempida, temprodz;
		bool r;
		try {
			f_fileA->open("plikA.txt", ios::in);
			while (*f_fileA >> tempid >> tempstr1 >> tempstr2)
			{
				f_bazaA->dodajAutoraWczyt(tempstr1, tempstr2, tempid);
			}
			f_fileA->close();

			f_fileK->open("plikK.txt", ios::in);
			while (*f_fileK >> tempid >> tempida >> temprodz >> chtstr)
			{
				tempstr1 = chtstr;
				f_bazaK->wczytKsiazka(tempstr1, temprodz,tempid);
				f_bazaK->getPtrLK()->dodajAutora(*f_bazaA->getAutorById(tempida));
			}
			f_fileK->close();

			f_fileC->open("plikC.txt", ios::in);
			while (*f_fileC >> tempid >> tempida >> tempstr2 >> chtstr)
			{
				tempstr1 = chtstr;
				if (tempstr2 == "Miesiecznik") temprodz = 1; else temprodz = 0;
				f_bazaC->dodajCzasopismo(tempstr1, temprodz, "TBD");
				f_bazaC->getPtrLK()->przyznajAutora(*f_bazaA->getAutorById(tempida));
			}
			f_fileC->close();

			f_fileD->open("plikD.txt", ios::in);
			while (*f_fileD >> tempid >> temprodz >> chtstr)
			{
				tempstr1 = chtstr;
				f_bazaD->wczytD(tempstr1, temprodz, tempid);
			}
			f_fileD->close();

			f_fileU->open("plikU.txt", ios::in);
			while (*f_fileU >> tempid >> temprodz >> r >> tempida)
			{
				if (r)f_bazaU->wczytK(f_bazaK->getPtrById(tempida), temprodz, tempid);
				else f_bazaU->wczytC(f_bazaC->getPtrById(tempida), temprodz, tempid);
			}
			f_fileU->close();

			f_fileSklK->open("pliksklK.txt", ios::in);
			while (*f_fileSklK >> tempid >> temprodz >> tempida >> cena)
			{
				if (temprodz == f_bazaK->getPtrById(tempida)->getRodzajInterwal())
					f_skl->wczytK(f_bazaK->getPtrById(tempid), tempida, cena);
			}
			f_fileSklK->close();

			f_fileSklC->open("pliksklC.txt", ios::in);
			while (*f_fileSklK >> tempid >> temprodz >> tempida >> cena)
			{
				if (temprodz == f_bazaC->getPtrById(tempida)->getRodzajInterwal())
					f_skl->wczytC(f_bazaC->getPtrById(tempid), tempida, cena);
			}
			f_fileSklC->close();
			std::cout << std::endl << "Pomyslnie otworzono." << std::endl;
			system("pause");

			temp_bazaK.swap(f_bazaK);
			temp_bazaC.swap(f_bazaC);
			temp_bazaA.swap(f_bazaA);
			temp_bazaD.swap(f_bazaD);
			temp_bazaU.swap(f_bazaU);
			temp_sklep.swap(f_skl);
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
