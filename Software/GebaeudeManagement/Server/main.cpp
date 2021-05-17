#include "Server.h"
#include "Raum.h"
#include <iostream>
#include <list>

using namespace std;

int main(int argc, char* argv[]) {
	Server s;
	int Raumnummer = 0;


	s.start(argv[1]); // Server starten



	list <Raum>::iterator iter;

	int listGröße = s.Raumliste.size();
	for (iter = s.Raumliste.begin(); iter!= s.Raumliste.end(); ++iter)
	{
		if (Raumnummer == iter->getRnr())
		{
			iter->getVerantw();
		}
	}

	
	return 0;

}