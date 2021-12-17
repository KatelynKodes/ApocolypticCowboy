#pragma once
#include "Enemy.h"
class FollowEnemy :
	public Enemy
{
public:
	FollowEnemy(float x, float y, const char* name, float health) : Enemy(x, y, name, health) {};
	void start() override;
	void update(float deltaTime) override;

};

