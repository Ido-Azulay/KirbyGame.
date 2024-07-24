#include "Spike.h"

Spike::Spike() {

	createLine();

	int i = 0;

	for (const auto& lines : m_Line)
	{
		std::vector<sf::RectangleShape> rect = createRectanglesOnLines(lines);
		m_rectangles.push_back(rect);
	}

}


void Spike::createLine()
{

	sf::VertexArray Line;
	Line.setPrimitiveType(sf::LinesStrip);

	float rightOffSet = 25.f;
	float downOffSet = -5.f;


	/// ///////////////////////third map

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5878.f + rightOffSet, 925.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6200.f + rightOffSet, 925.f + downOffSet)));

	m_Line.push_back(Line);
	Line.clear();

	
	Line.append(sf::Vertex(sf::Vector2f(6062.f + rightOffSet, 1420.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6380.f + rightOffSet, 1420.f + downOffSet)));

	m_Line.push_back(Line);
	Line.clear();


	Line.append(sf::Vertex(sf::Vector2f(5725.f + rightOffSet, 1420.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5882.f + rightOffSet, 1420.f + downOffSet)));

	m_Line.push_back(Line);
	Line.clear();


	Line.append(sf::Vertex(sf::Vector2f(5165.f + rightOffSet, 925.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5487.f + rightOffSet, 925.f + downOffSet)));

	m_Line.push_back(Line);
	Line.clear();


	
}


float Spike::isCollison(sf::FloatRect obj)
{
	for (const auto& rect : m_rectangles)
	{
		for (const auto& tiny_rects : rect)
		{
			if (tiny_rects.getGlobalBounds().intersects(obj))
			{
				return tiny_rects.getPosition().y;
			}
		}
	}

	return -10000;
}