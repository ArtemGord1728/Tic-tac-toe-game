#include "Neuron.h"

double Neuron::activation(std::vector<double> inputs, std::vector<double> weights) {
	activationResult_ = 0.0;

	for (size_t i = 0; i < inputs.size(); i++)
	{
		activationResult_ = inputs[i] * weights[i];
	}
	activationResult_ += biasWeight_;

	return activationResult_;
}

double Neuron::computeErrorMSE(double resSigmoid) {
	return pow((1 - resSigmoid) / 1, 2);
}

double Neuron::getActivationResult() {
	return activationResult_; 
}