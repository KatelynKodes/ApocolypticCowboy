#include "Bullet.h"
#include "MoveComponent.h";
#include "SpriteComponent.h";
#include "CircleCollider.h"
#include "raylib.h"
#include "Engine.h"
#include <ctime>

Bullet::Bullet(Actor* owner, float speed, MathLibrary::Vector2 direction, float x, float y, const char* name) : Actor::Actor(x, y, name)
{
	m_owner = owner;
	m_bulletSpeed = speed;
	m_bulletDirection = direction;

	m_bulletCollider = new CircleCollider(7, this);
	setCollider(m_bulletCollider);
}

void Bullet::start()
{
	m_spriteComponent = (dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/bullet.png"))));
	m_moveComponent = (dynamic_cast<MoveComponent*>(addComponent(new MoveComponent())));
	m_moveComponent->setMaxSpeed(m_bulletSpeed);

	m_startTime = clock();

	Actor::start();
}

void Bullet::update(float deltaTime)
{
	m_moveComponent->setVelocity(m_bulletDirection.getNormalized() * m_bulletSpeed);

	m_currentTime = clock();

	if ((m_currentTime - m_startTime) > 750)
	{
		Engine::destroy(this);
	}
	
	Actor::update(deltaTime);
}

void Bullet::draw()
{
	Actor::draw();
	//getCollider()->draw();
}

void Bullet::onCollision(Actor* other)
{
	if (other->getName() == "wall" || other->getName() == "rotator" || other->getName() == "house" || other->getName() == "house1"
		|| other->getName() == "house2" || other->getName() == "house3" || other->getName() == "house4")
	{
		Engine::destroy(this);
	}
	if (other->getName() == "PlayerBullet")
	{
		Engine::destroy(this);
		Engine::destroy(other);
	}
}




