#include "HealthComponent.h"
#include "UIText.h"
#include <string.h>
#include <iostream>
void HealthComponent::update(float deltaTime)
{
	//Deletes the health text variable to clean up the memory
	delete[] m_healthText;

	//Allocates space for the health text above the actors
	m_healthText = new char[20]{ " " };

	//shows the text to the screen
	sprintf_s(m_healthText, sizeof(char) * 20, "%d", (int)m_currHealth);

	//Sets the text to be shown on screen
	m_healthTextComponent->setText(m_healthText);
}

void HealthComponent::draw()
{
	//Draws the text to the screen
	m_healthTextComponent->draw();
}
