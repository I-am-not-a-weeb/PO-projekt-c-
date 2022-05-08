#include <iostream>
#include "System.h"
#include "ZarzadzaniePozycjamiIUmowanie.h"
#include <Windows.h>
#include "baza.h"

using namespace std;

int main()
{
	int id, rodzaj, ida;
	string imiea, nazwiskoa, tytul, tekst;
	bazaKsiazek baza;
	c_ksiazka temp;
	for (int i = 0; i < 3; i++)
	{
		cout << "Id: ";
		cin >> id;
		cout << endl << "Rodzaj: ";
		cin >> rodzaj;
		cout << endl << "Tytul: ";
		cin >> tytul;
		cout << endl << "Tekst: ";
		cin >> tekst;
		cout <<endl<< "Imie autora: ";
		cin >> imiea;
		cout <<endl<< "Nazwisko autora: ";
		cin >> nazwiskoa;
		cout <<endl<< "Id autora: ";
		cin >> ida;
		baza.dodajKsiazke(tytul, rodzaj, tekst);
		baza.dejksiazke(id)->dodajAutora(c_autor(imiea,nazwiskoa,ida));
	}
	system("cls");
	cout << baza.dump();
}