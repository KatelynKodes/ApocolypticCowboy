#include "Enemy.h"

class RotatingEnemy :
	public Enemy
{
public:
	//Constructor
	RotatingEnemy(float x, float y, const char* name, float health) : Enemy::Enemy(x, y, name, health) {};

	//Start and update
	void start() override;
	void update(float deltaTime) override;

private:
	float m_rotationSpeed;
	float m_currentTime;
	float m_startTime;
};

