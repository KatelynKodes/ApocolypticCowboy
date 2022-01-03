#include "FollowEnemy.h"
#include "MoveComponent.h";
#include "FollowComponent.h"
#include "SpriteComponent.h"
#include "Engine.h"
#include <iostream>

FollowEnemy::FollowEnemy(float x, float y, const char* name, float health, float enemySpeed, Actor* chasee) : Enemy::Enemy(x,y, name, health)
{
	m_enemySpeed = enemySpeed;
	m_chasee = chasee;
}

void FollowEnemy::start()
{
	setSpriteComponent(dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/enemy.png"))));
	m_moveComponent = (dynamic_cast<MoveComponent*>(addComponent(new MoveComponent())));
	m_moveComponent->setMaxSpeed(m_enemySpeed);
	m_followComponent = dynamic_cast<FollowComponent*>(addComponent(new FollowComponent()));
	m_followComponent->setChasee(m_chasee);

	

	Actor::start();
}

void FollowEnemy::update(float deltaTime)
{
	Actor::update(deltaTime);

	MathLibrary::Vector2 moveDir =  m_followComponent->GetIntendedPosition() - getTransform()->getLocalPosition();;

	if (GetHealth() <= 0)
		Engine::destroy(this);

	//If the velocity is greater than 0...
	if (m_moveComponent->getVelocity().getMagnitude() > 0)
		//...Rotate the enemy
		getTransform()->setForward(m_moveComponent->getVelocity());

	m_moveComponent->setVelocity(moveDir.getNormalized() * m_enemySpeed);
}
