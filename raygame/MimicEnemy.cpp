#include "MimicEnemy.h"
#include "MoveComponent.h";
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "Transform2D.h"
#include "Engine.h"

MimicEnemy::~MimicEnemy()
{
	delete m_inputComponent;
	Enemy::~Enemy();
}

void MimicEnemy::start()
{
	//Sets sprite, input, and move components
	setSpriteComponent(dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/mimic.png"))));
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	setMoveComponent(dynamic_cast<MoveComponent*>(addComponent(new MoveComponent())));
	getMoveComponent()->setMaxSpeed(10);
	
	//Calls base start
	Enemy::start();
}

void MimicEnemy::update(float deltaTime)
{
	//If the enemy is alive
	if (GetIsAlive())
	{
		//Set the move direction to the opposite of the players
		MathLibrary::Vector2 moveDir = m_inputComponent->getReverseMoveAxis();

		//If the velocity is greater than 0...
		if (getMoveComponent()->getVelocity().getMagnitude() > 0)
			//...Rotate the player
			getTransform()->setForward(getMoveComponent()->getVelocity());

		//Set the players velocity 
		getMoveComponent()->setVelocity(moveDir.getNormalized() * 200);

		//For all the children that this actor has
		for (int i = 0; i < getTransform()->getChildCount(); i++)
		{
			//Rotate them around this actor
			getTransform()->getChildren()[i]->rotate((PI * 2) * deltaTime);
		}
	}
	//If the enemy is dead
	else
	{
		//Destroy
		Engine::destroy(this);
	}

	//Calls base update
	Enemy::update(deltaTime);
}

