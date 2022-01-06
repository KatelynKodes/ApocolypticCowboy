#include "FollowEnemy.h"
#include "MoveComponent.h";
#include "FollowComponent.h"
#include "SpriteComponent.h"

FollowEnemy::FollowEnemy(float x, float y, const char* name, float health, float enemySpeed, Actor* chasee) : Enemy::Enemy(x,y, name, health)
{
	m_enemySpeed = enemySpeed;
	m_chasee = chasee;
}

void FollowEnemy::start()
{
	//Sprite and movement component
	setSpriteComponent(dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/followEnemy.png"))));
	setMoveComponent(dynamic_cast<MoveComponent*>(addComponent(new MoveComponent())));
	getMoveComponent()->setMaxSpeed(m_enemySpeed);

	//FollowComponent
	m_followComponent = dynamic_cast<FollowComponent*>(addComponent(new FollowComponent()));
	m_followComponent->setChasee(m_chasee);

	Enemy::start();
}

void FollowEnemy::update(float deltaTime)
{
	//Get the move direction by subtracting the follow enemies position by the direction of the chasee
	MathLibrary::Vector2 moveDir =  m_followComponent->GetIntendedPosition() - getTransform()->getLocalPosition();

	
	//If the velocity is greater than 0...
	if (getMoveComponent()->getVelocity().getMagnitude() > 0)
		//...Rotate the enemy
		getTransform()->setForward(getMoveComponent()->getVelocity());

	//Use the moveComponent to move the follow enemy towards the player
	getMoveComponent()->setVelocity(moveDir.getNormalized() * m_enemySpeed);

	Enemy::update(deltaTime);
}
