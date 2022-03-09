#include "FleeComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "Agent.h"

MathLibrary::Vector2 FleeComponent::calculateForce()
{
	if (!getTarget())
	{
		return { 0,0 };
	}

	setSteeringForce(500);

	MathLibrary::Vector2 directionToTarget = getOwner()->getTransform()->getWorldPosition() - getTarget()->getTransform()->getWorldPosition();

	MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
	MathLibrary::Vector2 fleeForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return fleeForce;
}
