#include "patient.hpp"


void Patient::ParseFIO(std::string FIO) {
    std::string temp = "";
    int count = 0;
    for (int i = 0; i < FIO.size(); i++){
        if (FIO[i] == 127){
            if (count++ == 0) _surname = temp;
            else if (count++ == 1) _name = temp;
            temp = "";
        }
        else temp += FIO[i];
    }
    if (count != 2) {
        _name = "";
        _surname = "";
        throw std::runtime_error("Error");
    }
    _patronomic = temp;
}

Patient::Patient(std::string name, std::string patronomic, std::string surname, std::string problem, Date bornDate){
    _name = name;
    _patronomic = patronomic;
    _surname = surname;
    _problem = problem;
    _bornDate = bornDate;
}
Patient::Patient(std::string FIO, std::string problem, Date bornDate){
    ParseFIO(FIO);
    _problem = problem;
    _bornDate = bornDate;
}

void Patient::PatientInfo() {
    std::cout << "FIO: " << _surname << " " << _name << " " << _patronomic << ", Problem: " << _problem << "\n";
}