#include "Enemy.h"

class FollowComponent;

class FollowEnemy :
	public Enemy
{
public:
	//Constructor
	FollowEnemy(float x, float y, const char* name, float health, float enemySpeed, Actor* chasee);

	//Start and Update 
	void start() override;
	void update(float deltaTime) override;

private:
	Actor* m_chasee;
	FollowComponent* m_followComponent;
	float m_enemySpeed;
	float m_currentTime;
	float m_startTime;
};

