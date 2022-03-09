#pragma once
#include "Component.h"
#include <Vector2.h>
#include "SteeringComponent.h"

class SeekComponent :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;
};

