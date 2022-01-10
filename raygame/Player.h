#pragma once
#include "Actor.h"
class InputComponent;
class MoveComponent;
class SpriteComponent;
class HealthComponent;
class UIText;

class Player :
	public Actor
{
public:
	Player(float health, float x, float y, const char* name) : Actor(x, y, name) { m_health = health; }

	/// <summary>
	/// Returns the value of the players health
	/// </summary>
	/// <returns> m_playerHealth </returns>
	float getHealth() { return m_health; }

	/// <summary>
	/// Sets the health text to be a certain UI Text
	/// </summary>
	/// <param name="text"></param>
	void setPlayerHealthText(UIText* text) { m_playerHealthText = text; }

	//Start, draw and update
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
	HealthComponent* m_healthComponent;
	UIText* m_playerHealthText;
};

