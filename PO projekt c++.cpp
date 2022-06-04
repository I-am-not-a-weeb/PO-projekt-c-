#include <iostream>
#include "System.h"
#include "ZarzadzaniePozycjamiIUmowanie.h"
#include <Windows.h>
#include "baza.h"

using namespace std;

int main()
{
	char ch;
	int id, rodzaj,rodzajU, ida;
	string imiea, nazwiskoa, tytul, tekst;
	bazaKsiazek baza;
	c_ksiazka temp;
	c_pozycja::count = -1;

	bazaKsiazek bazaK;
	bazaCzasopism bazaC;
	bazaAutorow bazaA;
	bazaUmow bazaU;					/// do zrobienia dump
	System sys;
	while (1)
	{
		system("cls");
		cout << "1. Bazy" << endl << "2. Sklep" << endl << "3. Zapisz system" << endl << "4. Otworz zapis" << endl << "0. Wylacz program"  << endl;
		ch = _getch();
		system("cls");
		switch (ch)
		{
		case '1':		//bazy
		{	
			while(1)
			{
			system("cls");
			cout << "1. Baza autorow" << endl << "2. Baza Drukarni" << endl << "3. Baza pozycji" << endl << "4. Baza umow" << endl << "0. Cofnij";
			ch = _getch();
			system("cls");
			switch (ch)
			{
			case '1':		//baza autorow
			{
				while(1)
				{
				system("cls");
				cout << "1. Wypisac baze" << endl << "2. Dodac autora" << endl << "3. Dodac umowe do autora" <<endl <<"0. Cofnij" << endl;
				ch = _getch();
				system("cls");
				switch (ch)
				{
				case '1':		//wypis bazy autorow
				{
					cout << bazaA.dump() << endl << "Nacisnij dowolny przycisk by kontynuowac." << endl;
					_getch();
					continue;
				}
				case '2':		//dodanie autora
				{
					cout << "Imie: ";
					cin >> imiea;
					cout << endl << "Nazwisko: ";
					cin >> nazwiskoa;
					try {
						bazaA.dodajAutora(imiea, nazwiskoa);
					}
					catch (except ex) { cout << endl << ex.getMsg() << endl << "Nacisnij dowolny przycisk aby kontynuowac."; }
					catch (bad_alloc) {}
					continue;
				}
				case '3':		//dodanie umowy
				{
					while (1)
					{
						system("cls");
						cout << "1. Umowa na ksiazke" << endl << "2. Umowa na czasopismo" << endl << "0. Cofnij" << endl;
						ch = _getch();
						system("cls");
						switch (ch)
						{
							cout << bazaA.dump() << endl << "Wpisz ID autora: ";
							cin >> ida;
							cout << endl << "Nazwa: ";
							cin >> tytul;
						case 1:			//ksiazka
						{
							bazaA.getAutorById(ida)->dodajUmowe(*bazaU.dodajUmoweK(bazaA.getAutorById(ida), bazaK.dodajKsiazke(tytul, rodzaj,"TBD"),rodzajU));
							
							continue;
						}
						case 2:			//czasopismo
						{
							bazaA.getAutorById(ida)->dodajUmowe();
							continue;
						}
						case 0:			//cofniecie
						{
							break;
						}
						}
						break;
					}
					
				}
				case '0':		//confniecie
				{

					break;
				}
				default:
				{
					continue;
				}
				}
				break;
				}
				continue;
			}
			case '2':		//baza drukarni
			{
				while (1)
				{
					system("cls");
					cout << "1. Wypisac baze" << endl << "2. Dodac drukarnie" <<endl << "0. Cofnij"<< endl;
					ch = _getch();
					switch (ch)
					{
					case 1:		//wypis bazy
					{

					}
					case 2:		//dodanie drukarki
					{

					}
					case 0:		//cofniecie
					{
						break;
					}
					default:
					{
						continue;
					}
					}
					break;
				}
				
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
			continue;
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
				//if (ch == 'y' || ch == 'Y'); //sys.Save();
				return 0;
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