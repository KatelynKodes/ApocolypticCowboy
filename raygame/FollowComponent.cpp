#include "FollowComponent.h"

/// <summary>
/// Gets the intended position of where the enemy is supposed to chase
/// </summary>
/// <returns>the local position of the actor getting chased</returns>
MathLibrary::Vector2 FollowComponent::GetIntendedPosition()
{
    return m_chasee->getTransform()->getLocalPosition();
}
