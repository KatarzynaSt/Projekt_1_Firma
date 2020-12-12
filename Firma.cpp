#include <iostream>
#include <istream>
#include <math.h>
#include "RandomNameGenerator.hpp"
#include <vector>
#include <string>
#include <cstdlib>
#include <iterator>
#include <list>
#include <ctime>
#include <iomanip>
#include <random>
#include <time.h>
#include "Firma.h"
#include "Pracownik.h"
#include "Inzynier.h"
#include "Magazynier.h"
#include "Marketer.h"
#include "Robotnik.h"
#include "Kredyt.h"

void Firma::zatrudnij_marketera() 
{
	lista_pracownikow.emplace_back(std::make_unique<Marketer>(rand() % 90 + 11, get_random_name()));
}

void Firma::zatrudnij_robotnika()
{
	lista_pracownikow.emplace_back(std::make_unique<Robotnik>(rand() % 9 + 36, get_random_name()));
}

void Firma::zatrudnij_inzyniera()
{
	lista_pracownikow.emplace_back(std::make_unique<Inzynier>(rand() % 3 + 1, get_random_name()));
}

void Firma::zatrudnij_magazyniera()
{
	lista_pracownikow.emplace_back(std::make_unique<Magazynier>(rand() % 3 + 1, get_random_name()));
	}

void Firma::wez_kredyt()
{
	int miesiace;
	double suma_kredytu;
	cout << "Na jaka kwote chcesz wziac kredyt?" << endl;
	cin >> suma_kredytu;
	while (cin.bad())
		{
		cout << "Musi byc liczba!!" << endl;
		cin.clear();
		cin >> suma_kredytu;
		}
	cout << "W ilu ratach (ilosc miesiecy) chcesz splacic kredyt?" << endl;
	cin >> miesiace;
	while (cin.bad())
		{
		cout << "Musi byc liczba calkowita!!" << endl;
		cin.clear();
		cin >> miesiace;
		}

	lista_kredytow.emplace_back(suma_kredytu, miesiace);
}

void Firma::wypisz_pracownikow()
{
	cout << "Twoja firma zatrudnia "<<lista_pracownikow.size()<<" pracownikow." << endl;
	int i;
	for (i = 0; i < lista_pracownikow.size(); i++)
	{
		lista_pracownikow[i]->drukuj_osobe();
	}
}

void Firma::koniec_miesiaca()
{
	numer_tury++;
	double cena_produktu = 0;
	double popyt = 0;
	double pojemnosc_magazynu = 0;
	double teor_wyprodukowane_produkty = 0;
	double wynagrodzenie_laczne = 0;
	for (int i=0; i< lista_pracownikow.size();i++) 
	{
	cena_produktu = cena_produktu + Pracownik::get_wzrost_ceny_produktu();
	popyt = popyt + Pracownik::get_popyt();
	pojemnosc_magazynu = pojemnosc_magazynu + Pracownik::get_PojemoscMagazynu();
	teor_wyprodukowane_produkty = teor_wyprodukowane_produkty + Pracownik::get_teorWypr_produkty();
	wynagrodzenie_laczne = wynagrodzenie_laczne + Pracownik::getWynagrodzenie();
	}

	double faktycznie_wyprod=0;
	if (pojemnosc_magazynu<teor_wyprodukowane_produkty)
		{
			faktycznie_wyprod =pojemnosc_magazynu;
		}
	else { 
		faktycznie_wyprod =teor_wyprodukowane_produkty; 
		 }

	double liczba_sprzed_prod;
	if (popyt > faktycznie_wyprod)
		{
			liczba_sprzed_prod = faktycznie_wyprod;
		}
	else { liczba_sprzed_prod = popyt; }

	double przychod = liczba_sprzed_prod * cena_produktu;

	historia_przychodow.push_front(przychod);
	if (numer_tury > (okres-1)) // sprawdzic dzialanie podczas samego programu juz
	{	double suma_przychodow_w_ostanim_roku=0;

	list< double >::iterator it = historia_przychodow.begin();
	
	for (it = historia_przychodow.begin(); it != historia_przychodow.end(); it++) 
		{
		suma_przychodow_w_ostanim_roku = suma_przychodow_w_ostanim_roku + *it;
			wartosc_spolki = (suma_przychodow_w_ostanim_roku / okres);
		}
	}

	double zysk = przychod - wynagrodzenie_laczne;

	suma_rat = 0;
	for (auto it = lista_kredytow.begin(); it != lista_kredytow.end();) {
		double rata;
		it->splac_rate();
		rata = it->getRata();
		if (it->splacony())
		{
		it=lista_kredytow.erase(it);
		}
		else { it++; }
		suma_rat = suma_rat + rata;
	}
	double czysty_zysk=zysk-suma_rat;

	cout << "Zakonczony miesiac " << get_numer_tury() << "." << endl;
	cout << " W tym miesiacu czysty zysk wyniosl " << fixed << setprecision(2) << czysty_zysk<< " zl."<< endl ;
	cout << " Obecna cena produktu to " << cena_produktu << "zl, pojemnosc magazynu - " << pojemnosc_magazynu << ", \n liczba produkowanych produktow - " << teor_wyprodukowane_produkty<< ", a ilosc mozliwych do sprzedania produktow - " << popyt<<"."<<endl;
	cout << " W tym miesiacu suma wyplacanych wynagrodzen dla "<< lista_pracownikow.size() <<" pracownikow wyniosla " << wynagrodzenie_laczne << "zl." << endl;
	cout << " W tym miesiacu suma rat splacanych kredytow wyniosla " <<fixed<<setprecision(2)<< suma_rat << "zl." << endl;
	if (numer_tury>okres)
	{
		cout << "Calkowita wartosc firmy wynosi "<<fixed<<setprecision(2) << wartosc_spolki << " zl." << endl;
	}
	
}

double Firma::getPrzychod()
{
	return przychod;
}

double Firma::get_numer_tury()
{
	return numer_tury;
}

double Firma::getWartosc_spolki()
{
	return wartosc_spolki;
}

double Firma::getSumaRat()
{
	return suma_rat;
}
