#pragma once
#include "Actor.h"
class SpriteComponent;
class CircleCollider;

class Powerups :
	public Actor
{
public:

	Powerups(float x, float y, const char* name);

	/// <summary>
	/// Gets if the player has a powerup or not
	/// </summary>
	/// <returns>true if the player has a powerup</returns>
	bool getPowerupState() { return m_powerupState; }

	/// <summary>
	/// Sets the players powerup status
	/// </summary>
	/// <param name="powerupState">true if the player has a powerup</param>
	void setPowerupState(bool powerupState) { m_powerupState = powerupState; }

	//The start update and draw override function
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

