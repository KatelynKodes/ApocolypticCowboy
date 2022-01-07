#pragma once
#include "Actor.h"
class SpriteComponent;
class CircleCollider;

class Powerups :
	public Actor
{
public:

	Powerups(float x, float y, const char* name);
	bool getPowerupState() { return m_powerupState; }
	void setPowerupState(bool powerupState) { m_powerupState = powerupState; }

	void start() override;
	void update(float deltaTime) override;
	void draw() override;
private:
	bool m_powerupState;
	SpriteComponent* m_spriteComponent;
	float m_currentTime;
	float m_startTime;
	CircleCollider* m_powerupCollider;
};

