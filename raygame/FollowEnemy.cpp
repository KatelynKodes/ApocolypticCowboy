#include "FollowEnemy.h"
#include "MoveComponent.h";
#include "FollowComponent.h"
#include "SpriteComponent.h"
#include "Engine.h"
#include "Bullet.h"
#include <iostream>
#include <ctime>

FollowEnemy::FollowEnemy(float x, float y, const char* name, float health, float enemySpeed, Actor* chasee) : Enemy::Enemy(x,y, name, health)
{
	//Sets the speed and the target
	m_enemySpeed = enemySpeed;
	m_chasee = chasee;
}

FollowEnemy::~FollowEnemy()
{
	//Deletes the components of this actor
	delete m_chasee;
	delete m_followComponent;
	Enemy::~Enemy();
}

void FollowEnemy::start()
{
	//Sprite and movement component
	setSpriteComponent(dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/followEnemy.png"))));

	//FollowComponent
	setMoveComponent(dynamic_cast<MoveComponent*>(addComponent(new MoveComponent())));
	getMoveComponent()->setMaxSpeed(m_enemySpeed);
	m_followComponent = dynamic_cast<FollowComponent*>(addComponent(new FollowComponent()));
	m_followComponent->setChasee(m_chasee);

	//Sets the current time to 0
	m_currentTime = 0;

	//Calls the base start function
	Enemy::start();
}

void FollowEnemy::update(float deltaTime)
{
	//Cals the base update function
	Enemy::update(deltaTime);

	if (GetIsAlive())
	{
		//Get the move direction by subtracting the follow enemies position by the direction of the chasee
		MathLibrary::Vector2 moveDir = m_followComponent->GetIntendedPosition() - getTransform()->getLocalPosition();

		//Sets the start time to be the timer time
		m_startTime = clock();

		//If 1000ms has passed
		if (m_startTime - m_currentTime > 1000)
		{
			//Fire a bullet in the direction this enemy is facing
			Scene* currentScene = Engine::getCurrentScene();
			Bullet* bullet = new Bullet(this, 500, getTransform()->getForward(), getTransform()->getLocalPosition().x, getTransform()->getLocalPosition().y, "EnemyBullet");
			bullet->getTransform()->setScale({ 50, 50 });
			currentScene->addActor(bullet);

			m_currentTime = m_startTime;
		}

		//If the velocity is greater than 0...
		if (getMoveComponent()->getVelocity().getMagnitude() > 0)
			//...Rotate the enemy
			getTransform()->setForward(getMoveComponent()->getVelocity());

		//Use the moveComponent to move the follow enemy towards the player
		getMoveComponent()->setVelocity(moveDir.getNormalized() * m_enemySpeed);
	}
	else
	{
		//Destroy if this enemy is dead
		Engine::destroy(this);
	}
}


	