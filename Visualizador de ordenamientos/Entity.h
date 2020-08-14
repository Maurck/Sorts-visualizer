#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class Entity
{
public:
	Texture* texture;
	Sprite* sprite;
public:
	Entity(Vector2f initPos, string texturePath);
	void Draw(RenderWindow* window);
	Vector2f GetPosition();
	void SetPosition(Vector2f pos);
};
