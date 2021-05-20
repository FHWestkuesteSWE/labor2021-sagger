#define _CRT_SECURE_NO_WARNINGS
#include "Server.h"
#include <string.h>
#include <algorithm>
#include "Raum.h"

Server::Server()
{
	
}


void Server::start(char port[]) {
	/* Initialisierung der Räume*/

	
	
	

	
	BasicServer::start(port);

}

void Server::processRequest(char req[], char ans[]) {
	
	char test[15];

	Raum* R1 = new Raum(1, "Laura Gersmeier");
	Raum* R2 = new Raum(2, "Eike Sagasser");
	Raum* R3 = new Raum(3, "Hans Meier");
	Raum* R4 = new Raum(4, "Hannelore Mais");
	Raum* R5 = new Raum(5, "Ernst Kuzorra");
	Raum* R6 = new Raum(6, "Ernst Kuzorra");
	Raum* R7 = new Raum(7, "Ernst Kuzorra");
	Raum* R8 = new Raum(8, "Ernst Kuzorra");
	Raum* R9 = new Raum(9, "Ernst Kuzorra");
	
	/*
	Raum R1(1, "Laura Gersmeier");
	Raum R2(2, "Eike Sagasser");
	Raum R3(3, "Hans Meier");
	Raum R4(4, "Hannelore Mais");
	Raum R5(5, "Ernst Kuzorra");
	Raum R6(6, "Ernst Kuzorra");
	Raum R7(7, "Ernst Kuzorra");
	Raum R8(8, "Ernst Kuzorra");
	Raum R9(9, "Ernst Kuzorra");
	Raum R10(10, "Ernst Kuzorra");
	*/

	// list <Raum> Raumliste = { R1, R2, R3, R4, R5, R6, R7, R8, R9, R10 };

	size_t size = 11;

	// strncpy(ans, req, std::min<int>(1024, strlen(ans) + 1));
	
	/*
	req[0] = 'L';
	req[1] = 'a';
	req[2] = 'u';
	req[3] = 'r';

	for (int i = 4; i <= 10; i++)
	{
		req[i] = 's';
	}

	// strncpy(ans, req, std::min<int>(1024, size));
	*/
	
	switch (req[0])
	{
		// geht hier nicht rein!!!!
		case '1':
			
			for (int i = 0; i <= 15; i++)
			{
				test[i] = R1->verantw.at(i);
			}

			strncpy(ans, test, 16);

		default: 
			
			
			req[0] = 'e';
			strncpy(ans, req, std::min<int>(1024, size));
			
			
	}
	
}

Server::~Server()
{
}


