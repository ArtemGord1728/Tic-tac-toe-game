#pragma once


class Net
{
public:
	void backPropogation();
	double updateWeights();
	double errorMSE();
};