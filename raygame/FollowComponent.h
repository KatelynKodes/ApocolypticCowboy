#pragma once
#include "Component.h"
#include "Actor.h"
#include "Transform2D.h"

class FollowComponent :
    public Component
{
public:
    /// <summary>
    /// Gets the players position to return the intended direction of the owner
    /// </summary>
    /// <returns> Vector2 of the intended direction </returns>
    MathLibrary::Vector2 GetIntendedPosition();
    
    /// <summary>
    /// Sets the chasee variable to be a new Actor Pointer
    /// </summary>
    /// <param name="newChasee"> Actor to change the chasee variable to</param>
    void setChasee(Actor* newChasee) { m_chasee = newChasee; }

private:
    Actor* m_chasee = nullptr;
};

