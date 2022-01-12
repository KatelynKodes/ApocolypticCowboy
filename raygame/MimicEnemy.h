#pragma once
#include "Enemy.h"

class InputComponent;
class MoveComponent;
class SpriteComponent;

class MimicEnemy :
    public Enemy
{
public:
    MimicEnemy(float x, float y, const char* name, float health) : Enemy::Enemy(x, y, name, health) {};
    ~MimicEnemy();

    //The base start and update 
    void start() override;
    void update(float deltaTime) override;


private:
    InputComponent* m_inputComponent;
};

