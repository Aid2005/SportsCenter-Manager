#include "Pomocne.h"
#include "Trening.h"
#include "GrupniTrening.h"
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

//Difoltni konstruktor
GrupniTrening::GrupniTrening():Trening(){
    _tip[0]='\0';
    _maxUcesnika=0;
}

//Konstruktor sa parametrima
GrupniTrening::GrupniTrening(const char* naziv, float cijena, int trajanjeMinuta,const char* tip, int maxUcesnika):Trening(naziv, cijena, trajanjeMinuta){
    if(tip != nullptr){
        strncpy(_tip,tip,29);
        _tip[29]='\0';
    }
    else{
        _tip[0]='\0';
    }
    _maxUcesnika=maxUcesnika;
}

//Kopija konstruktora
GrupniTrening::GrupniTrening(const GrupniTrening& other):Trening(other){
    strncpy(_tip,other._tip,29);
    _tip[29]='\0';
    _maxUcesnika=other._maxUcesnika;
    for(const char* u : other._ucesnici){
        _ucesnici.push_back(KreirajKopiju(u));
    }
}

//Dekonstruktor
GrupniTrening::~GrupniTrening(){
    for(const char* u : _ucesnici){
        delete[] u;
    }
    _ucesnici.clear();
}

//Operator
GrupniTrening& GrupniTrening::operator=(const GrupniTrening& other){
    if(this != &other){
        Trening::operator=(other);
        strncpy(_tip,other._tip,29);
        _tip[29]='\0';
        _maxUcesnika=other._maxUcesnika;
        
        for(const char* u : _ucesnici){
            delete[] u;
        }
        _ucesnici.clear();
        for(const char* u : other._ucesnici){
            _ucesnici.push_back(KreirajKopiju(u));
        }
    }
    return *this;
}

//Seteri
void GrupniTrening::SetTip(const char* tip){
    if(tip != nullptr){
        strncpy(_tip,tip,29);
        _tip[29]='\0';
    }
    else{
        _tip[0]='\0';
    }
}
void GrupniTrening::SetMaxUcesnika(int maxUcesnika){
    _maxUcesnika=maxUcesnika;
}
void GrupniTrening::SetUcesnici(const vector<const char*>& ucesnici){
    for(const char* u : _ucesnici){
        delete[] u;
    }
    _ucesnici.clear();
    for(const char* u : ucesnici){
        _ucesnici.push_back(KreirajKopiju(u));
    }
}

//Operatori
bool GrupniTrening::operator+=(const char* ucesnik) {
    if (ucesnik == nullptr) return false;
    if ((int)_ucesnici.size() >= _maxUcesnika) return false;

    for (const char* u : _ucesnici) {
        if (JesuLiIsti(u, ucesnik)) return false;
    }

    _ucesnici.push_back(KreirajKopiju(ucesnik));
    return true;
}

bool GrupniTrening::operator!() const {
    return (int)_ucesnici.size() >= _maxUcesnika;
}

//Metode
void GrupniTrening::Ispis() const{
    Trening::Ispis();
    cout << "Tip: " << _tip << endl;
    cout << "Maximalni broj ucesnika: " << _maxUcesnika << endl;
    cout << "Ucesnici: ";
    for(const char* u : _ucesnici){
        if(u) cout << u <<", " ;
    }
    cout << endl;
}
Trening* GrupniTrening::Clone() const{
    return new GrupniTrening(*this);
}

//Operatori
bool GrupniTrening::operator==(const GrupniTrening& other) const {
    if (!Trening::operator==(other)) return false;
    if (strcmp(_tip, other._tip) != 0) return false;
    if (_maxUcesnika != other._maxUcesnika) return false;
    if (!JesuLiIsti(_ucesnici, other._ucesnici)) return false;
    return true;
}
bool GrupniTrening::operator!=(const GrupniTrening& other) const {
    return !(*this == other);
}