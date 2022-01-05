#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "FollowEnemy.h"
#include "CircleCollider.h"
#include "RotatingEnemy.h"

void MainScene::start()
{
	Player* player = new Player(20, 200, 200, "Player");
	player->getTransform()->setScale({ 50, 50 });
	CircleCollider* playerCollider = new CircleCollider(25, player);
	player->setCollider(playerCollider);

	FollowEnemy* enemy = new FollowEnemy(20, 20, "enemy", 30, 100, player);
	enemy->getTransform()->setScale({ 50, 50 });


	RotatingEnemy* spinningEnemy = new RotatingEnemy(500, 200, "enemy", 30);
	spinningEnemy->getTransform()->setScale({50,50});
	RotatingEnemy* spinningEnemy2 = new RotatingEnemy(400, 200, "enemy", 30);
	spinningEnemy2->getTransform()->setScale({ 50,50 });
	RotatingEnemy* spinningEnemy3 = new RotatingEnemy(600, 700, "enemy", 30);
	spinningEnemy3->getTransform()->setScale({ 50,50 });

	addActor(player);
	addActor(enemy);
	addActor(spinningEnemy);
	addActor(spinningEnemy2);
	addActor(spinningEnemy3);
}
