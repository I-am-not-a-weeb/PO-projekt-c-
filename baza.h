#pragma once
#include "ZarzadzaniePozycjamiIUmowanie.h"
#include "ZarzadzanieAutorami.h"
#include "ZarzadzanieDrukarniami.h"
#include <sstream>
#include <vector>
#include <fstream>

class baza
{
protected:
    int maxID = 0;
public:
    virtual std::string dump() = 0;
};

class bazaKsiazek : protected baza
{
private:
    std::vector<c_ksiazka> vecKsiazka;
public:
    void dodajKsiazke(std::string f_tytul, int f_rodzaj, std::string f_tekst)
    {
        vecKsiazka.push_back(c_ksiazka(f_tytul, f_rodzaj, f_tekst, ++maxID));
    }
    void usunKsiazke(c_ksiazka f_ksiazka)
    {
        vecKsiazka.erase(std::remove(vecKsiazka.begin(),vecKsiazka.end(),f_ksiazka));
        /*t_ptr = std::for_each(vecKsiazka.begin(), vecKsiazka.end(), ).erase();
        vector<c_ksiazka>::iterator del;
        for (del = vecKsiazka.begin(); del!= vecKsiazka.end(); del++)
        {
            ~del();
        }*/
    }
    std::string dump()
    {
        std::ostringstream out;
        for (std::vector<c_ksiazka>::iterator i = vecKsiazka.begin(); i != vecKsiazka.end(); i++)
        {
            out << (*i).dump();
        }
        return out.str();
    }
};

class bazaCzasopism : protected baza
{
private:
    std::vector<c_czasopismo> vecCzasopism;
public:
    void dodajCzasopismo(std::string f_tytul, bool f_interwal, std::string f_tekst)
    {
        vecCzasopism.push_back(c_czasopismo(f_tytul, f_interwal, f_tekst, ++maxID));
    }
    void usunCzasopismo(c_czasopismo f_czasopismo)
    {
        vecCzasopism.erase(std::remove(vecCzasopism.begin(), vecCzasopism.end(), f_czasopismo));
    }
    std::string dump()
    {
        std::ostringstream out;
        for (std::vector<c_czasopismo>::iterator i = vecCzasopism.begin(); i != vecCzasopism.end(); i++)
        {
            out << (*i).dump();
        }
        return out.str();
    }
};

class bazaDrukarni : protected baza
{
private:
    std::vector<c_drukarnia> vecDrukarnie;
public:
    void dodajDrukarnie(std::string f_nazwa, bool f_album)
    {
        vecDrukarnie.push_back(c_drukarnia(f_nazwa, f_album,++maxID));
    }
    void usunDrukarnie(c_drukarnia f_drukarnia) 
    {
        vecDrukarnie.erase(std::remove(vecDrukarnie.begin(), vecDrukarnie.end(), f_drukarnia));
    }
    std::string dump()
    {
        std::ostringstream out;
        for (std::vector<c_drukarnia>::iterator i = vecDrukarnie.begin(); i != vecDrukarnie.end(); i++)
        {
            out << (*i).dump();
        }
        return out.str();
    }
};

class bazaAutorow : protected baza
{
private:
    std::vector<c_autor> vecAutor;
public:
    void dodajAutora(std::string f_imie, std::string f_nazwisko)
    {
        vecAutor.push_back(c_autor(f_imie, f_nazwisko, ++maxID));
    }
    std::string dump()  
    {
        std::ostringstream out;
        for (std::vector<c_autor>::iterator i = vecAutor.begin(); i != vecAutor.end(); i++)
        {
            out << (*i).dump();
        }
        return out.str();
    }
    void usunAutora(c_autor f_autor)
    {
        vecAutor.erase(std::remove(vecAutor.begin(), vecAutor.end(), f_autor));
    }
};