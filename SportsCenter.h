#pragma once
#include "Training.h"
#include <functional>
#include <iostream>
using namespace std;

class SportsCenter {
    private:
        char* _name;
        char _email[100];
        int _currentCount;
        Training* _trainings[100];
        
    public:
        // Constructors and destructor
        SportsCenter();
        SportsCenter(const char* name, const char* email);
        SportsCenter(const SportsCenter& other);
        ~SportsCenter();
        
        // Assignment operator
        SportsCenter& operator=(const SportsCenter& other);
        
        // Getters
        const char* GetName() const { return _name; }
        const char* GetEmail() const { return _email; }
        int GetCurrentCount() const { return _currentCount; }
        Training* GetElementAt(int index) const {
            if (index >= 0 && index < _currentCount) return _trainings[index];
            return nullptr;
        } 
        
        // Setters
        void SetName(const char* name);
        void SetEmail(const char* email);
        
        // Template
        template<class T>
        bool AddTraining(const T& training) {
            if (_currentCount >= 100) return false;
            _trainings[_currentCount++] = new T(training);
            return true;
        }
        
        // Methods
        int Count(function<bool(const Training&)> condition) const;
        Training* FindMostExpensive() const;
        friend ostream& operator<<(ostream& os, const SportsCenter& sc);

        // Comparison operators
        bool operator==(const SportsCenter& other) const;
        bool operator!=(const SportsCenter& other) const;
};