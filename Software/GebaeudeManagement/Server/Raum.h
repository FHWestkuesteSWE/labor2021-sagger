#pragma once
#include <string>
using namespace std;

class Raum
{
	public: 
		int rnr;
		string verantw;

		string getVerantw();
		bool setVerantw(int raumNr, string verantw);
		int getRnr();

		Raum(int nr = 0, string verantw = "");

};

