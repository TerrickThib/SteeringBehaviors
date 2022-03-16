#pragma once
#include "Component.h"

class Decision;
class Agent;

class DecisionComponent :
	public Component
{
public:
	DecisionComponent(Decision* root) { m_root = root; }
	void start() override;
	void update(float deltaTime) override;

private:
	Decision* m_root;
	Agent* m_owner;
};

