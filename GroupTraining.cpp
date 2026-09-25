#include "Helpers.h"
#include "Training.h"
#include "GroupTraining.h"
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

// Default constructor
GroupTraining::GroupTraining() : Training() {
    _type[0] = '\0';
    _maxParticipants = 0;
}

// Parameterized constructor
GroupTraining::GroupTraining(const char* name, float price, int durationMinutes, const char* type, int maxParticipants)
    : Training(name, price, durationMinutes) {
    if (type != nullptr) {
        strncpy(_type, type, 29);
        _type[29] = '\0';
    }
    else {
        _type[0] = '\0';
    }
    _maxParticipants = maxParticipants;
}

// Copy constructor
GroupTraining::GroupTraining(const GroupTraining& other) : Training(other) {
    strncpy(_type, other._type, 29);
    _type[29] = '\0';
    _maxParticipants = other._maxParticipants;
    for (const char* p : other._participants) {
        _participants.push_back(CreateCopy(p));
    }
}

// Destructor
GroupTraining::~GroupTraining() {
    for (const char* p : _participants) {
        delete[] p;
    }
    _participants.clear();
}

// Assignment operator
GroupTraining& GroupTraining::operator=(const GroupTraining& other) {
    if (this != &other) {
        Training::operator=(other);
        strncpy(_type, other._type, 29);
        _type[29] = '\0';
        _maxParticipants = other._maxParticipants;
        
        for (const char* p : _participants) {
            delete[] p;
        }
        _participants.clear();
        for (const char* p : other._participants) {
            _participants.push_back(CreateCopy(p));
        }
    }
    return *this;
}

// Setters
void GroupTraining::SetType(const char* type) {
    if (type != nullptr) {
        strncpy(_type, type, 29);
        _type[29] = '\0';
    }
    else {
        _type[0] = '\0';
    }
}

void GroupTraining::SetMaxParticipants(int maxParticipants) {
    _maxParticipants = maxParticipants;
}

void GroupTraining::SetParticipants(const vector<const char*>& participants) {
    for (const char* p : _participants) {
        delete[] p;
    }
    _participants.clear();
    for (const char* p : participants) {
        _participants.push_back(CreateCopy(p));
    }
}

// Operators
bool GroupTraining::operator+=(const char* participant) {
    if (participant == nullptr) return false;
    if ((int)_participants.size() >= _maxParticipants) return false;

    for (const char* p : _participants) {
        if (AreEqual(p, participant)) return false;
    }

    _participants.push_back(CreateCopy(participant));
    return true;
}

bool GroupTraining::operator!() const {
    return (int)_participants.size() >= _maxParticipants;
}

// Methods
void GroupTraining::Print() const {
    Training::Print();
    cout << "Type: " << _type << endl;
    cout << "Maximum number of participants: " << _maxParticipants << endl;
    cout << "Participants: ";
    for (const char* p : _participants) {
        if (p) cout << p << ", ";
    }
    cout << endl;
}

Training* GroupTraining::Clone() const {
    return new GroupTraining(*this);
}

// Comparison operators
bool GroupTraining::operator==(const GroupTraining& other) const {
    if (!Training::operator==(other)) return false;
    if (strcmp(_type, other._type) != 0) return false;
    if (_maxParticipants != other._maxParticipants) return false;
    if (!AreEqual(_participants, other._participants)) return false;
    return true;
}

bool GroupTraining::operator!=(const GroupTraining& other) const {
    return !(*this == other);
}