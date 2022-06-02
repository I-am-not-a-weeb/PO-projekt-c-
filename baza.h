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
    virtual size_t getMaxID() = 0;
};

class bazaKsiazek : protected baza
{
private:
    std::vector<c_ksiazka> vecKsiazka;
public:
    ~bazaKsiazek()
    {

    }
    void dodajKsiazke(std::string f_tytul, int f_rodzaj, std::string f_tekst)
    {
        vecKsiazka.push_back(c_ksiazka(f_tytul, f_rodzaj, f_tekst, ++maxID));
    }
    size_t getMaxID()
    {
        return vecKsiazka.size();
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
    //void usunCzasopismo(c_czasopismo f_czasopismo)
    //{
    //    vecCzasopism.erase(std::remove(vecCzasopism.begin(), vecCzasopism.end(), f_czasopismo));
    //}
    size_t getMaxID()
    {
        return vecCzasopism.size();
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
    size_t getMaxID()
    {
        return vecDrukarnie.size();
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
    size_t getMaxID()
    {
        return vecAutor.size();
    }
};
class bazaUmow : protected baza
{
private:
    std::vector<c_umowa> vecUmow;
public:
    void dodajUmoweK(std::shared_ptr<c_autor> f_autor, std::shared_ptr<c_ksiazka> f_ksiazka,int f_rodzaj)
    {
        vecUmow.push_back(c_umowa(f_ksiazka, f_rodzaj));
        f_autor->dodajUmowe(vecUmow.back());
    }
    void dodajUmoweC(std::shared_ptr<c_autor> f_autor, std::shared_ptr<c_czasopismo> f_czasopismo, int f_rodzaj)
    {
        vecUmow.push_back(c_umowa(f_czasopismo, f_rodzaj));
        f_autor->dodajUmowe(vecUmow.back());
    }
    size_t getMaxID()
    {
        return vecUmow.size();
    }
};