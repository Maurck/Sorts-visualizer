#include "Pilar.h"

Pilar::Pilar(Vector2f initPos, Vector2f size) : Entity(initPos,"Textures/white.jpg"), size(size)
{
	sprite->setScale(50.f / (float)sprite->getTexture()->getSize().x, size.y / (float)sprite->getTexture()->getSize().y);
	sprite->setOrigin(0, sprite->getTexture()->getSize().y);
}

sf::Vector2f Pilar::GetSize()
{
	return size;
}

void Pilar::SetSize(Vector2f size)
{
	sprite->setScale(size.x / (float)sprite->getTexture()->getSize().x, size.y / (float)sprite->getTexture()->getSize().y);
}
