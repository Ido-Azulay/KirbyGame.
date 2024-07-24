#include "LeftWall.h"

LeftWall::LeftWall() {

	createLine();

	int i = 0;

	for (const auto& lines : m_Line)
	{
		std::vector<sf::RectangleShape> rect = createRectanglesOnLines(lines);
		m_rectangles.push_back(rect);
	}

}


void LeftWall::createLine()
{

	sf::VertexArray Line;
	Line.setPrimitiveType(sf::LinesStrip);

	float rightOffSet = 25.f;
	float downOffSet = 65.f;

	Line.append(sf::Vertex(sf::Vector2f(20.f + rightOffSet, 61.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(20.f + rightOffSet, 1025.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(20.f + rightOffSet, 1185.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(20.f + rightOffSet, 1665.f + downOffSet)));


	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(420.f + rightOffSet, 625.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(420.f + rightOffSet, 540.f + downOffSet)));


	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(660.f + rightOffSet, 545.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(660.f + rightOffSet, 470.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(900.f + rightOffSet, 460.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(900.f + rightOffSet, 390.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(980.f + rightOffSet, 620.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(980.f + rightOffSet, 785.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(660.f + rightOffSet, 710.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(660.f + rightOffSet, 865.f + downOffSet)));


	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(340.f + rightOffSet, 785.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(340.f + rightOffSet, 940.f + downOffSet)));


	m_Line.push_back(Line);

	/*Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(980.f + rightOffSet, 1100.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(980.f + rightOffSet, 1040.f + downOffSet)));*/


	//m_Line.push_back(Line);

	//////////////////////////////////Second Map
	downOffSet = 75.f;

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2845.f + rightOffSet, 2630.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2845.f + rightOffSet, 1515.f + downOffSet)));


	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2915.f + rightOffSet, 2235.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2915.f + rightOffSet, 2270.f + downOffSet)));


	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2915.f + rightOffSet, 1915.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2915.f + rightOffSet, 1950.f + downOffSet)));


	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2680.f + rightOffSet, 1515.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2680.f + rightOffSet, 1355.f + downOffSet)));


	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2530.f + rightOffSet, 715.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2530.f + rightOffSet, 1355.f + downOffSet)));


	m_Line.push_back(Line);



	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2600.f + rightOffSet, 1040.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2600.f + rightOffSet, 1070.f + downOffSet)));


	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3080.f + rightOffSet, 310.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3080.f + rightOffSet, 630.f + downOffSet)));


	m_Line.push_back(Line);



	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3240.f + rightOffSet, 475.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3240.f + rightOffSet, 505.f + downOffSet)));


	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2680.f + rightOffSet, 215.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2680.f + rightOffSet, 75.f + downOffSet)));


	m_Line.push_back(Line);



	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2520.f + rightOffSet, 235.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2520.f + rightOffSet, 470.f + downOffSet)));


	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2600.f + rightOffSet, 630.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2600.f + rightOffSet, 700.f + downOffSet)));


	m_Line.push_back(Line);


	/////////////////////////third map
	downOffSet = 65.f;

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5020.f + rightOffSet, 1888.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5020.f + rightOffSet, 1650.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5490.f + rightOffSet, 1730.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5490.f + rightOffSet, 1970.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5725.f + rightOffSet, 1807.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5725.f + rightOffSet, 1490.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6762.f + rightOffSet, 1490.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6762.f + rightOffSet, 1420.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6285.f + rightOffSet, 1180.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6285.f + rightOffSet, 1252.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6049.f + rightOffSet, 1245.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6049.f + rightOffSet, 1327.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5655.f + rightOffSet, 1014.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5655.f + rightOffSet, 1095.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5565.f + rightOffSet, 1095.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5565.f + rightOffSet, 1170.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5495.f + rightOffSet, 1170.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5495.f + rightOffSet, 1255.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(4605.f + rightOffSet, 938.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(4605.f + rightOffSet, 620.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5165.f + rightOffSet, 620.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5165.f + rightOffSet, 925.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5878.f + rightOffSet, 620.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5878.f + rightOffSet, 925.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6619.f + rightOffSet, 620.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6619.f + rightOffSet, 925.f + downOffSet)));

	m_Line.push_back(Line);
}

float LeftWall::isCollison(sf::FloatRect obj)
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