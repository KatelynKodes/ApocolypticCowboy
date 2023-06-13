#pragma once
#include "Actor.h"
#include <Vector2.h>
class MoveComponent;
class SpriteComponent;
class CircleCollider;

class Bullet :
	public Actor
{
public:
	Bullet(Actor* owner, float speed, MathLibrary::Vector2 direction, float x, float y, const char* name = "Bullet");

	/// <summary>
	/// The base start
	/// </summary>
	void start() override;

	/// <summary>
   /// Called every loop to update on screen visuals
   /// </summary>
	void draw() override;

	/// <summary>
	/// Called every frame
	/// </summary>
	/// <param name="deltaTime">The time that has passed from the previous frame to the current</param>
	void update(float deltaTime) override;

	/// <summary>
	/// Called when a collision between this actor and another occurs. 
	/// </summary>
	/// <param name="other">The actor this actor collided with.</param>
	void onCollision(Actor* other) override;

private:
	Actor* m_owner;
	float m_bulletSpeed;
	float m_currentTime;
	float m_startTime;
	CircleCollider* m_bulletCollider;
	MathLibrary::Vector2 m_bulletDirection;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
};

