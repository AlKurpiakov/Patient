#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <stdint.h>
// #include <boost/uuid/uuid.hpp>
// #include <boost/uuid/random_generator.hpp>
// #include <boost/uuid/uuid_io.hpp>

struct Diag
{
    std::string desis;
    std::string pills;
};


struct Date
{
    char day;
    char month;
    uint16_t year;
    uint32_t datecode;
};

class Patient
{
private:
    std::string _name;
    std::string _patronomic;
    std::string _surname;
    Date _bornDate;
    //UUID _patientID;
    Diag _diag;
    std::string _problem;
    void ParseFIO(std::string FIO);

public:
    Patient(std::string name, std::string patronomic, std::string surname, std::string problem, Date bornDate);
    Patient(std::string FIO, std::string problem, Date bornDate);
    void PatientInfo();
};

void Patient::ParseFIO(std::string FIO){
    std::string temp;
    int flag = 0;
    for (int i = 0; i < FIO.size(); i++){
        if (FIO[i] == 127){
            if (flag == 0) _surname = temp;
            if (flag == 1) _name = temp;
            temp = "";
            flag += 1;
        }
        temp += FIO[i];
    }
    if (flag != 2){
        _name = "";
        _surname = "";
    }
    _patronomic = temp;
    temp = "";
};

Patient::Patient(std::string name, std::string patronomic, std::string surname, std::string problem, Date bornDate){
    _name = name;
    _patronomic = patronomic;
    _surname = surname;
    _bornDate = bornDate;
    _problem = problem;
};

Patient::Patient(std::string FIO, std::string problem, Date bornDate){
    ParseFIO(std::string (FIO));
    _bornDate = bornDate;
};

void Patient::PatientInfo(){
    std:: cout << "FIO:" <<  _surname << _name <<  _patronomic << "\n";
    std:: cout << "Birthday:" <<  _bornDate.day << _bornDate.month <<  _bornDate.year << "\n";
    std:: cout << "Problem:" << _problem << "\n";
};