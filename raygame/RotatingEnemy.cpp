#include "RotatingEnemy.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include <raylib.h>

RotatingEnemy::RotatingEnemy(float x, float y, const char* name, float health) : Enemy :: Enemy(x,y,name,health)
{
}

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
