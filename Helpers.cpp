#include "Helpers.h"
#include <cstring>
using namespace std;

//1.
char* CreateCopy(const char* text) {
    if(text == nullptr)
        return nullptr;
        
    int length = strlen(text) + 1;
    char* newText = new char[length];
    strcpy(newText, text);
    return newText;
}

//2.
int CountWords(const char* text) {
    if(text == nullptr || strlen(text) == 0)
        return 0;
        
    int count = 0;
    bool inWord = false;
    for(size_t i = 0; i < strlen(text); i++) {
        if(text[i] != ' ') {
            if(!inWord) {
                count++;
                inWord = true;
            }
        }
        else {
            inWord = false;
        }
    }
    return count;
}

//3.
char* JoinText(const char* first, const char* second, char separator) {
    const char* f = (first != nullptr) ? first : "";
    const char* s = (second != nullptr) ? second : "";
    
    int length = strlen(f) + strlen(s) + 2;
    char* result = new char[length];
    
    strcpy(result, f);
    int position = strlen(f);
    result[position] = separator;
    strcpy(result + position + 1, s);
    return result;
}

//4.
bool AreEqual(const char* t1, const char* t2) {
    if(t1 == nullptr && t2 == nullptr) return true;
    if(t1 == nullptr || t2 == nullptr) return false;
    
    return strcmp(t1, t2) == 0;
}

//6.
bool AreEqual(const vector<const char*>& v1, const vector<const char*>& v2) {
    if(v1.size() != v2.size())
        return false;
        
    for(size_t i = 0; i < v1.size(); i++) {
        if(!AreEqual(v1[i], v2[i]))
            return false;
    }
    return true;
}