#include "Employee.h"
#include "Conge.h"
#include <iostream>
#include<mysql.h>
#include<fstream>
#include<string.h>
#include<sstream>
#include <windows.h>
using namespace std;
Employee::Employee()
{
    username=new char[10];
    strcpy(username,"admin");
    username=new char[10];
    strcpy(username,"admin");
}

Employee::~Employee()
{
    delete[]username;
    delete[]password;
}
Employee::Employee(const char* uname, const char* pass):Personne(uname,pass)
{

}

void Employee::affiche(){
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
        cout << "\t\t\t\t----------------------VOTRE INFORMATIONS -----------------\n" << endl;
        cout << "\n Entrer le CIN de l'employe : ";
        cin >> CIN;
        cout << "\n----------------------------------------\n";

        if (mysql_real_connect(connection, host, user, pass, db, 0, nullptr, 0))
        {
            string query = "SELECT * FROM Employee where idEmp='" + string(CIN) + "'";

            if (mysql_query(connection, query.c_str()) == 0)
            {

                res = mysql_use_result(connection);
                if (res){
                    while ((row = mysql_fetch_row(res)) != nullptr)
                    {          string srtf;
            cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n CIN     |   NOM   |   PRENOM   |     AGE     |  NUMERO  |   EMAIL  |   ADRESSE  |  SALAIRE  |  DATE DE NAISSANCE   |  IDDEPARTEMENT | DateEmbauche  \n";
            cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                            cout <<"|  ";
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
                        ShowMenuu();
            }
                }

        else
        {
            cout << "Impossible de se connecter a la base de donnees" << endl;
            if(waitForEnter()){
                ShowMenuu();
            }
        }

        mysql_close(connection);
    }
        }
    }
    }
void Employee::CongeList()  {
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
        cout << "\n----------------------------------------\n";
        cout << "\n Entrer votre CIN  : ";
        cin >> CIN;
        if (mysql_real_connect(connection, host, user, pass, db, 0, nullptr, 0))
        {
            string query = "SELECT Date_Debut,Date_Fin,Type_Conge FROM Conges where idEmp='" + string(CIN) + "'";
            if (mysql_query(connection, query.c_str()) == 0)
            {
                res = mysql_use_result(connection);
            cout<<"\n-----------------------------------------------\n";
            cout<<"\n    Date_debut   |   Date_fin   |     Type       \n";
            cout<<"--------------------------------------------------\n";
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
                        ShowMenuu();
            }
                }

        else
        {
            cout << "Impossible de se connecter a la base de donnees" << endl;
            if(waitForEnter()){
                ShowMenuu();
            }
        }

        mysql_close(connection);
    }
}
    }
    }

void Employee::ShowMenuu()  {
    int choix;
    do {
         cout<<"\n\t\t\t\t\t>>>>>>>>>>> Menu Employes <<<<<<<<<<<";

                cout<<"\n";
        cout<<"\n\t\t\t\t\t------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t ENTER    1:   Modifier un employe";
        cout<<"\n\t\t\t\t\t------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t ENTER    2:   afficher votre informations    ";
        cout<<"\n\t\t\t\t\t------------------------------------------------";
         cout<<"\n\t\t\t\t\t\t ENTER    3:   afficher conges    ";
         cout<<"\n\t\t\t\t\t------------------------------------------------";
         cout<<"\n\t\t\t\t\t\t ENTER    4:   Demander conge    ";
        cout<<"\n\t\t\t\t\t------------------------------------------------";
         cout<<"\n\t\t\t\t\t\t ENTER    0:   Quitter    ";
        cout<<"\n\t\t\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";
        cin >> choix;

        switch (choix) {
            case 1:
                modifierInformations();
                break;
                 case 2:
                affiche();
                break;
                case 3:
                CongeList();
                break;
                case 4:
                addConge();
                break;
            case 0:

                 cout<<"Au revoir"<<endl;
                break;
            default:
                cout << "Option non valide. Veuillez reessayer.\n";
        }
    } while (choix >2 || choix<0);
}
bool Employee::Login() {
    char inputUsername[50];
    char inputPassword[50];
    cout << "\n\t\t\t\t\t------------------------------------------------";
    cout << "\n\t\t\t\t\t\t Entrez le nom d'utilisateur : ";
    cin >> inputUsername;
    cout << "\n\t\t\t\t\t------------------------------------------------";
    cout << "\n\t\t\t\t\t\t Entrez le mot de passe : ";

    // Utilisation de _getch() pour lire le mot de passe caractère par caractère
    char ch;
    int i = 0;
    while ((ch = _getwch()) != '\r') {  // '\r' représente la touche "Entrée"
        inputPassword[i] = ch;
        cout << '*';  // Affiche un astérisque pour chaque caractère du mot de passe
        i++;
    }
    inputPassword[i] = '\0';  // Ajoute le caractère de fin de chaîne

    ifstream inputFile("info.txt");
    if (!inputFile) {
        cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return false;
    }

    string line;
    string name;
    string pass;
    bool loginSuccessful = false;

    while (getline(inputFile, line)) {
        int delimiterPos = line.find(' ');
        name = line.substr(0, delimiterPos);
        pass = line.substr(delimiterPos + 1);

        if (name == inputUsername && pass == inputPassword) {
            loginSuccessful = true;
            break;
        }
    }

    inputFile.close();

    if (loginSuccessful) {
        cout << "\n\t\t\t\t\t------------------------------------------------\n\n\n";
        cout << "\n\t\t\t\t\t\t****Connexion reussie****" << endl;
        cout << "\n\t\t\t\t\t------------------------------------------------";
        ShowMenuu();
    } else {
        cout << "\n\t\t\t\t\t------------------------------------------------";
        cout << "\n\t\t\t\t\t\tNom d'utilisateur ou mot de passe incorrect" << endl;
        cout << "\n\t\t\t\t\t------------------------------------------------";
        Login();
    }

    return loginSuccessful;
}
void Employee::modifierInformations()  {
    MYSQL* connection;
    connection = mysql_init(nullptr);

    if (connection) {
        const char* host = "localhost";
        const char* user = "root";
        const char* pass = "";
        const char* db = "entreprise";

        cout << "\t\t\t\t----------------------MODIFICATION DE VOS INFORMATIONS-----------------\n" << endl;
        cout << "\n----------------------------------------";
        cout << "\n Entrer votre CIN : ";
        cin >> CIN;
        string ch;
        cout << "\nSi vous voulez modifier vos informations, tapez 'ok'; sinon, tapez 'annuler'\n";
        cin >> ch;

        if (ch == "ok") {
            if (mysql_real_connect(connection, host, user, pass, db, 0, nullptr, 0)) {
                string choixModifications,login;
                cout << "\nChoisissez les informations que vous souhaitez modifier (numero/email/adresse/motdepasse/login) : ";
                cin >> choixModifications;

                string query;
                stringstream ss;
                 fstream fichier("info.txt");

              if ( choixModifications=="login"|| choixModifications=="password"){
    if (fichier) {
        // Lire le fichier ligne par ligne
        string ligne;
        string nouveau;
        cout<<"Entrer ancienne login";
        cin>> login;
        cout<<"Entrer nouveau login";
        cin>>nouveau;
        while (!fichier.eof()) {
           stringstream ss(ligne);
            string champ1, champ2, champ3;
            ss >> champ1 >> champ2 >> champ3;

            // Effectuer les modifications nécessaires
            if (champ1 == login) {
                // Remplacer la valeur du champ1 par le nouveau nom
                champ1 = nouveau;

                // Positionner le pointeur de fichier à la position de la ligne actuelle
                streampos position = fichier.tellg();

                // Écrire la ligne modifiée dans le fichier
                fichier.seekp(position);
                fichier << champ1 << " " << champ2 << " " << champ3 << endl;
            }

        }

        // Tronquer le fichier à la position actuelle du pointeur de fichier
        fichier.close();

        cout << "Le nom a été remplacé dans le fichier 'donnees.txt'." << endl;
    } else {
        cout << "Erreur : Le fichier 'donnees.txt' n'existe pas." << endl;
    }

              }
              ss << "UPDATE employee SET ";

                 if (choixModifications == "numero") {
                    int nouveau_numero;
                    cout << "\n Entrer le nouveau numero : ";
                    cin >> nouveau_numero;
                    ss << "numero = '" << nouveau_numero << "'";
                } else if (choixModifications == "email") {
                    string nouveau_email;
                    cout << "\n Entrer le nouveau email : ";
                    cin >> nouveau_email;
                    ss << "email = '" << nouveau_email<< "'";
                } else if (choixModifications == "adresse") {
                    string nouvel_addresse;
                    cout << "\n Entrer le nouvel adresse : ";
                    cin >>nouvel_addresse ;
                    ss << "adresse = '" <<nouvel_addresse<<"'";
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
                ShowMenuu();
            }
        } else if (ch == "annuler") {
            ShowMenuu();
        }

        mysql_close(connection);
    }
}
void Employee::addConge()
{
    MYSQL* connection;
    connection = mysql_init(nullptr);
    Conge ad;
    if (connection)
    {
        const char* host = "localhost";
        const char* user = "root";
        const char* pass = "";
        const char* db = "entreprise";

        cout << "\t\t\t\t----------------------DEMANDE  UN Conge-----------------\n" << endl;
        cout << "\n Entrer le CIN d'Employee: ";
        cin >> CIN;
        cout << "\n----------------------------------------";
        cout << "\n Entrer la date de debut d'Employee: ";
        cin >> date;
        cout << "\n----------------------------------------";
        cout << "\n Entrer la date de fin d'Employee: ";
        cin >> dat;
        cout << "\n----------------------------------------";
        cout << "\n Entrer le type de conge: ";
        cin >> type;
        string ch;
        cout << "\nEntrer 'SAVE' pour enregistrer les informations\n";
        cin >> ch;
        cout << "\n----------------------------------------";

        if (ch == "SAVE")
        {
            if (mysql_real_connect(connection, host, user, pass, db, 0, nullptr, 0))
            {
                string query;
                stringstream ss;
                ad.calculateDifference(date,dat);
                ss << "INSERT INTO conges (idEmp, Date_Debut, Date_Fin, Type_Conge) VALUES ('" <<  CIN << "', '" << date << "', '" << dat << "', '" << type << "')";
                query = ss.str();

                if (mysql_query(connection, query.c_str()) == 0)
                {
                    cout << "\nDonnees inserees avec succes !\n" << endl;
                }
                else
                {
                    cout << "\nErreur lors de l'insertion des donnees dans la base de donnees: " << mysql_error(connection) << endl;
                }
            }
            else
            {
                cout << "Impossible de se connecter a la base de donnees: " << mysql_error(connection) << endl;
            }
        }
        else
        {
            cout << "Annulation de l'enregistrement des informations." << endl;
        }

        mysql_close(connection);
    }
    else
    {
        cout << "Erreur lors de l'initialisation de la connexion MySQL" << endl;
    }
}
