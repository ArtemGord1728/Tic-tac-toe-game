#include "Neuron.h"

double Neuron::activationFunction(double& val) {
	return 1 / 1 + abs(val);
}