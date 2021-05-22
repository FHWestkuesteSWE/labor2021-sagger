#pragma once
#include <string>
#include "TempSensor.h"
using namespace std;

class Raum
{
	public: 
		int rnr;
		string verantw;
		TempSensor tempSensor; 

		string getVerantw();
		void setVerantw(string req);
		int getRnr();

		Raum(int nr = 0, string verantw = "");

};

