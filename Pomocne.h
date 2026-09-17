#pragma once
#include<vector>
using namespace std;

//1.
char* KreirajKopiju(const char* tekst);

//2.
int PrebrojiRijeci(const char* tekst);

//3.
char* SpojiTekst(const char* prvi, const char* drugi, char separator);

//4.
bool JesuLiIsti(const char* t1, const char* t2);

//5.
template<typename T>
bool operator==(const vector<T> & v1,const vector<T> & v2){
	if(v1.size()!=v2.size())
		return false;
	for(int i=0;i<v1.size();i++){
		if(v1[i]!=v2[i])
			return false;
	}
	return true;
}

template<typename T>
bool operator!=(const vector<T> & v1,const vector<T> & v2){
	return !(v1==v2);
}

//6.
bool JesuLiIsti(const vector<const char*>& v1, const vector<const char*>& v2);