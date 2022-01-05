#include "Enemy.h"
#include "UIText.h"
#include "HealthComponent.h"
#include "Transform2D.h"

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
	//Health Component
	setHealthComponent(dynamic_cast<HealthComponent*>(addComponent(new HealthComponent())));
	m_healthComponent->setUIText(m_healthText);
	m_healthComponent->setMinHealth(m_health);
	m_healthComponent->setMaxHealth(m_maxhealth);
	//Call base start method
	Actor::start();
}

void Enemy::update(float deltaTime)
{
	MathLibrary::Vector2 HealthTextPos = MathLibrary::Vector2{ (getTransform()->getLocalPosition().x - 20),
		(getTransform()->getLocalPosition().y - 50) };
	m_healthText->getTransform()->setLocalPosition(HealthTextPos);
	Actor::update(deltaTime);
}
