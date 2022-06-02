#include <iostream>
#include "System.h"
#include "ZarzadzaniePozycjamiIUmowanie.h"
#include <Windows.h>
#include "baza.h"

using namespace std;

int main()
{
	char ch;
	int id, rodzaj, ida;
	string imiea, nazwiskoa, tytul, tekst;
	bazaKsiazek baza;
	c_ksiazka temp;
	c_pozycja::count = -1;

	bazaKsiazek bazaK;
	bazaCzasopism bazaC;
	bazaAutorow bazaA;
	System sys;
	while (1)
	{
		cout << "1. Bazy" << endl << "2. Sklep" << endl << "3. Zapisz system" << endl << "4. Otworz zapis" << endl << "0. Wyłacz program"  << endl;
		ch = _getch();
		system("cls");
		switch (ch)
		{
		case '1':		//bazy
		{	
			while(1)
			{
			cout << "1. Baza autorow" << endl << "2. Baza Drukarni" << endl << "3. Baza pozycji" << endl << "4. Baza umow" << endl << "0. Wyjdz";
			ch = _getch();
			system("cls");
			switch (ch)
			{
			case '1':		//baza autorow
			{
				cout << "1. Wypisac baze" << endl << "2. Dodac autora" << endl << "3. Dodac umowe do autora" <<endl <<"0. Wyjdz" << endl;
				ch = _getch();
				system("cls");
				switch (ch)
				{
				case '1':		//wypis bazy autorow
				{
					cout << bazaA.dump() << endl << "Nacisnij dowolny przycisk by kontynuowac." << endl;
				}
				case '2':		//dodanie autora
				{
					cout << "Imie: ";
					cin >> imiea;
					cout << endl << "Nazwisko: ";
					cin >> nazwiskoa;
					try{ 
						bazaA.dodajAutora(imiea, nazwiskoa); 
					}
					catch (except ex) { cout << endl << ex.getMsg()<< endl <<"Nacisnij dowolny przycisk aby kontynuowac."; }
					continue;
				}
				case '3':		//dodanie umowy
				{

				}
				case '0':
				{

				}

				}
				continue;
			}
			case '2':		//baza drukarni
			{
				cout << "1. Wypisac baze" << endl << "2. Dodac drukarnie" << endl;

				continue;
			}
			case '3':		//baza pozycji
			{
				cout << "1. Baza ksiazek" << endl << "2. Baza czasopism" << endl;
				ch = _getch();
				system("cls");
				switch (ch)
				{
				case '1':
				{

				}
				case '2':
				{

				}

				}
			}
			case '4':		//baza umow
			{

				continue;
			}
			case '0':		//wyjscie
			{
				break;
			}
			default:		//zly przycisk
			{
				continue;
			}
			}
			break;
			}
		}
		case '2':		//sklep
		{

		}
		case '3':		//zapis ->
		{

		}
		case '4':		//odczyt <-
		{

		}
		case '0':		//wyjscie z programu
		{
			while (1)				//pytanie o zapis
			{
				cout << "Czy zapisac stan? Y/N";
				ch = _getch();
				if (ch == 'y' || ch == 'Y'); //sys.Save();
			}
		}
		default:
		{
			continue;
		}
		}
		break;
	}
}