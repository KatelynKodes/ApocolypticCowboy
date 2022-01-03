#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "FollowEnemy.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50, 50 });

	FollowEnemy* enemy = new FollowEnemy(20, 20, "enemy", 20, 50, player);
	enemy->getTransform()->setScale({ 50, 50 });

	addActor(player);
	addActor(enemy);
}
