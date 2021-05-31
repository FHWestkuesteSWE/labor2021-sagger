// main.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Client.h"
#include <string>

using namespace std;
int main(int argc, char* argv[])
{



    Client c(argv[1], argv[2]);
    char req[1024];
    char ans[1024];
    char wahl;
    do {
        cout << "Gebaeedeleitsystem digitales Testgebaude\n"<<endl;
        cout << "Welchen Raum wollen sie auswaehlen?" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Bitte geben sie die Raumnummer an \t" << endl;
        cout << "Beenden \t\t\t\t(0)" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Ihre Wahl: ";
        cin >> wahl;
       
        if (wahl == '0')
        {
            break;
        }


        strncpy_s(req, &wahl, 1);
   
        c.sendRequest(req, ans);
        cout << "Fuer Raum " << wahl << " liegen die nachfolgenden Daten vor: " << endl;
        bool gleich = strcmp(ans, "Raum existiert nicht");
        if (!gleich)
        {
            // strings sind gleich -> Rückgabewert von strcmp false
            cout << ans << endl;
		}
        else
        {
            cout << "Raumverantwortlicher: " << ans << endl;

            cout << "Was wollen Sie tun?" << endl;
            cout << "1. Raumverantwortlichen aendern? (v)" << endl;
            cout << "2. Raumtemperatur anzeigen? (t)" << endl;

            cin >> wahl;

            string vant;
            switch (wahl)
            {
            case 'v':

                req[1] = wahl;
                //strncpy_s(req, &wahl, 1);
                cout << endl << "Geben Sie einen neuen Verantwortlichen ein:" << endl;
                
                getline(cin, vant);
                cin >> vant;

                for (int i = 2; i < sizeof(req); i++)
                {
                    req[i] = vant[i - 2];

                    if (i >= vant.length() + 2)
                    {
                        break;
                    }
                }
                c.sendRequest(req, ans);

                cout << "Raumverantwortlicher: " << ans << endl;
                break;

            case 't':
                req[1] = wahl;
                c.sendRequest(req, ans);
                cout << "Raumtemperatur: " << ans << endl;
                break;

            default:
                break;
            }
        }      
      
    } while (wahl != '0' );
}

