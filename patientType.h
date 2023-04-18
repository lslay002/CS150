#include <iostream>
#include <string>
using namespace std;
#ifndef PATIENTTYPE_H
#define PATIENTTYPE_H


class patientType
{
    public:
        patientType();
        string name;
        string state;
        char gender;
        void setYear(int y);
        void printYear();
        int getYear();
    private:
        int year;
};

#endif // PATIENTTYPE_H
