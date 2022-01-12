#include "Player.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "HealthComponent.h"
#include "Transform2D.h"
#include "Bullet.h"
#include "Engine.h"
#include "CircleCollider.h"
#include "Powerups.h"
#include <stdlib.h> 
#include <ctime>
#include <iostream>

void Player::start()
{
	Actor::start();

	//Input and move components
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(10);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/player.png")));

	//True if the player has a powerup
	m_powerupStatus = false;
	//Sets the current time to 0
	m_currentTime = 0;

	//Health Component
	m_healthComponent = dynamic_cast<HealthComponent*>(addComponent(new HealthComponent()));
	m_healthComponent->setCurrHealth(m_health);
	m_healthComponent->setUIText(m_playerHealthText);
}

void Player::update(float deltaTime)
{
	//Calls the base update
	Actor::update(deltaTime);

	//If the player dies
	if (m_health <= 0)
	{
		//Respawn the player
		getTransform()->setLocalPosition({ 50, 100 });
		m_health = 20;
	}

	//Sets the start time to the timer time
	m_startTime = clock();

	//If 15000ms passes
	if (m_startTime - m_currentTime > 15000)
	{
		//Spawn a bulpoweruplet in a random location on the screen
		float randomX = rand() % 900 + 50;
		float randomY = rand() % 700 + 50;
		Powerups* powerup = new Powerups(randomX, randomY, "powerup");
		Scene* currentScene = Engine::getCurrentScene();
		powerup->getTransform()->setScale({ 50, 50 });
		currentScene->addActor(powerup);

		//Sets the current time to the start time to reset the timer
		m_currentTime = m_startTime;
	}

	//Sets the move direction the the player input
	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	//If the player presses the spacebar nad has a powerup
	if (m_inputComponent->getSpacePress() && m_powerupStatus == true) 
	{
		//Spawn a bullet and set the bullets collider
		Scene* currentScene = Engine::getCurrentScene();
		Bullet* bullet = new Bullet(this, 500, getTransform()->getForward(), getTransform()->getLocalPosition().x, getTransform()->getLocalPosition().y, "PlayerUpgradedBullet");
		bullet->getTransform()->setScale({ 200, 200 });
		CircleCollider* m_bulletCollider = new CircleCollider(30, bullet);
		bullet->setCollider(m_bulletCollider);
		currentScene->addActor(bullet);
	}
	//If the player presses the spacebar and doesn't have a powerup
	else if (m_inputComponent->getSpacePress())
	{
		//Spawn a regular bullet
		Scene* currentScene = Engine::getCurrentScene();
		Bullet* bullet = new Bullet(this, 500, getTransform()->getForward(), getTransform()->getLocalPosition().x, getTransform()->getLocalPosition().y, "PlayerBullet");
		bullet->getTransform()->setScale({ 50, 50 });
		currentScene->addActor(bullet);
	}

	//If the velocity is greater than 0...
	if (m_moveComponent->getVelocity().getMagnitude() > 0)
		//...Rotate the player
		getTransform()->setForward(m_moveComponent->getVelocity());

	//Set the players velocity 
	m_moveComponent->setVelocity(moveDirection.getNormalized() * 200);


	//Sets the current health to the players current health
	m_healthComponent->setCurrHealth(m_health);


	//Set the health text to always be following the player
	MathLibrary::Vector2 HealthTextPos = MathLibrary::Vector2{ (getTransform()->getLocalPosition().x - 20),
		(getTransform()->getLocalPosition().y - 50) };
	m_playerHealthText->getTransform()->setLocalPosition(HealthTextPos);
	
}

void Player::draw()
{
	Actor::draw();
	//getCollider()->draw();
}

void Player::onCollision(Actor* other)
{
	//If the player collides with an enemy
	if (other->getName() == "enemy")
	{
		//Destroy the enemy and take 10 health away
		Engine::destroy(other);
		m_health -= 10;
	}
	//If the player collides with an enemy bullet
	if (other->getName() == "EnemyBullet")
	{
		//Destroy the bullet and take 5 health away
		Engine::destroy(other);
		m_health -= 5;
	}
	//If the player collides with a powerup
	if (other->getName() == "powerup")
	{
		//Destroy the powerup and set the powerup status to be true
		Engine::destroy(other);
		m_powerupStatus = true;
	}
	//If the player collides with any of the buildings
	if (other->getName() == "house" || other->getName() == "house1" || other->getName() == "house2" || other->getName() == "wall" 
		|| other->getName() == "house3" || other->getName() == "house4")
	{
		//Sets the players position back to where it was
		getTransform()->setWorldPosition(getTransform()->getWorldPosition() - getCollider()->getCollisionNormal());
	}
	//If the player collides with the rotator around the mimic
	if (other->getName() == "rotator")
	{
		//Kill the player instantly
		m_health -= 20;
	}
		
}
