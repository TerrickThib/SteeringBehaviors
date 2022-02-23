#pragma once
#include "Component.h"
#include <Vector2.h>
#include "MoveComponent.h"

class FleeComponent :
	public Component
{
public:
	FleeComponent(const char* name = "FleeComponent") : Component::Component(name) {}
	FleeComponent(Actor* agent, Actor* target, MoveComponent* movecomponent, const char* name = "FleeComponent");

	void update(float deltaTime) override;

private:
	Actor* m_agent;
	Actor* m_target;
	MoveComponent* m_movecomponent;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_steeringForce;
	MathLibrary::Vector2 m_currentVelocity;

	float m_seekForce = 86;
};

