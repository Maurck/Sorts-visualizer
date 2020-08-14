#include "Game.h"

Game::Game(Vector2i res, string title)
{
	window = new RenderWindow(VideoMode(res.x, res.y, 32), title);
	window->setFramerateLimit(60);

	isOrdered = true;
	index_i = 0;
	index_j = 0;

	gameEvent = new Event();

	Loop();
}

void Game::Draw()
{
	window->clear(Color::Blue);

	for (unsigned int i = 0; i < pilars.size(); i++)
	{
		pilars[i].Draw(window);
	}		

	window->display();
}

void Game::Loop()
{
	float position = 100;
	Clock clock;

	while (window->isOpen())
	{
		InitPilars(position,clock);
		ProcessEvents();
		Draw();
	}
}

void Game::ProcessEvents()
{
	while (window->pollEvent(*gameEvent))
	{
		switch (gameEvent->type)
		{
			case Event::Closed:
				window->close();
				exit(1);
			break;
		}
	}
}

void Game::InitPilars(float &position, Clock &clock)
{
	if (pilars.size() < maxPilars)
	{
		Time time;
		time = clock.getElapsedTime();

		if (time.asSeconds() > 0.1f)
		{
			InitPilar(position);
			clock.restart();
		}
	}
}

void Game::InitPilar(float &position)
{
	float height = float(rand() % 400) + 100.0f;
	Pilar pilar = Pilar(Vector2f(position, 700), Vector2f(50.0f, height));
	pilars.push_back(pilar);
	position += pilar.GetSize().x + 10;
}
