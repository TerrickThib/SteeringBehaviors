#pragma once
#include "Component.h"
#include <Vector2.h>
#include "MoveComponent.h"
#include "SteeringComponent.h"

class FleeComponent :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;
};


