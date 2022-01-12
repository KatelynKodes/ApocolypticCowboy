#include "MainScene.h"
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
	UIText* playerHealthText = new UIText(20, 19, "Player Health", "0/0", (float)50, (float)50, (float)25, "resources/fonts/jupiter_crash.png", Color(), RED);
	Player* player = new Player(20, 50, 100, "Player");
	player->getTransform()->setScale({ 50, 50 });
	player->setPlayerHealthText(playerHealthText);
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

	//Mimic
	MimicEnemy* mimicEnemy = new MimicEnemy(700, 500, "enemy", player->getHealth());
	UIText* mimicHealth = new UIText(0, 0, "mimic health", "0/0", (float)50, (float)50, (float)25, "resources/fonts/jupiter_crash.png", Color(), RED);
	mimicEnemy->getTransform()->setScale({ 50,50 });
	mimicEnemy->setHealthText(mimicHealth);

	//The invisible actor connected to the mimic
	Actor* child = new Actor(0, 0, "child");
	mimicEnemy->getTransform()->addChild(child->getTransform());
	child->getTransform()->setScale({ 50, 50 });
	CircleCollider* childCollider = new CircleCollider(30, child);
	child->setCollider(childCollider);

	//The two actors childed to the invisible actor to rotate around the mimic
	Actor* rotator = new Actor(.02f, 0, "rotator");
	child->getTransform()->addChild(rotator->getTransform());
	rotator->getTransform()->setScale({ 100, 100 });
	CircleCollider* rotatorCollider = new CircleCollider(12, rotator);
	rotator->setCollider(rotatorCollider);

	Actor* rotator2 = new Actor(-.02f, 0, "rotator");
	child->getTransform()->addChild(rotator2->getTransform());
	rotator2->getTransform()->setScale({ 100, 100 });
	CircleCollider* rotator2Collider = new CircleCollider(12, rotator2);
	rotator2->setCollider(rotator2Collider);


	//The four walls on the outside of the screen
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


	//The house sprites
	Actor* wall = new Actor(300, 100, "house");
	wall->getTransform()->setScale({ 100, 100 });
	AABBCollider* wallCollider = new AABBCollider(100, 100, wall);
	wall->setCollider(wallCollider);

	Actor* wall5 = new Actor(400, 600, "house2");
	wall5->getTransform()->setScale({ 200, 200 });
	AABBCollider* wall5Collider = new AABBCollider(180, 140, wall5);
	wall5->setCollider(wall5Collider);

	Actor* wall6 = new Actor(800, 250, "house1");
	wall6->getTransform()->setScale({ 200, 150 });
	AABBCollider* wall6Collider = new AABBCollider(140, 130, wall6);
	wall6->setCollider(wall6Collider);

	Actor* wall7 = new Actor(800, 550, "house4");
	wall7->getTransform()->setScale({ 200, 150 });
	AABBCollider* wall7Collider = new AABBCollider(200, 150, wall7);
	wall7->setCollider(wall7Collider);


	//The background
	Actor* background = new Actor(500, 450, "background");
	background->getTransform()->setScale({ 1000, 800 });

	//Adding the actors to the scene
	addActor(Instructions);
	addActor(background);
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
	addActor(player);
	addActor(mimicEnemy);

	//Call base start
	Scene::start();
}

void MainScene::draw()
{
	ClearBackground(ORANGE);
	Scene::draw();
}

	
	
	