#pragma once
#include "BasicServer.h"
#include "Raum.h"
#include <list>
#include "GebaeudeKonfiguration.h"

class Server : public BasicServer
{
public:
	void start(char port[]);
	Server();
	~Server();

	
	
	// Vor dem Serverstart Initialisierung der Räume
	
	/*
		Raum* R1 = new Raum(1, "Laura Gersmeier");
		Raum* R2 = new Raum(2, "Eike Sagasser");
		Raum* R3 = new Raum(3, "Hans Meier");
		Raum* R4 = new Raum(4, "Hannelore Mais");
		Raum* R5 = new Raum(5, "Ernst Kuzorra");
		Raum* R6 = new Raum(6, "Heinz Tomate");
		Raum* R7 = new Raum(7, "Ulla Richter");
		Raum* R8 = new Raum(8, "Werner Hausmann");
		Raum* R9 = new Raum(9, "Erna Kunze");
	*/
		
	
	
	

// protected:
	virtual void processRequest(char request[], char answer[]);

	
};

