#pragma once
#include "ZarzadzaniePozycjamiIUmowanie.h"
#include "ZarzadzanieAutorami.h"
#include "ZarzadzanieDrukarniami.h"
#include <sstream>

class baza
{
protected:
    int maxID = 0;
public:

};

class bazaKsiazek : protected baza
{
private:
    c_ksiazka* ksiazki, * temp_ksiazki;
public:
    void dodajKsiazke(std::string f_tytul, int f_rodzaj, std::string f_tekst)
    {
        temp_ksiazki = new c_ksiazka[++maxID];
        for (int i = 0; i < maxID; i++)
        {
            temp_ksiazki[i] = ksiazki[i];
        }
        delete[] ksiazki;
        ksiazki = new c_ksiazka[maxID];
        for (int i = 0; i < maxID; i++)
        {
            ksiazki[i] = temp_ksiazki[i];
        }
        ksiazki[maxID - 1] = c_ksiazka(f_tytul, f_rodzaj, f_tekst, maxID - 1);
    }
    std::string dump()     /// do zapisu
    {
        std::ostringstream out;
        out << "KS:" << endl;
        for (int i = 0; i < maxID; i++)
        {
            out << ksiazki[i].getId() << " " << ksiazki[i].getTytul() << " " << ksiazki[i].getAutor().getImie();
            out << " " << ksiazki[i].getAutor().getNazwisko() << " " << ksiazki[i].getTekst() << endl;
        }
        return out.str();
    }
    void usunKsiazke(c_ksiazka f_autor)                        ///cala ta funckcja ale ze zmianami
    {
        int temp_i, temp;                                       ///nie wiem co zrobic z f_autor
        for (int i = 0; i < maxID; i++)
        {
            if (f_autor == ksiazki[i])
            {
                temp = maxID - i;
                temp_i = i;
                for (int i = temp; i < maxID - 1; i++)
                {
                    ksiazki[i] = ksiazki[i + 1];
                }
                for (int i = 0; i < maxID; i++)
                {
                    temp_ksiazki[i] = ksiazki[i];
                }
                delete[] ksiazki;
                ksiazki = new c_ksiazka[maxID];
                for (int i = 0; i < maxID; i++)
                {
                    ksiazki[i] = temp_ksiazki[i];
                }
                break;
            }
        }

    }
    ///tutaj c_autor -> c_ksiazka/ autorzy[]->ksiazki[]
};

class bazaCzasopism : protected baza
{
private:
    c_czasopismo* czasopisma, * temp_czasopisma;
public:
    void dodajCzasopismo(std::string f_tytul, bool f_interwal, std::string f_tekst)
    {
        temp_czasopisma = new c_czasopismo[++maxID];
        for (int i = 0; i < maxID; i++)
        {
            temp_czasopisma[i] = czasopisma[i];
        }
        delete[] czasopisma;
        czasopisma = new c_czasopismo[maxID];
        for (int i = 0; i < maxID; i++)
        {
            czasopisma[i] = temp_czasopisma[i];
        }
        czasopisma[maxID - 1] = c_czasopismo(f_tytul, f_interwal, f_tekst, maxID - 1);
        delete[] temp_czasopisma;
    }
    std::string dump()     /// do zapisu
    {
        std::ostringstream out;
        out << "CZAS:" << endl;
        for (int i = 0; i < maxID; i++)
        {
            out << czasopisma[i].getId() << " " << czasopisma[i].getTytul() << " " << czasopisma[i].getAutor().getImie();
            out << " " << czasopisma[i].getAutor().getNazwisko() << " " << czasopisma[i].getTekst() << endl;
        }
        return out.str();
    }
    void usunCzasopismo(c_czasopismo f_autor)                        ///cala ta funckcja ale ze zmianami
    {
        int temp_i, temp;                                       ///nie wiem co zrobic z f_autor
        for (int i = 0; i < maxID; i++)
        {
            if (f_autor == czasopisma[i])
            {
                temp = maxID - i;
                temp_i = i;
                for (int i = temp; i < maxID - 1; i++)
                {
                    czasopisma[i] = czasopisma[i + 1];
                }
                for (int i = 0; i < maxID; i++)
                {
                    temp_czasopisma[i] = czasopisma[i];
                }
                delete[] czasopisma;
                czasopisma = new c_czasopismo[maxID];
                for (int i = 0; i < maxID; i++)
                {
                    czasopisma[i] = temp_czasopisma[i];
                }
                break;
            }
        }

    }
    ///tutaj c_autor -> c_czasopismo/ autorzy[]->czasopisma[]
};

class bazaDrukarni : protected baza
{
private:
    c_drukarnia* drukarnie, * temp_drukarnie;
public:
    void dodajDrukarnie(bool f_album, std::string f_nazwa)
    {
        temp_drukarnie = new c_drukarnia[++maxID];
        for (int i = 0; i < maxID; i++)
        {
            temp_drukarnie[i] = drukarnie[i];
        }
        delete[] drukarnie;
        drukarnie = new c_drukarnia[maxID];
        for (int i = 0; i < maxID; i++)
        {
            drukarnie[i] = temp_drukarnie[i];
        }
        drukarnie[maxID - 1] = c_drukarnia(f_album, f_nazwa, maxID - 1);
        delete temp_drukarnie;
    }
    void usunDrukarnie(c_drukarnia f_autor)                        ///cala ta funckcja ale ze zmianami
    {
        int temp_i, temp;                                       ///nie wiem co zrobic z f_autor
        for (int i = 0; i < maxID; i++)
        {
            if (f_autor == drukarnie[i])
            {
                temp = maxID - i;
                temp_i = i;
                for (int i = temp; i < maxID - 1; i++)
                {
                    drukarnie[i] = drukarnie[i + 1];
                }
                for (int i = 0; i < maxID; i++)
                {
                    temp_drukarnie[i] = drukarnie[i];
                }
                delete[] drukarnie;
                drukarnie = new c_drukarnia[maxID];
                for (int i = 0; i < maxID; i++)
                {
                    drukarnie[i] = temp_drukarnie[i];
                }
                break;
            }
        }

    }
    ///tutaj c_autor -> c_drukarnia/ autorzy[]->drukarnie[]
};

class bazaAutorow : protected baza
{
private:
    c_autor* autorzy, * temp_autorzy;
public:
    void dodajAutora(std::string f_imie, std::string f_nazwisko)
    {
        temp_autorzy = new c_autor[++maxID];
        for (int i = 0; i < maxID; i++)
        {
            temp_autorzy[i] = autorzy[i];
        }
        delete[] autorzy;
        autorzy = new c_autor[maxID];
        for (int i = 0; i < maxID; i++)
        {
            autorzy[i] = temp_autorzy[i];
        }
        autorzy[maxID - 1] = c_autor(f_imie, f_nazwisko, maxID - 1);
        delete[] temp_autorzy;
    }
    std::string dump()     /// do zapisu
    {
        std::ostringstream out;
        out << "AU:" << endl;
        for (int i = 0; i < maxID; i++)
        {
            out << autorzy[i].getImie() << " " << autorzy[i].getNazwisko() << endl;
        }
        return out.str();
    }
    void usunAutora(c_autor f_autor)                        ///cala ta funckcja ale ze zmianami
    {
        int temp_i, temp;
        for (int i = 0; i < maxID; i++)
        {
            if (f_autor == autorzy[i])
            {
                temp = maxID - i;
                temp_i = i;
                for (int i = temp; i < maxID - 1; i++)
                {
                    autorzy[i] = autorzy[i + 1];
                }
                for (int i = 0; i < maxID; i++)
                {
                    temp_autorzy[i] = autorzy[i];
                }
                delete[] autorzy;
                autorzy = new c_autor[maxID];
                for (int i = 0; i < maxID; i++)
                {
                    autorzy[i] = temp_autorzy[i];
                }
                break;
            }
        }

    }
};
