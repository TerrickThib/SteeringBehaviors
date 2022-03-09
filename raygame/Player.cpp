#include "Player.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "Transform2D.h"

void Player::start()
{
	Actor::start();

	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(10);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));

	//Set spawn point
	//Set Move speed
	//Set position clamps
}

void Player::update(float deltaTime)
{
	Actor::update(deltaTime);

	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	moveDirection.normalize();

	m_moveComponent->setVelocity(moveDirection * 200);

	if (m_moveComponent->getVelocity().getMagnitude() > 0)
		this->getTransform()->setForward(m_moveComponent->getVelocity().getNormalized());
}
