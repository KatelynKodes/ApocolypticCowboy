#include "Enemy.h"
class RotatingEnemy :
	public Enemy
{
public:
	RotatingEnemy(float x, float y, const char* name, float health) : Enemy::Enemy(x, y, name, health) {};
	void start() override;
	void update(float deltaTime) override;

private:
	float m_rotationSpeed;
};

