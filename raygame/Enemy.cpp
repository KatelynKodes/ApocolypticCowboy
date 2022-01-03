#include "Enemy.h"

Enemy::Enemy(float x, float y, const char* name, float health) : Actor:: Actor(x, y, name)
{
	m_maxhealth = health;
	m_health = m_maxhealth;
	m_isAlive = true;
}

Enemy::~Enemy()
{
}

void Enemy::start()
{
	//Call base start method
	Actor::start();
}
