#include "Enemy.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "SeekComponent.h"
#include "FleeComponent.h"

Enemy::Enemy(float x, float y, const char* name, Actor* target) :Actor(x, y, name)
{
	m_target = target;
}

void Enemy::start()
{
	Actor::start();
	m_spritecomponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/enemy.png")));
	m_movecomponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	/*m_seekcomponent = dynamic_cast<SeekComponent*>(addComponent(new SeekComponent(this, m_target, m_movecomponent)));*/
	m_fleecomponent = dynamic_cast<FleeComponent*>(addComponent(new FleeComponent(this, m_target, m_movecomponent)));
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
}

void Enemy::draw()
{
	Actor::draw();
}
