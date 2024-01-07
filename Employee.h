#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include "Personne.h"

using namespace std;
class Employee : public Personne
{

public:
        Employee();
        virtual ~Employee();
        Employee(const char* uname, const char* pass);
         void ShowMenuu() ;
         void CongeList();
         void affiche();
         void addConge();
        bool Login()override ;
        void modifierInformations();
    protected:
  double salaire;
    private:
       string type;
        char dat[20];
};

#endif // EMPLOYEE_H
