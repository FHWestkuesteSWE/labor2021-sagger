#include "GebaeudeKonfiguration.h"
#include "Raum.h"
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "Server.h"


bool GebaeudeKonfiguration::instanceFlag = false;
GebaeudeKonfiguration* GebaeudeKonfiguration::GebKonfig = NULL;

GebaeudeKonfiguration* GebaeudeKonfiguration::getInstance()
{
	if (!instanceFlag)
	{
		GebKonfig = new GebaeudeKonfiguration();
		instanceFlag = true;
		return GebKonfig;
	}
	else
	{
		return GebKonfig;
	}

}

GebaeudeKonfiguration* GebaeudeKonfiguration::mapping()
{
	map<int, Raum*>mapRaeume();
	// mapRaeume.insert(make_pair(1, Server::R1));
	return 0;
}