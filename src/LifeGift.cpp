
#include "LifeGift.h"
#include "Kirby.h"

LifeGift::LifeGift(const sf::Vector2f& pos) : StaticObject(pos, Resources::instance().getTexture(Resources::t_kirbyLife))
{

}


LifeGift::~LifeGift()
{

}

void LifeGift::handleCollison(Kirby& obj)
{
    m_isDisposed = true;
    obj.handleCollison(*this);
}