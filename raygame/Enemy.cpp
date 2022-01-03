#include "Enemy.h"
#include "MoveComponent.h";
#include "SpriteComponent.h";
#include "CircleCollider.h"

Enemy::Enemy(float x, float y, const char* name, float health) : Actor:: Actor(x, y, name)
{
	m_maxhealth = health;
	m_enemyCollider = new CircleCollider(25, this);
	setCollider(m_enemyCollider);
}

Enemy::~Enemy()
{
}

void Enemy::start()
{
	//Set the starting values
	m_health = m_maxhealth;
	m_isAlive = true;
}

void Enemy::draw()
{
	Actor::draw();
	getCollider()->draw();
}
