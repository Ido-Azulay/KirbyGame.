#pragma once

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	StaticObject();
	StaticObject(const sf::Vector2f& pos, const sf::Texture& tex);
	virtual ~StaticObject();

	bool get_is_disposed() const;

	void set_is_disposed();

protected:
	bool m_isDisposed = false;

private:

};

