
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
            // Votre logique pour ajouter un employé...

            // Exécutez la requête pour obtenir le nombre d'employés dans le département après l'ajout
            string countQuery = "SELECT COUNT(*) as b FROM employee WHERE iddepart = " + to_string(iddepart) + " GROUP BY iddepart";

            if (mysql_query(connection, countQuery.c_str()) == 0) {
                MYSQL_RES* countResult = mysql_store_result(connection);
                if (countResult) {
                    MYSQL_ROW countRow = mysql_fetch_row(countResult);
                    if (countRow) {
                        int nombreemployes = atoi(countRow[0]);

                        // Ensuite, mettez à jour le nombre d'employés pour le département
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
                    cout << "\nErreur lors de l'execution de la requête pour compter les employes." << endl;
                }
            } else {
                cout << "\nErreur lors de l'execution de la requete pour compter les employes." << endl;
            }
        } else {
            cout << "Impossible de se connecter à la base de donnees" << endl;
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
            // Votre logique pour supprimer un employé...

            // Exécutez la requête pour obtenir le nombre d'employés dans le département après la suppression
            string countQuery = "SELECT COUNT(*) as b FROM employee WHERE iddepart = " + to_string(iddepart) + " GROUP BY iddepart";

            if (mysql_query(connection, countQuery.c_str()) == 0) {
                MYSQL_RES* countResult = mysql_store_result(connection);
                if (countResult) {
                    MYSQL_ROW countRow = mysql_fetch_row(countResult);
                    if (countRow) {
                        int nombreEmployes = atoi(countRow[0]);

                        // Ensuite, mettez à jour le nombre d'employés pour le département
                        string updateQuery = "UPDATE departement SET nombreemployees = " + to_string(nombreEmployes) + " WHERE iddepart = " + to_string(iddepart);

                        if (mysql_query(connection, updateQuery.c_str()) == 0) {
                            cout << "\nNombre d'employés mis à jour pour le département avec succès !" << endl;
                        } else {
                            cout << "\nErreur lors de la mise à jour du nombre d'employés pour le département." << endl;
                        }
                    } else {
                        cout << "\nAucun employé dans le département." << endl;
                    }

                    mysql_free_result(countResult);
                } else {
                    cout << "\nErreur lors de l'exécution de la requête pour compter les employés." << endl;
                }
            } else {
                cout << "\nErreur lors de l'exécution de la requête pour compter les employés." << endl;
            }
        } else {
            cout << "Impossible de se connecter à la base de données" << endl;
        }

        mysql_close(connection);
    }
}
