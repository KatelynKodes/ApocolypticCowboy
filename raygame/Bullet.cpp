#include "Bullet.h"
#include "MoveComponent.h";
#include "SpriteComponent.h";

Bullet::Bullet(Actor* owner, float speed, MathLibrary::Vector2 direction, float x, float y, const char* name) : Actor::Actor(x, y, name)
{
	m_owner = owner;
	m_bulletSpeed = speed;
	m_bulletDirection = direction;
}

void Bullet::start()
{
	m_spriteComponent = (dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/bullet.png"))));
	m_moveComponent = (dynamic_cast<MoveComponent*>(addComponent(new MoveComponent())));
	m_moveComponent->setMaxSpeed(m_bulletSpeed);

	Actor::start();
}

void Bullet::update(float deltaTime)
{
	m_moveComponent->setVelocity(m_bulletDirection.getNormalized() * m_bulletSpeed);


	Actor::update(deltaTime);
}


