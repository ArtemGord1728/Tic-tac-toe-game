#pragma once
#include <iostream>
#include "Net.h"
#include "Neuron.h"

class GameAgent
{
public:
	void start(const char figure);
	void select_figure();
	void step();
};