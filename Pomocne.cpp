#include "Pomocne.h"
#include <cstring>
using namespace std;

//1.
char* KreirajKopiju(const char* tekst){
	if(tekst==nullptr)
		return nullptr;
		
	int duzina=strlen(tekst)+1;
	char* novi=new char[duzina];
	strcpy(novi,tekst);
	return novi;
}

//2.
int PrebrojiRijeci(const char* tekst){
	if(tekst==nullptr || strlen(tekst)==0)
		return 0;
		
	int brojac=0;
	bool uRijec=false;
	for(int i=0;i<strlen(tekst);i++){
		if(tekst[i]!=' '){
			if(!uRijec){
				brojac++;
				uRijec=true;
			}
		}
		else{
			uRijec=false;
		}
	}
	return brojac;
}

//3.
char* SpojiTekst(const char* prvi, const char* drugi, char separator){
	const char* p=(prvi != nullptr) ? prvi : "";
	const char* d=(drugi != nullptr) ? drugi : "";
	
	int duzina=strlen(p)+strlen(d)+2;
	char* rezultat=new char[duzina];
	
	strcpy(rezultat,p);
	int pozicija=strlen(p);
	rezultat[pozicija]=separator;
	strcpy(rezultat+pozicija+1,d);
	return rezultat;
}

//4.
bool JesuLiIsti(const char* t1, const char* t2){
	if(t1==nullptr && t2==nullptr) return true;
	if(t1==nullptr || t2==nullptr) return false;
	
	return strcmp(t1,t2)==0;
}

//6.
bool JesuLiIsti(const vector<const char*>& v1, const vector<const char*>& v2){
	if(v1.size() != v2.size())
		return false;
		
	for(int i=0;i<v1.size();i++){
		if(!JesuLiIsti(v1[i],v2[i]))
			return false;
	}
	return true;
}