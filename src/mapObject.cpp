#include "mapObject.h"

mapObject::mapObject() {}

void mapObject::drawLine(sf::RenderWindow& window) const {

	//window.draw(m_floorLine);

	for (int i = 0; i < m_rectangles.size(); i++)
	{
		for (const auto& rectangle : m_rectangles[i])
		{
			window.draw(rectangle);
		}
	}
	
	
}


std::vector<sf::RectangleShape> mapObject::createRectanglesOnLines(const sf::VertexArray& lines)
{

	std::vector<sf::RectangleShape> rectangles;

	// Set the size and color of the rectangles
	const sf::Vector2f rectangleSize(4.f, 4.f);
	const sf::Color rectangleColor = sf::Color::Blue;

	// Iterate through the lines and create rectangles on them
	for (std::size_t i = 0; i < lines.getVertexCount() - 1; ++i)
	{
		// Get the start and end positions of the current line segment
		const sf::Vector2f& startPos = lines[i].position;
		const sf::Vector2f& endPos = lines[i + 1].position;

		// Calculate the direction and length of the line segment
		const sf::Vector2f dir = endPos - startPos;
		const float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);

		// Calculate the number of rectangles to draw on the line segment
		const int numRectangles = static_cast<int>(length / rectangleSize.x);

		// Calculate the step size for each rectangle
		const sf::Vector2f step = dir / static_cast<float>(numRectangles);

		// Create rectangles along the line segment
		sf::Vector2f rectPos = startPos;
		for (int j = 0; j < numRectangles; ++j)
		{
			// Create and position the rectangle
			sf::RectangleShape rectangle(rectangleSize);
			rectangle.setFillColor(rectangleColor);
			rectangle.setPosition(rectPos);

			// Add the rectangle to the vector
			rectangles.push_back(rectangle);

			// Move the position for the next rectangle
			rectPos += step;
		}
	}

	return rectangles;
}


