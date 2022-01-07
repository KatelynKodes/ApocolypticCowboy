#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "FollowEnemy.h"
#include "CircleCollider.h"
#include "AABBCollider.h"
#include "RotatingEnemy.h"
#include "MimicEnemy.h"
#include "UIText.h"

void MainScene::start()
{
	//Text displaying instructions
	UIText* Instructions = new UIText(0, 0, "Instructions", "Press WASD to move, press SPACE to shoot", (float)1000, (float)50, (float)25, "resources/fonts/jupiter_crash.png", BLACK, WHITE);

	//Player
	Player* player = new Player(20, 400, 400, "Player");
	player->getTransform()->setScale({ 50, 50 });
	CircleCollider* playerCollider = new CircleCollider(25, player);
	player->setCollider(playerCollider);

	//The following Enemy
	FollowEnemy* enemy = new FollowEnemy(20, 20, "enemy", 20, 150, player);
	UIText* FollowEnemyHealth = new UIText(20, 19, "Follow Enemy Health", "0/0", (float)50, (float)50, (float)25, "resources/fonts/jupiter_crash.png", Color(), RED);
	enemy->getTransform()->setScale({ 50, 50 });
	enemy->setHealthText(FollowEnemyHealth);

	//The rotating Enemies
	RotatingEnemy* spinningEnemy = new RotatingEnemy(500, 200, "enemy", 30);
	UIText* spinningEnemyHealth = new UIText(500, 100, "spinny boi 1 health", "0/0", (float)50, (float)50, (float) 25, "resources/fonts/jupiter_crash.png", Color(), RED);
	spinningEnemy->getTransform()->setScale({80,80});
	spinningEnemy->setHealthText(spinningEnemyHealth);


	RotatingEnemy* spinningEnemy2 = new RotatingEnemy(400, 200, "enemy", 30);
	UIText* spinningEnemyHealth2 = new UIText(400, 300, "spinny boi 2 health", "0/0", (float)50, (float)50, (float)25, "resources/fonts/jupiter_crash.png", Color(), RED);
	spinningEnemy2->getTransform()->setScale({ 80,80 });
	spinningEnemy2->setHealthText(spinningEnemyHealth2);


	RotatingEnemy* spinningEnemy3 = new RotatingEnemy(600, 700, "enemy", 30);
	UIText* spinningEnemyHealth3 = new UIText(600, 500, "spinny boi 2 health", "0/0", (float)50, (float)50, (float)25, "resources/fonts/jupiter_crash.png", Color(), RED);
	spinningEnemy3->getTransform()->setScale({ 80,80 });
	spinningEnemy3->setHealthText(spinningEnemyHealth3);

	//Mimic
	MimicEnemy* mimicEnemy = new MimicEnemy(800, 500, "enemy", 25);
	UIText* mimicHealth = new UIText(0, 0, "mimic health", "0/0", (float)50, (float)50, (float)25, "resources/fonts/jupiter_crash.png", Color(), RED);
	mimicEnemy->getTransform()->setScale({ 50,50 });
	mimicEnemy->setHealthText(mimicHealth);

	Actor* wall = new Actor(300, 100, "wall");
	wall->getTransform()->setScale({ 100, 100 });
	AABBCollider* wallCollider = new AABBCollider(100, 100, wall);
	wall->setCollider(wallCollider);

	Actor* wall1 = new Actor(0, 400, "wall");
	wall1->getTransform()->setScale({ 10, 800 });
	AABBCollider* wall1Collider = new AABBCollider(10, 800, wall1);
	wall1->setCollider(wall1Collider);

	Actor* wall2 = new Actor(1000, 400, "wall");
	wall2->getTransform()->setScale({ 10, 800 });
	AABBCollider* wall2Collider = new AABBCollider(10, 800, wall2);
	wall2->setCollider(wall2Collider);

	Actor* wall3 = new Actor(500, 50, "wall");
	wall3->getTransform()->setScale({ 1000, 10 });
	AABBCollider* wall3Collider = new AABBCollider(1000, 10, wall3);
	wall3->setCollider(wall3Collider);

	Actor* wall4 = new Actor(500, 800, "wall");
	wall4->getTransform()->setScale({ 1000, 10 });
	AABBCollider* wall4Collider = new AABBCollider(1000, 10, wall4);
	wall4->setCollider(wall4Collider);

	//Adding the actors to the scene
	addActor(Instructions);
	addActor(player);
	addActor(mimicEnemy);
	addActor(enemy);
	addActor(spinningEnemy);
	addActor(spinningEnemy2);
	addActor(spinningEnemy3);
	addActor(wall);
	addActor(wall1);
	addActor(wall2);
	addActor(wall3);
	addActor(wall4);

	Scene::start();
}

void MainScene::draw()
{
	ClearBackground(ORANGE);
	Scene::draw();
}
