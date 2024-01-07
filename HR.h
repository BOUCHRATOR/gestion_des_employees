#ifndef HR_H
#define HR_H
#include "Personne.h"

class HR : public Personne
{
      public:
    HR();
    HR(const char* uname, const char* pass);
       void confermerConge(int joursConge);
    bool Login()override;
    void stocker();
    void CongeList();
     void ShowMenu()  ;
    void EmployeeList() ;
    //bool waitForEnter();
     void addEmploye();
     void DepartementList();
     void Supprimer();
      void RECHERCHE();
    void modify();
    virtual ~HR();

    protected:
      double salaire;
     int ide;




};

#endif // HR_H
