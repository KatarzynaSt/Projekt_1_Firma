#pragma once
#include <iostream>
#include <istream>
#include <math.h>
#include <vector>
#include <string>
#include <random>
#include <time.h>
#include "Marketer.h"

void Marketer::drukuj_osobe()
    {
        cout << "Pracownik na stanowisku     Marketer,\t imie jego to " << imie;
        cout << "\t , na mediach spolecznosciowych obserwuje go " << spec << " osob." << endl;
    }

int Marketer::getWynagrodzenie() {
    return wynagrodzenie;
}

int Marketer::get_popyt() {
    return stala;
}