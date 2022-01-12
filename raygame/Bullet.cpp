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

	//Sets the bullet collider
	m_bulletCollider = new CircleCollider(7, this);
	setCollider(m_bulletCollider);
}

void Bullet::start()
{
	//Sets Sprite and move components
	m_spriteComponent = (dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/bullet.png"))));
	m_moveComponent = (dynamic_cast<MoveComponent*>(addComponent(new MoveComponent())));
	m_moveComponent->setMaxSpeed(m_bulletSpeed);

	//Starts a timer to delete the bullet after some time
	m_startTime = clock();

	//Calls the base start
	Actor::start();
}

void Bullet::update(float deltaTime)
{
	//Sets the bullet velocity
	m_moveComponent->setVelocity(m_bulletDirection.getNormalized() * m_bulletSpeed);

	//Sets the current time to the timer
	m_currentTime = clock();

	//If the timer passes 750ms
	if ((m_currentTime - m_startTime) > 750)
	{
		//Destroy the bullet
		Engine::destroy(this);
	}
	
	//Calls base update
	Actor::update(deltaTime);
}

void Bullet::draw()
{
	//Calls the base draw
	Actor::draw();
	//getCollider()->draw();
}

void Bullet::onCollision(Actor* other)
{
	//If the actors name is one of the buildings or walls
	if (other->getName() == "wall" || other->getName() == "rotator" || other->getName() == "house" || other->getName() == "house1"
		|| other->getName() == "house2" || other->getName() == "house3" || other->getName() == "house4")
	{
		//Destroy the bullet
		Engine::destroy(this);
	}
	//If the actors name is the players bullet
	if (other->getName() == "PlayerBullet")
	{
		//destroy both bullets
		Engine::destroy(this);
		Engine::destroy(other);
	}
}




