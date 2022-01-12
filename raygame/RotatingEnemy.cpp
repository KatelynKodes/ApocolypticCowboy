#include "RotatingEnemy.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Bullet.h"
#include "Engine.h"
#include <raylib.h>
#include <stdlib.h> 
#include <ctime>

RotatingEnemy::RotatingEnemy(float x, float y, const char* name, float health) : Enemy(x, y, name, health) {};

void RotatingEnemy::start()
{
	//Sets the sprite component
	setSpriteComponent(dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/canon.png"))));
	Enemy::start();

	//Sets the current time to be 0
	m_currentTime = 0;
}

void RotatingEnemy::update(float deltaTime)
{
	//Calls the base update
	Enemy::update(deltaTime);

	//If the enemy is alive
	if (GetIsAlive())
	{
		//Rotate the enemy
		getTransform()->rotate(PI * deltaTime);

		//Sets the start time to be the timer time
		m_startTime = clock();

		//Sets the time in between shooting to be random between 2500ms and 800ms
		float timeBetweenShots = rand() % 2500 + 800;

		//If the start time minus the current time is greater than the time between shots
		if (m_startTime - m_currentTime > timeBetweenShots)
		{
			//Spawn a bullet in the direction this enemy is facing
			Scene* currentScene = Engine::getCurrentScene();
			Bullet* bullet = new Bullet(this, 500, getTransform()->getForward(), getTransform()->getLocalPosition().x, getTransform()->getLocalPosition().y, "EnemyBullet");
			bullet->getTransform()->setScale({ 50, 50 });
			currentScene->addActor(bullet);

			//Sets the current time to be the start time to reset the timer
			m_currentTime = m_startTime;
		}
	}
	//If this enemy is dead
	else
	{
		//Destroy
		Engine::destroy(this);
	}
}
