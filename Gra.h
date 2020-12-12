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
#ifndef GRA_H
#define GRA_H

using namespace std;
class Gra
{
public:
	Gra() {
		this->granie();
	}
	
	void granie();

};

#endif //!GRA_H