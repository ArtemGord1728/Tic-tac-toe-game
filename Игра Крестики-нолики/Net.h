#pragma once

struct Connection
{
	double weight;
	double delta;
};

class Net
{
public:
	void backPropogation();
};