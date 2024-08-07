#pragma once

#include "MovingObject.h"
#include <SFML/Graphics.hpp>


class OrangeEnemy : public MovingObject
	{
	public:
		OrangeEnemy();
		OrangeEnemy(sf::Vector2f pos, int travelLimit);
		~OrangeEnemy();

		void setDirection(Direction dir);
		virtual void updateDirection(sf::Vector2f& obj, int num) {};
		virtual void move(const sf::Time &delta, MovingVector& mov, StaticVector& stat) override;
	
		virtual void handleCollison(Kirby& obj);
		virtual void handleCollison(Airpuff& obj);
		virtual void handleCollison(Inhale& obj);
		virtual void handleCollison(KirbyStar& obj);
		virtual void handleCollison(Fire& obj);

	private:
		void rightAnimation(const sf::Time &deltaTime);
		void leftAnimation(const sf::Time &deltaTime);
		void inhaledAnimation(const sf::Time &deltaTime);
		void inhaledLeftAnimation(const sf::Time &deltaTime);
		float m_traveld;
		float m_travelLimit;
		bool m_isInhaled = false;

	};



