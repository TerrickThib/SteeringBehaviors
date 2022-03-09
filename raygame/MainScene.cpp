#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "SeekComponent.h"
#include "Agent.h"
#include "WanderComponent.h"
#include "FleeComponent.h"
#include "StateMachineComponent.h"

void MainScene::start()
{
	//Declares player and sets scale
	Player* player = new Player(50, 50, "Player");	
	player->getTransform()->setScale({ 50,50 });
	player->addComponent(new SpriteComponent("Images/player.png"));

	Agent* enemy = new Agent();
	enemy->getTransform()->setScale({ 50,50 });
	enemy->setMaxForce(50);
	enemy->addComponent(new SpriteComponent("Images/enemy.png"));

	WanderComponent* wanderComponent = new WanderComponent(50, 100, 10);
	enemy->addComponent(wanderComponent);

	SeekComponent* comp = new SeekComponent();//Makes Enemy seek
	comp->setSteeringForce(20);
	comp->setTarget(player);
	enemy->addComponent(comp);
	enemy->addComponent<StateMachineComponent>();

	addActor(player);
	addActor(enemy);
}
