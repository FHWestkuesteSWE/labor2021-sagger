#pragma once
#include "BasicServer.h"
#include "Raum.h"
#include <list>
class Server : public BasicServer
{
public:
	void start(char port[]);
	Server();
	~Server();

	/* Vor dem Serverstart Initialisierung der R�ume*/
	Raum R1, R2, R3, R4, R5, R6, R7, R8, R9, R10;

	/* Liste mit allen R�umen erstellen*/
	list<Raum> Raumliste = { R1, R2, R3, R4, R5, R6, R7, R8, R9, R10 };

// protected:
	virtual void processRequest(char request[], char answer[]);
};

