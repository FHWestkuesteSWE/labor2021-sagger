#include "Sensor.h"
# include <random>
#include <iomanip>
#include <boost/random.hpp>

using namespace std;

constexpr int FLOAT_MIN = 15;
constexpr int FLOAT_MAX = 30;

using std::setprecision;


float Sensor::getValue()
{
	random_device rd;
	default_random_engine eng(rd());
	uniform_real_distribution<> distr(FLOAT_MIN, FLOAT_MAX);
	
	return  distr(eng);
	
	


	
}