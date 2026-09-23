#include <iostream>
#include <vector>
#include <functional>
#include <ctime>

#include "Pomocne.h"
#include "Trening.h"
#include "IndividualniTrening.h"
#include "GrupniTrening.h"
#include "SportskiCentar.h"

using namespace std;

/*
    NTP - INTEGRALNI ISPIT
    Funkcije nije dozvoljeno mijenjati
*/

void TestPomocne()
{
    cout << "\n===== POMOCNE FUNKCIJE =====\n";

    char* kopija = KreirajKopiju("Napredne tehnike programiranja");
    cout << "Kopija: " << (kopija ? kopija : "nullptr") << endl;
    delete[] kopija;

    cout << "Broj rijeci: "
         << PrebrojiRijeci("  C++   programiranje i OOP  ")
         << endl;

    char* spojeno = SpojiTekst("FIT", "ZENICA", '-');
    cout << "Spojeno: " << (spojeno ? spojeno : "nullptr") << endl;
    delete[] spojeno;

    cout << "Jednaki stringovi: " << JesuLiIsti("NTP", "NTP") << endl;

    vector<int> v1{ 1, 2, 3 };
    vector<int> v2{ 1, 2, 3 };
    cout << "Jednaki vektori: " << (v1 == v2) << endl;

    vector<const char*> s1{ "C++", "OOP" };
    vector<const char*> s2{ "C++", "OOP" };
    cout << "Jednaki tekstualni vektori: " << JesuLiIsti(s1, s2) << endl;
}

void TestTrening()
{
    cout << "\n===== TRENING =====\n";

    Trening t1("Kondicioni trening", 25.0f, 75);
    t1.DodajOcjenu(5);
    t1.DodajOcjenu(4);
    t1.DodajOcjenu(5);
    t1.DodajOcjenu(8);

    t1.Ispis();

    float prosjek = t1.Izracunaj(
        [](const vector<int>& ocjene) -> float {
            if (ocjene.empty()) return 0.0f;
            float suma = 0;
            for (int x : ocjene) suma += x;
            return suma / ocjene.size();
        }
    );

    cout << "Prosjek: " << prosjek << endl;
    cout << "Dug trening: " << (!t1 ? "DA" : "NE") << endl;

    Trening t2(t1);
    cout << "Copy ctor jednak: " << (t1 == t2) << endl;

    Trening t3;
    t3 = t1;
    cout << "Operator= jednak: " << (t1 == t3) << endl;
}

void TestIndividualni()
{
    cout << "\n===== INDIVIDUALNI TRENING =====\n";

    IndividualniTrening i1("Individualni fitness", 45.0f, 60, "Amar Trener", 9);

    cout << "Prije ++: " << i1.GetBrojTermina() << endl;
    ++i1;
    cout << "Poslije ++: " << i1.GetBrojTermina() << endl;
    cout << "10 ili vise termina: " << (!i1 ? "DA" : "NE") << endl;

    IndividualniTrening i2(i1);
    cout << "Copy ctor jednak: " << (i1 == i2) << endl;

    IndividualniTrening i3;
    i3 = i1;
    cout << "Operator= jednak: " << (i1 == i3) << endl;

    i1.Ispis();
}
/*
void TestGrupni()
{
    cout << "\n===== GRUPNI TRENING =====\n";

    GrupniTrening g1("HIIT grupa", 15.0f, 50, "HIIT", 3);

    cout << "Dodavanje Ena: " << (g1 += "Ena") << endl;
    cout << "Dodavanje Amar: " << (g1 += "Amar") << endl;
    cout << "Ponovno Ena: " << (g1 += "Ena") << endl;
    cout << "Dodavanje Lejla: " << (g1 += "Lejla") << endl;
    cout << "Dodavanje nakon popunjavanja: " << (g1 += "Tarik") << endl;

    cout << "Popunjen trening: " << (!g1 ? "DA" : "NE") << endl;

    GrupniTrening g2(g1);
    cout << "Copy ctor jednak: " << (g1 == g2) << endl;

    if (!g1.GetUcesnici().empty() && !g2.GetUcesnici().empty()) {
        cout << "Deep copy ucesnika: "
             << (g1.GetUcesnici()[0] != g2.GetUcesnici()[0])
             << endl;
    }

    GrupniTrening g3;
    g3 = g1;
    cout << "Operator= jednak: " << (g1 == g3) << endl;

    g1.Ispis();
}

void TestSportskiCentar()
{
    cout << "\n===== SPORTSKI CENTAR =====\n";

    Trening t("Kondicioni trening", 25.0f, 75);
    IndividualniTrening i("Personalni trening", 50.0f, 60, "Coach A", 12);
    GrupniTrening g("Pilates", 18.0f, 55, "Pilates", 2);

    g += "Ena";
    g += "Lejla";

    SportskiCentar centar("Arena Fitness", "info@arena.ba");

    cout << "Dodaj bazni: " << centar.DodajTrening(t) << endl;
    cout << "Dodaj individualni: " << centar.DodajTrening(i) << endl;
    cout << "Dodaj grupni: " << centar.DodajTrening(g) << endl;

    cout << "\nCentar:\n" << centar << endl;

    int skupljiOd20 = centar.Prebroji(
        [](const Trening& trening) {
            return trening.GetCijena() > 20.0f;
        }
    );

    cout << "Broj treninga skupljih od 20 KM: " << skupljiOd20 << endl;

    Trening* najskuplji = centar.PronadjiNajskuplji();
    if (najskuplji != nullptr) {
        cout << "Najskuplji trening: "
             << najskuplji->GetNaziv()
             << " (" << najskuplji->GetCijena() << " KM)"
             << endl;
    }

    SportskiCentar kopija(centar);
    cout << "Copy ctor centra - broj elemenata: " << kopija.GetTrenutno() << endl;

    if (centar.GetTrenutno() > 0 && kopija.GetTrenutno() > 0) {
        cout << "Deep copy prvog elementa: "
             << (centar.GetElementAt(0) != kopija.GetElementAt(0))
             << endl;
    }

    SportskiCentar dodjela;
    dodjela = centar;
    cout << "Operator= centra - broj elemenata: " << dodjela.GetTrenutno() << endl;
}
*/
int main()
{
    srand((unsigned)time(nullptr));
	
	// Za testiranje odkomentarisati odgovarajucu metodu
    
	TestPomocne();
    TestTrening();
    TestIndividualni();
    //TestGrupni();
    //TestSportskiCentar();

    return 0;
}