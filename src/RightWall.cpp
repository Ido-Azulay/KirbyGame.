#include "RightWall.h"

RightWall::RightWall() {

	createLine();

	int i = 0;

	for (const auto& lines : m_Line)
	{
		std::vector<sf::RectangleShape> rect = createRectanglesOnLines(lines);
		m_rectangles.push_back(rect);
	}

}


void RightWall::createLine()
{

	sf::VertexArray Line;
	Line.setPrimitiveType(sf::LinesStrip);

	float rightOffSet = 30.f;
	float downOffSet = 65.f;


	Line.append(sf::Vertex(sf::Vector2f(1150.f + rightOffSet, 1190.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(1150.f + rightOffSet, 61.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(180.f + rightOffSet, 625.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(180.f + rightOffSet, 545.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(420.f + rightOffSet, 545.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(420.f + rightOffSet, 460.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(655.f + rightOffSet, 385.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(655.f + rightOffSet, 460.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(900.f + rightOffSet, 385.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(900.f + rightOffSet, 300.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(180.f + rightOffSet, 790.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(180.f + rightOffSet, 940.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(500.f + rightOffSet, 865.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(500.f + rightOffSet, 705.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(825.f + rightOffSet, 780.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(825.f + rightOffSet, 622.f + downOffSet)));

	m_Line.push_back(Line);

	downOffSet = 75.f;

	////////////////////////////////////Second map
	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3180.f + rightOffSet, 2630.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3180.f + rightOffSet, 1515.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3090.f + rightOffSet, 2400.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3090.f + rightOffSet, 2430.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3090.f + rightOffSet, 2080.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3090.f + rightOffSet, 2110.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3485.f + rightOffSet, 1270.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3485.f + rightOffSet, 1515.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2850.f + rightOffSet, 795.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2850.f + rightOffSet, 1270.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2765.f + rightOffSet, 1195.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2765.f + rightOffSet, 1230.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2765.f + rightOffSet, 875.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2765.f + rightOffSet, 910.f + downOffSet)));

	m_Line.push_back(Line);



	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3330.f + rightOffSet, 795.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3330.f + rightOffSet, 635.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3485.f + rightOffSet, 230.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3485.f + rightOffSet, 635.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3330.f + rightOffSet, 230.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3330.f + rightOffSet, 75.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2930.f + rightOffSet, 315.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2930.f + rightOffSet, 470.f + downOffSet)));

	m_Line.push_back(Line);
	////////////////////////////////////Third Map

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5250.f + rightOffSet, 1888.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5250.f + rightOffSet, 1730.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5580.f + rightOffSet, 1650.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5580.f + rightOffSet, 1807.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6910.f + rightOffSet, 1490.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6910.f + rightOffSet, 1160.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6380.f + rightOffSet, 1185.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6380.f + rightOffSet, 1417.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6125.f + rightOffSet, 1185.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6125.f + rightOffSet, 1245.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5882.f + rightOffSet, 1245.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5882.f + rightOffSet, 1327.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5104.f + rightOffSet, 1255.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5104.f + rightOffSet, 1175.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5010.f + rightOffSet, 1175.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5010.f + rightOffSet, 1080.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(4937.f + rightOffSet, 1080.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(4937.f + rightOffSet, 1020.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(4860.f + rightOffSet, 1020.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(4860.f + rightOffSet, 931.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(4780.f + rightOffSet, 931.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(4780.f + rightOffSet, 890.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(7000.f + rightOffSet, 700.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(7000.f + rightOffSet, 925.f + downOffSet)));

	m_Line.push_back(Line);
}

float RightWall::isCollison(sf::FloatRect obj)
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