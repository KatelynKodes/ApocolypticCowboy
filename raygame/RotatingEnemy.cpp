#include "RotatingEnemy.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Bullet.h"
#include "Engine.h"
#include <raylib.h>
#include <stdlib.h> 
#include <ctime>

RotatingEnemy::RotatingEnemy(float x, float y, const char* name, float health) : Enemy :: Enemy(x,y,name,health)
{
}

void RotatingEnemy::start()
{
	setSpriteComponent(dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/player.png"))));
	Enemy::start();

	m_currentTime = 0;
}

void RotatingEnemy::update(float deltaTime)
{
	getTransform()->rotate(PI * deltaTime);

	m_startTime = clock();

	float timeBetweenShots = rand() % 2500 + 800;

	if (m_startTime - m_currentTime > timeBetweenShots)
	{
		Scene* currentScene = Engine::getCurrentScene();
		Bullet* bullet = new Bullet(this, 500, getTransform()->getForward(), getTransform()->getLocalPosition().x, getTransform()->getLocalPosition().y, "EnemyBullet");
		bullet->getTransform()->setScale({ 50, 50 });
		currentScene->addActor(bullet);

		m_currentTime = m_startTime;
	}

	if (GetHealth() <= 0)
		Engine::destroy(this);


	Actor::update(deltaTime);


}
