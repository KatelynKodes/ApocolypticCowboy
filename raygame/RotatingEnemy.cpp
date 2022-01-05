#include "RotatingEnemy.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Engine.h"
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

	float currentTime = deltaTime;

	if (GetHealth() <= 0)
		Engine::destroy(this);


	Actor::update(deltaTime);


}
