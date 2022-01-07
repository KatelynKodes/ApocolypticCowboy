#pragma once
#include "Actor.h"

class UIText;
class HealthComponent;
class SpriteComponent;
class MoveComponent;
class CircleCollider;

class Enemy :
	public Actor
{
public:
	/// <summary>
	/// Base constructor for the Enemy. Sets the max health
	/// </summary>
	/// <param name="x"> xpos of the enemy </param>
	/// <param name="y"> ypos of the enemy </param>
	/// <param name="name"> The name of the enemy </param>
	/// <param name="health"> How much health the enemy has </param>
	Enemy(float x, float y, const char* name, float health);
	~Enemy();

	/// <summary>
	/// Gets the value of the enemies health
	/// </summary>
	/// <returns> the value of the m_health value </returns>
	float GetHealth() { return m_health; }

	/// <summary>
	/// Gets the value of the enemies maximum health
	/// </summary>
	/// <returns> the value of the m_maxealth value </returns>
	float GetMaxHealth() { return m_maxhealth; }

	/// <summary>
	/// Gets the value of m_isAlive to determine if the enemy is alive
	/// </summary>
	/// <returns> The m_isAlive value </returns>
	bool GetIsAlive() { return m_isAlive; }

	void start() override;
	void draw() override;
	void onCollision(Actor* other) override;
	virtual void update(float deltaTime) override;
	
	/// <summary>
	/// Sets the health text to be a certain UI Text
	/// </summary>
	/// <param name="text"></param>
	void setHealthText(UIText* text) { m_healthText = text; }

protected:
	//Set the get functions of getting/setting the sprite and move components value to "protected" to avoid other 
	//classes aside from those that inherit from enemy can get/set the values of them.

	/// <summary>
	/// Returns the value of the sprite component attatched to the Enemy
	/// </summary>
	/// <returns> m_spriteComponent </returns>
	SpriteComponent* getSpriteComponent() { return m_spriteComponent; }

	/// <summary>
	/// Sets the value of the move component attatched to the enemy to a new value 
	/// </summary>
	/// <param name="value">The value to set the SpriteComponent value to</param>
	void setSpriteComponent(SpriteComponent* value) { m_spriteComponent = value; }

	/// <summary>
	/// Returns the value of the move component attatched to the Enemy 
	/// </summary>
	/// <returns> m_moveComponent </returns>
	MoveComponent* getMoveComponent() { return m_moveComponent; }

	/// <summary>
	/// Sets the value of the move component attatched to the enemy to a new value 
	/// </summary>
	/// <param name="value">The value to set the MoveComponent value to</param>
	void setMoveComponent(MoveComponent* value) { m_moveComponent = value; }

	/// <summary>
	/// Sets the healthcomponent
	/// </summary>
	/// <param name="value"></param>
	void setHealthComponent(HealthComponent* value) { m_healthComponent = value; }

private:
	float m_health;
	float m_maxhealth;
	bool m_isAlive;
	CircleCollider* m_enemyCollider;
	SpriteComponent* m_spriteComponent;
	MoveComponent* m_moveComponent;
	UIText* m_healthText;
	HealthComponent* m_healthComponent;
};
