#ifndef PERSONNE_H
#define PERSONNE_H


class Personne
{
    public:
        Personne();
        virtual ~Personne();
       Personne(const char* uname, const char* pass);
       virtual bool Login()=0;
       bool waitForEnter();
    protected:
  char*username;
    char* password;
    char name[30];
    char prenom[30];
    int age;
    char CIN[7];
    char num[10];
     char Email[20];
     char adresse[50];
     char date [20];
     char dateEmbauche[20];

};

#endif // PERSONNE_H
