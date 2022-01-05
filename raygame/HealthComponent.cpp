#include "HealthComponent.h"
#include "UIText.h"
#include <string.h>
#include <iostream>
void HealthComponent::update(float deltaTime)
{
	
	const char* currHealthText = new char[20]{""};
	const char* slash = "/";

	sprintf_s((char*)currHealthText, sizeof(char) * 20, "%u", m_currHealth);
	strcat_s((char*)currHealthText, sizeof(char) * 20, slash);
	sprintf_s((char*)currHealthText, sizeof(char) * 20, "%u", m_maxHealth);

	m_healthText->setText(currHealthText);
}

void HealthComponent::draw()
{
	m_healthText->draw();
}
