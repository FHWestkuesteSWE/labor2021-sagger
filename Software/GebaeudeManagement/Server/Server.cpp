#define _CRT_SECURE_NO_WARNINGS
#include "Server.h"
#include <string.h>
#include <algorithm>
#include "Raum.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "GebaeudeKonfiguration.h"



Server::Server()
{
	
	
}


void Server::start(char port[]) {

	GebaeudeKonfiguration* gebKonfig = GebaeudeKonfiguration::getInstance();
	gebKonfig->init();
		
	BasicServer::start(port);

	
	

	
	/*
	string filename;
	cout << "Datei: ";
	cin >> filename;

	ifstream input(filename);

	if (!input)
	{
		std::cerr << "Datei beim Oeffnen der Datei " << filename << "\n";
		
	}

	std::string line;

	while (std::getline(input, line))
	{
		std::cout << line << '\n';
	}
	
	
	*/
	



}

void Server::processRequest(char req[], char ans[]) {

	char* test;
	char* cTemp;
	float rTemp;
	string sTemp /*= to_string(rTemp)*/;
	stringstream ss;
	

	std::list<Raum>::iterator iter =  GebaeudeKonfiguration::getInstance()->raumListe.begin();
	for (int i = 0; i <= (int) GebaeudeKonfiguration::getInstance()->raumListe.size(); i++)
	{
		int i_req = 0;
		sscanf(req, "%d", &i_req);


		if (i_req == iter->rnr)
		{
			test = new char[iter->verantw.length() + 1];
			strcpy(test, iter->getVerantw().c_str());
			strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			if (req[4] == 'v')
			{
				iter->setVerantw(req);
				test = new char[iter->verantw.length() + 1];
				strcpy(test, iter->getVerantw().c_str());
				strncpy(ans, test, std::min<int>(1024, strlen(test) + 1));
			}
			else if(req[4] == 't')
			{
				rTemp = iter->tempSensor.getValue();
				ss << setprecision(3) << rTemp;
				sTemp = ss.str();
				cTemp = new char[sTemp.length() + 1];
				strcpy(cTemp, sTemp.c_str());
				strncpy(ans, cTemp, std::min<int>(1024, strlen(cTemp) + 1));
			}
			else
			{
				//;
			}
		}

		if (i < (int)GebaeudeKonfiguration::getInstance()->raumListe.size() - 1)
		{
			// Advance the iterator by 4 positions,
			std::advance(iter, 1);
		}
		


		//it++;
	}

/*

	switch (req[0])
	{
		// Raumverantwortlicher ausgeben
		case '1': 
			test = new char[R1->verantw.length() + 1];
			strcpy(test, R1->getVerantw().c_str());
			strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			if (req[1] == 'v')
			{				
				R1->setVerantw(req);
				test = new char[R1->verantw.length() + 1];
				strcpy(test, R1->getVerantw().c_str());
				strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			}
			else
			{
				if (req[1] == 't')
				{
					rTemp = R1->tempSensor.getValue();
					ss << setprecision(3) << rTemp;
					sTemp = ss.str();
					cTemp = new char[sTemp.length() + 1];
					strcpy(cTemp, sTemp.c_str());
					strncpy(ans, cTemp, std::min<int>(1024, strlen(ans) + 1));

					
					
				}
				else
				{
					;
				}
			}
				
			break;

		case '2':
			test = new char[R2->verantw.length() + 1];
			strcpy(test, R2->getVerantw().c_str());
			strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			if (req[1] == 'v')
			{				
				R2->setVerantw(req);
				test = new char[R2->verantw.length() + 1];
				strcpy(test, R2->getVerantw().c_str());
				strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			}
			else
			{
				if (req[1] == 't')
				{
					rTemp = R2->tempSensor.getValue();
					ss << setprecision(3) << rTemp;
					sTemp = ss.str();
					cTemp = new char[sTemp.length() + 1];
					strcpy(cTemp, sTemp.c_str());
					strncpy(ans, cTemp, std::min<int>(1024, strlen(ans) + 1));



				}
				else
				{
					;
				}
			}
				
			break;

		case '3':
			test = new char[R3->verantw.length() + 1];
			strcpy(test, R3->getVerantw().c_str());
			strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			if (req[1] == 'v')
			{				
				R3->setVerantw(req);
				test = new char[R3->verantw.length() + 1];
				strcpy(test, R3->getVerantw().c_str());
				strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			}
			else
			{
				if (req[1] == 't')
				{
					rTemp = R3->tempSensor.getValue();
					ss << setprecision(3) << rTemp;
					sTemp = ss.str();
					cTemp = new char[sTemp.length() + 1];
					strcpy(cTemp, sTemp.c_str());
					strncpy(ans, cTemp, std::min<int>(1024, strlen(ans) + 1));



				}
				else
				{
					;
				}
			}
				
			break;

		case '4': 
			test = new char[R4->verantw.length() + 1];
			strcpy(test, R4->getVerantw().c_str());
			strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			if (req[1] == 'v')
			{				
				R4->setVerantw(req);
				test = new char[R4->verantw.length() + 1];
				strcpy(test, R4->getVerantw().c_str());
				strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			}
			else
			{
				if (req[1] == 't')
				{
					rTemp = R4->tempSensor.getValue();
					ss << setprecision(3) << rTemp;
					sTemp = ss.str();
					cTemp = new char[sTemp.length() + 1];
					strcpy(cTemp, sTemp.c_str());
					strncpy(ans, cTemp, std::min<int>(1024, strlen(ans) + 1));



				}
				else
				{
					;
				}
			}
			break;

		case '5':
			test = new char[R5->verantw.length() + 1];
			strcpy(test, R5->getVerantw().c_str());
			strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			if (req[1] == 'v')
			{				
				R5->setVerantw(req);
				test = new char[R5->verantw.length() + 1];
				strcpy(test, R5->getVerantw().c_str());
				strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			}
			else
			{
				if (req[1] == 't')
				{
					rTemp = R5->tempSensor.getValue();
					ss << setprecision(3) << rTemp;
					sTemp = ss.str();
					cTemp = new char[sTemp.length() + 1];
					strcpy(cTemp, sTemp.c_str());
					strncpy(ans, cTemp, std::min<int>(1024, strlen(ans) + 1));



				}
				else
				{
					;
				}
			}
				
			break;

		case '6':
			test = new char[R6->verantw.length() + 1];
			strcpy(test, R6->getVerantw().c_str());
			strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			if (req[1] == 'v')
			{				
				R6->setVerantw(req);
				test = new char[R6->verantw.length() + 1];
				strcpy(test, R6->getVerantw().c_str());
				strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			}
			else
			{
				if (req[1] == 't')
				{
					rTemp = R6->tempSensor.getValue();
					ss << setprecision(3) << rTemp;
					sTemp = ss.str();
					cTemp = new char[sTemp.length() + 1];
					strcpy(cTemp, sTemp.c_str());
					strncpy(ans, cTemp, std::min<int>(1024, strlen(ans) + 1));



				}
				else
				{
					;
				}
			}
				
			break;

		case '7':
			test = new char[R7->verantw.length() + 1];
			strcpy(test, R7->getVerantw().c_str());
			strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			if (req[1] == 'v')
			{
				R7->setVerantw(req);
				test = new char[R7->verantw.length() + 1];
				strcpy(test, R7->getVerantw().c_str());
				strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			}
			else
			{
				if (req[1] == 't')
				{
					rTemp = R7->tempSensor.getValue();
					ss << setprecision(3) << rTemp;
					sTemp = ss.str();
					cTemp = new char[sTemp.length() + 1];
					strcpy(cTemp, sTemp.c_str());
					strncpy(ans, cTemp, std::min<int>(1024, strlen(ans) + 1));



				}
				else
				{
					;
				
				}
			}
			break;

		case '8':
			test = new char[R8->verantw.length() + 1];
			strcpy(test, R8->getVerantw().c_str());
			strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			if (req[1] == 'v') {
				R8->setVerantw(req);
				test = new char[R8->verantw.length() + 1];
				strcpy(test, R8->getVerantw().c_str());
				strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			}
			else
			{
				if (req[1] == 't')
				{
					rTemp = R8->tempSensor.getValue();
					ss << setprecision(3) << rTemp;
					sTemp = ss.str();
					cTemp = new char[sTemp.length() + 1];
					strcpy(cTemp, sTemp.c_str());
					strncpy(ans, cTemp, std::min<int>(1024, strlen(ans) + 1));



				}
				else
				{
					;
				}
			}
			break;

		case '9':
			test = new char[R9->verantw.length() + 1];
			strcpy(test, R9->getVerantw().c_str());
			strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			if (req[1] == 'v')
			{

				R9->setVerantw(req);
				test = new char[R9->verantw.length() + 1];
				strcpy(test, R9->getVerantw().c_str());
				strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
			}
			else
			{
				if (req[1] == 't')
				{
					rTemp = R9->tempSensor.getValue();
					ss << setprecision(3) << rTemp;
					sTemp = ss.str();
					cTemp = new char[sTemp.length() + 1];
					strcpy(cTemp, sTemp.c_str());
					strncpy(ans, cTemp, std::min<int>(1024, strlen(ans) + 1));



				}
				else
				{
					;
				}
			}
			break;

		default:
			test = new char[15];
			strcpy(test, "Raum existiert nicht");
			strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
	}

	*/
}

Server::~Server()
{
}


