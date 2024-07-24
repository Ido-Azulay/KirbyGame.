#pragma once

#include "MovingObject.h"
#include <SFML/Graphics.hpp>

class KirbyStar : public MovingObject
{
public:
	KirbyStar();
	KirbyStar(sf::Vector2f pos);
	~KirbyStar();

	virtual void move(const sf::Time &delta, MovingVector& mov, StaticVector& stat) override;
	void setDirection(Direction dir);
	virtual void updateDirection(sf::Vector2f& obj, int num) {};

	//void handleFloorCollison(float groundlevel, sf::Time deltaTime);
	void handleLeftWallCollison(float Walllevel, const sf::Time &deltaTime);
	void handleRightWallCollison(float Walllevel, const sf::Time &deltaTime);
	virtual void handleCollison(Kirby& obj) {};
	virtual void handleCollison(SwordEnemy& obj);
	virtual void handleCollison(FireEnemy& obj);
	virtual void handleCollison(PlantEnemy& obj);
	virtual void handleCollison(OrangeEnemy& obj);
	virtual void handleCollison(FlyingEnemy& obj);
	virtual void handleCollison(IceManEnemy& obj);

private:
	void rightAnimation(const sf::Time &deltaTime);
	void leftAnimation(const sf::Time &deltaTime);
	float m_starTime = 0;
};


