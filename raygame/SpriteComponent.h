#pragma once
#include "Component.h"
class Texture2D;

class SpriteComponent :
	public Component
{
public:
	/// <param name="texture">Sets the sprites image to be this texture</param>
	/// <param name="name">The name of the component instance</param>
	SpriteComponent(Texture2D* texture, const char* name = "SpriteComponent");

	/// <param name="texture">The path of the texture to load</param>
	/// <param name="name">The name of the component instance</param>
	SpriteComponent(const char* path, const char* name = "SpriteComponent");

	~SpriteComponent() override; 

	/// <summary>
	/// returns the sprite's height
	/// </summary>
	/// <returns> the value of the m_health value </returns>
	int getHeight() { return m_height; }

	/// <summary>
	/// returns the sprite's width
	/// </summary>
	/// <returns> the value of the m_health value </returns>
	int getWidth() { return m_width; }

	void draw() override;

private:
	Texture2D* m_texture;
	int m_width;
	int m_height;
};

