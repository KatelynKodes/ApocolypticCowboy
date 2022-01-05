#include "Enemy.h"

class FollowComponent;

class FollowEnemy :
	public Enemy
{
public:
	FollowEnemy(float x, float y, const char* name, float health, float enemySpeed, Actor* chasee);
	void start() override;
	void update(float deltaTime) override;

private:
	Actor* m_chasee;
	FollowComponent* m_followComponent;
	MoveComponent* m_moveComponent;
	float m_enemySpeed;
	float m_currentTime;
	float m_startTime;
};

