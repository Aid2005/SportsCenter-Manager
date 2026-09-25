#pragma once
#include "Training.h"
#include <vector>
using namespace std;

class GroupTraining : public Training {
    private:
        char _type[30];
        int _maxParticipants;
        vector<const char*> _participants;
        
    public:
        // Constructors and destructor
        GroupTraining();
        GroupTraining(const char* name, float price, int durationMinutes, const char* type, int maxParticipants);
        GroupTraining(const GroupTraining& other);
        virtual ~GroupTraining();
        
        // Assignment operator
        GroupTraining& operator=(const GroupTraining& other);
        
        // Getters
        const char* GetType() const { return _type; }
        int GetMaxParticipants() const { return _maxParticipants; }
        const vector<const char*>& GetParticipants() const { return _participants; }
        
        // Setters
        void SetType(const char* type);
        void SetMaxParticipants(int maxParticipants);
        void SetParticipants(const vector<const char*>& participants);
        
        // Operators
        bool operator+=(const char* participant);
        bool operator!() const; 
        
        // Methods
        virtual void Print() const override;
        virtual Training* Clone() const override;
        
        // Comparison operators
        bool operator==(const GroupTraining& other) const;
        bool operator!=(const GroupTraining& other) const;
};