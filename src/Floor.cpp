#include "Floor.h"

Floor::Floor() {

	createLine();

	int i = 0;

	for (const auto& lines : m_Line)
	{
		std::vector<sf::RectangleShape> rect = createRectanglesOnLines(lines);
		m_rectangles.push_back(rect);
	}
	
}


void Floor::createLine()
{
	
	sf::VertexArray Line;
	Line.setPrimitiveType(sf::LinesStrip);

	float rightOffSet = 25.f;
	float downOffSet = 65.f;

	Line.append(sf::Vertex(sf::Vector2f(24.f + rightOffSet, 1665.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(340.f + rightOffSet, 1665.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(650.f + rightOffSet, 1500.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(830.f - rightOffSet, 1500.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(1150.f - rightOffSet, 1190.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(970.f + rightOffSet, 1025.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(900.f + rightOffSet, 1025.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(750.f + rightOffSet, 955.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(575.f + rightOffSet, 955.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(435.f + rightOffSet, 1025.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(265.f + rightOffSet, 1025.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(24.f + rightOffSet, 1025.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(175.f + rightOffSet, 1025.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(180.f + rightOffSet, 790.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(329.f + rightOffSet, 790.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(500.f + rightOffSet, 706.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(660.f + rightOffSet, 706.f + downOffSet)));

	m_Line.push_back(Line);
	
	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(830.f + rightOffSet, 622.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(975.f + rightOffSet, 622.f + downOffSet)));

	m_Line.push_back(Line);
	
	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(20.f + rightOffSet, 545.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(420.f + rightOffSet, 545.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(420.f + rightOffSet, 460.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(655.f + rightOffSet, 460.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(655.f + rightOffSet, 385.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(900.f + rightOffSet, 385.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(900.f + rightOffSet, 300.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(1135.f + rightOffSet, 300.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(975.f + rightOffSet, 1025.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(1140.f + rightOffSet, 1025.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6153.f + rightOffSet, 3446.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(7028.f + rightOffSet, 3446.f + downOffSet)));

	m_Line.push_back(Line);
	///////////////////////////////Second map
	downOffSet = 70.f;

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2845.f + rightOffSet, 2640.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3160.f + rightOffSet, 2640.f + downOffSet)));
	
	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3110.f + rightOffSet, 2400.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3160.f + rightOffSet, 2400.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2845.f + rightOffSet, 2235.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2915.f + rightOffSet, 2235.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3110.f + rightOffSet, 2075.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3160.f + rightOffSet, 2075.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2845.f + rightOffSet, 1915.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2915.f + rightOffSet, 1915.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3485.f + rightOffSet, 1515.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3190.f + rightOffSet, 1515.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2680.f + rightOffSet, 1515.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2840.f + rightOffSet, 1515.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2680.f + rightOffSet, 1355.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2530.f + rightOffSet, 1355.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2785.f + rightOffSet, 1195.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2845.f + rightOffSet, 1195.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2600.f + rightOffSet, 1040.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2520.f + rightOffSet, 1040.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2785.f + rightOffSet, 875.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2850.f + rightOffSet, 875.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2850.f + rightOffSet, 795.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3325.f + rightOffSet, 795.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3330.f + rightOffSet, 635.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3560.f + rightOffSet, 635.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3080.f + rightOffSet, 475.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3240.f + rightOffSet, 475.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2930.f + rightOffSet, 312.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3080.f + rightOffSet, 312.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2520.f + rightOffSet, 470.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2930.f + rightOffSet, 470.f + downOffSet)));

	m_Line.push_back(Line);

	downOffSet = 65.f;
	/// ///////////////////////third map

	

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5020.f + rightOffSet, 1888.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5250.f + rightOffSet, 1888.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5250.f + rightOffSet, 1730.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5490.f + rightOffSet, 1730.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5490.f + rightOffSet, 1970.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6456.f + rightOffSet, 1970.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6910.f + rightOffSet, 1490.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6910.f + rightOffSet, 1420.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6770 + rightOffSet, 1420.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6527.f + rightOffSet, 1185.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6380.f + rightOffSet, 1185.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6285.f + rightOffSet, 1175.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6124.f + rightOffSet, 1175.f + downOffSet)));

	m_Line.push_back(Line);

	//Line.clear();

	//Line.append(sf::Vertex(sf::Vector2f(6285.f + rightOffSet, 1185.f + downOffSet)));
	//Line.append(sf::Vertex(sf::Vector2f(6124.f + rightOffSet, 1185.f + downOffSet)));

	//m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6050.f + rightOffSet, 1245.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5880.f + rightOffSet, 1245.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6380.f + rightOffSet, 1417.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5130.f + rightOffSet, 1417.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(4630.f + rightOffSet, 938.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(4605.f + rightOffSet, 854.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(4780.f + rightOffSet, 854.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5010.f + rightOffSet, 620.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5165.f + rightOffSet, 620.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5487.f + rightOffSet, 850.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5725.f + rightOffSet, 620.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5878.f + rightOffSet, 620.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6209.f + rightOffSet, 850.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6446.f + rightOffSet, 620.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6615.f + rightOffSet, 620.f + downOffSet)));

	m_Line.push_back(Line);
	
	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6615.f + rightOffSet, 925.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(7000.f + rightOffSet, 925.f + downOffSet)));

	m_Line.push_back(Line);
}

float Floor::isCollison(sf::FloatRect obj)
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