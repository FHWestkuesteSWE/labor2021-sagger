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
        cout << "Fuer Raum " << wahl << " liegen die nachfolgenden Daten vor: " << endl;
        
        cout << "Raumverantwortlicher: " << ans << endl;

        cout << "Was wollen Sie tun?" << endl;
        cout << "1. Raumverantwortlichen aendern? (v)" << endl;
        
        cin >> wahl; 
        switch (wahl)
        {
        case 'v':

                req[1] = wahl;
                //strncpy_s(req, &wahl, 1);
                cout << endl<< "geben sie einen neuen verantwortlichen ein:" << endl;
                string vant;
                cin >> vant;
                for (int i=2 ; i<vant.length()+2; i++)
                {
                    req[i] = vant[i - 2];
                }
                c.sendRequest(req, ans);
                cout << "Raumverantwortlicher: " << ans << endl;
                break;



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

