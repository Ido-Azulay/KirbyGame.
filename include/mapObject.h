#pragma once

#include "ConstAndEnum.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Kirby;

class mapObject {
public:
	mapObject();
	~mapObject() = default;
	virtual void createLine() = 0;
	void drawLine(sf::RenderWindow& window) const;


	std::vector<sf::RectangleShape> createRectanglesOnLines(const sf::VertexArray& lines);


protected:
	std::vector<sf::VertexArray>  m_Line;
	std::vector <std::vector<sf::RectangleShape>> m_rectangles;
	
};