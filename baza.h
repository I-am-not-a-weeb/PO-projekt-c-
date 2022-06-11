#pragma once
#include "ZarzadzaniePozycjamiIUmowanie.h"
#include "ZarzadzanieAutorami.h"
#include "ZarzadzanieDrukarniami.h"
#include <sstream>
#include <vector>
#include <fstream>

void null_deleter(c_autor*) {}

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
    std::shared_ptr<c_ksiazka> dodajKsiazke(std::string f_tytul, int f_rodzaj, std::string f_tekst)
    {
        c_ksiazka temp = c_ksiazka(f_tytul, f_rodzaj, f_tekst, ++maxID);
        vecKsiazka.push_back(temp);
        return std::shared_ptr<c_ksiazka>(&vecKsiazka.back());
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
    std::shared_ptr<c_czasopismo> dodajCzasopismo(std::string f_tytul, bool f_interwal, std::string f_tekst)
    {
        c_czasopismo temp = c_czasopismo(f_tytul, f_interwal, f_tekst, ++maxID);
        vecCzasopism.push_back(temp);
        return std::shared_ptr<c_czasopismo>(&temp);
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
    std::shared_ptr<c_autor> getAutorById(int f_id)
    {
        return std::shared_ptr<c_autor>(&vecAutor[f_id - 1],&null_deleter);
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
    std::shared_ptr<c_umowa> dodajUmoweK(std::shared_ptr<c_autor> f_autor, std::shared_ptr<c_ksiazka> f_ksiazka,int f_rodzaj)
    {
        std::shared_ptr<c_umowa> tmp;
        tmp= std::shared_ptr<c_umowa>(new c_umowa(f_ksiazka, f_rodzaj));
        vecUmow.push_back(*tmp);
        return tmp;
    }
    std::shared_ptr<c_umowa> dodajUmoweC(std::shared_ptr<c_autor> f_autor, std::shared_ptr<c_czasopismo> f_czasopismo, int f_rodzaj)
    {
        std::shared_ptr<c_umowa> tmp;
        *tmp = c_umowa(f_czasopismo, f_rodzaj);
        vecUmow.push_back(*tmp);
        f_autor->dodajUmowe(tmp);
        return tmp;
    }
    size_t getMaxID()
    {
        return vecUmow.size();
    }
    std::string dump()
    {
        std::ostringstream out;
        for (std::vector<c_umowa>::iterator i = vecUmow.begin(); i != vecUmow.end(); i++)
        {
            out << (*i).dump();
        }
        return out.str();
    }
};