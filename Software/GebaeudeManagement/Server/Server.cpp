#define _CRT_SECURE_NO_WARNINGS
#include "Server.h"
#include <string.h>
#include <algorithm>
#include "Raum.h"

Server::Server()
{
	
}


void Server::start(char port[]) {
		
	BasicServer::start(port);
	
}

void Server::processRequest(char req[], char ans[]) {
	

	Raum* R1 = new Raum(1, "Laura Gersmeier");
	Raum* R2 = new Raum(2, "Eike Sagasser");
	Raum* R3 = new Raum(3, "Hans Meier");
	Raum* R4 = new Raum(4, "Hannelore Mais");
	Raum* R5 = new Raum(5, "Ernst Kuzorra");
	Raum* R6 = new Raum(6, "Ernst Kuzorra");
	Raum* R7 = new Raum(7, "Ernst Kuzorra");
	Raum* R8 = new Raum(8, "Ernst Kuzorra");
	Raum* R9 = new Raum(9, "Ernst Kuzorra");
	
	
	char * test = new char[R1->verantw.length()+1];
	strcpy(test, R1->verantw.c_str());

	strncpy(ans, test, std::min<int>(1024, strlen(ans) + 1));

}

Server::~Server()
{
}


