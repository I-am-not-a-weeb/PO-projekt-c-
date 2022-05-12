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

//class bazaKsiazek : protected baza
//{
//private:
//    c_ksiazka* ksiazki, *temp_ksiazki;
//public:
//    void dodajKsiazke(std::string f_tytul, int f_rodzaj, std::string f_tekst)
//    {
//        if (maxID > 0)
//        {
//            temp_ksiazki = new c_ksiazka[maxID];
//            for (int i = 0; i < maxID; i++)
//            {
//                temp_ksiazki[i] = ksiazki[i];
//            }
//            delete[] ksiazki;
//            ksiazki = new c_ksiazka[++maxID];
//            for (int i = 0; i < maxID-1; i++)
//            {
//                ksiazki[i] = temp_ksiazki[i];
//            }
//            ksiazki[maxID - 1] = c_ksiazka(f_tytul, f_rodzaj, f_tekst, maxID - 1);
//        }
//        else
//        {
//            ksiazki = new c_ksiazka[++maxID];
//            ksiazki[0] = c_ksiazka(f_tytul, f_rodzaj, f_tekst, maxID - 1);
//        }
//    }
//    std::string dump()     /// do zapisu
//    {
//        std::ostringstream out;
//        out << "KS:" << std::endl;
//        for (int i = 0; i < maxID; i++)
//        {
//            out << ksiazki[i].getId() << " " << ksiazki[i].getTytul() <<" " << ksiazki[i].getRodzajInterwal() << " " << ksiazki[i].getAutor().getImie() << " " << ksiazki[i].getAutor().getNazwisko() << " " << ksiazki[i].getTekst() << std::endl;
//        }
//        return out.str();
//    }
//    void usunKsiazke(c_ksiazka f_ksiazka)                        ///cala ta funckcja ale ze zmianami
//    {
//        int temp_i, temp;                                       ///nie wiem co zrobic z f_autor
//        for (int i = 0; i < maxID; i++)
//        {
//            if (f_ksiazka == ksiazki[i])
//            {
//                temp = maxID - i;
//                temp_i = i;
//                for (int i = temp; i < maxID - 1; i++)
//                {
//                    ksiazki[i] = ksiazki[i + 1];
//                }
//                for (int i = 0; i < maxID; i++)
//                {
//                    temp_ksiazki[i] = ksiazki[i];
//                }
//                delete[] ksiazki;
//                ksiazki = new c_ksiazka[maxID];
//                for (int i = 0; i < maxID; i++)
//                {
//                    ksiazki[i] = temp_ksiazki[i];
//                }
//                break;
//            }
//        }
//
//    }                                                            ///tutaj c_autor -> c_ksiazka/ autorzy[]->ksiazki[]
//    void testwypisywania()
//    {
//        for (int i = 0; i < maxID; i++)
//        {
//            std::cout << ksiazki[i].getId() << " " << ksiazki[i].getTytul() << " " << ksiazki[i].getAutor().getImie() << " " << ksiazki[i].getAutor().getNazwisko() << " " << ksiazki[i].getTekst() << std::endl;
//        }
//    }
//    c_ksiazka* dejksiazke(int f_id)
//    {
//        return &ksiazki[f_id];
//    }
//};

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
    void usunDrukarnie(c_drukarnia f_drukarnia)                        ///cala ta funckcja ale ze zmianami
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
        out << "AU:" << std::endl;
        for (int i = 0; i < maxID; i++)
        {
            out << autorzy[i].getImie() << " " << autorzy[i].getNazwisko() << std::endl;
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
