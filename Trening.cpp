#include "Trening.h"
#include "Pomocne.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

// Metoda za generisanje ID
const char* Trening::GenerisiId() {
    static int brojac = 1;
    char bafer[16];
    snprintf(bafer, sizeof(bafer), "T-%05d", brojac++); 
    return KreirajKopiju(bafer);
}

// Podrazumijevani konstruktor
Trening::Trening() {
    _id = GenerisiId();
    _naziv = nullptr;
    _cijena = nullptr;
    _trajanjeMinuta = 0;
}

// Konstruktor sa parametrima
Trening::Trening(const char* naziv, float cijena, int trajanjeMinuta) {
    _id = GenerisiId();
    _naziv = KreirajKopiju(naziv);
    _cijena = new float(cijena);
    _trajanjeMinuta = trajanjeMinuta;
}

// Kopirni konstruktor (Deep copy)
Trening::Trening(const Trening& other) {
    _id = KreirajKopiju(other._id);
    _naziv = KreirajKopiju(other._naziv);
    _cijena = (other._cijena != nullptr) ? new float(*other._cijena) : nullptr; 
    _trajanjeMinuta = other._trajanjeMinuta;
    _ocjene = other._ocjene;
}

// Destruktor
Trening::~Trening() {
    delete[] _id;
    delete[] _naziv;
    delete _cijena; 
}

// Operator dodjele
Trening& Trening::operator=(const Trening& other) {
    if (this != &other) {
        delete[] _naziv;
        delete _cijena;

        _naziv = KreirajKopiju(other._naziv);
        _cijena = (other._cijena != nullptr) ? new float(*other._cijena) : nullptr;
        _trajanjeMinuta = other._trajanjeMinuta;
        _ocjene = other._ocjene;
    }
    return *this;
}

// Seteri
void Trening::SetNaziv(const char* naziv) {
    delete[] _naziv;
    _naziv = KreirajKopiju(naziv);
}

void Trening::SetCijena(float cijena) {
    if (_cijena == nullptr)
        _cijena = new float(cijena);
    else
        *_cijena = cijena;
}

void Trening::SetTrajanjeMinuta(int trajanje) {
    _trajanjeMinuta = trajanje;
}

// Metoda za dodavanje ocjene
void Trening::DodajOcjenu(int ocjena) {
    if (ocjena >= 1 && ocjena <= 5)
        _ocjene.push_back(ocjena);
}

float Trening::Izracunaj(function<float(const vector<int>&)> funkcija) const {
    if (!funkcija) return 0.0f;
    return funkcija(_ocjene);
}

// Operator ! 
bool Trening::operator!() const {
    return _trajanjeMinuta > 60;
}

// Metoda za ispis 
void Trening::Ispis() const {
    cout << "ID: " << (_id ? _id : "N/A") << endl;
    cout << "Naziv: " << (_naziv ? _naziv : "N/A") << endl;
    cout << "Cijena: " << GetCijena() << " KM" << endl;
    cout << "Trajanje: " << _trajanjeMinuta << " min" << endl;
    cout << "Ocjene: ";
    for (int o : _ocjene) {
        cout << o << " ";
    }
    cout << endl;
}

Trening* Trening::Clone() const {
    return new Trening(*this);
}

// Operator == (Ispravljen naziv)
bool Trening::operator==(const Trening& other) const {
    if (!JesuLiIsti(_naziv, other._naziv)) return false;
    if (GetCijena() != other.GetCijena()) return false;
    if (_trajanjeMinuta != other._trajanjeMinuta) return false;
    if (_ocjene != other._ocjene) return false;
    return true;
}

// Operator !=
bool Trening::operator!=(const Trening& other) const {
    return !(*this == other);
}