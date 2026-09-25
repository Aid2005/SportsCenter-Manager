#include "Helpers.h"
#include "SportsCenter.h"
#include <cstring>
using namespace std;

// Default constructor
SportsCenter::SportsCenter() {
    _name = nullptr;
    _email[0] = '\0';
    _currentCount = 0;
    for (int i = 0; i < 100; i++) _trainings[i] = nullptr;
}

// Parameterized constructor
SportsCenter::SportsCenter(const char* name, const char* email) {
    _name = CreateCopy(name);
    if (email != nullptr) {
        strncpy(_email, email, 99);
        _email[99] = '\0';
    }
    else {
        _email[0] = '\0';
    }
    _currentCount = 0;
    for (int i = 0; i < 100; i++) _trainings[i] = nullptr;
}

// Copy constructor
SportsCenter::SportsCenter(const SportsCenter& other) {
    _name = CreateCopy(other._name);
    strncpy(_email, other._email, 99);
    _email[99] = '\0';
    _currentCount = other._currentCount;
    for (int i = 0; i < 100; i++) {
        if (i < _currentCount && other._trainings[i] != nullptr) {
            _trainings[i] = other._trainings[i]->Clone();
        } else {
            _trainings[i] = nullptr;
        }
    }
}

// Destructor
SportsCenter::~SportsCenter() {
    delete[] _name;
    for (int i = 0; i < _currentCount; i++) {
        delete _trainings[i];
    }
}

// Assignment operator
SportsCenter& SportsCenter::operator=(const SportsCenter& other) {
    if (this != &other) {
        delete[] _name;
        for (int i = 0; i < 100; i++) {
            delete _trainings[i];
            _trainings[i] = nullptr;
        }
        _name = CreateCopy(other._name);
        strncpy(_email, other._email, 99);
        _email[99] = '\0';
        _currentCount = other._currentCount;

        for (int i = 0; i < 100; i++) {
            if (i < _currentCount && other._trainings[i] != nullptr) {
                _trainings[i] = other._trainings[i]->Clone();
            } else {
                _trainings[i] = nullptr;
            }
        }
    }
    return *this;
}

// Setters
void SportsCenter::SetName(const char* name) {
    delete[] _name;
    _name = CreateCopy(name);
}

void SportsCenter::SetEmail(const char* email) {
    if (email != nullptr) {
        strncpy(_email, email, 99);
        _email[99] = '\0';
    }
    else {
        _email[0] = '\0';
    }
}

// Methods
int SportsCenter::Count(function<bool(const Training&)> condition) const {
    if (!condition) return 0;
    int count = 0;
    for (int i = 0; i < _currentCount; i++) {
        if (_trainings[i] != nullptr && condition(*_trainings[i])) {
            count++;
        }
    }
    return count;
}

Training* SportsCenter::FindMostExpensive() const {
    if (_currentCount == 0) return nullptr;

    Training* mostExpensive = _trainings[0];
    for (int i = 1; i < _currentCount; i++) {
        if (_trainings[i] != nullptr && _trainings[i]->GetPrice() > mostExpensive->GetPrice()) {
            mostExpensive = _trainings[i];
        }
    }
    return mostExpensive;
}

ostream& operator<<(ostream& os, const SportsCenter& sc) {
    os << "Center: " << (sc._name ? sc._name : "N/A") << " (" << sc._email << ")" << endl;
    os << "Trainings:" << endl;
    for (int i = 0; i < sc._currentCount; i++) {
        if (sc._trainings[i] != nullptr) {
            sc._trainings[i]->Print();
            os << "--------------------" << endl;
        }
    }
    return os;
}

// Comparison operators
bool SportsCenter::operator==(const SportsCenter& other) const {
    if (!AreEqual(_name, other._name)) return false;
    if (strcmp(_email, other._email) != 0) return false;
    if (_currentCount != other._currentCount) return false;

    for (int i = 0; i < _currentCount; i++) {
        if (*_trainings[i] != *other._trainings[i]) return false;
    }
    return true;
}

bool SportsCenter::operator!=(const SportsCenter& other) const {
    return !(*this == other);
}