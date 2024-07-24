#pragma once

#include "MovingObject.h"
#include <SFML/Graphics.hpp>


class PlantEnemy : public MovingObject
{
public:
	PlantEnemy(); //
	PlantEnemy(sf::Vector2f pos, int travelLimit);//
	~PlantEnemy();

	virtual void move(const sf::Time &delta, MovingVector& mov, StaticVector& stat) override;
	//void setDirection(Direction dir);
	virtual void updateDirection(sf::Vector2f& obj, int num) {};

	virtual void handleCollison(Kirby& obj);
	virtual void handleCollison(Airpuff& obj);
	virtual void handleCollison(Inhale& obj);
	virtual void handleCollison(KirbyStar& obj);
	virtual void handleCollison(Fire& obj);

private:
	void rightAnimation(const sf::Time &deltaTime);
	void inhaledAnimation(const sf::Time &deltaTime);
	//void inhaledLeftAnimation(sf::Time deltaTime);
	//void leftAnimation(sf::Time deltaTime);
	//void inhaledAnimation(sf::Time deltaTime);
	//void inhaledLeftAnimation(sf::Time deltaTime);
	bool m_isInhaled = false;



};


