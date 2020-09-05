#pragma once

#include <stdlib.h>
#include <vector>
#include <stdio.h> 
#include <time.h>
#include "SFML/Graphics.hpp"
#include "Pilar.h"
#include <iostream>
#include <thread>

using namespace std;
using namespace sf;

class Application
{
private:
	RenderWindow* window;
	Event* appEvent;
	int maxPilars = 15;
	chrono::duration<double> speed = 0.1s;
	vector<Pilar> pilars;
	Clock dtClock;
	float dt;

	void InitWindow(Vector2i res, string title);
	void InitPilars();
	void InitPilar(float& position);
public:
	Application(Vector2i res, string title);
	~Application();

	void Draw();
	void BubbleSort();
	void Start();
	void UpdateDt();
	void UpdateEvents();
	void Update();
	void Loop();
};