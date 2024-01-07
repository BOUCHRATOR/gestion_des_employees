#include "HR.h"
#include<mysql.h>
#include<fstream>
#include "Conge.h"
#include "departement.h"
#include "Personne.h"
#include "Employee.h"
#include <iostream>
#include<string.h>
#include <sstream>
#include <windows.h>
using namespace std;
//static int HR::nbEmp=0;
HR::HR(){

    username = new char[3];
    strcpy(username, "hr");
    password = new char[11];
    strcpy(password, "password_hr");

}
HR::HR(const char* uname, const char* pass):Personne(uname,pass)
{

}
HR::~HR()
{
    delete username;
    delete password;
}
void HR::stocker(){
        char inputUsername [50];
        char inputPassword [50];
        cout << "\t\t\t\t----------------------CREER UN COMPTE D'UN EMPLOYEE-----------------\n" << endl;
         cout<<"\n\t\t\t\t\t\t Entrez le nom d'utilisateur  :";
        cin >> inputUsername;

        cout<<"\n\t\t\t\t\t------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t Entrez le mot de passe :";
        cin >> inputPassword;
        cout<<"\n\t\t\t\t\t\t Entrez le mot de passe pour le confirmer :";
        cin >> inputPassword;
        ofstream fichier("info.txt", ios::app);
        if (fichier) {

            fichier << inputUsername << " " << inputPassword<< endl;
            fichier.close();

            cout << "Le Compte est creer avec succes." << endl;
        } else {
            cout << " le compte n'a pas creer!!!!!" << endl;
        }

}




    void HR::RECHERCHE()  {
    MYSQL* connection;
    MYSQL_ROW row = nullptr;
    MYSQL_RES* res = nullptr;


    connection = mysql_init(nullptr);
    if (connection)
    {
        const char* host = "localhost";
        const char* user = "root";
        const char* pass = "";
        const char* db = "entreprise";
        cout << "\t\t\t\t----------------------RECHERCHE SUR UN EMPLOYEE-----------------\n" << endl;
        cout << "\n Entrer le CIN de l'employe : ";
        cin >> CIN;
        cout << "\n----------------------------------------\n";
        cout<<"Loading";
        for(int a=1;a<5;a++) // Change 'a<?' to how many * you want
	{
		Sleep(500);
		 cout<<"*";

	}
        if (mysql_real_connect(connection, host, user, pass, db, 0, nullptr, 0))
        {
            string query = "SELECT * FROM Employee where idEmp='" + string(CIN) + "'";

            if (mysql_query(connection, query.c_str()) == 0)
            {
                   bool employeeFound = false;
                res = mysql_use_result(connection);
                if (res){
                    while ((row = mysql_fetch_row(res)) != nullptr)
                    {          string srtf;
            cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n CIN     |   NOM   |   PRENOM   |     AGE     |  NUMERO  |   EMAIL  |   ADRESSE  |  SALAIRE  |  DATE DE NAISSANCE   |  IDDEPARTEMENT | DateEmbauche  \n";
            cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                            for(int i=0;i<11;i++){
                         srtf = row[i];

                        // Faites quelque chose avec employeename (par exemple, l'afficher)
                    cout <<"|  "<< srtf << " |";
                    }
                    cout<<endl;
                    cout<<endl;
                     employeeFound = true;
                    }
                    if (!employeeFound) {
                        cout << "\n-------------------------------------------------\n";
                        cout << "\nL'employe n'existe pas dans la base de donnees." << endl;
                    }
                    mysql_free_result(res);
                     if(waitForEnter()){
                        ShowMenu();
            }
                }

        else
        {
            cout << "Impossible de se connecter a la base de donnees" << endl;
            if(waitForEnter()){
                ShowMenu();
            }
        }

        mysql_close(connection);
    }
        }
    }
    }
    void HR::EmployeeList()  {
    MYSQL* connection;
    MYSQL_ROW row = nullptr;
    MYSQL_RES* res = nullptr;


    connection = mysql_init(nullptr);
    if (connection)
    {
        const char* host = "localhost";
        const char* user = "root";
        const char* pass = "";
        const char* db = "entreprise";

        if (mysql_real_connect(connection, host, user, pass, db, 0, nullptr, 0))
        {
            string query = "SELECT * FROM Employee";
            if (mysql_query(connection, query.c_str()) == 0)
            {
                res = mysql_use_result(connection);
            cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n CIN     |   NOM   |   PRENOM   |     AGE     |  NUMERO  |   EMAIL  |   ADRESSE  |  SALAIRE  |  DATE DE NAISSANCE   |  IDDEPARTEMENT  |  DateEmbauche  \n";
            cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                if (res){
                    while ((row = mysql_fetch_row(res)) != nullptr)
                    {          string srtf;
                                cout <<"| ";
                            for(int i=0;i<11;i++){
                         srtf = row[i];

                        // Faites quelque chose avec employeename (par exemple, l'afficher)
                    cout <<"  "<< srtf << " |";
                    }
                    cout<<endl;
                    cout<<endl;

                    }

                    mysql_free_result(res);
                     if(waitForEnter()){
                        ShowMenu();
            }
                }

        else
        {
            cout << "Impossible de se connecter a la base de donnees" << endl;
            if(waitForEnter()){
                ShowMenu();
            }
        }

        mysql_close(connection);
    }
}
    }
    }
     void HR::CongeList()  {
    MYSQL* connection;
    MYSQL_ROW row = nullptr;
    MYSQL_RES* res = nullptr;


    connection = mysql_init(nullptr);
    if (connection)
    {
        const char* host = "localhost";
        const char* user = "root";
        const char* pass = "";
        const char* db = "entreprise";

        if (mysql_real_connect(connection, host, user, pass, db, 0, nullptr, 0))
        {
            string query = "SELECT idEmp,Date_Debut,Date_Fin,Type_Conge FROM Conges";
            if (mysql_query(connection, query.c_str()) == 0)
            {
                res = mysql_use_result(connection);
            cout<<"\n-------------------------------------------------------------\n";
            cout<<"\n CIN     |   Date_debut   |   Date_fin   |     Type       \n";
            cout<<"-----------------------------------------------------------\n";
                if (res){
                    while ((row = mysql_fetch_row(res)) != nullptr)
                    {          string srtf;
                                cout <<"| ";
                            for(int i=0;i<4;i++){
                         srtf = row[i];

                        // Faites quelque chose avec employeename (par exemple, l'afficher)
                    cout <<"  "<< srtf << " |";
                    }
                    cout<<endl;
                    cout<<endl;

                    }

                    mysql_free_result(res);
                     if(waitForEnter()){
                        ShowMenu();
            }
                }

        else
        {
            cout << "Impossible de se connecter a la base de donnees" << endl;
            if(waitForEnter()){
                ShowMenu();
            }
        }

        mysql_close(connection);
    }
}
    }
    }
 void HR::addEmploye()
{
    MYSQL* connection;
    Departement AJOUT;
    connection = mysql_init(nullptr);
    if (connection)
    {
        const char* host = "localhost";
        const char* user = "root";
        const char* pass = "";
        const char* db = "entreprise";

        cout << "\t\t\t\t----------------------AJOUTER UN EMPLOYEE-----------------\n" << endl;
        cout<<"\n Entrer le CIN d'Employee: ";
        cin>>CIN;
        cout<<"\n----------------------------------------";
        cout<<"\n Entrer le Nom d'Employee: ";
        cin>>name;
        cout<<"\n----------------------------------------";
        cout<<"\n Entrer le Prenom d'Employee: ";
        cin>>prenom;
        cout<<"\n----------------------------------------";
        cout<<"\n Entrer Employee Age: ";
        cin>>age;
        cout<<"\n----------------------------------------";
        cout<<"\n Entrer numero d'Employee: ";
        cin>>num;
        cout<<"\n----------------------------------------";
        cout<<"\n Entrer Email Employee : ";
        cin>>Email;
        cout<<"\n----------------------------------------";
        cout<<"\n Entrer adresse Employee : ";
        cin>>adresse;
        cout<<"\n----------------------------------------";
        cout<<"\n Entrer salaire Employee : ";
        cin>>salaire;
        cout<<"\n----------------------------------------";
        cout<<"\n Entrer date de naissance Employee : ";
        cin>>date;
        cout<<"\n----------------------------------------";
        cout<<"\n Entrer dateEmbauche  d'Employee : ";
        cin>>dateEmbauche;
        cout<<"\n----------------------------------------";
        cout<<"\n Entrer ID de departement d'Employee : ";
        cin>>ide;
        cout<<"\n----------------------------------------";
        string ch;
        cout<<"\nEntrer 'SAVE' pour enregestrie les  information\n";
        cin>>ch;
        cout<<"\n----------------------------------------";
        if (ch == "SAVE")
        {
            if (mysql_real_connect(connection, host, user, pass, db, 0, nullptr, 0))
            {

                string query;
                stringstream ss;
                ss << "INSERT INTO employee (idEmp, Employenom, Employeprenom, age, numero, email, adresse, salaire, date_naissance, iddepart, dateEmbauche) VALUES ('" << CIN << "', '" << name << "', '" << prenom << "', " << age << ", '" << num << "', '" << Email << "', '" << adresse << "', " << salaire << ", '" << date << "', " << ide << ", '" << dateEmbauche << "')";
                query = ss.str();

                if (mysql_query(connection, query.c_str()) == 0)
                {
                    cout << "\nDonnees inserees avec succes !\n" << endl;
                    stocker();
                    AJOUT.AjouterEmployeAuDepartement(ide);
                }
                else
                {
                    cout << "\nErreur lors de l'insertion des donnees dans la base de donnees" << endl;
                }
            }
            else
            {
                cout << "Impossible de se connecter a la base de donnees" << endl;
            }

            if (waitForEnter())
            {
                ShowMenu();
            }
        }

        mysql_close(connection);
    }
}
   void HR::Supprimer() {
    MYSQL* connection;
    Departement SUPP;
    connection = mysql_init(nullptr);

    if (connection) {
        const char* host = "localhost";
        const char* user = "root";
        const char* pass = "";
        const char* db = "entreprise";

        cout << "\t\t\t\t----------------------SUPPRESSION D'UN EMPLOYEE-----------------\n" << endl;
        cout << "\n Entrer le CIN de l'employe : ";
        cin >> CIN;
        cout << "\n----------------------------------------";

        string ch;
        cout << "\nSi vous voulez supprimer cet employe, tapez 'ok'; sinon, tapez 'annuler'\n";
        cin >> ch;

        if (ch == "ok") {
            if (mysql_real_connect(connection, host, user, pass, db, 0, nullptr, 0)) {
                string query;
                stringstream ss;
                query = "DELETE FROM employee WHERE idEmp = '" + string(CIN) + "'";
                if (mysql_query(connection, query.c_str()) == 0) {
                    cout << "\nDonnees supprimees avec succes !" << endl;
                    //SUPP.SupprimerEmployeAuDepartement(CIN);
                } else {
                    cout << "\nErreur lors de la suppression des donnees dans la base de donnees" << endl;
                }
            } else {
                cout << "Impossible de se connecter a la base de donnees" << endl;
            }

            if (waitForEnter()) {
                ShowMenu();
            }
        } else if (ch == "annuler") {
            ShowMenu();
        }

        mysql_close(connection);
    }
}
void HR::ShowMenu()  {
    int choix;
     // Variable pour stocker le choix précédent
    do {

         cout<<"\n\t\t\t\t\t>>>>>>>>>>> Menu Ressources Humaines <<<<<<<<<<<";
                cout<<"\n";
        cout<<"\n\t\t\t\t\t-------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t ENTER    0:   Liste des employes";
        cout<<"\n\t\t\t\t\t-------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t ENTER    1:   ajouter un employe";
        cout<<"\n\t\t\t\t\t-------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t ENTER    2:   Modifier un employe";
        cout<<"\n\t\t\t\t\t-------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t ENTER    3:   Supprimer un employe";
        cout<<"\n\t\t\t\t\t-------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t ENTER    4:   Recherche sur un employe";
        cout<<"\n\t\t\t\t\t-------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t ENTER    5:   afficher les conges des employees";
        cout<<"\n\t\t\t\t\t-------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t ENTER    6:   afficher les departement";
        cout<<"\n\t\t\t\t\t-------------------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t ENTER    7:   Quitter    ";
        cout<<"\n\t\t\t\t\t-------------------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";
        cin >> choix;

        switch (choix) {
            case 0:
                  EmployeeList();
                break;
            case 1:
                  addEmploye();
                break;
                case 2:
                  modify();
                break;
                case 3:
                  Supprimer();
                break;
                case 4:
            RECHERCHE();
                break;
                 case 5:
            CongeList();
                break;
                 case 6:
            DepartementList();
                break;
                case 7:
                  cout<<endl;
                  cout<<"\t\t\t\t Au revoir ";
                   break;
            default:
                cout << "Option non valide. Veuillez reessayer.\n";
        }

    } while (choix >7 || choix<0);

}
bool HR::Login()  {
        char inputUsername [50];
        char inputPassword [50];

        cout<<"\n\t\t\t\t\t------------------------------------------------";

        cout<<"\n\t\t\t\t\t\t Entrez le nom d'utilisateur  :";
        cin >> inputUsername;
        cout<<"\n\t\t\t\t\t------------------------------------------------";
        cout<<"\n\t\t\t\t\t\t Entrez le mot de passe :";
         char ch;
         int i = 0;
           while ((ch = _getwch()) != '\r') {  // '\r' représente la touche "Entrée"
        inputPassword[i] = ch;
        cout << '*';  // Affiche un astérisque pour chaque caractère du mot de passe
        i++;
    }

    if (strcmp(username, inputUsername) == 0 && strcmp(password, inputPassword) == 0)
    {
        cout<<"\nLoading";
        for(int a=1;a<8;a++) // Change 'a<?' to how many * you want
	{
		Sleep(500);
		cout << "....";
	}
	        cout<<"\n\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t****Connexion reussie**" << endl;
        cout<<"\n\t\t\t\t\t------------------------------------------------";
        ShowMenu();
        return true;

    }
    else

    {
        cout<<"\n\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\t Nom d'utilisateur ou mot de passe incorrect" << endl;
        cout<<"\n\t\t\t\t\t------------------------------------------------";
        Login();
    return false;
    }
    // Simulation : fonction de modification d'employé

    }
    void HR::modify() {
    MYSQL* connection;
    connection = mysql_init(nullptr);

    if (connection) {
        const char* host = "localhost";
        const char* user = "root";
        const char* pass = "";
        const char* db = "entreprise";

        cout << "\t\t\t\t----------------------MODIFICATION DES INFORMATIONS D'UN EMPLOYEE-----------------\n" << endl;
        cout << "\n Entrer le CIN de l'employe : ";
        cin >> CIN;
        cout << "\n----------------------------------------";

        string ch;
        cout << "\nSi vous voulez modifier les informations de cet employe, tapez 'ok'; sinon, tapez 'annuler'\n";
        cin >> ch;

        if (ch == "ok") {
            if (mysql_real_connect(connection, host, user, pass, db, 0, nullptr, 0)) {
                string choixModifications;
                cout << "\nChoisissez les informations que vous souhaitez modifier (nom/prenom/iddepart/salaire) : ";
                cin >> choixModifications;

                string query;
                stringstream ss;

                ss << "UPDATE employee SET ";

                if (choixModifications == "nom") {
                    string nouveauNom;
                    cout << "\n Entrer le nouveau nom : ";
                    cin >> nouveauNom;
                    ss << "Employenom = '" << nouveauNom << "'";
                } else if (choixModifications == "prenom") {
                    string nouveauPrenom;
                    cout << "\n Entrer le nouveau prenom : ";
                    cin >> nouveauPrenom;
                    ss << "Employeprenom = '" << nouveauPrenom << "'";
                } else if (choixModifications == "iddepart") {
                    int nouvelIdDepartement;
                    cout << "\n Entrer le nouvel ID du departement : ";
                    cin >> nouvelIdDepartement;
                    ss << "iddepart = " << nouvelIdDepartement;
                } else if (choixModifications == "salaire") {
                    double nouveauSalaire;
                    cout << "\n Entrer le nouveau salaire : ";
                    cin >> nouveauSalaire;
                    ss << "salaire = " << nouveauSalaire;
                } else {
                    cout << "\nChoix invalide." << endl;
                    return;
                }

                ss << " WHERE idEmp = '" << string(CIN) << "'";
                query = ss.str();

                if (mysql_query(connection, query.c_str()) == 0) {
                    cout << "\nInformations modifiees avec succes !" << endl;
                } else {
                    cout << "\nErreur lors de la modification des informations dans la base de donnees" << endl;
                }
            } else {
                cout << "Impossible de se connecter a la base de donnees" << endl;
            }

            if (waitForEnter()) {
                ShowMenu();
            }
        } else if (ch == "annuler") {
            ShowMenu();
        }

        mysql_close(connection);
    }
}


void HR::DepartementList()  {
    MYSQL* connection;
    MYSQL_ROW row = nullptr;
    MYSQL_RES* res = nullptr;


    connection = mysql_init(nullptr);
    if (connection)
    {
        const char* host = "localhost";
        const char* user = "root";
        const char* pass = "";
        const char* db = "entreprise";

        if (mysql_real_connect(connection, host, user, pass, db, 0, nullptr, 0))
        {
            string query = "SELECT * FROM DEPARTEMENT";
            if (mysql_query(connection, query.c_str()) == 0)
            {
                res = mysql_use_result(connection);
            cout<<"\n------------------------------------------------------------";
            cout<<"\n IDDEPARTMENT  | NOM DE DEPARTEMENT | NOMBRE DES EMPLOYEES  \n";
            cout<<"--------------------------------------------------------------\n";
                if (res){
                    while ((row = mysql_fetch_row(res)) != nullptr)
                    {          string srtf;
                                cout <<"| ";
                            for(int i=0;i<3;i++){
                         srtf = row[i];

                        // Faites quelque chose avec employeename (par exemple, l'afficher)
                    cout <<"  "<< srtf << " |";
                    }
                    cout<<endl;
                    cout<<endl;

                    }

                    mysql_free_result(res);
                     if(waitForEnter()){
                        ShowMenu();
            }
                }

        else
        {
            cout << "Impossible de se connecter a la base de donnees" << endl;
            if(waitForEnter()){
                ShowMenu();
            }
        }

        mysql_close(connection);
    }
}
    }
    }
    void HR::confermerConge(int joursConge) {
    if (joursConge > 25) {
        cout << "\nvotre demande est  refuser" << endl;
    } else {
        cout << "\nvotre demande est accepter" << endl;
    }
    }

