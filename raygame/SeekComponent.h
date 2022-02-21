#pragma once
#include "Component.h"
#include <Vector2.h>

class SeekComponent :
	public Component
{
public:

	SeekComponent(Actor m_agent, const char m_target);

private:
	int m_target;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_steeringForce;
	MathLibrary::Vector2 m_velocity;
};

