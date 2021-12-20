#include "FollowComponent.h"

MathLibrary::Vector2 FollowComponent::GetIntendedPosition()
{
    return m_chasee->getTransform()->getLocalPosition() - getOwner()->getTransform()->getLocalPosition();
}
