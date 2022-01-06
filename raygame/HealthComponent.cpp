#include "HealthComponent.h"
#include "UIText.h"
#include <string.h>
#include <iostream>
void HealthComponent::update(float deltaTime)
{
	
	const char* currHealthText = new char[20]{""};

	sprintf_s((char*)currHealthText, sizeof(char) * 20, "%d", (int)m_currHealth);

	m_healthText->setText(currHealthText);
}

void HealthComponent::draw()
{
	m_healthText->draw();
}
