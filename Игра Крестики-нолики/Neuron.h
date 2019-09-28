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
	double activationFunction(double value);
	double neuronBias(double weight);
	double summator();
private:
	const double momentum;
	const double learning_rate;
};