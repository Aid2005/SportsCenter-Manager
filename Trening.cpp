#include "Trening.h"
#include "Pomocne.h"
#include <iostream>
#include <vector>
#include <stdlib>
#include <cstring>
#include <string>
using namespace std;

const char* Trening::GenerisiId(){
	
}

//Difolt konstruktor
Trening::Trening(){
	_id=GenerisiId();
	_naziv=nullptr;
	_cijena=nullptr;
	_trajanjeMinuta=0;
}

//Dekonstruktor
Trening::~Trening(){
	delete[] _id;
	delete[] _naziv;
	delete cijena;
}