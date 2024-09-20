#include "patient.hpp"


int main(){
    Doctor doc;
    PatientQueue queue;
    while (1){
        queue.AddPatient(new Patient("1 1 1", "2", 123));
    }
    while (1)
    {
        auto p = queue.GetNext();
        doc.TakePatient(p);
        delete p;
    }
    return 0;
}