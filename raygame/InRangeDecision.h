#pragma once
#include "BooleanDecision.h"

class InRangeDecision :
	public BooleanDecision
{
public:
	InRangeDecision(Decision* left = nullptr, Decision* right = nullptr) : BooleanDecision(left, right) {};
	bool checkCondition(Agent* agent, float deltaTime) override;
};

