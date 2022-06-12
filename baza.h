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
    std::shared_ptr<c_ksiazka> dodajKsiazke(std::string f_tytul, int f_rodzaj, std::string f_tekst)
    {
        std::shared_ptr<c_ksiazka> temp(new c_ksiazka(f_tytul, f_rodzaj, f_tekst, ++maxID), [](c_ksiazka*) {});
        vecKsiazka.push_back(*temp);
        return temp;
    }
    size_t getMaxID()
    {
        return vecKsiazka.size();
    }
    std::shared_ptr<c_ksiazka> getPtrById(int f_id)
    {
        for (std::vector<c_ksiazka>::iterator i = vecKsiazka.begin(); i != vecKsiazka.end(); i++)
        {
            if (i->getId() == f_id) return i->getPtr();
        }
        throw except("Brak ksiazki o podanym id.");
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
    std::shared_ptr<c_czasopismo> getPtrById(int f_id)
    {
        for (std::vector<c_czasopismo>::iterator i = vecCzasopism.begin(); i != vecCzasopism.end(); i++)
        {
            if (i->getId() == f_id) return i->getPtrB();
        }
        throw except("Brak pozycji po podanym id");
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
        if (f_id >= 0 && f_id <= vecAutor.size()) return std::shared_ptr<c_autor>(&vecAutor[f_id - 1], &null_deleter);
        else throw except("Brak autora o podanym id.");
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
        tmp= std::shared_ptr<c_umowa>(new c_umowa(f_ksiazka, f_rodzaj),[](c_umowa*){});
        vecUmow.push_back(*tmp);
        return tmp;
    }
    std::shared_ptr<c_umowa> dodajUmoweC(std::shared_ptr<c_autor> f_autor, std::shared_ptr<c_czasopismo> f_czasopismo, int f_rodzaj)
    {
        std::shared_ptr<c_umowa> tmp;
        tmp = std::shared_ptr<c_umowa>(new c_umowa(f_czasopismo, f_rodzaj),[](c_umowa*){});
        vecUmow.push_back(*tmp);
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

void null_deleter(bazaDrukarni*) {}