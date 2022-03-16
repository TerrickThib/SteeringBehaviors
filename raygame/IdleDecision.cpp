#include "IdleDecision.h"
#include "WanderComponent.h"
#include "SeekComponent.h"
#include "Agent.h"

void IdleDecision::makeDecision(Agent* agent, float deltaTime)
{
	WanderComponent* wander = agent->getComponent<WanderComponent>();

	if (wander)
		wander->setSteeringForce(0);

	SeekComponent* seek = agent->getComponent<SeekComponent>();

	if (seek)
		seek->setSteeringForce(0);
}
