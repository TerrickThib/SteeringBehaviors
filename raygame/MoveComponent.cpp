#include "MoveComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "Engine.h"

void MoveComponent::update(float deltaTime)
{
	//Add the new velocity to the old position to get the new position
	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getLocalPosition() + getVelocity() * deltaTime;

	//Allowes the players sprite to change based on movement
	MathLibrary::Vector2 forwardDirection = getVelocity().getNormalized();

	if (getUpdateFacing() && getVelocity().getMagnitude() > 0)
		getOwner()->getTransform()->setForward(getVelocity().getNormalized());

	if (newPosition.x > Engine::getScreenWidth())
		newPosition.x = 0;
	else if (newPosition.x < 0)
		newPosition.x = Engine::getScreenWidth();

	if (newPosition.y > Engine::getScreenHeight())
		newPosition.y = 0;
	else if (newPosition.y < 0)
		newPosition.y = Engine::getScreenHeight();

	//Set the actors position to be the new position found
	getOwner()->getTransform()->setLocalPosition(newPosition);
}