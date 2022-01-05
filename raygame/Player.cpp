#include "Player.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Bullet.h"
#include "Engine.h"
#include "CircleCollider.h"
#include <iostream>

void Player::start()
{
	Actor::start();

	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(10);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/player.png")));

	//Set spawn point
	//Set move speed
	//Set position clamps
}

void Player::update(float deltaTime)
{
	Actor::update(deltaTime);

	if (m_health <= 0)
	{
		getTransform()->setLocalPosition({ 10, 10 });
		m_health = 20;
	}

	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	if (m_inputComponent->getSpacePress()) 
	{
		Scene* currentScene = Engine::getCurrentScene();
		Bullet* bullet = new Bullet(this, 500, getTransform()->getForward(), getTransform()->getLocalPosition().x, getTransform()->getLocalPosition().y, "PlayerBullet");
		bullet->getTransform()->setScale({ 50, 50 });
		currentScene->addActor(bullet);
		std::cout << bullet->getName() << std::endl;
	}

	//If the velocity is greater than 0...
	if (m_moveComponent->getVelocity().getMagnitude() > 0)
		//...Rotate the player
		getTransform()->setForward(m_moveComponent->getVelocity());

	//Set the players velocity 
	m_moveComponent->setVelocity(moveDirection.getNormalized() * 200);
}

void Player::draw()
{
	Actor::draw();
	getCollider()->draw();
}

void Player::onCollision(Actor* other)
{
	if (other->getName() == "enemy")
	{
		Engine::destroy(other);
		m_health -= 5;
	}
	if (other->getName() == "EnemyBullet")
	{
		Engine::destroy(other);
		m_health -= 5;
	}
		
}
