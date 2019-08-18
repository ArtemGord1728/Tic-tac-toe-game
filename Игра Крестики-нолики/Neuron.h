#pragma once
#include <cmath>

struct Connection
{
	double weight;
	double delta;
};

class Neuron
{
public:
	double activationFunction(double& value);
};