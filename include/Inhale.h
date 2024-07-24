#pragma once

#include "MovingObject.h"
#include <SFML/Graphics.hpp>

class Inhale : public MovingObject
{
public:
	Inhale();
	Inhale(sf::Vector2f pos);
	~Inhale();

	virtual void move(const sf::Time &delta, MovingVector& mov, StaticVector& stat) override;
	void setDirection(Direction dir);
	virtual void updateDirection(sf::Vector2f& obj, int num) {};

	void handleFloorCollison(float groundlevel,const sf::Time deltaTime);
	virtual void handleCollison(Kirby& obj) {};
	virtual void handleCollison(SwordEnemy& obj);
	virtual void handleCollison(KirbyStar& obj) {};
	virtual void handleCollison(Airpuff& obj) {};
	virtual void handleCollison(PlantEnemy& obj);
	virtual void handleCollison(FireEnemy& obj);
	virtual void handleCollison(FlyingEnemy& obj);
	virtual void handleCollison(IceManEnemy& obj);
	
	bool isDirecrionRight();

private:
	void rightAnimation(const sf::Time &deltaTime);
	void leftAnimation(const sf::Time &deltaTime);
	sf::Sound m_sound;

};


