#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "patientType.h"

using namespace std;

int getNumberPatients(ifstream& inData);
void readData(patientType patientList[], int nPatients, ifstream& inData);
void outputData(patientType patientList[], int nPatients);
void femalesMales(patientType patientList[], int nPatients);
void oldestPatient(patientType patientList[], int nPatients);

int main()
{
    ifstream inData;
    int numberPatients;
    numberPatients= getNumberPatients(inData);

    patientType patientList[numberPatients];

    readData(patientList, numberPatients, inData);

    outputData(patientList, numberPatients);

    femalesMales(patientList, numberPatients);

    oldestPatient(patientList, numberPatients);

    return 0;
}
