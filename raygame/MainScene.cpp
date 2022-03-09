#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "SeekComponent.h"
#include "Agent.h"

void MainScene::start()
{
	//Declares player and sets scale
	Player* player = new Player(50, 50, "Player");	
	player->getTransform()->setScale({ 50,50 });
	player->addComponent(new SpriteComponent("Images/player.png"));
	addActor(player);

	Agent* enemy = new Agent();
	enemy->getTransform()->setScale({ 50,50 });
	enemy->setMaxForce(50);
	enemy->addComponent(new SpriteComponent("Images/enemy.png"));
	SeekComponent* comp = new SeekComponent();//Makes Enemy seek

	comp->setTarget(player);
	enemy->addComponent(comp);
	addActor(enemy);
}
