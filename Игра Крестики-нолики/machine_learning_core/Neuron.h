#pragma once
#include <cmath>
#include <vector>

class Neuron
{
public:
	double activation(std::vector<double> inputs, std::vector<double> weights);
	double getActivationResult();
	double computeErrorMSE(double resSigmoid);
private:
	double error_;
	double biasWeight_;
	double activationResult_;
	const double momentum_;
	const double learning_rate_;
};