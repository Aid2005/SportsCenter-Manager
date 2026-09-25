#pragma once
#include <vector>
using namespace std;

//1.
char* CreateCopy(const char* text);

//2.
int CountWords(const char* text);

//3.
char* JoinText(const char* first, const char* second, char separator);

//4.
bool AreEqual(const char* t1, const char* t2);

//5.
template<typename T>
bool operator==(const vector<T>& v1, const vector<T>& v2) {
    if(v1.size() != v2.size())
        return false;
    for(size_t i = 0; i < v1.size(); i++) {
        if(v1[i] != v2[i])
            return false;
    }
    return true;
}

template<typename T>
bool operator!=(const vector<T>& v1, const vector<T>& v2) {
    return !(v1 == v2);
}

//6.
bool AreEqual(const vector<const char*>& v1, const vector<const char*>& v2);