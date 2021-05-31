#pragma once
#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>
#include <iterator>

using namespace std;

class GebaeudeKonfiguration
{
private:
	static GebaeudeKonfiguration* GebKonfig;
	static bool instanceFlag;

	GebaeudeKonfiguration()
	{
		// private constructor
	}

public:
	static GebaeudeKonfiguration* getInstance();
	static GebaeudeKonfiguration* mapping();


	~GebaeudeKonfiguration()
	{
		// deconstructor
		instanceFlag = false;
	}

};

