#pragma once;
#include "Trening.h"
#include <functional>
#include <iostream>
using namespace std;

class SportskiCentar{
	private:
		char* _naziv;
    	char _email[100];
    	int _trenutno;
    	Trening* _treninzi[100];
		
	public:
		//Konstruktori i dekonstruktori
		SportskiCentar();
		SportskiCentar(const char* naziv, const char* email);
		SportskiCentar(const SportskiCentar& other);
		~SportskiCentar();
		
		//Operator
		SportskiCentar& operator=(const SportskiCentar& other);
		
		//Geteri
		const char* GetNaziv() const {return _naziv;}
		const char* GetEmail() const {return _email;}
		int GetTrenutno() const {return _trenutno;}
		Trening* GetElementAt(int index) const {
			if (index >= 0 && index < _trenutno) return _treninzi[index];
        	return nullptr;
		} 
		
		//Seteri
		void SetNaziv(const char* naziv);
		void SetEmail(const char* email);
		
		//Templejt
		template<class T>
		bool DodajTrening(const T& trening){
			if(_trenutno >= 100) return false;
			_treninzi[_trenutno++]=new T(trening);
			return true;
		}
		
		//Metode
		int Prebroj(function<bool(const Trening&)> uslov) const;
		Trening* PronadjiNajskuplji() const;
		friend ostream& operator<<(ostream& os, const SportskiCentar& sc);

		//Operatori
    	bool operator==(const SportskiCentar& other) const;
    	bool operator!=(const SportskiCentar& other) const;
};