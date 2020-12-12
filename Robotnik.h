#pragma once
#include "Pracownik.h"
#ifndef ROBOTNIK_H
#define ROBOTNIK_H

class Robotnik : public Pracownik
{
public:
    Robotnik(int spec, string imie) : spec(spec), Pracownik(imie)
    {};

    virtual void drukuj_osobe();
    virtual int getWynagrodzenie();
    int get_teorWypr_produkty();
  

protected:
    int spec;
    int stala = 9; // wzrost podazy (ilosci wyprodukowanych teoretycznie produktow) o 9
    int wynagrodzenie = 5; //wynagrodzenie Robotnika
    string imie;
};

#endif // !ROBOTNIK_H