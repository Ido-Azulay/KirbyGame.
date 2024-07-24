#include "Inhale.h"
#include <iostream>
#include "SwordEnemy.h"
#include "PlantEnemy.h"
#include "FireEnemy.h"
#include "FlyingEnemy.h"
#include "IceManEnemy.h"

Inhale::Inhale()
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_inhale));
	m_char = 'I';

}
Inhale::Inhale(sf::Vector2f pos)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_inhale));
	m_char = 'I';
	m_sound.setBuffer(Resources::instance().getSound(Resources::s_airSuck));
	m_sound.play();
}



Inhale::~Inhale()
{

}


void Inhale::handleFloorCollison(float groundlevel,const sf::Time deltaTime)
{

}

void Inhale::rightAnimation(const sf::Time &deltaTime)
{
	m_numFrames = 4;
	m_frameWidth = 48/* width of a single frame */;
	m_frameHeight = 44/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth), (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

	if (m_currentFrame == m_numFrames - 1)
	{
		//m_isDisposed = true;
	}
} 


void Inhale::setDirection(Direction dir)
{
	m_direction = dir;
}

void Inhale::leftAnimation(const sf::Time &deltaTime)
{

}

void Inhale::move(const sf::Time &deltaTime, MovingVector& mov, StaticVector& stat)
{

	rightAnimation(deltaTime);	

	//m_isDisposed = true;
	for (const auto& moving : mov)
	{
		if (m_sprite.getGlobalBounds().intersects(moving->getBounds()))
		{
			moving->handleCollison(*this);
		}
	}
}



void Inhale::handleCollison(SwordEnemy& obj)
{
	obj.handleCollison(*this);
}


void Inhale::handleCollison(FireEnemy& obj)
{
	obj.handleCollison(*this);
}

void Inhale::handleCollison(PlantEnemy& obj)
{
	obj.handleCollison(*this);
}

void Inhale::handleCollison(FlyingEnemy& obj)
{
	obj.handleCollison(*this);
}

void Inhale::handleCollison(IceManEnemy& obj)
{
	obj.handleCollison(*this);
}

bool Inhale::isDirecrionRight()
{
	return m_direction == Direction::Right;
}