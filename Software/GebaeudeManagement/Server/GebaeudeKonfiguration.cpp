#include "GebaeudeKonfiguration.h"
#include "Raum.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <list>
#include <iterator>

using namespace std;


GebaeudeKonfiguration* GebaeudeKonfiguration::GebKonfig = nullptr;
GebaeudeKonfiguration::GebaeudeKonfiguration() {}

GebaeudeKonfiguration* GebaeudeKonfiguration::getInstance()
{
	if (GebKonfig == nullptr)
	{
		GebKonfig = new GebaeudeKonfiguration();
	}
	return GebKonfig;
}

void /* std::list<Raum>raumListe */ GebaeudeKonfiguration::init() {
	ifstream rdat("Raeume.dat");
	//rdat.open("Raeume.dat");

	int rnr; // Raumnummer
	std::string rname; // Raumname;
	
	while (!rdat.fail())
	{
		rdat >> rnr;
		rdat >> rname;
		raumByNr[rnr] = rname;
	}
	rdat.close();

	std::list<Raum>::iterator it = GebaeudeKonfiguration::raumListe.begin();

	for (int i = 1; i <= (int)raumByNr.size(); i++)
	{
		Raum newRoom(i, raumByNr[i]);
		GebaeudeKonfiguration::raumListe.push_back(newRoom);
		
		// Advance the iterator by 2 positions,
		// advance(it, i + 1);
		//++it;
	}

	return;
	// return GebaeudeKonfiguration::raumListe
}



Raum* GebaeudeKonfiguration::RaumNummer(int rnr) {

	string verantw = raumByNr[rnr];
	
	Raum* R = new Raum(rnr, verantw);
	return R;
}

