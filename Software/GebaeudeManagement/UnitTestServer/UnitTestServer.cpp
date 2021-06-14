#include "pch.h"
#include "CppUnitTest.h"
#include "GebaeudeKonfiguration.h"
#include "Sensor.h"

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

			// Advance the iterator by 4 positions,
			std::advance(it, 4);

			Assert::AreEqual(5,it->rnr);
		}
		
	

		TEST_METHOD(TestRaumVerantwortlicher)
		{
			GebaeudeKonfiguration* gebKonfig = GebaeudeKonfiguration::getInstance();
			gebKonfig->init();

			std::list<Raum>::iterator it = gebKonfig->raumListe.begin();

			// Advance the iterator by 6 positions,
			std::advance(it, 6);

			Assert::AreEqual((std::string)"Ulla", it->verantw);

		}	

		TEST_METHOD(TestRaumTemperatur)
		{
			Sensor s;
			float rTemp = s.getValue();
			constexpr float FLOAT_MIN = 15.0;
			constexpr float FLOAT_MAX = 30.0;

			bool rTempGT15ST30 = (rTemp >= FLOAT_MIN) && (rTemp <= FLOAT_MAX);

			Assert::IsTrue(rTempGT15ST30);

		}
		
	};
}
