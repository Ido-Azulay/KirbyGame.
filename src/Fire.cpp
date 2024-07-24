#include "Fire.h"
#include <iostream>
#include "SwordEnemy.h"
#include "PlantEnemy.h"
#include "OrangeEnemy.h"
#include "FireEnemy.h"
#include "FlyingEnemy.h"



Fire::Fire()
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_fire));
	m_char = '!';
	

}
Fire::Fire(sf::Vector2f pos , bool set)
{
	if (set)
	{
		m_sprite.setTexture(Resources::instance().getTexture(Resources::t_fire));
		m_sound.setBuffer(Resources::instance().getSound(Resources::s_fire));
		m_sound.setLoop(true);
		m_sound.play();
	}
	else {
		m_sprite.setTexture(Resources::instance().getTexture(Resources::t_ice));
		m_sound.setBuffer(Resources::instance().getSound(Resources::s_shootingIce));
		m_sound.setLoop(true);
		m_sound.play();
	}
	m_char = FIRE;
	m_frameDuration = 0.05f;
	}



Fire::~Fire()
{
	m_sound.stop();
}


void Fire::handleFloorCollison(float groundlevel,const sf::Time &deltaTime)
{

}

void Fire::rightAnimation(const sf::Time &deltaTime)
{
	
	m_numFrames = 7;
	m_frameWidth = 36/* width of a single frame */;
	m_frameHeight = 30/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration ) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 4, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

	if (m_currentFrame == m_numFrames - 1)
	{
		//m_isDisposed = true;
	}
}


void Fire::leftAnimation(const sf::Time &deltaTime)
{
	m_numFrames = 7;
	m_frameWidth = 36/* width of a single frame */;
	m_frameHeight = 30/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 4;


	m_sprite.setTextureRect(sf::IntRect(framecalc,  (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

	if (m_currentFrame == m_numFrames - 1)
	{
		//m_isDisposed = true;
	}
}


void Fire::setDirection(Direction dir)
{
	m_direction = dir;
}


void Fire::move(const sf::Time &deltaTime, MovingVector& mov, StaticVector& stat)
{

	if (m_direction == Direction::Right)
	{
		rightAnimation(deltaTime);
	}
	else leftAnimation(deltaTime);

	for (const auto& moving : mov)
	{
		if (m_sprite.getGlobalBounds().intersects(moving->getBounds()))
		{
			moving->handleCollison(*this);
		}
	}
}


void Fire::handleCollison(SwordEnemy& obj)
{
	obj.handleCollison(*this);
}

void Fire::handleCollison(PlantEnemy& obj)
{
	obj.handleCollison(*this);
}

void Fire::handleCollison(OrangeEnemy& obj)
{
	obj.handleCollison(*this);
}

void Fire::handleCollison(FlyingEnemy& obj)
{
	obj.handleCollison(*this);
}


void Fire::handleCollison(FireEnemy& obj)
{
	obj.handleCollison(*this);
}

bool Fire::isDirecrionRight()
{
	return m_direction == Direction::Right;
}