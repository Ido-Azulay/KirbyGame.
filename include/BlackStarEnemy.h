#pragma once

#include "MovingObject.h"
#include <SFML/Graphics.hpp>


class BlackStarEnemy : public MovingObject
{
public:
	BlackStarEnemy(); //
	BlackStarEnemy(sf::Vector2f pos, int travelLimit);//
	~BlackStarEnemy();

	virtual void move(const sf::Time& delta, MovingVector& mov, StaticVector& stat) override;
	virtual void updateDirection(sf::Vector2f& obj, int num) {};

	virtual void handleCollison(Kirby& obj);
	/*virtual void handleCollison(Airpuff& obj);
	virtual void handleCollison(Inhale& obj);
	virtual void handleCollison(KirbyStar& obj);
	virtual void handleCollison(Fire& obj);*/

private:
	void animation(const sf::Time& deltaTime);
	/*void rightAnimation(const sf::Time& deltaTime);
	void inhaledAnimation(const sf::Time& deltaTime);*/
	//void inhaledLeftAnimation(sf::Time deltaTime);
	//void leftAnimation(sf::Time deltaTime);
	//void inhaledAnimation(sf::Time deltaTime);
	//void inhaledLeftAnimation(sf::Time deltaTime);
	float m_traveld;
	float m_flightTraveld;
	float m_travelLimit;
	float m_hightLimit;
	bool m_isInhaled = false;



};


