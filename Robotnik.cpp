#pragma once
#include <iostream>
#include <istream>
#include <math.h>
#include <vector>
#include <string>
#include <random>
#include <time.h>
#include "Robotnik.h"


void Robotnik::drukuj_osobe()
{
  cout << "Pracownik na stanowisku     Robotnik,\t imie jego to " << imie;
  cout << "\t , jego rozmiar buta to " << spec << "." << endl;
   }

int Robotnik::getWynagrodzenie() {
    return wynagrodzenie;
}

int Robotnik::get_teorWypr_produkty() {
    return stala;
}