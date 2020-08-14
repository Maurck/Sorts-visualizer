#pragma once
#include "Entity.h"

class Pilar : public Entity
{
private:
	Vector2f size;
public:
	Pilar(Vector2f initPos, Vector2f size);
	Vector2f GetSize();
	void SetSize(Vector2f size);
};
