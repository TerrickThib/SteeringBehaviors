#include "Enemy.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "IsAggressiveDecision.h"
#include "SeekDecision.h"
#include "IdleDecision.h"
#include "InRangeDecision.h"
#include "WanderDecision.h"
#include "DecisionComponent.h"

Enemy::Enemy(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target) : Agent(x, y, name, maxForce, maxSpeed)
{
	m_target = target;
}

void Enemy::start()
{
	Agent::start();
	//Initialize and add wander comonent
	WanderComponent* wanderComponent = new WanderComponent(50, 100, 10);
	addComponent(wanderComponent);

	//Add sprite component
	getTransform()->setScale({ 50,50 });
	addComponent(new SpriteComponent("Images/enemy.png"));

	IdleDecision* idle = new IdleDecision();
	WanderDecision* wander = new WanderDecision();
	SeekDecision* seek = new SeekDecision();

	IsAggressiveDecision* aggressive = new IsAggressiveDecision(idle, wander);
	InRangeDecision* inRange = new InRangeDecision(aggressive, seek);

	addComponent(new DecisionComponent(inRange));

	//Initalize the seek component
	SeekComponent* comp = new SeekComponent();//Makes Enemy seek
	comp->setSteeringForce(20);
	comp->setTarget(m_target);
	addComponent(comp);
}

bool Enemy::getTargetInSight()
{
	float distance = (m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getMagnitude();
	MathLibrary::Vector2 direction = (m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getNormalized();

	return distance <= 300 && acos(MathLibrary::Vector2::dotProduct(direction, getTransform()->getForward())) < 1;
}

