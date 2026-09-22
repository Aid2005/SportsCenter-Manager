#pragma once
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

class Trening {
    private:
        const char* _id;
    protected:
        char* _naziv;
        float* _cijena;
        int _trajanjeMinuta;
        vector<int> _ocjene;
        
        static const char* GenerisiId();
    public:
        //Konstruktori i dekonstruktor
        Trening();
        Trening(const char* naziv, float cijena, int trajanjeMinuta);
        Trening(const Trening& other);
        virtual ~Trening();
        
        //Operator dodjele
        Trening& operator=(const Trening& other);
        
        //Geteri
        const char* GetId() const { return _id; }
        const char* GetNaziv() const { return _naziv; }
        float GetCijena() const { return (_cijena != nullptr) ? *_cijena : 0.0f; } 
        int GetTrajanjeMinuta() const { return _trajanjeMinuta; }
        const vector<int>& GetOcjene() const { return _ocjene; } 
        
        //Seteri
        void SetNaziv(const char* naziv);
        void SetCijena(float cijena); 
        void SetTrajanjeMinuta(int trajanje);
        
        //Metode
        void DodajOcjenu(int ocjena);
        float Izracunaj(function<float(const vector<int>&)> funkcija) const;
        bool operator!() const;
        
        virtual void Ispis() const;
        virtual Trening* Clone() const;
        
        //Operatori poređenja (const ide na kraj)
        bool operator==(const Trening& other) const;
        bool operator!=(const Trening& other) const;
};