#include <iostream>
#include <istream>
#include <math.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <time.h>
#include "Pracownik.h"
#include <list>
#include "Kredyt.h"
#pragma once
#ifndef FIRMA_H
#define FIRMA_H

class Firma
{
public:
	Firma()
	{
		this->zatrudnij_inzyniera();
		this->zatrudnij_magazyniera();    
		this->zatrudnij_marketera();   
		this->zatrudnij_robotnika();  
	};

	void zatrudnij_marketera();
	void zatrudnij_robotnika();
	void zatrudnij_inzyniera();
	void zatrudnij_magazyniera();

	void wez_kredyt();

	double getWartosc_spolki();

	void wypisz_pracownikow();
	double getSumaRat();
	double getPrzychod();
	void koniec_miesiaca();

	double get_numer_tury();

protected:
	std::vector <Kredyt> lista_kredytow;
	std::list <double> historia_przychodow;
	std::vector <std::unique_ptr <Pracownik>> lista_pracownikow;

	double suma_rat;
	double przychod;
	double wartosc_spolki = 100;
	int okres = 12; //ilosc miesiecy, na pdstawie ktorych liczymy wartosc spolki
	int numer_tury = 0;
};

#endif // !FIRMA_H
