#include "UIText.h"
#include "Transform2D.h"

UIText::UIText(int x, int y, const char* name, const char* text, float width, float height, float fontSize, 
	const char* font, Color textBoxColor = Color(), Color textColor = WHITE) : Actor :: Actor(x,y, name)
{
	m_text = text;
	m_width = width;
	m_height = height;
	m_fontSize = fontSize;
	m_font = RAYLIB_H::LoadFont(font);
	m_textBoxColor = textBoxColor;
	m_textColor = textColor;
}

void UIText::draw()
{
	Rectangle textbox = Rectangle{getTransform()->getLocalPosition().x, getTransform()->getLocalPosition().y, getWidth(), getHeight()};
	RAYLIB_H::DrawRectangleRec(textbox, m_textBoxColor);
	RAYLIB_H::DrawTextRec(m_font, getText(), textbox, (float)m_fontSize, 1, true, m_textColor);
}
