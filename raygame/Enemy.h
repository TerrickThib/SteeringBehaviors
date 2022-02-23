#pragma once
#include "Actor.h"
class MoveComponent;
class SeekComponent;
class SpriteComponent;
class FleeComponent;

class Enemy :
	public Actor
{
public:
	Enemy(float x, float y, const char* name, Actor* target);
	~Enemy();

	void start()override;
	void update(float deltaTime) override;
	void draw()override;

private:
	MoveComponent* m_movecomponent;
	Actor* m_target;
	SeekComponent* m_seekcomponent;
	SpriteComponent* m_spritecomponent;
	FleeComponent* m_fleecomponent;

};

