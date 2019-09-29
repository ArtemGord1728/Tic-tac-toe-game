#pragma once
#include <iostream>
#include "Net.h"
#include "Neuron.h"

class GameAgent
{
public:
	void start();
	void select_figure();
	void step();
};