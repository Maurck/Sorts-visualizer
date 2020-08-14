#include "Entity.h"

Entity::Entity(Vector2f initPos, string texturePath)
{
	texture = new Texture;
	texture->loadFromFile(texturePath);
	sprite = new Sprite(*texture);

	sprite->setPosition(initPos);
}

void Entity::Draw(RenderWindow* window)
{
	window->draw(*sprite);
}

sf::Vector2f Entity::GetPosition()
{
	return sprite->getPosition();
}

void Entity::SetPosition(Vector2f pos)
{
	sprite->setPosition(pos);
}

