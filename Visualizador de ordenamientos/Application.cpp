#include "Application.h"

Application::Application(Vector2i res, string title)
{
	window = new RenderWindow(VideoMode(res.x, res.y, 32), title);
	window->setFramerateLimit(60);

	gameEvent = new Event();

	Loop();
}

void Application::Draw()
{
	window->clear(Color::Blue);

	for (unsigned int i = 0; i < pilars.size(); i++)
	{
		pilars[i].Draw(window);
	}		

	window->display();
}

void Application::Start()
{
	InitPilars();
	BubbleSort();
}

void Application::Loop()
{
	thread startWorker([this] { this->Start(); });
	while (window->isOpen())
	{
		ProcessEvents();
		Draw();
	}
	startWorker.join();
}

void Application::ProcessEvents()
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

void Application::InitPilars()
{
	float position = 100;
	for (int i = 0; i < maxPilars; i++)
	{
		InitPilar(position);
		this_thread::sleep_for(0.05s);
	}
}

void Application::InitPilar(float &position)
{
	float height = float(rand() % 400) + 100.0f;
	Pilar pilar = Pilar(Vector2f(position, 700), Vector2f(50.0f, height));
	pilars.push_back(pilar);
	position += pilar.GetSize().x + 10;
}

void Application::BubbleSort()
{
	for (int i = 0; i < pilars.size() - 1; i++)
	{
		for (int j = 0; j < pilars.size() - i - 1; j++)
		{
			if (pilars[j].GetSize().y > pilars[j + 1].GetSize().y)
			{
				float temp = pilars[j].GetSize().y;
				pilars[j].SetSize(Vector2f(pilars[j].GetSize().x, pilars[j + 1].GetSize().y));
				pilars[j+1].SetSize(Vector2f(pilars[j+1].GetSize().x, temp));
				this_thread::sleep_for(0.05s);
			}
		}
	}
}
