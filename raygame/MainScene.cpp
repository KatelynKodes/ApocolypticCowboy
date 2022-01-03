#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "FollowEnemy.h"
#include "RotatingEnemy.h"

void MainScene::start()
{
	Player* player = new Player(400, 500, "Player");
	player->getTransform()->setScale({ 50, 50 });

	FollowEnemy* enemy = new FollowEnemy(20, 20, "enemy", 20, 150, player);
	enemy->getTransform()->setScale({ 50, 50 });


	RotatingEnemy* spinningEnemy = new RotatingEnemy(500, 200, "Spinny boi", 30);
	spinningEnemy->getTransform()->setScale({50,50});
	RotatingEnemy* spinningEnemy2 = new RotatingEnemy(400, 200, "Spinny boi2", 30);
	spinningEnemy2->getTransform()->setScale({ 50,50 });
	RotatingEnemy* spinningEnemy3 = new RotatingEnemy(600, 700, "Spinnyboi3", 30);
	spinningEnemy3->getTransform()->setScale({ 50,50 });

	addActor(player);
	addActor(enemy);
	addActor(spinningEnemy);
	addActor(spinningEnemy2);
	addActor(spinningEnemy3);
}
