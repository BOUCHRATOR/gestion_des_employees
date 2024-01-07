#include <iostream>
#include "HR.h"
#include "Personne.h"
#include "Employee.h"
using namespace std;

int main()
{

    HR M("hr","password_hr");
    Employee h;
  int choixPrincipal;

 do {


       cout<<"\n\n\n\n";
  cout<<"\n\t\t\t\t\t>>>>>>>>>>>>>>>>  Menu Principal <<<<<<<<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t\t\t------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t ENTER   1:  Ressources Humaines (HR)";
                cout<<"\n\t\t\t\t\t------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t ENTER   2:   employe";
                cout<<"\n\t\t\t\t\t------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t ENTER   3:   Quitter";
                cout<<"\n\t\t\t\t\t------------------------------------------------";
                cout<<"\n\t\t\t\t\t\t  Please Enter Your Choice: ";
    cin >> choixPrincipal;

    switch (choixPrincipal) {
        case 1:
            if (M.Login()) {
               M.ShowMenu();
            }
            break;
            case 2:
               h.Login();
            break;
        case 3:
            cout << "Au revoir!\n";
            break;
        default:
            cout << "Option non valide. Veuillez reessayer.\n";
    }

    // Ajoutez une ligne vide pour espacer les menus
    cout << endl;

} while (choixPrincipal >3 || choixPrincipal<0);

    return 0;
}
