#include "Raum.h"

Raum::Raum(int nr, string verant) {
	rnr = nr;
	verantw = verant;
}

string Raum::getVerantw() {
	return verantw;
}


void Raum::setVerantw(string req) {
	this->verantw = "";
	for (int i = 5; i < req.length()+1; i++)
	{
		if (req[i] != NULL)
		{
			this->verantw = this->verantw + req[i];
		}
		else
		{
			break;
		}
	}
}

int Raum::getRnr()
{
	return rnr;
}
