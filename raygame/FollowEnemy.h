#include "Enemy.h"

class FollowEnemy :
	public Enemy
{
public:
	FollowEnemy(float x, float y, const char* name, float health, float enemySpeed);
	void start() override;
	void update(float deltaTime) override;

private:
	Actor* m_chasee;
	float m_enemySpeed;
};

