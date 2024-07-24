#include "Airpuff.h"
#include <iostream>
#include "SwordEnemy.h"

Airpuff::Airpuff()
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_AirPuff));
	m_char = 'F';
}

Airpuff::Airpuff(sf::Vector2f pos)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_AirPuff));
	m_char = 'F';
}



Airpuff::~Airpuff()
{

}
	

void Airpuff::handleFloorCollison(float groundlevel,const sf::Time &deltaTime)
{

}

void Airpuff::rightAnimation(const sf::Time &deltaTime)
{
	m_numFrames = 5;
	m_frameWidth = 24/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 4, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

	if (m_currentFrame == m_numFrames - 1)
	{
		m_isDisposed = true;
	}
}
	

void Airpuff::setDirection(Direction dir)
{
	m_direction = dir;
}
	
void Airpuff::leftAnimation(const sf::Time &deltaTime)
{

}

void Airpuff::move(const sf::Time &deltaTime, MovingVector& mov, StaticVector& stat)
{
	if (m_direction == Direction::Right)
	{
		rightAnimation(deltaTime);
		sf::Vector2f right(300, 0);
		m_sprite.move(right * deltaTime.asSeconds());
	}
	else {
		rightAnimation(deltaTime);
		sf::Vector2f right(-300, 0);
		m_sprite.move(right * deltaTime.asSeconds());
	}
	
	//m_isDisposed = true;
	for (const auto&  moving : mov )
	{
		if (m_sprite.getGlobalBounds().intersects(moving->getBounds()))
		{
			moving->handleCollison(*this);
		}
	}
}



void Airpuff::handleCollison(SwordEnemy& obj)
{

	m_isDisposed = true;
}


void Airpuff::handleCollison(FireEnemy& obj)
{
	m_isDisposed = true;
}

void Airpuff::handleCollison(PlantEnemy& obj)
{
	m_isDisposed = true;
}

void Airpuff::handleCollison(IceManEnemy& obj)
{
	m_isDisposed = true;
}

void Airpuff::handleCollison(OrangeEnemy& obj)
{
	m_isDisposed = true;
}

void Airpuff::handleCollison(FlyingEnemy& obj)
{
	m_isDisposed = true;
}


