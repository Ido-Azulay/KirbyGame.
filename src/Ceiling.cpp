#include "Ceiling.h"

Ceiling::Ceiling() {

	createLine();

	int i = 0;

	for (const auto& lines : m_Line)
	{
		std::vector<sf::RectangleShape> rect = createRectanglesOnLines(lines);
		m_rectangles.push_back(rect);
	}

}


void Ceiling::createLine()
{

	sf::VertexArray Line;
	Line.setPrimitiveType(sf::LinesStrip);

	float rightOffSet = 30.f;
	float downOffSet = 65.f;

	Line.append(sf::Vertex(sf::Vector2f(15.f + rightOffSet, 61.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(1135.f + rightOffSet, 61.f + downOffSet)));


	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(180.f + rightOffSet, 625.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(420.f + rightOffSet, 625.f + downOffSet)));


	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(420.f + rightOffSet, 545.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(655.f + rightOffSet, 545.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(655.f + rightOffSet, 460.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(900.f + rightOffSet, 460.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(900.f + rightOffSet, 385.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(1130.f + rightOffSet, 385.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(24.f + rightOffSet, 1185.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(96.f + rightOffSet, 1108.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(165.f + rightOffSet, 1108.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(270.f + rightOffSet, 1108.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(490.f + rightOffSet, 1108.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(570.f + rightOffSet, 1180.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(745.f + rightOffSet, 1180.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(820.f + rightOffSet, 1108.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(970.f + rightOffSet, 1108.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(180.f + rightOffSet, 940.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(330.f + rightOffSet, 940.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(500.f + rightOffSet, 865.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(660.f + rightOffSet, 865.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(975.f + rightOffSet, 780.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(822.f + rightOffSet, 780.f + downOffSet)));

	m_Line.push_back(Line);

	///////////////////////////////////Second map
	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3090.f + rightOffSet, 2432.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3160.f + rightOffSet, 2432.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2840.f + rightOffSet, 2273.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2915.f + rightOffSet, 2273.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3090.f + rightOffSet, 2112.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3160.f + rightOffSet, 2112.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2840.f + rightOffSet, 1950.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2915.f + rightOffSet, 1950.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2840.f + rightOffSet, 1270.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3480.f + rightOffSet, 1270.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2765.f + rightOffSet, 1230.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2845.f + rightOffSet, 1230.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2520.f + rightOffSet, 1070.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2600.f + rightOffSet, 1070.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2765.f + rightOffSet, 915.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2845.f + rightOffSet, 915.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2520.f + rightOffSet, 715.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2600.f + rightOffSet, 715.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3080.f + rightOffSet, 630.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2600.f + rightOffSet, 630.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3320.f + rightOffSet, 230.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(3484.f + rightOffSet, 230.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(3320.f + rightOffSet, 75.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2680.f + rightOffSet, 75.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(2520.f + rightOffSet, 235.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(2680.f + rightOffSet, 235.f + downOffSet)));

	m_Line.push_back(Line);

  ///////////////////////////////////////Third map

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5020.f + rightOffSet, 1650.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5580.f + rightOffSet, 1650.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5580.f + rightOffSet, 1800.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5725.f + rightOffSet, 1800.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5725.f + rightOffSet, 1490.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6762.f + rightOffSet, 1490.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6910.f + rightOffSet, 1160.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6765.f + rightOffSet, 1014.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5655.f + rightOffSet, 1014.f + downOffSet)));


	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5655.f + rightOffSet, 1095.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5565.f + rightOffSet, 1095.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5565.f + rightOffSet, 1170.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5495.f + rightOffSet, 1170.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5495.f + rightOffSet, 1255.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5105.f + rightOffSet, 1255.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5105.f + rightOffSet, 1175.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(5010.f + rightOffSet, 1175.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5010.f + rightOffSet, 1080.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(4937.f + rightOffSet, 1080.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(4937.f + rightOffSet, 1020.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(4861.f + rightOffSet, 1020.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(4861.f + rightOffSet, 931.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(4780.f + rightOffSet, 931.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(4605.f + rightOffSet, 620.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(4851.f + rightOffSet, 357.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6685.f + rightOffSet, 357.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(7000.f + rightOffSet, 700.f + downOffSet)));

	m_Line.push_back(Line);


	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(6125.f + rightOffSet, 1245.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6258.f + rightOffSet, 1245.f + downOffSet)));

	m_Line.push_back(Line);

	Line.clear();

	Line.append(sf::Vertex(sf::Vector2f(5882.f + rightOffSet, 1327.f + downOffSet)));
	Line.append(sf::Vertex(sf::Vector2f(6050.f + rightOffSet, 1327.f + downOffSet)));

	m_Line.push_back(Line);
}

float Ceiling::isCollison(sf::FloatRect obj)
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