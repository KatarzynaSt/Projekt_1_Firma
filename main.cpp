#pragma once
#include <iostream>
#include <istream>
#include <math.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <time.h>
#include "Gra.h"

using namespace std;
int main()
{
    cout << " Oto moja gra, milej zabawy! :) \n";

    cout << " W grze mozesz (podane odpowiednie komendy): \n - zatrudnic: inzyniera - zatrInz,\n\t      magazyniera - zatrMag, \n\t      marketera - zatrMark, \n \t      robotnika - zatrRob, \n";
    cout << " - wyswietlic liste pracownikow wraz z ich umiejetnosciami - listPrac,\n - wziac kredyt - bioreKredyt.\n\n";
    cout << " W grze mozesz rowniez zakonczyc miesiac - koniecMies. Wtedy oplaczasz odsetki, placisz wynagrodzenia pracownikom \n i przede wszystkim sprzedajesz towar. Niesprzedany towar w danym miesiacu marnuje sie." <<endl;

    cout << "\n Rozpoczynasz gre! Wpisuj komendy i powodzenia!\n";
    cout << " Musisz osiagnac kapital 1000zl, aby wygrac.\n Twoj kapital poczatkowy to 100zl." << endl;
    cout << " Twoja firma zatrudnia po jednym z pracownikow kazdego zawodu." << endl;
    cout << "\n Wpisz ""START"" aby rozpoczac!\n ";
    string y;
    cin >> y;
    Gra T;
    T.granie();

    cout << "\nKoniec main \n";

    system("pause > 0");
}
