#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "ConstAndEnum.h"

class Menu
{
public:
	Menu();
	~Menu();

	char handleClick(const sf::Event::MouseButtonEvent& event , sf::RenderWindow& window);
	void handleHover(const sf::Event::MouseMoveEvent& event, sf::RenderWindow& window);
	void drawMenu(sf::RenderWindow& window);
	void drawHelp(sf::RenderWindow& window);
	void displayLoose(sf::RenderWindow& window);
	void displayWin(sf::RenderWindow& window);
	bool getIsHelp();
	void setIsHelp();

private:


	sf::Sound m_sound;
	sf::RectangleShape m_help_button;
	sf::RectangleShape m_exit_button;
	sf::RectangleShape m_play_button;
	sf::RectangleShape m_background;
	sf::RectangleShape m_back_button;
	sf::RectangleShape m_help_display;
	sf::RectangleShape m_gameOverDisplay;
	sf::RectangleShape m_WinDisplay;

	bool m_draw_help = false;
};

