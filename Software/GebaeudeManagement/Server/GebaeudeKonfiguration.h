#pragma once
#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>
#include <list>
#include "Raum.h"

using namespace std;

class GebaeudeKonfiguration
{
public:
	static GebaeudeKonfiguration* getInstance();
	Raum* RaumNummer(int rnr);
	void init();

	std::list<Raum> raumListe;

	
	// ~GebaeudeKonfiguration() {};
	
	
private:
	static GebaeudeKonfiguration* GebKonfig;
	GebaeudeKonfiguration() /*{}*/; // privater Konstruktor
	// ~GebaeudeKonfiguration() {};
	std::map<int, std::string> raumByNr; // Mapping-Funktion

	
};

