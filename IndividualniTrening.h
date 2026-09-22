#pragma once
#include "Trening.h"
using namespace std;

class IndividualniTrening : public Trening{
	private:
		char _trener[50];
		int* _brojTermina;
	public:
		
		//Konstruktori i dekonstruktori
		IndividualniTrening();
		IndividualniTrening(const char* naziv, float cijena, int trajanjeMinuta,const char* trener, int brojTermina);
		IndividualniTrening(const IndvidualniTrening& other);
		virtual ~IndividualniTrening();
		
		
};