#include "Enemy.h"
#include "MoveComponent.h";
#include "SpriteComponent.h";
#include "CircleCollider.h"
#include "Engine.h"

Enemy::Enemy(float x, float y, const char* name, float health) : Actor:: Actor(x, y, name)
{
	m_maxhealth = health;
}

Enemy::~Enemy()
{
}

void Enemy::start()
{
	//Set the starting values
	m_health = m_maxhealth;

	m_enemyCollider = new CircleCollider(25, this);

	setCollider(m_enemyCollider);

	m_isAlive = true;

	Actor::start();
}

void Enemy::draw()
{
	Actor::draw();
	getCollider()->draw();
}

void Enemy::onCollision(Actor* other)
{
	if (other->getName() == "PlayerBullet") 
	{
		m_health -= 5;
		Engine::destroy(other);
	}
		
		
}


	