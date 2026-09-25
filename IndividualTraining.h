#pragma once
#include "Training.h"
using namespace std;

class IndividualTraining : public Training {
    private:
        char _trainer[50];
        int* _sessionCount;
    public:
        
        // Constructors and destructor
        IndividualTraining();
        IndividualTraining(const char* name, float price, int durationMinutes, const char* trainer, int sessionCount);
        IndividualTraining(const IndividualTraining& other);
        virtual ~IndividualTraining();
        
        // Assignment operator
        IndividualTraining& operator=(const IndividualTraining& other);
        
        // Getters
        const char* GetTrainer() const { return _trainer; }
        int GetSessionCount() const { return (_sessionCount != nullptr) ? *_sessionCount : 0; }
        
        // Setters
        void SetTrainer(const char* trainer);
        void SetSessionCount(int sessionCount);
        
        // Operators
        IndividualTraining& operator++();
        bool operator!() const;
        
        // Methods
        virtual void Print() const override;
        virtual Training* Clone() const override;
        
        // Comparison operators
        bool operator==(const IndividualTraining& other) const;
        bool operator!=(const IndividualTraining& other) const;
};