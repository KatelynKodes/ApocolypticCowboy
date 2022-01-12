#pragma once
#include "Component.h"
#include "UIText.h";

class HealthComponent :
    public Component
{
public:
    void update(float deltaTime) override;
    void draw() override;

    /// <summary>
    /// Sets the current helth of the health component 
    /// </summary>
    /// <param name="value"> the value to set the float to</param>
    void setCurrHealth(float value) { m_currHealth = value; }

    /// <summary>
    /// Sets the UItext used to display the health of the enemy
    /// </summary>
    /// <param name="value"></param>
    void setUIText(UIText* text) { m_healthTextComponent = text; }

private:
    float m_currHealth;
    UIText* m_healthTextComponent;
    char* m_healthText;
};

