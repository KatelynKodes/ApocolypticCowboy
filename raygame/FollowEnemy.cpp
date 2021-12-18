#include "FollowEnemy.h"
#include "MoveComponent.h";
#include "SpriteComponent.h";

FollowEnemy::FollowEnemy(float x, float y, const char* name, float health, float enemySpeed) : Enemy::Enemy(x,y, name, health)
{
	m_enemySpeed = enemySpeed;
}

void FollowEnemy::start()
{
	setSpriteComponent(dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/followEnemy.png"))));
	setMoveComponent(dynamic_cast<MoveComponent*>(addComponent(new MoveComponent())));
	getMoveComponent()->setMaxSpeed(m_enemySpeed);
}

void FollowEnemy::update(float deltaTime)
{
}
