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
	//Constructor 
	Player(float x, float y, const char* name, float health);

	/// <summary>
	/// Returns the value of the players health
	/// </summary>
	/// <returns> m_playerHealth </returns>
	float getHealth() { return m_playerHealth; }

	/// <summary>
	/// Sets the health text to be a certain UI Text
	/// </summary>
	/// <param name="text"></param>
	void setPlayerHealthText(UIText* text) { m_playerHealthText = text; }

	//Start and update
	void start() override;
	void update(float deltaTime) override;

private:
	float m_playerHealth;
	InputComponent* m_inputComponent;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	HealthComponent* m_healthComponent;
	UIText* m_playerHealthText;
};

