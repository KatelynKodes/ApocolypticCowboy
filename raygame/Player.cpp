#include "Player.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "HealthComponent.h"
#include "Transform2D.h"
#include <iostream>

Player::Player(float x, float y, const char* name, float health) : Actor::Actor(x, y, name)
{
	m_playerHealth = health;
}

void Player::start()
{
	Actor::start();

	//Input and move components
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(10);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/player.png")));

	//Health Component
	m_healthComponent = dynamic_cast<HealthComponent*>(addComponent(new HealthComponent()));
	m_healthComponent->setCurrHealth(m_playerHealth);
	m_healthComponent->setUIText(m_playerHealthText);
}

void Player::update(float deltaTime)
{
	Actor::update(deltaTime);

	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	//If the velocity is greater than 0...
	if (m_moveComponent->getVelocity().getMagnitude() > 0)
		//...Rotate the player
		getTransform()->setForward(m_moveComponent->getVelocity());

	//Set the players velocity 
	m_moveComponent->setVelocity(moveDirection.getNormalized() * 200);

	//Set the health text to always be following the player
	MathLibrary::Vector2 HealthTextPos = MathLibrary::Vector2{ (getTransform()->getLocalPosition().x - 20),
		(getTransform()->getLocalPosition().y - 50) };
	m_playerHealthText->getTransform()->setLocalPosition(HealthTextPos);

	
}
