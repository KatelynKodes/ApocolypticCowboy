#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "FollowEnemy.h"
#include "RotatingEnemy.h"
#include "UIText.h"

void MainScene::start()
{
	//Text displaying instructions
	UIText* Instructions = new UIText(0, 0, "Instructions", "Press WASD to move, press SPACE to shoot", (float)1000, (float)50, (float)25, "resources/fonts/jupiter_crash.png", BLACK, WHITE);

	Player* player = new Player(400, 500, "Player");
	player->getTransform()->setScale({ 50, 50 });

	FollowEnemy* enemy = new FollowEnemy(20, 20, "enemy", 20, 150, player);
	//UIText* FollowEnemyHealth = new UIText(20, 15, "Follow Enemy Health", "0/0", (float)50, (float)50, (float)15, "resources/fonts/jupiter_crash.png", Color(), RED);
	//enemy->getTransform()->addChild(FollowEnemyHealth->getTransform());
	enemy->getTransform()->setScale({ 50, 50 });


	RotatingEnemy* spinningEnemy = new RotatingEnemy(500, 200, "Spinny boi", 30);
	spinningEnemy->getTransform()->setScale({50,50});
	RotatingEnemy* spinningEnemy2 = new RotatingEnemy(400, 200, "Spinny boi2", 30);
	spinningEnemy2->getTransform()->setScale({ 50,50 });
	RotatingEnemy* spinningEnemy3 = new RotatingEnemy(600, 700, "Spinnyboi3", 30);
	spinningEnemy3->getTransform()->setScale({ 50,50 });

	addActor(Instructions);
	addActor(player);
	addActor(enemy);
	addActor(spinningEnemy);
	addActor(spinningEnemy2);
	addActor(spinningEnemy3);

	Scene::start();
}

void MainScene::draw()
{
	ClearBackground(ORANGE);
	Scene::draw();
}
