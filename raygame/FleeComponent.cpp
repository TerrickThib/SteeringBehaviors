#include "FleeComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "MoveComponent.h"

FleeComponent::FleeComponent(Actor* agent, Actor* target, MoveComponent* movecomponent, const char* name) : Component::Component(name)
{
	m_agent = agent;
	m_target = target;
	m_movecomponent = movecomponent;
}
void FleeComponent::update(float deltaTime)
{
	//Sets current velocity to the velocity
	m_currentVelocity = m_movecomponent->getVelocity();
	//Normalizes the tarefests world postioon minus the agents world position times the seek force and sets it to the desiredVelocity
	m_desiredVelocity = MathLibrary::Vector2::normalize(m_agent->getTransform()->getWorldPosition() - m_target->getTransform()->getWorldPosition()) * m_seekForce;
	//Set steering force to be equel to desiredforce minus currentVelocity 
	m_steeringForce = m_desiredVelocity - m_currentVelocity;
	//Velocity is equel to velocity + sterring force times deltaTime
	m_movecomponent->setVelocity(m_movecomponent->getVelocity() + (m_steeringForce * deltaTime));
	//set agents world position to world position + velocity times deltaTime
	m_agent->getTransform()->setWorldPostion(m_agent->getTransform()->getWorldPosition() + (m_movecomponent->getVelocity() * deltaTime));
}
