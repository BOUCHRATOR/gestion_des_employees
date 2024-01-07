
#ifndef Departement_H
#define Departement_H

#include <string>
using namespace std;

class Departement {
public:
    Departement();
    virtual ~Departement();
    void AjouterEmployeAuDepartement(int iddepart);
    void SupprimerEmployeAuDepartement(int iddepart, const string& CIN);

private:
    int id;
    string name;
    int nombreemployees;
};

#endif // Departement_H
