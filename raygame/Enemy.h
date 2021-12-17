#include "Actor.h"
class SpriteComponent;
class MoveComponent;

class Enemy :
	public Actor
{
public:
	Enemy(float x, float y, const char* name, float health) : Actor(x, y, name) { m_maxhealth = health; }
	~Enemy();

	void start() override;
private:
	float m_health;
	float m_maxhealth;
	bool m_isAlive;
	SpriteComponent* m_spriteComponent;
	MoveComponent* m_moveComponent;
};
