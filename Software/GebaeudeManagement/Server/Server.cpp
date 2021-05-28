#define _CRT_SECURE_NO_WARNINGS
#include "Server.h"
#include <string.h>
#include <algorithm>
#include "Raum.h"
#include <stdio.h>

Server::Server()
{
}


void Server::start(char port[]) {
		
	BasicServer::start(port);
}

void Server::processRequest(char req[], char ans[]) {

	char* test;

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
					float rTemp = R1->tempSensor.getValue();
					string sTemp = to_string(rTemp);
					char cTemp[sTemp.length() + 1];

					strcpy(cTemp, sTemp);
					strncpy(ans, cTemp, std::min<int>(1024, strlen(ans) + 1));
					
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
			break;

		default:
			test = new char[15];
			strcpy(test, "Raum existiert nicht");
			strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));
	}
}

Server::~Server()
{
}


