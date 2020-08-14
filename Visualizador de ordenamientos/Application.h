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
	Event* gameEvent;
	int maxPilars = 15;
	vector<Pilar> pilars;
public:
	Application(Vector2i res, string title);
	void Draw();
	void Start();
	void Loop();
	void ProcessEvents();
	void InitPilars();
	void InitPilar(float &position);
	void BubbleSort();
};