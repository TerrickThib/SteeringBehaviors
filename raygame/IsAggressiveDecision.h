#pragma once
#include "BooleanDecision.h"
class IsAggressiveDecision :
	public BooleanDecision
{
public:
	IsAggressiveDecision(Decision* left = nullptr, Decision* right = nullptr) : BooleanDecision(left, right) {};
	bool checkCondition(Agent* agent, float deltaTime) override;
};

