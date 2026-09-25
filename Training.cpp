#include "Training.h"
#include "Helpers.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

// Method for generating ID
const char* Training::GenerateId() {
    static int counter = 1;
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "T-%05d", counter++); 
    return CreateCopy(buffer);
}

// Default constructor
Training::Training() {
    _id = GenerateId();
    _name = nullptr;
    _price = nullptr;
    _durationMinutes = 0;
}

// Parameterized constructor
Training::Training(const char* name, float price, int durationMinutes) {
    _id = GenerateId();
    _name = CreateCopy(name);
    _price = new float(price);
    _durationMinutes = durationMinutes;
}

// Copy constructor (Deep copy)
Training::Training(const Training& other) {
    _id = CreateCopy(other._id);
    _name = CreateCopy(other._name);
    _price = (other._price != nullptr) ? new float(*other._price) : nullptr; 
    _durationMinutes = other._durationMinutes;
    _ratings = other._ratings;
}

// Destructor
Training::~Training() {
    delete[] _id;
    delete[] _name;
    delete _price; 
}

// Assignment operator
Training& Training::operator=(const Training& other) {
    if (this != &other) {
        delete[] _name;
        delete _price;

        _name = CreateCopy(other._name);
        _price = (other._price != nullptr) ? new float(*other._price) : nullptr;
        _durationMinutes = other._durationMinutes;
        _ratings = other._ratings;
    }
    return *this;
}

// Setters
void Training::SetName(const char* name) {
    delete[] _name;
    _name = CreateCopy(name);
}

void Training::SetPrice(float price) {
    if (_price == nullptr)
        _price = new float(price);
    else
        *_price = price;
}

void Training::SetDurationMinutes(int durationMinutes) {
    _durationMinutes = durationMinutes;
}

// Method for adding a rating
void Training::AddRating(int rating) {
    if (rating >= 1 && rating <= 5)
        _ratings.push_back(rating);
}

// Calculate method
float Training::Calculate(function<float(const vector<int>&)> func) const {
    if (!func) return 0.0f;
    return func(_ratings);
}

// Operator ! 
bool Training::operator!() const {
    return _durationMinutes > 60;
}

// Print method 
void Training::Print() const {
    cout << "ID: " << (_id ? _id : "N/A") << endl;
    cout << "Name: " << (_name ? _name : "N/A") << endl;
    cout << "Price: " << GetPrice() << " KM" << endl;
    cout << "Duration: " << _durationMinutes << " min" << endl;
    cout << "Ratings: ";
    for (int r : _ratings) {
        cout << r << " ";
    }
    cout << endl;
}

// Clone method
Training* Training::Clone() const {
    return new Training(*this);
}

// Operator == 
bool Training::operator==(const Training& other) const {
    if (!AreEqual(_name, other._name)) return false;
    if (GetPrice() != other.GetPrice()) return false;
    if (_durationMinutes != other._durationMinutes) return false;
    if (_ratings != other._ratings) return false;
    return true;
}

// Operator !=
bool Training::operator!=(const Training& other) const {
    return !(*this == other);
}