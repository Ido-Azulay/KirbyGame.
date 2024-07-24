#include "StaticObject.h"



StaticObject::StaticObject() : m_isDisposed(false) {}

StaticObject::StaticObject(const sf::Vector2f& pos, const sf::Texture& tex) :GameObject(pos, tex) { m_isDisposed = false; }

StaticObject::~StaticObject() {}


//returns if an object is supposed to be erased by the board
bool StaticObject::get_is_disposed() const
{
	return m_isDisposed;
}

//set if m_is disposed so the board will erase it from the game
void StaticObject::set_is_disposed()
{
	m_isDisposed = true;
}
