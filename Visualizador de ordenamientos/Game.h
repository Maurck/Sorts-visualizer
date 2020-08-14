#pragma once

#include <stdlib.h>
#include <vector>
#include <stdio.h> 
#include <time.h>
#include "SFML/Graphics.hpp"
#include "Pilar.h"
#include <iostream>
#include <windows.h>

using namespace std;
using namespace sf;

class Game
{
private:
	RenderWindow* window;
	Event* gameEvent;
	int maxPilars = 15;
	vector<Pilar> pilars;
	bool isOrdered;
	int index_i, index_j;
public:
	Game(Vector2i res, string title);
	void Draw();
	void Loop();
	void ProcessEvents();
	void InitPilars(float &position, Clock &clock);
	void InitPilar(float &position);
	void OrderPilars(int& index_i, int& index_j, Clock &clock);
};