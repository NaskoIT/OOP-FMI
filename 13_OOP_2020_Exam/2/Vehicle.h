#ifndef EXAMPREPARATION_VEHICLE_H
#define EXAMPREPARATION_VEHICLE_H

#include <string>

using namespace std;

enum ProblemSeverity {
    Low,
    Medium,
    High,
};

class Vehicle {
private:
    string make;
    string model;
    unsigned int year;
    string problem;
    ProblemSeverity problemSeverity;

public:
    Vehicle();

    Vehicle(const string &make, const string &model, unsigned int year, const string &problem, ProblemSeverity problemPriority);

    string getMake() const;

    void setMake(const string &newMake);

    string getModel() const;

    void setModel(const string &newModel);

    unsigned int getYear() const;

    void setYear(unsigned int year);

    string getProblem() const;

    void setProblem(const string &newProblem);

    ProblemSeverity getProblemSeverity() const;

    void setProblemSeverity(ProblemSeverity newProblemSeverity);

    virtual Vehicle *clone() const = 0;

    virtual ~Vehicle() = default;
};


#endif //EXAMPREPARATION_VEHICLE_H
