#include "RotatingEnemy.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include <raylib.h>

void RotatingEnemy::start()
{
	setSpriteComponent(dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/player.png"))));
	Enemy::start();
}

void RotatingEnemy::update(float deltaTime)
{
	getTransform()->rotate(PI * deltaTime);
	Enemy::update(deltaTime);
}
