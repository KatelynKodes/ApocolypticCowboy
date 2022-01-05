#pragma once
#include "Component.h"
#include "UIText.h";

class HealthComponent :
    public Component
{
public:
    void update(float deltaTime) override;
    void draw() override;

    void setMinHealth(float value) { m_currHealth = value; }
    void setMaxHealth(float value) { m_maxHealth = value; }
    void setUIText(UIText* text) { m_healthText = text; }

private:
    float m_currHealth;
    float m_maxHealth;
    UIText* m_healthText;
};

