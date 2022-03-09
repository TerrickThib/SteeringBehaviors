#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>
#include "MoveComponent.h"

class WanderComponent :
	public SteeringComponent
{
public:
	WanderComponent(float circleDistance, float circleRadius, float wanderForce);
	MathLibrary::Vector2 calculateForce() override;

private:
	float m_circleDistance = 0;
	float m_circleRadius = 0;
	float m_wanderAngle = 0;

	MathLibrary::Vector2 m_target;//Makes m_target a vector 2
	MathLibrary::Vector2 m_circlePos;
};

