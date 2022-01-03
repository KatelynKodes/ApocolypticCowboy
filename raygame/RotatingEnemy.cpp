#include "RotatingEnemy.h"
#include "SpriteComponent.h"

void RotatingEnemy::start()
{
	setSpriteComponent(dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/player.png"))));
	Enemy::start();
}

void RotatingEnemy::update(float deltaTime)
{
}
