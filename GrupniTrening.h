#pragma once
#include "Trening.h"
#include <vector>
using namespace std;

class GrupniTrening : public Trening {
    private:
        char _tip[30];
        int _maxUcesnika;
        vector<const char*> _ucesnici;
        
    public:
        //Konstruktori i dekonstruktori
        GrupniTrening();
        GrupniTrening(const char* naziv, float cijena, int trajanjeMinuta, const char* tip, int maxUcesnika);
        GrupniTrening(const GrupniTrening& other);
        virtual ~GrupniTrening();
        
        //Operator dodjele (nedostajao u deklaraciji)
        GrupniTrening& operator=(const GrupniTrening& other);
        
        //Geteri
        const char* GetTip() const {return _tip;}
        int GetMaxUcesnika() const {return _maxUcesnika;}
        const vector<const char*>& GetUcesnici() const {return _ucesnici;}
        
        //Seteri
        void SetTip(const char* tip);
        void SetMaxUcesnika(int maxUcesnika);
        void SetUcesnici(const vector<const char*>& ucesnici);
        
        //Operatori
        bool operator+=(const char* ucesnik);
        bool operator!() const; 
        
        //Metode
        virtual void Ispis() const override;
        virtual Trening* Clone() const override;
        
        //Operatori
        bool operator==(const GrupniTrening& other) const;
        bool operator!=(const GrupniTrening& other) const;
};