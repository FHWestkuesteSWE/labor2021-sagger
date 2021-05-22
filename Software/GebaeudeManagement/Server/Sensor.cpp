#include "Sensor.h"
# include <random>
#include <iomanip>

using namespace std;

constexpr int FLOAT_MIN = 10;
constexpr int FLOAT_MAX = 100;

using std::setprecision;

float getValue(int nr)
{

	random_device rd;
	default_random_engine eng(rd());
	uniform_real_distribution<> distr(FLOAT_MIN, FLOAT_MAX);

	constexpr float MIN = 15.0;
	constexpr float MAX = 30.0;

	setprecision(3);

	return  distr(eng);
}