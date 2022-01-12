#include "Powerups.h"
#include "SpriteComponent.h"
#include "CircleCollider.h"
#include "raylib.h"
#include "Engine.h"
#include "Transform2D.h"
#include <ctime>

Powerups::Powerups(float x, float y, const char* name) : Actor(x, y, name) {}

void Powerups::start()
{
	//Set the sprite component 
	m_spriteComponent = (dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/powerup.png"))));

	//Sets the collider for the powerup
	m_powerupCollider = new CircleCollider(23, this);
	setCollider(m_powerupCollider);

	//Calls the base start
	Actor::start();
}

void Powerups::update(float deltaTime)
{
	//Rotates the powerup every frame
	getTransform()->rotate(-2 * deltaTime);

	//Calls the base update
	Actor::update(deltaTime);
}

void Powerups::draw()
{
	Actor::draw();
	//getCollider()->draw();
}


