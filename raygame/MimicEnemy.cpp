#include "MimicEnemy.h"
#include "MoveComponent.h";
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "Transform2D.h"

void MimicEnemy::start()
{
	setSpriteComponent(dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/mimic.png"))));
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	setMoveComponent(dynamic_cast<MoveComponent*>(addComponent(new MoveComponent())));
	getMoveComponent()->setMaxSpeed(10);

}

void MimicEnemy::update(float deltaTime)
{
	

	MathLibrary::Vector2 moveDir= m_inputComponent->getReverseMoveAxis();

	//If the velocity is greater than 0...
	if (getMoveComponent()->getVelocity().getMagnitude() > 0)
		//...Rotate the player
		getTransform()->setForward(getMoveComponent()->getVelocity());

	//Set the players velocity 
	getMoveComponent()->setVelocity(moveDir.getNormalized() * 200);

	Enemy::update(deltaTime);
}
