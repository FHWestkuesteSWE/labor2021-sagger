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



	BasicServer::start(port);

}

void Server::processRequest(char req[], char ans[]) {
	strncpy(ans, req, std::min<int>(1024, strlen(ans) + 1));
}

Server::~Server()
{
}


