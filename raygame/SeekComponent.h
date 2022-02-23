#pragma once
#include "Component.h"
#include <Vector2.h>
#include "MoveComponent.h"

class SeekComponent :
	public Component
{
public:
	SeekComponent(const char* name = "SeekComponent"): Component::Component(name){}
	SeekComponent(Actor* agent,Actor* target, MoveComponent* movecomponent, const char* name = "SeekComponent");

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

