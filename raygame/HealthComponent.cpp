#include "HealthComponent.h"
#include "UIText.h"
#include <string.h>
#include <iostream>
void HealthComponent::update(float deltaTime)
{
	delete[] m_healthText;

	m_healthText = new char[20]{ " " };

	sprintf_s(m_healthText, sizeof(char) * 20, "%d", (int)m_currHealth);

	m_healthTextComponent->setText(m_healthText);
}

void HealthComponent::draw()
{
	m_healthTextComponent->draw();
}
