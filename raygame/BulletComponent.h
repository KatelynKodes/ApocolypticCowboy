#pragma once
#include "Component.h"
#include <Vector2.h>

class BulletComponent :
	public Component
{
public:
	BulletComponent(const char* name = "BulletComponent") : Component::Component(name) {}

	float getBulletSpeed() { return m_bulletSpeed; }

	void setBulletSpeed(float bulletSpeed) { m_bulletSpeed = bulletSpeed; }

	MathLibrary::Vector2 getBulletDirection() { return m_bulletDirection; }

	void setBulletDirection(MathLibrary::Vector2 bulletDirection) { m_bulletDirection = bulletDirection; }

private:
	float m_bulletSpeed;
	MathLibrary::Vector2 m_bulletDirection;
};

