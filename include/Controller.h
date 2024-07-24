/*
Conroller class - holding members of most classes, incharge to run and manage the game
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Map.h"
#include "Resources.h"
#include "GameObject.h"
#include "MovingObject.h"
#include "Menu.h"
#include <thread>
#include <chrono>
#include "ConstAndEnum.h"


class Controller
{
public:
	Controller(); // ctur
	void Run(); // start the program and open home screen.
	void RunGame(); // start the game


private:
	void drawMap();
	void updateMap();


	sf::RenderWindow m_window;
	sf::Clock m_clock;
	Map m_map;
	Menu m_menu;
	sf::Sound m_sound;
	sf::Music m_music;

	int m_level;
};