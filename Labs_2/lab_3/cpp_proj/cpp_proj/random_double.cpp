#include "random_double.h"


double random_double(double min, double max)
{
	double random = min + (max - min) * (double)rand() / RAND_MAX;
	return random;
}
