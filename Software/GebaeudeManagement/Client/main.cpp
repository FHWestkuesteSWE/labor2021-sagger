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
        cout << endl;
        if (wahl != 0)
        {
            switch (wahl) {
            case '1': // req zusammenbauen
                strncpy_s(req, "1", 1);
                c.sendRequest(req, ans);
                cout << req << endl;
                cout << ans << endl;
                break;
            default: cout << req;
            }
        }
            //req zusammenbauen
            //sprintf_s(char_wahl, "%c", wahl );
            //strcpy_s(req, char_wahl[0],char_wahl[1]);
            //req[0] = char_wahl[0];
            //req[1] = char_wahl[1];
            
            /*strcpy_s(req, wahl, 1);
            cout << req;
            
            c.sendRequest(req, ans);
            cout << " fuer den Folgenden Raum liegen die nachfolgenden Daten vor " << endl;
           
            cout << ans << endl;
        }
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

