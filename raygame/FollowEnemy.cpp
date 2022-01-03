#include "FollowEnemy.h"
#include "MoveComponent.h";
#include "FollowComponent.h"
#include "SpriteComponent.h";

FollowEnemy::FollowEnemy(float x, float y, const char* name, float health, float enemySpeed, Actor* chasee) : Enemy::Enemy(x,y, name, health)
{
	m_enemySpeed = enemySpeed;
	m_chasee = chasee;
}

void FollowEnemy::start()
{
	setSpriteComponent(dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/player.png"))));
	m_moveComponent = (dynamic_cast<MoveComponent*>(addComponent(new MoveComponent())));
	m_moveComponent->setMaxSpeed(m_enemySpeed);
	m_followComponent = dynamic_cast<FollowComponent*>(addComponent(new FollowComponent()));
	m_followComponent->setChasee(m_chasee);
}

void FollowEnemy::update(float deltaTime)
{
	Actor::update(deltaTime);

	MathLibrary::Vector2 moveDir = m_followComponent->GetIntendedPosition();

	//If the velocity is greater than 0...
	if (m_moveComponent->getVelocity().x > 0 || m_moveComponent->getVelocity().y < 0)
		//...Rotate the enemy
		getTransform()->setForward(m_moveComponent->getVelocity());

	m_moveComponent->setVelocity(moveDir.getNormalized() * m_enemySpeed * deltaTime);


}
