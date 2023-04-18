#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "patientType.h"

using namespace std;
patientType::patientType()
{
    year = 0;
}

int getNumberPatients(ifstream& inData)
{
    inData.open("input.txt");
    string temp;
    int counter =0;

    while (getline(inData,temp))
    {
        counter++;
    }

    inData.close();
    return counter;
}

void readData(patientType patientList[],int nPatients,ifstream& inData)
{
    inData.open("input.txt");
    int birthYear;

    for (int i=0; i<nPatients; i++)
    {
        inData >> patientList[i].name
               >> birthYear
               >> patientList[i].state
               >> patientList[i].gender;
        patientList[i].setYear(birthYear);
    }
    inData.close();
}

void outputData(patientType patientList[], int nPatients)
{
    cout << left;
    cout << setw(10) << "Name"
         << setw(10) << "Year"
         << setw(10) << "State"
         << setw(10) << "Gender"
         << endl;
    cout << setw(10) << "===="
         << setw(10) << "===="
         << setw(10) << "====="
         << setw(10) << "======"
         << endl;

    for (int i=0; i<nPatients; i++)
    {
        cout << setw(10) << patientList[i].name
             << setw(10) << patientList[i].getYear()
             << setw(12) << patientList[i].state
             << setw(10) << patientList[i].gender << endl;
    }
    cout << "\nThere are " << nPatients << " patients." << endl;
}


void femalesMales(patientType patientList[], int nPatients)
{
    int femaleCounter =0;
    int maleCounter = 0;

    for (int i=0; i<nPatients; i++)
    {
        if (patientList[i].gender == 'F')
            femaleCounter++;
        else
            maleCounter++;
    }

    cout << "Number of female patients = " << femaleCounter << endl;
    cout << "Number of male patients = " << maleCounter << endl;
}

void oldestPatient(patientType patientList[], int nPatients)
{
    int smallestYear = 2020;
    int birthYear;
    string name;

    for (int i=0; i<nPatients; i++)
    {
        birthYear = patientList[i].getYear();

        if(birthYear < smallestYear)
        {
            smallestYear = birthYear;
            name = patientList[i].name;
        }
    }

    cout << "The name oldest oldest patient is " << name << endl;
    cout << name << " is " << 2023-smallestYear << " years old" << endl;

}


void patientType::setYear(int y)
{
    year = y;
}

void patientType::printYear()
{
    cout << left << setw(10) << year;
}

int patientType::getYear()
{
    return year;
}




