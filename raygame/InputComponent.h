#pragma once
#include "Component.h"
#include <raylib.h>
#include <Vector2.h>

class InputComponent :
	public Component
{
public:

	InputComponent(const char* name = "InputComponent") : Component::Component(name) {}

	/// <summary>
	/// Gets the axis values that are used to move depending on the input being given by the player
	/// </summary>
	MathLibrary::Vector2 getMoveAxis();

	/// <summary>
	/// Gets the reverse axis values that are used to move depending on the input given by the player
	/// </summary>
	/// <returns>Vector2 representing the direction the method returns based on what key is inputted </returns>
	MathLibrary::Vector2 getReverseMoveAxis();

private:
	RAYLIB_H::KeyboardKey m_action1Key = RAYLIB_H::KeyboardKey::KEY_SPACE;
	RAYLIB_H::KeyboardKey m_action2Key = RAYLIB_H::KeyboardKey::KEY_LEFT_SHIFT;
	RAYLIB_H::KeyboardKey m_submitKey = RAYLIB_H::KeyboardKey::KEY_ENTER;
	RAYLIB_H::KeyboardKey m_cancelKey = RAYLIB_H::KeyboardKey::KEY_BACKSPACE;
};

