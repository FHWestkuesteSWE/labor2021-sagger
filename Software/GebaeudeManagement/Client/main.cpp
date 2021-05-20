// main.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Client.h"

using namespace std;
int main(int argc, char* argv[])
{



    Client c(argv[1], argv[2]);
    char req[1024];
    char ans[1024];
    char wahl;
    do {
        std::cout << "Gebaeedeleitsystem digitales Testgebaude\n"<<endl;
        cout << "Welchen Raum wollen sie auswaehlen?" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Bitte geben sie die Raumnummer an \t" << endl;
        cout << "Beenden \t\t\t\t(0)" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Ihre Wahl: ";
        cin >> wahl;
       
        strncpy_s(req, &wahl, 1);
   
        c.sendRequest(req, ans);
        cout << " fuer Raum " << wahl << " liegen die nachfolgenden Daten vor: " << endl;
        
        cout << ans << endl;
        
        /*switch (wahl) {
        case 't': // req zusammenbauen
            strncpy_s(req, "get Temp", 10);
            c.sendRequest(req, ans);
            
            cout << ans;
            break;
        default:;*/

        //}
    } while (wahl ==0 );
}

