#pragma once
#include "Decision.h"

class WanderDecision :
	public Decision
{
	void makeDecision(Agent* agent, float deltaTime) override;
};

