#pragma once
#include <iostream>
#include <istream>
#include <math.h>
#include <vector>
#include <string>
#include <random>
#include <time.h>
#include "Inzynier.h"

 void Inzynier::drukuj_osobe()
    {
        cout << "Pracownik na stanowisku     Inzynier,\t imie jego to " << imie;
        cout << ",\t " << gg << endl;
    }

 int Inzynier::getWynagrodzenie() {
     return wynagrodzenie;
 }

 int Inzynier::get_wzrost_ceny_produktu() 
 {
     return stala;
 }
