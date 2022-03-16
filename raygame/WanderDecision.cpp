#include "WanderDecision.h"
#include "WanderComponent.h"
#include "SeekComponent.h"
#include "Agent.h"

void WanderDecision::makeDecision(Agent* agent, float deltaTime)
{
	WanderComponent* wander = agent->getComponent<WanderComponent>();
	SeekComponent* seek = agent->getComponent<SeekComponent>();

	if (wander)
	{
		wander->setSteeringForce(100);
	}

	if (seek)
	{
		seek->setSteeringForce(0);
	}
}
