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
    int wahl;
    char c_wahl;
    do {
        cout << "Gebaeedeleitsystem digitales Testgebaude\n"<<endl;
        cout << "Welchen Raum wollen sie auswaehlen?" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Bitte geben sie die Raumnummer an \t" << endl;
        cout << "Beenden \t\t\t\t(0)" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Ihre Wahl: ";
        cin >> wahl;
       
        if (wahl == 0|| wahl > 999)
        {
            break;
        }

        char cArray_wahl[4];
        sprintf_s(cArray_wahl, "%ld", wahl);

        //strncpy_s(req, &wahl, 1);
        strncpy_s(req, cArray_wahl, 4);
   
        for (int i = 0; i < sizeof(req); i++)
        { // Nullterminator '\0' gegen '\n' austauschen, sodass Request korrek an Server übertragen wird
            if (req[i] == '\0')
            {
                req[i] = '\n';
                break;
            }
        }

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

            cin >> c_wahl;

            string vant;
            switch (c_wahl)
            {
            case 'v':

                req[4] = c_wahl;
                //strncpy_s(req, &wahl, 1);
                cout << endl << "Geben Sie einen neuen Verantwortlichen ein:" << endl;
                
                getline(cin, vant);
                cin >> vant;

                for (int i = 5; i < sizeof(req); i++)
                {
                    req[i] = vant[i - 5];

                    if (i >= vant.length() + 5)
                    {
                        break;
                    }
                }
                c.sendRequest(req, ans);

                cout << "Raumverantwortlicher: " << ans << endl;
                break;

            case 't':
                req[4] = c_wahl;
                c.sendRequest(req, ans);
                cout << "Raumtemperatur: " << ans << endl;
                break;

            default:
                break;
            }
            // c.sendRequest(req, ans);
        }      
      
    } while (wahl != '0' );
}

