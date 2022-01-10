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
	Player* player = new Player(20, 50, 100, "Player");
	player->getTransform()->setScale({ 50, 50 });
	CircleCollider* playerCollider = new CircleCollider(25, player);
	player->setCollider(playerCollider);

	//The following Enemy
	FollowEnemy* enemy = new FollowEnemy(950, 750, "enemy", 20, 150, player);
	UIText* FollowEnemyHealth = new UIText(20, 19, "Follow Enemy Health", "0/0", (float)50, (float)50, (float)25, "resources/fonts/jupiter_crash.png", Color(), RED);
	enemy->getTransform()->setScale({ 50, 50 });
	enemy->setHealthText(FollowEnemyHealth);

	//The rotating Enemies
	RotatingEnemy* spinningEnemy = new RotatingEnemy(900, 100, "enemy", 30);
	UIText* spinningEnemyHealth = new UIText(550, 100, "spinny boi 1 health", "0/0", (float)50, (float)50, (float) 25, "resources/fonts/jupiter_crash.png", Color(), RED);
	spinningEnemy->getTransform()->setScale({80,80});
	spinningEnemy->setHealthText(spinningEnemyHealth);

	RotatingEnemy* spinningEnemy3 = new RotatingEnemy(900, 730, "enemy", 30);
	UIText* spinningEnemyHealth3 = new UIText(600, 500, "spinny boi 2 health", "0/0", (float)50, (float)50, (float)25, "resources/fonts/jupiter_crash.png", Color(), RED);
	spinningEnemy3->getTransform()->setScale({ 80,80 });
	spinningEnemy3->setHealthText(spinningEnemyHealth3);

	RotatingEnemy* spinningEnemy4 = new RotatingEnemy(820, 400, "enemy", 30);
	UIText* spinningEnemyHealth4 = new UIText(600, 500, "spinny boi 3 health", "0/0", (float)50, (float)50, (float)25, "resources/fonts/jupiter_crash.png", Color(), RED);
	spinningEnemy4->getTransform()->setScale({ 80,80 });
	spinningEnemy4->setHealthText(spinningEnemyHealth4);

	Actor* rotater = new Actor(10, 10, "rotater");
	Transform2D* rotatorTransfrom = new Transform2D(rotater);
	spinningEnemy->getTransform()->addChild(rotatorTransfrom);
	rotater->getTransform()->setScale({ 50, 50 });
	CircleCollider* childCollider = new CircleCollider(10, rotater);
	rotater->setCollider(childCollider);

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
	wall1->getTransform()->setScale({ 0, 800 });
	AABBCollider* wall1Collider = new AABBCollider(0, 800, wall1);
	wall1->setCollider(wall1Collider);

	Actor* wall2 = new Actor(1000, 400, "wall");
	wall2->getTransform()->setScale({ 0, 800 });
	AABBCollider* wall2Collider = new AABBCollider(0, 800, wall2);
	wall2->setCollider(wall2Collider);

	Actor* wall3 = new Actor(500, 50, "wall");
	wall3->getTransform()->setScale({ 1000, 0 });
	AABBCollider* wall3Collider = new AABBCollider(1000, 0, wall3);
	wall3->setCollider(wall3Collider);

	Actor* wall4 = new Actor(500, 800, "wall");
	wall4->getTransform()->setScale({ 1000, 0 });
	AABBCollider* wall4Collider = new AABBCollider(1000, 0, wall4);
	wall4->setCollider(wall4Collider);

	Actor* wall5 = new Actor(400, 800, "wall");
	wall5->getTransform()->setScale({ 100, 400 });
	AABBCollider* wall5Collider = new AABBCollider(200, 400, wall5);
	wall5->setCollider(wall5Collider);

	Actor* wall6 = new Actor(800, 250, "wall");
	wall6->getTransform()->setScale({ 100, 50 });
	AABBCollider* wall6Collider = new AABBCollider(200, 150, wall6);
	wall6->setCollider(wall6Collider);

	Actor* wall7 = new Actor(800, 550, "wall");
	wall7->getTransform()->setScale({ 100, 50 });
	AABBCollider* wall7Collider = new AABBCollider(200, 150, wall7);
	wall7->setCollider(wall7Collider);

	//Adding the actors to the scene
	addActor(Instructions);
	addActor(player);
	addActor(mimicEnemy);
	addActor(enemy);
	addActor(spinningEnemy);
	addActor(spinningEnemy3);
	addActor(spinningEnemy4);
	addActor(wall);
	addActor(wall1);
	addActor(wall2);
	addActor(wall3);
	addActor(wall4);
	addActor(wall5);
	addActor(wall6);
	addActor(wall7);
	//addActor(rotater);

	Scene::start();
}

void MainScene::draw()
{
	ClearBackground(ORANGE);
	Scene::draw();
}
