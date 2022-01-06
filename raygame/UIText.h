#pragma once
#include "Actor.h"
#include <raylib.h>

class UIText :
    public Actor
{
public:
    UIText(int x, int y, const char* name, const char* text, float width, float height, float fontSize, const char* font, Color
        textBoxColor, Color textColor);

    /// <summary>
    /// returns the text displayed on the UI text
    /// </summary>
    /// <returns>a const char* representing what is being displayed in the UI</returns>
    const char* getText() { return m_text; }

    /// <summary>
    /// sets the UI's text element to be something else
    /// </summary>
    /// <param name="value"> the value to set the text to.</param>
    void setText(const char* value) { m_text = value; }

    /// <summary>
    /// Returns the width of the UI element
    /// </summary>
    /// <returns>The UI element's width</returns>
    float getWidth() { return m_width; }

    /// <summary>
    /// Changes width of the UI element
    /// </summary>
    /// <param name="value">The value to set the UI element's width to</param>
    void setWidth(int value) { m_width = value; }


    /// <summary>
    /// Returns the height of the UI element
    /// </summary>
    /// <returns>The UI element's height</returns>
    float getHeight() { return m_height; }

    /// <summary>
    /// Changes the height of the UI element
    /// </summary>
    /// <param name="value">The value to set the UI element's height to</param>
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

