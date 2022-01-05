#pragma once
#include "Actor.h"
class RotateEnemy :
	public Actor
{
public:
	RotateEnemy(float x, float y, const char* name, float health);
	~RotateEnemy();
	void start() override;
	void update(float deltaTime) override;
};

