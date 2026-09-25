#pragma once
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

class Training {
    private:
        const char* _id;
    protected:
        char* _name;
        float* _price;
        int _durationMinutes;
        vector<int> _ratings;
        
        static const char* GenerateId();
    public:
        // Constructors and destructor
        Training();
        Training(const char* name, float price, int durationMinutes);
        Training(const Training& other);
        virtual ~Training();
        
        // Assignment operator
        Training& operator=(const Training& other);
        
        // Getters
        const char* GetId() const { return _id; }
        const char* GetName() const { return _name; }
        float GetPrice() const { return (_price != nullptr) ? *_price : 0.0f; } 
        int GetDurationMinutes() const { return _durationMinutes; }
        const vector<int>& GetRatings() const { return _ratings; } 
        
        // Setters
        void SetName(const char* name);
        void SetPrice(float price); 
        void SetDurationMinutes(int durationMinutes);
        
        // Methods
        void AddRating(int rating);
        float Calculate(function<float(const vector<int>&)> func) const;
        bool operator!() const;
        
        virtual void Print() const;
        virtual Training* Clone() const;
        
        // Comparison operators
        bool operator==(const Training& other) const;
        bool operator!=(const Training& other) const;
};