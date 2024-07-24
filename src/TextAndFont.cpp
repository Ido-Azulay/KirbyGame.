#include "TextAndFont.h"
#include "Resources.h"



TextAndFont::TextAndFont()
{
	
	m_score_num.setFont(Resources::instance().getFont());
	m_score_num.setCharacterSize(60);
	m_score_num.setScale(1, 3);
	m_score_num.setFillColor(sf::Color::Magenta);
	m_score_num.setOutlineColor(sf::Color::Black);
	m_score_num.setOutlineThickness(2.f);

	
	//m_score_num.setPosition(sf::Vector2f(220, (WINDOW_HEIGT - 135)));
	m_score_num.setString("0");
}

TextAndFont::~TextAndFont()
{
	
}


void TextAndFont::setScore(int num)
{
	std::string str = std::to_string(num);
	
	m_score_num.setString(str);
}


void TextAndFont::draw(sf::RenderWindow& window) const
{
	window.draw(m_score_num);
}


void TextAndFont::setPosition(sf::Vector2f pos)
{
	m_score_num.setPosition(pos);
}