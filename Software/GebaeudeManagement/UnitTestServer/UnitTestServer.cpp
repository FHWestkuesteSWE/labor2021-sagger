#include "pch.h"
#include "CppUnitTest.h"
#include "GebaeudeKonfiguration.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestServer
{
	TEST_CLASS(UnitTestServer)
	{
	public:				
		TEST_METHOD(TestRaumNummer)
		{
			GebaeudeKonfiguration* gebKonfig = GebaeudeKonfiguration::getInstance();
			gebKonfig->init();

			std::list<Raum>::iterator it = gebKonfig->raumListe.begin();

			// Advance the iterator by 2 positions,
			std::advance(it, 2);

			Assert::AreEqual(3,it->rnr);
		}
		
	

		TEST_METHOD(TestRaumVerantwortlicher)
		{
			GebaeudeKonfiguration* gebKonfig = GebaeudeKonfiguration::getInstance();
			gebKonfig->init();

			std::list<Raum>::iterator it = gebKonfig->raumListe.begin();

			// Advance the iterator by 5 positions,
			std::advance(it, 5);

			Assert::AreEqual((std::string)"Heinz", it->verantw);

		}			
		
	};
}
