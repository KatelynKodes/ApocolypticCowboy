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

	void start() override;

	void draw() override;

	void update(float deltaTime) override;

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

