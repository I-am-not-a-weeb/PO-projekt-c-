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
    std::shared_ptr<c_ksiazka> wczytKsiazka(std::string f_tytul, int f_rodzaj, int f_id)
    {
        std::shared_ptr<c_ksiazka>temp(new c_ksiazka(f_tytul, f_rodzaj, f_id, 1), [](c_ksiazka*) {});
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
    bool isItId(int f_id)
    {
        for (std::vector<c_ksiazka>::iterator i = vecKsiazka.begin(); i != vecKsiazka.end(); i++)
        {
            if (i->getId() == f_id) return 1;
        }
        return 0;
    }
    std::shared_ptr<c_ksiazka> getPtrLK()
    {
        return std::shared_ptr<c_ksiazka>(&vecKsiazka.back(), [](c_ksiazka*) {});
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
        std::shared_ptr<c_czasopismo> temp(new c_czasopismo(f_tytul, f_interwal, f_tekst, ++maxID),[](c_czasopismo*){});
        vecCzasopism.push_back(*temp);
        return temp;
    }
    std::shared_ptr<c_czasopismo> wczytCzasopismo(std::string f_tytul, bool f_interwal, int f_id)
    {
        std::shared_ptr<c_czasopismo> temp(new c_czasopismo(f_tytul, f_interwal,f_id,1), [](c_czasopismo*) {});
        vecCzasopism.push_back(*temp);
        return temp;
    }
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
        throw except("Brak czasopisma po podanym id");
    }

    bool isItId(int f_id)
    {
        for (std::vector<c_czasopismo>::iterator i = vecCzasopism.begin(); i != vecCzasopism.end(); i++)
        {
            if (i->getId() == f_id) return 1;
        }
        return 0;
    }
    std::shared_ptr<c_czasopismo> getPtrLK()
    {
        return std::shared_ptr<c_czasopismo>(&vecCzasopism.back(), [](c_czasopismo*) {});
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
    void dodajAutoraWczyt(std::string f_imie, std::string f_nazwisko,int f_id)
    {
        vecAutor.push_back(c_autor(f_imie, f_nazwisko, f_id));
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
        if (f_id >= 0 && f_id <= vecAutor.size()) return std::shared_ptr<c_autor>(&vecAutor[f_id - 1], [](c_autor*){});
        else throw except("Brak autora o podanym id.");
    }
    std::shared_ptr<c_autor> wczytGetAutorById(int f_id)
    {
        if (f_id >= 0 && f_id <= vecAutor.size()) return std::shared_ptr<c_autor>(&vecAutor[f_id], &null_deleter);
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
    std::shared_ptr<c_umowa> dodajUmoweK(std::shared_ptr<c_ksiazka> f_ksiazka,int f_rodzaj)
    {
        std::shared_ptr<c_umowa> tmp;
        tmp= std::shared_ptr<c_umowa>(new c_umowa(f_ksiazka, f_rodzaj));
        vecUmow.push_back(*tmp);
        return tmp;
    }
    std::shared_ptr<c_umowa> wczytK(std::shared_ptr<c_ksiazka> f_ksiazka, int f_rodzaj,int f_id, std::shared_ptr<bazaKsiazek> f_bazaK)
    {
        std::shared_ptr<c_umowa> tmp;
        tmp = std::shared_ptr<c_umowa>(new c_umowa(f_ksiazka, f_rodzaj, f_id));
        if(!f_bazaK->isItId(f_id))vecUmow.push_back(*tmp);
        return tmp;
    }
    std::shared_ptr<c_umowa> wczytC(std::shared_ptr<c_czasopismo> f_czasopismo, int f_rodzaj, int f_id,std::shared_ptr<bazaCzasopism> f_bazaC)
    {
        std::shared_ptr<c_umowa> tmp;
        tmp = std::shared_ptr<c_umowa>(new c_umowa(f_czasopismo, f_rodzaj, f_id));
        if(!f_bazaC->isItId(f_id)) vecUmow.push_back(*tmp);
        return tmp;
    }
    std::shared_ptr<c_umowa> dodajUmoweC(std::shared_ptr<c_czasopismo> f_czasopismo, int f_rodzaj)
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