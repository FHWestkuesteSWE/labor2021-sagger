#include "Server.h"
#include "Raum.h"
#include <iostream>
#include <list>

using namespace std;

int main(int argc, char* argv[]) {
	Server s;

	s.start(argv[1]); // Server starten
	

	return 0;
}