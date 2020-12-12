#pragma once
#include "Pracownik.h"
#ifndef MAGAZYNIER_H
#define MAGAZYNIER_H

using namespace std;

class Magazynier : public Pracownik
{
public:
    Magazynier(int spec, string imie) :Pracownik(imie) , spec(spec)
    {
        if (spec == 3) {
            ff = "nie umie obslugiwac wozka widlowego.";
        }
        else if (spec == 1)
        {
            ff = "umie obslugiwac wozek widlowy.";
        }
        else if (spec == 2)
        {
            ff = "umie obslugiwac wozek widlowy.";
        }
    }
    virtual void drukuj_osobe();
    virtual int getWynagrodzenie();
    int get_PojemoscMagazynu();


protected:
    int spec;
    string imie;
    int stala = 10; // wzrost pojemnosci magazynu o 10
    int wynagrodzenie = 6; //wynagrodzenie Magazyniera
    string ff;
};

#endif // !MAGAZYNIER_H

