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
	m_spriteComponent = (dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/powerup.png"))));

	m_powerupCollider = new CircleCollider(23, this);
	setCollider(m_powerupCollider);

	m_currentTime = 0;

	Actor::start();
}

void Powerups::update(float deltaTime)
{
	getTransform()->rotate(-2 * deltaTime);

	Actor::update(deltaTime);
}

void Powerups::draw()
{
	Actor::draw();
	//getCollider()->draw();
}


