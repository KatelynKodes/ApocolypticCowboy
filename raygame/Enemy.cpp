#include "Enemy.h"
#include "UIText.h"
#include "HealthComponent.h"
#include "Transform2D.h"
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
	delete m_enemyCollider;
	delete m_spriteComponent;
	delete m_moveComponent;
	delete m_healthText;
	delete m_healthComponent;
	Actor::~Actor();
}

void Enemy::start()
{
	//Health Component
	setHealthComponent(dynamic_cast<HealthComponent*>(addComponent(new HealthComponent())));
	m_healthComponent->setUIText(m_healthText);
	m_healthComponent->setCurrHealth(m_health);
	//Call base start method
	//Set the starting values
	m_health = m_maxhealth;

	//Sets the enemy collider
	m_enemyCollider = new CircleCollider(this);

	setCollider(m_enemyCollider);

	m_isAlive = true;

	Actor::start();
}

void Enemy::update(float deltaTime)
{
	//If the health is less than 0
	if (m_health <= 0)
	{
		//set isAlive to be false
		m_isAlive = false;
	}

	//If the enemy is alives
	if (m_isAlive == true)
	{
		//set the health component to be the current health
		m_healthComponent->setCurrHealth(m_health);

		//set the position of the enemy health to be the position of the enemy
		MathLibrary::Vector2 HealthTextPos = MathLibrary::Vector2{ (getTransform()->getLocalPosition().x - 20),
			(getTransform()->getLocalPosition().y - 50) };
		m_healthText->getTransform()->setLocalPosition(HealthTextPos);
	}

	//Call base update
	Actor::update(deltaTime);
}

void Enemy::draw()
{
	Actor::draw();
	//getCollider()->draw();
}

void Enemy::onCollision(Actor* other)
{
	//If the enemy collides with a bullet
	if (other->getName() == "PlayerBullet") 
	{
		//Remove 5 health and destroy the bullet
		m_health -= 5;
		Engine::destroy(other);
	}
	//If the enemy collides with the upgraded bullet
	if (other->getName() == "PlayerUpgradedBullet")
	{
		//Remove 10 health and destroy the bullet
		m_health -= 10;
		Engine::destroy(other);
	}
	/*if (other->getName() == "house" || other->getName() == "house1" || other->getName() == "house2" || other->getName() == "wall" || other->getName() == "house3")
	{
		m_moveComponent->setVelocity(other->getCollider()->getCollisionNormal() * m_moveComponent->getVelocity().getMagnitude());
	}*/
}


	