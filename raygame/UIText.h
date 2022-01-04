#pragma once
#include "Actor.h"
#include <raylib.h>

class UIText :
    public Actor
{
public:
    UIText(int x, int y, const char* name, const char* text, float width, float height, float fontSize, const char* font, Color
        textBoxColor, Color textColor);

    //Getters and setters
    const char* getText() { return m_text; }
    void setText(const char* value) { m_text = value; }

    float getWidth() { return m_width; }
    void setWidth(int value) { m_width = value; }

    float getHeight() { return m_height; }
    void setHeight(int value) { m_height = value; }

    //Draw
    void draw() override;

private:
    const char* m_text;
    float m_width;
    float m_height;
    int m_fontSize;
    Font m_font;
    Color m_textBoxColor;
    Color m_textColor;
};

