#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Enemy.h"

void MainScene::start()
{
	//Declares player and sets scale
	Player* player = new Player(200, 50, "Player");	
	player->getTransform()->setScale({ 50,50 });
	player->addComponent(new SpriteComponent("Images/player.png"));

	Enemy* enemy = new Enemy(100, 100, "Enemy", 100, 100, player);

	addActor(player);
	addActor(enemy);
}
