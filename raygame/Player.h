#pragma once
#include "Actor.h"
class InputComponent;
class MoveComponent;
class SpriteComponent;

class Player :
	public Actor
{
public:
	Player(float health, float x, float y, const char* name) : Actor(x, y, name) { m_health = health; }
	void start() override;
	void draw() override;
	void update(float deltaTime) override;
	void onCollision(Actor* other) override;

private:
	float m_health;
	bool m_powerupStatus;
	float m_startTime;
	float m_currentTime;
	InputComponent* m_inputComponent;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
};

