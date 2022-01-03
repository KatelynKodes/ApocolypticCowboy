#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "FollowEnemy.h"
#include "CircleCollider.h"

void MainScene::start()
{
	Player* player = new Player(200, 200, "Player");
	player->getTransform()->setScale({ 50, 50 });
	CircleCollider* playerCollider = new CircleCollider(25, player);
	player->setCollider(playerCollider);

	FollowEnemy* enemy = new FollowEnemy(20, 20, "enemy", 20, 100, player);
	enemy->getTransform()->setScale({ 50, 50 });

	addActor(player);
	addActor(enemy);
}
