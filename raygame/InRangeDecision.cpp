#include "InRangeDecision.h"
#include "Enemy.h"

bool InRangeDecision::checkCondition(Agent* agent, float deltaTime)
{
	Enemy* enemy = dynamic_cast<Enemy*>(agent);
	if (enemy)
	{
		return enemy->getTargetInSight();
	}

	return false;
}
