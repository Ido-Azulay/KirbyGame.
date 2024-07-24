#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>


class TextAndFont
{
public:
	TextAndFont();
	~TextAndFont();

	char numToString(int num) const;
	void setScore(int num);
	void draw(sf::RenderWindow& window) const;
	void setPosition(sf::Vector2f pos);

private:

	sf::Text m_score_num;
	
};
