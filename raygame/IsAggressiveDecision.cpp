#include "IsAggressiveDecision.h"
#include "Enemy.h"

bool IsAggressiveDecision::checkCondition(Agent* agent, float deltaTime)
{
	Enemy* enemy = dynamic_cast<Enemy*>(agent);

	if (enemy)
	{
		return enemy->getIsAggressive();
	}
	
	return false;
}
