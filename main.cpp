#include <iostream>
#include <vector>
#include <functional>
#include <ctime>

#include "Helpers.h"
#include "Training.h"
#include "IndividualTraining.h"
#include "GroupTraining.h"
#include "SportsCenter.h"

using namespace std;

/*
    Personal Project - Sports Center Management
    Testing main functionality
*/

void TestHelpers()
{
    cout << "\n===== HELPER FUNCTIONS =====\n";

    char* copy = CreateCopy("Advanced programming techniques");
    cout << "Copy: " << (copy ? copy : "nullptr") << endl;
    delete[] copy;

    cout << "Word count: "
         << CountWords("  C++   programming and OOP  ")
         << endl;

    char* joined = JoinText("FIT", "ZENICA", '-');
    cout << "Joined: " << (joined ? joined : "nullptr") << endl;
    delete[] joined;

    cout << "Equal strings: " << AreEqual("NTP", "NTP") << endl;

    vector<int> v1{ 1, 2, 3 };
    vector<int> v2{ 1, 2, 3 };
    cout << "Equal vectors: " << (v1 == v2) << endl;

    vector<const char*> s1{ "C++", "OOP" };
    vector<const char*> s2{ "C++", "OOP" };
    cout << "Equal text vectors: " << AreEqual(s1, s2) << endl;
}

void TestTraining()
{
    cout << "\n===== TRAINING =====\n";

    Training t1("Conditioning training", 25.0f, 75);
    t1.AddRating(5);
    t1.AddRating(4);
    t1.AddRating(5);
    t1.AddRating(8);

    t1.Print();

    float average = t1.Calculate(
        [](const vector<int>& ratings) -> float {
            if (ratings.empty()) return 0.0f;
            float sum = 0;
            for (int x : ratings) sum += x;
            return sum / ratings.size();
        }
    );

    cout << "Average: " << average << endl;
    cout << "Long training: " << (!t1 ? "YES" : "NO") << endl;

    Training t2(t1);
    cout << "Copy ctor equal: " << (t1 == t2) << endl;

    Training t3;
    t3 = t1;
    cout << "Operator= equal: " << (t1 == t3) << endl;
}

void TestIndividualTraining()
{
    cout << "\n===== INDIVIDUAL TRAINING =====\n";

    IndividualTraining i1("Individual fitness", 45.0f, 60, "Amar Trainer", 9);

    cout << "Before ++: " << i1.GetSessionCount() << endl;
    ++i1;
    cout << "After ++: " << i1.GetSessionCount() << endl;
    cout << "10 or more sessions: " << (!i1 ? "YES" : "NO") << endl;

    IndividualTraining i2(i1);
    cout << "Copy ctor equal: " << (i1 == i2) << endl;

    IndividualTraining i3;
    i3 = i1;
    cout << "Operator= equal: " << (i1 == i3) << endl;

    i1.Print();
}

void TestGroupTraining()
{
    cout << "\n===== GROUP TRAINING =====\n";

    GroupTraining g1("HIIT group", 15.0f, 50, "HIIT", 3);

    cout << "Adding Ena: " << (g1 += "Ena") << endl;
    cout << "Adding Amar: " << (g1 += "Amar") << endl;
    cout << "Adding Ena again: " << (g1 += "Ena") << endl;
    cout << "Adding Lejla: " << (g1 += "Lejla") << endl;
    cout << "Adding after full: " << (g1 += "Tarik") << endl;

    cout << "Training full: " << (!g1 ? "YES" : "NO") << endl;

    GroupTraining g2(g1);
    cout << "Copy ctor equal: " << (g1 == g2) << endl;

    if (!g1.GetParticipants().empty() && !g2.GetParticipants().empty()) {
        cout << "Deep copy of participants: "
             << (g1.GetParticipants()[0] != g2.GetParticipants()[0])
             << endl;
    }

    GroupTraining g3;
    g3 = g1;
    cout << "Operator= equal: " << (g1 == g3) << endl;

    g1.Print();
}

void TestSportsCenter()
{
    cout << "\n===== SPORTS CENTER =====\n";

    Training t("Conditioning training", 25.0f, 75);
    IndividualTraining i("Personal training", 50.0f, 60, "Coach A", 12);
    GroupTraining g("Pilates", 18.0f, 55, "Pilates", 2);

    g += "Ena";
    g += "Lejla";

    SportsCenter center("Arena Fitness", "info@arena.ba");

    cout << "Add base training: " << center.AddTraining(t) << endl;
    cout << "Add individual training: " << center.AddTraining(i) << endl;
    cout << "Add group training: " << center.AddTraining(g) << endl;

    cout << "\nCenter:\n" << center << endl;

    int expensiveThan20 = center.Count(
        [](const Training& training) {
            return training.GetPrice() > 20.0f;
        }
    );

    cout << "Number of trainings more expensive than 20 KM: " << expensiveThan20 << endl;

    Training* mostExpensive = center.FindMostExpensive();
    if (mostExpensive != nullptr) {
        cout << "Most expensive training: "
             << mostExpensive->GetName()
             << " (" << mostExpensive->GetPrice() << " KM)"
             << endl;
    }

    SportsCenter copy(center);
    cout << "Copy ctor of center - element count: " << copy.GetCurrentCount() << endl;

    if (center.GetCurrentCount() > 0 && copy.GetCurrentCount() > 0) {
        cout << "Deep copy of first element: "
             << (center.GetElementAt(0) != copy.GetElementAt(0))
             << endl;
    }

    SportsCenter assignment;
    assignment = center;
    cout << "Operator= of center - element count: " << assignment.GetCurrentCount() << endl;
}

int main()
{
    srand((unsigned)time(nullptr));
    
    // Uncomment corresponding methods for testing
    
    //TestHelpers();
    //TestTraining();
    //TestIndividualTraining();
    //TestGroupTraining();
    //TestSportsCenter();

    return 0;
}