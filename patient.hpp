#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <stdint.h>
// #include <>

struct Date
{
    std::byte day;
    std::byte month;
    uint16_t year;
    uint32_t datecode;
};

struct Diag
{
    std::string desis;
    std::string pills;
};

enum Estate{I, II, III};

class PatientQueue{
private:
    Patient** _patients_I;
    Patient** _patients_II;
    Patient** _patients_III;
    size_t _pI;
    size_t _pII;
    size_t _pIII;

public:
    PatientQueue();
    ~PatientQueue();
    Patient* GetNext();
    void AddPatient(Patient* P);
};

class Doctor{
private:
    std::string* _drugs = {};

public:
    void TakePatient(Patient* P);
    void PrintProblem(Patient* P);
    void FillDiagnos(Diag* diag);
    ~Doctor();
};




class Patient
{
private:
    std::string _name;
    std::string _patronomic;
    std::string _surname;
    Date _bornDate;
    // UUID _patientID;
    Diag _diag;
    std::string _problem;
    Estate _estate;
    void ParseFIO(std::string FIO);

public:
    Patient(std::string name, std::string patronomic, std::string surname, std::string problem, Date bornDate);
    Patient(std::string FIO, std::string problem, Date bornDate);
    void PatientInfo();
};


