#include "Neuron.h"

double Neuron::activationFunction(double val) {
	return 1 / 1 + abs(val);
}

double Neuron::neuronBias(double weight) {
	return activationFunction(0.0) + weight;
}

double Neuron::summator() {
	return 0.0;
}