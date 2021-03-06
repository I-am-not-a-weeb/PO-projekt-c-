#include <iostream>
#include "System.h"
#include "baza.h"
#include "ZarzadzaniePozycjamiIUmowanie.h"
//#include <Windows.h>
#include <fstream>
//#include "baza.h"

using namespace std;

int main()
{
	bool yn;
	char ch;
	int id = -1, rodzaj = -1, rodzajU = -1, ida = -1,ilosc = -1;
	float cena = 0;
	string imiea, nazwiskoa, tytul, tekst, nazwa;
	bazaKsiazek baza;
	c_ksiazka temp;
	c_pozycja::count = -1;

	bazaKsiazek bazaK;
	bazaCzasopism bazaC;
	bazaAutorow bazaA;
	bazaDrukarni bazaD;
	bazaUmow bazaU;				

	shared_ptr<bazaDrukarni> PtrBazaD(&bazaD);

	fstream fileK, fileC, fileA, fileD, fileU, filesklK, filesklC;
	sklep sklepp;
	System sys;
	while (1)
	{
		system("cls");
		cout << "1. Bazy" << endl << "2. Sklep" << endl << "3. Zapisz system" << endl << "4. Otworz zapis" << endl << "0. Wylacz program" << endl;
		ch = _getch();
		system("cls");
		switch (ch)
		{
		case '1':		//bazy
		{
			while (1)
			{
				system("cls");
				cout << "1. Baza autorow" << endl << "2. Baza Drukarni" << endl << "3. Baza pozycji" << endl << "4. Baza umow" << endl << "0. Cofnij";
				ch = _getch();
				system("cls");
				switch (ch)
				{
				case '1':		//baza autorow
				{
					while (1)
					{
						system("cls");
						cout << "1. Wypisac baze" << endl << "2. Dodac autora" << endl << "3. Dodac umowe do autora" << endl << "0. Cofnij" << endl;
						ch = _getch();
						system("cls");
						switch (ch)
						{
						case '1':		//wypis bazy autorow
						{
							cout << "Id autora w bazie     Imie     Nazwisko" << endl;
							cout << bazaA.dump() << endl << endl << "Nacisnij dowolny przycisk by kontynuowac." << endl;
							_getch();
							continue;
						}
						case '2':		//dodanie autora
						{
							cout << "Imie: ";
							cin.clear();
							getline(cin,imiea);
							cout << endl << "Nazwisko: ";
							cin.clear();
							getline(cin,nazwiskoa);
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
								case '1':			//ksiazka
								{
									cout << bazaA.dump() << endl << "Wpisz ID autora: ";
									cin >> ida;
									cout << endl << "Nazwa ksiazki: ";
									cin.clear();
									cin.ignore();
									getline(cin,tytul);
									cout << endl << "Rodzaj: ";
									cin >> rodzaj;
									cout << endl << "Rodzaj umowy: ";
									cin >> rodzajU;
									try {
										bazaU.dodajUmoweK(bazaK.dodajKsiazke(tytul, rodzaj, "TBD"), rodzajU);
										bazaK.getPtrLK()->dodajAutora(*bazaA.getAutorById(ida));
									}
									catch (except es) {
										cout << endl << es.getMsg();
										system("pause");
									}
									break;
								}
								case '2':			//czasopismo
								{
									cout << bazaA.dump() << endl << "Wpisz ID autora: ";
									cin >> ida;
									cout << endl << "Nazwa czasopisma: ";
									cin.clear();
									cin.ignore();
									getline(cin,tytul);
									cout << endl << "Interwal: ";
									cin >> rodzaj;
									cout << endl << "Rodzaj umowy: ";
									cin >> rodzajU;
									try {
										bazaU.dodajUmoweC(bazaC.dodajCzasopismo(tytul, rodzaj, "TBD"), rodzajU);
										bazaC.getPtrLK()->przyznajAutora(*bazaA.getAutorById(ida));
									}
									catch (except es)
									{
										cout << endl << es.getMsg();
										system("pause");
									}
									break;
								}
								case '0':			//cofniecie
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
						cout << "1. Wypisac baze" << endl << "2. Dodac drukarnie" << endl << "0. Cofnij" << endl;
						ch = _getch();
						system("cls");
						switch (ch)
						{
						case '1':		//wypis bazy
						{
							cout << "Id drukarni     Czy drukuje albumy   Nazwa" << endl;
							cout << bazaD.dump() << endl << endl << "Nacisnij dowolny przycisk aby kontynuowac." << endl;
							_getch();
							continue;
						}
						case '2':		//dodanie drukarki
						{
							cout << "Nazwa: ";
							cin.clear();
							getline(cin,nazwa);
							while (1)
							{
								cout << endl << "Czy drukuje albumy? Y/N";
								ch = _getch();
								if (ch == 'Y' || ch == 'y') { yn = 1; break; }
								else if (ch == 'N' || ch == 'n') { yn = 0; break; }
								else continue;
							}
							bazaD.dodajDrukarnie(nazwa, yn);
							continue;
						}
						case '0':		//cofniecie
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
				case '3':		//baza pozycji
				{
					while (1)
					{
						system("cls");
						cout << "1. Baza ksiazek" << endl << "2. Baza czasopism" << endl << "0. Confij" << endl;
						ch = _getch();
						system("cls");
						switch (ch)
						{
						case '1':		//baza ksiazek
						{
							while (1)
							{
								system("cls");
								cout << "1. Wypisac baze" << endl << "2. Dodac ksiazke" << endl << "0. Cofnij" << endl;
								ch = _getch();
								system("cls");
								switch (ch)
								{
								case '1':		//wypis bazy
								{
									cout << "Id ksiazki    Id autora    Rodzaj    Tytul" << endl;
									cout << bazaK.dump() << endl << endl << "Nacisnij dowolny przycisk aby kontynuowac." << endl;
									_getch();
									continue;
								}
								case '2':		//dodanie ksiazki
								{
									while (1)
									{
										cout << endl << "Tytul: ";
										cin.ignore();
										getline(cin,tytul);
										cout << endl << "Rodzaj: ";
										cin >>rodzaj;
										cout << endl << "Id autora    Imie    Nazwisko" << endl << bazaA.dump();
										cout << endl << "ID autora:";
										cin >> ida;
										while (1)
										{
											cout << "Potwierdzenie dodania ksiazki o nazwie \"" << tytul << "\" rodzaju: \"" << rodzaj << "\" i ID autora: \"" << ida << "\"  Y/N";
											ch = _getch();
											if (ch == 'y' || ch == 'Y')
											{	
												try {
													bazaA.getAutorById(ida)->dodajKsiazke(bazaK.dodajKsiazke(tytul, rodzaj, "TBD"));
													bazaK.getPtrLK()->dodajAutora(*bazaA.getAutorById(ida));
													cout << endl << "Dodano ksiazke.";
												}
												catch (except es) { cout << endl << es.getMsg(); }
												cout << endl << "Nacisnij dowolny przycisk aby kontynuowac." << endl;
												_getch();
												break;
											}
											else if (ch == 'n' || ch == 'N') break;
										}
										break;
									}
									continue;
								}
								case '0':		//cofniecie
								{
									break;
								}
								default: continue;
								}
								break;
							}
							continue;
						}
						case '2':		//baza czasopism
						{
							while (1)
							{
								system("cls");
								cout << "1. Wypisac baze" << endl << "2. Dodac czasopismo" << endl << "0. Cofnij" << endl;
								ch = _getch();
								switch (ch)
								{
								case '1':		//wypis bazy
								{
									cout << "Id czasopisma   Id autora   Interwal   Tytul" << endl;
									cout << bazaC.dump() << endl << endl << "Nacisnij dowolny przycisk aby kontynuowac." << endl;
									_getch();
									continue;
								}
								case '2':		//dodanie czaopisma
								{
									cout << "Tytul: ";
									cin.ignore();
									getline(cin,tytul);
									cout << endl << "Interwal: ";
									cin.clear();
									cin >> rodzaj;
									cout << endl <<"Id autora    Imie    Nazwisko" << endl << bazaA.dump();
									cout << endl << "ID autora:";
									cin.clear();
									cin >> ida;
									while (1)
									{
										cout << "Potwierdzenie dodania ksiazki o nazwie \"" << tytul << "\" rodzaju: \"" << rodzaj << "\" i ID autora: \"" << ida << "\"  Y/N";
										ch = _getch();
										if (ch == 'y' || ch == 'Y')
										{
											try {
												bazaA.getAutorById(ida)->dodajCzasopismo(bazaC.dodajCzasopismo(tytul, rodzaj, "TBD"));
												bazaC.getPtrLK()->przyznajAutora(*bazaA.getAutorById(ida));
												cout << endl << "Dodano czasopismo.";
											}
											catch (except es) { cout << endl << es.getMsg(); }
											cout << endl << "Nacisnij dowolny przycisk aby kontynuowac." << endl;
											_getch();
											break;
										}
										else if
											(ch == 'n' || ch == 'N')
										{
											break;
										}
										else continue;
									}
								}
								case '0':		//cofniecie
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
						case '0':		//cofnij
						{
							break;
						}
						default:
							continue;
						}
						}
						break;
					}
					continue;
				}
				case '4':		//baza umow
				{
					while (1)
					{
						system("cls");
						cout << "1. Wypisac baze" << endl << "0. Cofnij" << endl;
						ch = _getch();
						system("cls");
						switch (ch)
						{
						case '1':		//wypis
						{
							cout << "Id umowy  Rodzaj umowy  Ksiazka?  Id ksiazki/czasopisma" << endl;
							cout << bazaU.dump() << endl << endl << "Nacisnij dowolny przycisk aby kontynuowac." << endl;
							_getch();
							continue;
						}
						case '0':		//cofniecie
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
			while (1)
			{	
				system("cls");
				cout << "1. Wypisz stan" << endl << "2. Sprzedaj pozycje" << endl << "3. Zamow do druku" << endl << "0. Cofnij";
				ch = _getch();
				system("cls");
				switch (ch)
				{
				case '1':		//wypis stanu sklepu
				{
					cout << sklepp.wypis() << endl << endl << "Nacisnij dowolny przycisk aby kontynuowac." << endl;
					_getch();
					continue;
				}
				case '2':		//sprzedaz
				{
					cout << sklepp.wypis() << endl << "ID: ";
					cin >> id;
					cout << endl << "Ilosc:";
					cin >> ilosc;
					try {
						sklepp.sprzed(id, ilosc);
					}
					catch (except es) { cout << es.getMsg() << "Nacisnij dowolny przycisk aby kontynuowac." << endl; _getch(); }
					continue;
				}
				case '3':		//drukowanko
				{
					cout << "Id  Id autora  Rodzaj/Interwal  Tytul" << endl;
					cout << bazaK.dump() << endl << "ID: ";
					cin.ignore();
					cin >> id;
					cout << endl << "Ilosc:";
					cin >> ilosc;
					cout << endl << "Cena: ";
					cin >> cena;
					try {
						sklepp.dodruk_k(bazaK.getPtrById(id), ilosc, PtrBazaD, cena); }
					catch (except es) {
						try { sklepp.dodruk_c(bazaC.getPtrById(id), ilosc, cena); }
						catch (except es) {
							cout << endl << es.getMsg() << endl << "Nacisnij dowolny przycisk aby kontynuowac.";
							_getch();
						}
					}
					continue;
				}
				case '0':		//cofniecie
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
		case '3':		//zapis ->
		{
			try{
 				sys.Save(shared_ptr<bazaKsiazek>(&bazaK,[](bazaKsiazek*){}), shared_ptr<bazaCzasopism>(&bazaC,[](bazaCzasopism*){}), shared_ptr <bazaAutorow>(&bazaA,[](bazaAutorow*){}), shared_ptr<bazaDrukarni>(&bazaD,[](bazaDrukarni*){}), shared_ptr<bazaUmow>(&bazaU,[](bazaUmow*){})
					, shared_ptr<sklep>(&sklepp,[](sklep*){}), shared_ptr<fstream>(&fileK, [](fstream*) {}), shared_ptr<fstream>(&fileC,[](fstream*){}), shared_ptr<fstream>(&fileA, [](fstream*) {}), shared_ptr<fstream>(&fileU, [](fstream*) {}), shared_ptr<fstream>(&fileD, [](fstream*) {})
					, shared_ptr<fstream>(&filesklK,[](fstream*) {}), shared_ptr<fstream>(&filesklC,[](fstream*){}));

				cout << endl << "Pomyslnie zapisano.";
				system("pause");
			}
			catch (except es) { cout << endl << es.getMsg(); }
			catch (exception es2){}
			continue;
		}
		case '4':		//odczyt <-
		{
			try {
				sys.Open(shared_ptr<bazaKsiazek>(&bazaK, [](bazaKsiazek*) {}), shared_ptr<bazaCzasopism>(&bazaC, [](bazaCzasopism*) {}), shared_ptr <bazaAutorow>(&bazaA, [](bazaAutorow*) {}), shared_ptr<bazaDrukarni>(&bazaD, [](bazaDrukarni*) {}), shared_ptr<bazaUmow>(&bazaU, [](bazaUmow*) {})
					, shared_ptr<sklep>(&sklepp, [](sklep*) {}), shared_ptr<fstream>(&fileK, [](fstream*) {}), shared_ptr<fstream>(&fileC, [](fstream*) {}), shared_ptr<fstream>(&fileA, [](fstream*) {}), shared_ptr<fstream>(&fileU, [](fstream*) {}), shared_ptr<fstream>(&fileD, [](fstream*) {})
					, shared_ptr<fstream>(&filesklK, [](fstream*) {}), shared_ptr<fstream>(&filesklC, [](fstream*) {}));
				continue;
			}
			catch (except es) {}
			
		}
		case '0':		//wyjscie z programu
		{
			while (1)				//pytanie o zapis
			{
				std::cout << "Czy zapisac stan? Y/N";
				ch = _getch();
				//if (ch == 'y' || ch == 'Y'); //sys.Save();
				exit(0);
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