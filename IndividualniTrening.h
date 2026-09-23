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
		IndividualniTrening(const IndividualniTrening& other);
		virtual ~IndividualniTrening();
		
		//Operator 
		IndividualniTrening& operator=(const IndividualniTrening& other);
		
		//Geteri
		const char* GetTrener() const {return _trener;}
		int GetBrojTermina() const {return (_brojTermina != nullptr) ? *_brojTermina : 0;}
		
		//Seteri
		void SetTrener(const char* trener);
		void SetBrojTermina(int brojTermina);
		
		//Operatori
		IndividualniTrening& operator++();
		bool operator!() const;
		
		//Metode
		virtual void Ispis() const override;
		virtual Trening* Clone() const override;
		
		//Operatori
		bool operator == (const IndividualniTrening& other) const;
		bool operator != (const IndividualniTrening& other) const;
};