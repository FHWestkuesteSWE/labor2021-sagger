#include "Raum.h"

Raum::Raum(int nr, string verant) {
	rnr = nr;
	verantw = verant;
}

string Raum::getVerantw() {
	return verantw;
}


bool Raum::setVerantw(int raumNr, string verantw) {
	return false;
}

int Raum::getRnr()
{
	return rnr;
}
