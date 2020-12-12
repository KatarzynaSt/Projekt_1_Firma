#pragma once
#include <iostream>
#include <istream>
#include <math.h>
#include <vector>
#include <string>
#include <random>
#include <time.h>
#include "Pracownik.h"

#ifndef MARKETER_H
#define MARKETER_H

class Marketer : public Pracownik
{
public:
    Marketer(int spec, string imie) : spec(spec), Pracownik(imie)
    { };

    virtual void drukuj_osobe();
    virtual int getWynagrodzenie();
   int get_popyt();

protected:
    int spec;
    int stala = 10; // wzrost popytu (ilosci sprzedanych produktow w miesiacu) o 10
    int wynagrodzenie = 7; //wynagrodzenie Marketera
    string imie;
};

#endif //!MARKETER_H