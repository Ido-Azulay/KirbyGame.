#include "GameObject.h"


GameObject::GameObject()
{
	m_char = ' ';
}

GameObject::GameObject(const sf::Texture& tex) : m_sprite(tex)
{
	m_char = ' ';
}


GameObject::GameObject(const sf::Vector2f& pos, const sf::Texture& tex) : GameObject(tex) // reuse
{
	setPosition(pos);
	m_char = ' ';
}



//this function is for the handle collision of the game objects
//it is virtual and each object will have a different use of the function
void GameObject::handleCollison(GameObject& obj)
{
	obj.handleCollison(*this);
}



//draw object function
void GameObject::drawObject(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}


//======================================Set Functions==============================
//a function to set the position of an object on the screen 
void GameObject::setPosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
}


//set scales to a scalse calculated by Board class according to board and sprite size
void GameObject::setScale(const sf::Vector2f& scale)
{
	m_sprite.scale(scale);
}

//======================================GET FUNCTIONS=============================


//this function returns the position of an object
sf::Vector2f GameObject::getPosition() const
{

	return m_sprite.getPosition();
}

sf::FloatRect GameObject::getBounds() const
{
	return m_sprite.getGlobalBounds();
}

void GameObject::setFactor(sf::Vector2f factor)
{
	m_factor = factor;
}


char GameObject::getChar()
{
	return m_char;
}
