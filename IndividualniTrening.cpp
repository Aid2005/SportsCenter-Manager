#include "Pomocne.h"
#include "Trening.h"
#include "IndividualniTrening.h"
#include <iostream>
#include <cstring>
using namespace std;

//Podrazumjevani konstruktor
IndividualniTrening::IndividualniTrening():Trening(){
    _trener[0]='\0';
    _brojTermina=new int(0);
}

//Konstruktor sa parametrima
IndividualniTrening::IndividualniTrening(const char* naziv, float cijena, int trajanjeMinuta, const char* trener, int brojTermina)
:Trening(naziv,cijena,trajanjeMinuta){
    if(trener != nullptr){
        strncpy(_trener,trener,49);
        _trener[49]='\0';
    }
    else{
        _trener[0]='\0';
    }
    _brojTermina=new int(brojTermina);
}

//Kopija konstruktora
IndividualniTrening::IndividualniTrening(const IndividualniTrening& other):Trening(other){
    strncpy(_trener,other._trener,49);
    _trener[49]='\0';
    _brojTermina = (other._brojTermina != nullptr) ? new int(*other._brojTermina) : new int(0);
}

//Virtualni destruktor
IndividualniTrening::~IndividualniTrening(){
    delete _brojTermina;
}

//Operator=
IndividualniTrening& IndividualniTrening::operator=(const IndividualniTrening& other) {
    if(this != &other){
        Trening::operator=(other);
        strncpy(_trener,other._trener,49);
        _trener[49]='\0';
        if(_brojTermina == nullptr){
            _brojTermina=new int(0);
        }
        *_brojTermina = (other._brojTermina != nullptr) ? *other._brojTermina : 0;
    }
    return *this;
}

//Seteri
void IndividualniTrening::SetTrener(const char* trener){
    if(trener != nullptr){
        strncpy(_trener,trener,49);
        _trener[49]='\0';
    }
    else{
        _trener[0]='\0';
    }
}

void IndividualniTrening::SetBrojTermina(int brojTermina){
    if(_brojTermina == nullptr){
        _brojTermina=new int(brojTermina);
    }
    else{
        *_brojTermina=brojTermina;
    }
}

//Operatori
IndividualniTrening& IndividualniTrening::operator++(){
    if(_brojTermina != nullptr){
        (*_brojTermina)++;
    }
    return *this;
}

bool IndividualniTrening::operator!() const{
    return GetBrojTermina() >= 10;
}

//Metode
void IndividualniTrening::Ispis() const{
    Trening::Ispis();
    cout << "Trener: " << _trener << endl;
    cout << "Broj Termina: " << GetBrojTermina() << endl;
}

Trening* IndividualniTrening::Clone() const{
    return new IndividualniTrening(*this);
}

//Operatori
bool IndividualniTrening::operator==(const IndividualniTrening& other) const {
    if (!Trening::operator==(other)) return false;
    if (strcmp(_trener, other._trener) != 0) return false;
    if (GetBrojTermina() != other.GetBrojTermina()) return false;
    return true;
}

bool IndividualniTrening::operator!=(const IndividualniTrening& other) const {
    return !(*this == other);
}