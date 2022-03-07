#pragma once
#include "Component.h"
#include <Vector2.h>
#include "MoveComponent.h"

class WanderComponent :
	public Component
{
public:
	WanderComponent(const char* name = "WanderComponent") : Component::Component(name){}
	WanderComponent(Actor* agent, int point, MoveComponent* movecomponent, const char* name = "WanderComponent");

	void update(float deltaTime) override;

private:
	Actor* m_agent;
	int m_point;
	MoveComponent* m_movecomponent;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_steeringForce;
	MathLibrary::Vector2 m_currentVelocity;
	float m_seekForce = 86;
};

