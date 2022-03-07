#include "SeekComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "MoveComponent.h"

SeekComponent::SeekComponent(Actor* agent, Actor* target, MoveComponent* movecomponent, const char* name) : Component::Component(name) 
{
	m_agent = agent;
	m_target = target;
	m_movecomponent = movecomponent;
}
void SeekComponent::update(float deltaTime)
{
	//Sets current velocity to the velocity
	m_currentVelocity = m_movecomponent->getVelocity();
	//Normalizes the tarefests world postion minus the agents world position times the seek force and sets it to the desiredVelocity
	m_desiredVelocity = MathLibrary::Vector2::normalize(m_target->getTransform()->getWorldPosition() - m_agent->getTransform()->getWorldPosition()) * m_seekForce;
	//Set steering force to be equel to desiredforce minus currentVelocity 
	m_steeringForce = m_desiredVelocity - m_currentVelocity;
	//Velocity is equel to velocity + sterring force times deltaTime
	m_movecomponent->setVelocity(m_movecomponent->getVelocity() + (m_steeringForce * deltaTime));
	//set agents world position to world position + velocity times deltaTime
	m_agent->getTransform()->setWorldPostion(m_agent->getTransform()->getWorldPosition() + (m_movecomponent->getVelocity() * deltaTime));
}

MathLibrary::Vector2 SeekComponent::calculateForce()
{
	if (!getTarget())
	{
		return { 0,0 };
	}

	MathLibrary::Vector2 directionToTarget = getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition();

	MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
	MathLibrary::Vector2 seekForce = 
}
