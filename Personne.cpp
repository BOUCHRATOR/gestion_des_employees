#include "Personne.h"
#include "Employee.h"
#include<mysql.h>
#include <iostream>
#include<string.h>
#include <sstream>
#include <iostream>
#include <windows.h>
#include "HR.h"
using namespace std;
//HR K;
Personne::Personne()
{
  username = new char[11];
    password = new char[11];
}
Personne::Personne(const char* uname, const char* pass)
{
username = new char[strlen(uname) + 1];
    strcpy(username, uname);
    password = new char[strlen(pass) + 1];
    strcpy(password, pass);
}
Personne::~Personne()
{
   delete username;
    delete password;
}
bool Personne::waitForEnter(){
            cout<<"\n\n\n Press enter to go back \n\n";
            cin.get();
            cin.get();
            return true;
        }

