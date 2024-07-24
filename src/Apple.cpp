#include "Apple.h"
#include "Kirby.h"


Apple::Apple(const sf::Vector2f& pos) : StaticObject(pos, Resources::instance().getTexture(Resources::t_apple))
{

}


Apple::~Apple()
{

}

void Apple::handleCollison(Kirby& obj)
{
    m_isDisposed = true;
    obj.handleCollison(*this);
}