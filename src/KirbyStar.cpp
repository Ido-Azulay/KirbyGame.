#include "KirbyStar.h"
#include <iostream>
#include "SwordEnemy.h"
#include "FireEnemy.h"
#include "FlyingEnemy.h"

KirbyStar::KirbyStar()
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_kirbyStar));
	m_char = '*';
	std::cout << " i was created \n";

}
KirbyStar::KirbyStar(sf::Vector2f pos)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_kirbyStar));
	m_char = '*';
	std::cout << " i was created \n";
	
	
}



KirbyStar::~KirbyStar()
{
	
}


void KirbyStar::handleLeftWallCollison(float Walllevel, const sf::Time &deltaTime)
{
	m_sound.play();
	m_isDisposed = true;

}
void KirbyStar::handleRightWallCollison(float Walllevel, const sf::Time &deltaTime)
{
	
	m_isDisposed = true;
}

//----------------------------------------------------------------------------------------------------------
void KirbyStar::rightAnimation(const sf::Time &deltaTime)
{

		m_numFrames = 4;
		m_frameWidth = 26 /* width of a single frame */;
		m_frameHeight = 24/* height of a single frame */;
		m_desiredRow = 0;// 0-based index of the desired row

		m_elapsedFrameTime += deltaTime.asSeconds();

		if (m_elapsedFrameTime >= m_frameDuration) {
			// Move to the next frame
			m_currentFrame = (m_currentFrame + 1) % m_numFrames;
			m_elapsedFrameTime = 0.0f;
		}

		m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) , (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
		m_sprite.setScale(3.0f, 3.0f);
}

void KirbyStar::leftAnimation(const sf::Time &deltaTime)
{
		m_numFrames = 10;
		m_frameWidth = 24/* width of a single frame */;
		m_frameHeight = 24/* height of a single frame */;
		m_desiredRow = 0;// 0-based index of the desired row

		m_elapsedFrameTime += deltaTime.asSeconds();

		if (m_elapsedFrameTime >= m_frameDuration) {
			// Move to the next frame

			m_currentFrame = (m_currentFrame + 1) % m_numFrames;

			m_elapsedFrameTime = 0.0f;
		}

		int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 4;


		m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
		m_sprite.setScale(3.0f, 3.0f);
}

//-------------------------------------------------------------------------------------------------------------------------

void KirbyStar::setDirection(Direction dir)
{
	m_direction = dir;
}



void KirbyStar::move(const sf::Time &deltaTime, MovingVector& mov, StaticVector& stat)
{

	m_starTime += deltaTime.asSeconds();
	if (m_direction == Direction::Right)
	{
		rightAnimation(deltaTime);
		sf::Vector2f right(20, 0);
		m_sprite.move(right);
	} 
	else {
		rightAnimation(deltaTime);
		sf::Vector2f right(-20, 0);
		m_sprite.move(right);
	}
	for (const auto& moving : mov)
	{
		if (m_sprite.getGlobalBounds().intersects(moving->getBounds()))
		{
			moving->handleCollison(*this);
		}
	}
	if (m_starTime > 2.f)
	{
		m_sound.play();
		m_isDisposed = true;
	}
}



void KirbyStar::handleCollison(SwordEnemy& obj)
{

	m_isDisposed = true;
}

void KirbyStar::handleCollison(FireEnemy& obj)
{
	m_isDisposed = true;
}


void KirbyStar::handleCollison(PlantEnemy& obj)
{
	m_isDisposed = true;
}



void KirbyStar::handleCollison(OrangeEnemy& obj)
{
	m_isDisposed = true;
}


void KirbyStar::handleCollison(FlyingEnemy& obj)
{
	m_isDisposed = true;
}

void KirbyStar::handleCollison(IceManEnemy& obj)
{
	m_isDisposed = true;
}
