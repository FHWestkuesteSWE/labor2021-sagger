#pragma once
#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>
#include <iterator>
#include <map>
#include <list>
#include "Raum.h"

using namespace std;

class GebaeudeKonfiguration
{
private:
	static GebaeudeKonfiguration* GebKonfig;
	

	GebaeudeKonfiguration(); // privater Konstruktor

	std::map<int, std::string> raumByNr; // Mapping-Funktion

public:
	std::list<Raum> raumListe;
	Raum* /*std::string*/ RaumNummer(int rnr);
	static GebaeudeKonfiguration* getInstance();
	void init();
	

	~GebaeudeKonfiguration()
	{
	
	}

};

