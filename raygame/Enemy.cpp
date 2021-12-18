#include "Enemy.h"
#include "MoveComponent.h";
#include "SpriteComponent.h";

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
	m_isAlive = true;
}
