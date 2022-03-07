#include "WanderComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "MoveComponent.h"

WanderComponent::WanderComponent(Actor* agent, int point, MoveComponent* movecomponent, const char* name)
{
	m_agent = agent;
	m_point = point;
	m_movecomponent = movecomponent;
}

void WanderComponent::update(float deltaTime)
{
	//Sets current velocity to the velocity
	m_currentVelocity = m_movecomponent->getVelocity();

	//Set steering force to be equel to desiredforce minus currentVelocity 
	m_steeringForce = m_desiredVelocity - m_currentVelocity;
	//Velocity is equel to velocity + sterring force times deltaTime
	m_movecomponent->setVelocity(m_movecomponent->getVelocity() + (m_steeringForce * deltaTime));
	//set agents world position to world position + velocity times deltaTime
	m_agent->getTransform()->setWorldPostion(m_agent->getTransform()->getWorldPosition() + (m_movecomponent->getVelocity() * deltaTime));
}
