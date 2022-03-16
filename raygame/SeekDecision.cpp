#include "SeekDecision.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "Agent.h"
#include "Enemy.h"

void SeekDecision::makeDecision(Agent* agent, float deltaTime)
{
	SeekComponent* seek = agent->getComponent<SeekComponent>();
	Enemy* enemy = dynamic_cast<Enemy*>(agent);
	WanderComponent* wander = agent->getComponent<WanderComponent>();

	if (seek)
	{
		seek->setSteeringForce(52);
	}

	if (enemy)
		enemy->setIsAggressive(true);

	if (wander)
		wander->setSteeringForce(0);
}
