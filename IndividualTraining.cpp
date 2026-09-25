#include "Helpers.h"
#include "Training.h"
#include "IndividualTraining.h"
#include <iostream>
#include <cstring>
using namespace std;

// Default constructor
IndividualTraining::IndividualTraining() : Training() {
    _trainer[0] = '\0';
    _sessionCount = new int(0);
}

// Parameterized constructor
IndividualTraining::IndividualTraining(const char* name, float price, int durationMinutes, const char* trainer, int sessionCount)
    : Training(name, price, durationMinutes) {
    if (trainer != nullptr) {
        strncpy(_trainer, trainer, 49);
        _trainer[49] = '\0';
    }
    else {
        _trainer[0] = '\0';
    }
    _sessionCount = new int(sessionCount);
}

// Copy constructor
IndividualTraining::IndividualTraining(const IndividualTraining& other) : Training(other) {
    strncpy(_trainer, other._trainer, 49);
    _trainer[49] = '\0';
    _sessionCount = (other._sessionCount != nullptr) ? new int(*other._sessionCount) : new int(0);
}

// Virtual destructor
IndividualTraining::~IndividualTraining() {
    delete _sessionCount;
}

// Assignment operator
IndividualTraining& IndividualTraining::operator=(const IndividualTraining& other) {
    if (this != &other) {
        Training::operator=(other);
        strncpy(_trainer, other._trainer, 49);
        _trainer[49] = '\0';
        if (_sessionCount == nullptr) {
            _sessionCount = new int(0);
        }
        *_sessionCount = (other._sessionCount != nullptr) ? *other._sessionCount : 0;
    }
    return *this;
}

// Setters
void IndividualTraining::SetTrainer(const char* trainer) {
    if (trainer != nullptr) {
        strncpy(_trainer, trainer, 49);
        _trainer[49] = '\0';
    }
    else {
        _trainer[0] = '\0';
    }
}

void IndividualTraining::SetSessionCount(int sessionCount) {
    if (_sessionCount == nullptr) {
        _sessionCount = new int(sessionCount);
    }
    else {
        *_sessionCount = sessionCount;
    }
}

// Operators
IndividualTraining& IndividualTraining::operator++() {
    if (_sessionCount != nullptr) {
        (*_sessionCount)++;
    }
    return *this;
}

bool IndividualTraining::operator!() const {
    return GetSessionCount() >= 10;
}

// Methods
void IndividualTraining::Print() const {
    Training::Print();
    cout << "Trainer: " << _trainer << endl;
    cout << "Session Count: " << GetSessionCount() << endl;
}

Training* IndividualTraining::Clone() const {
    return new IndividualTraining(*this);
}

// Comparison operators
bool IndividualTraining::operator==(const IndividualTraining& other) const {
    if (!Training::operator==(other)) return false;
    if (strcmp(_trainer, other._trainer) != 0) return false;
    if (GetSessionCount() != other.GetSessionCount()) return false;
    return true;
}

bool IndividualTraining::operator!=(const IndividualTraining& other) const {
    return !(*this == other);
}