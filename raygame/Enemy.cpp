#include "Enemy.h"
#include "MoveComponent.h";
#include "SpriteComponent.h";

Enemy::~Enemy()
{
}

void Enemy::start()
{
	//Set the starting values
	m_health = m_maxhealth;
	m_isAlive = true;
}
