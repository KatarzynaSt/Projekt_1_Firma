#pragma once
#include <iostream>
#include <istream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <time.h>
using namespace std;

#ifndef PRACOWNIK_H
#define PRACOWNIK_H


class Pracownik 
{
public:
   Pracownik() {};
   Pracownik(string imie) : imie(std::move(imie)) {};
   virtual void drukuj_osobe();
   static int getWynagrodzenie();
   static int get_teorWypr_produkty();
   static int get_popyt();
   static int get_PojemoscMagazynu();
   static int get_wzrost_ceny_produktu();

protected:
    string imie;
};


#endif // !PRACOWNIK_H

