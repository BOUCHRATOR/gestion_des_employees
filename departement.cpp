
#include "Departement.h"
#include<mysql.h>
#include<iostream>
using namespace std;
Departement::Departement()  {

}

Departement::~Departement() {}



void Departement::AjouterEmployeAuDepartement(int iddepart) {
    MYSQL* connection;
    connection = mysql_init(nullptr);

    if (connection) {
        const char* host = "localhost";
        const char* user = "root";
        const char* pass = "";
        const char* db = "entreprise";

        if (mysql_real_connect(connection, host, user, pass, db, 0, nullptr, 0)) {
            // Votre logique pour ajouter un employ�...

            // Ex�cutez la requ�te pour obtenir le nombre d'employ�s dans le d�partement apr�s l'ajout
            string countQuery = "SELECT COUNT(*) as b FROM employee WHERE iddepart = " + to_string(iddepart) + " GROUP BY iddepart";

            if (mysql_query(connection, countQuery.c_str()) == 0) {
                MYSQL_RES* countResult = mysql_store_result(connection);
                if (countResult) {
                    MYSQL_ROW countRow = mysql_fetch_row(countResult);
                    if (countRow) {
                        int nombreemployes = atoi(countRow[0]);

                        // Ensuite, mettez � jour le nombre d'employ�s pour le d�partement
                        string updateQuery = "UPDATE departement SET nombreemployes = " + to_string(nombreemployes) + " WHERE iddepart = " + to_string(iddepart);

                        if (mysql_query(connection, updateQuery.c_str()) == 0) {
                            cout << "\nNombre d'employes mis a jour pour le departement avec succes !" << endl;
                        } else {
                            cout << "\nErreur lors de la mise a jour du nombre d'employes pour le departement." << endl;
                        }
                    } else {
                        cout << "\nAucun employe dans le departement." << endl;
                    }

                    mysql_free_result(countResult);
                } else {
                    cout << "\nErreur lors de l'execution de la requ�te pour compter les employes." << endl;
                }
            } else {
                cout << "\nErreur lors de l'execution de la requete pour compter les employes." << endl;
            }
        } else {
            cout << "Impossible de se connecter � la base de donnees" << endl;
        }

        mysql_close(connection);
    }
}
void Departement::SupprimerEmployeAuDepartement(int iddepart, const string& CIN) {
    MYSQL* connection;
    connection = mysql_init(nullptr);

    if (connection) {
        const char* host = "localhost";
        const char* user = "root";
        const char* pass = "";
        const char* db = "entreprise";

        if (mysql_real_connect(connection, host, user, pass, db, 0, nullptr, 0)) {
            // Votre logique pour supprimer un employ�...

            // Ex�cutez la requ�te pour obtenir le nombre d'employ�s dans le d�partement apr�s la suppression
            string countQuery = "SELECT COUNT(*) as b FROM employee WHERE iddepart = " + to_string(iddepart) + " GROUP BY iddepart";

            if (mysql_query(connection, countQuery.c_str()) == 0) {
                MYSQL_RES* countResult = mysql_store_result(connection);
                if (countResult) {
                    MYSQL_ROW countRow = mysql_fetch_row(countResult);
                    if (countRow) {
                        int nombreEmployes = atoi(countRow[0]);

                        // Ensuite, mettez � jour le nombre d'employ�s pour le d�partement
                        string updateQuery = "UPDATE departement SET nombreemployees = " + to_string(nombreEmployes) + " WHERE iddepart = " + to_string(iddepart);

                        if (mysql_query(connection, updateQuery.c_str()) == 0) {
                            cout << "\nNombre d'employ�s mis � jour pour le d�partement avec succ�s !" << endl;
                        } else {
                            cout << "\nErreur lors de la mise � jour du nombre d'employ�s pour le d�partement." << endl;
                        }
                    } else {
                        cout << "\nAucun employ� dans le d�partement." << endl;
                    }

                    mysql_free_result(countResult);
                } else {
                    cout << "\nErreur lors de l'ex�cution de la requ�te pour compter les employ�s." << endl;
                }
            } else {
                cout << "\nErreur lors de l'ex�cution de la requ�te pour compter les employ�s." << endl;
            }
        } else {
            cout << "Impossible de se connecter � la base de donn�es" << endl;
        }

        mysql_close(connection);
    }
}
