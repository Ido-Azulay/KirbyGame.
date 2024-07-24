#include "SwordEnemy.h"
#include <iostream>
#include "Kirby.h"
#include "Airpuff.h"
#include "Inhale.h"
#include "KirbyStar.h"
#include "PlantEnemy.h"
#include "Fire.h"
#include "BlackStarEnemy.h"

//--------------------------------------------------------------------------------------------------------

const int SIZE = 10;

//--------------------------------------------------------------------------------------------------------

BlackStarEnemy::BlackStarEnemy() :m_traveld(0.0f), m_travelLimit(2.0f), m_hightLimit(1.0f)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_blackStarEnemy));
	m_char = BLACKSTARENEMY;
}

//--------------------------------------------------------------------------------------------------------

BlackStarEnemy::BlackStarEnemy(sf::Vector2f pos, int travelLimit)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_blackStarEnemy));
	m_char = BLACKSTARENEMY;
	m_sprite.setPosition(pos);
	m_original_position = pos;
	m_frameDuration = 0.15;
	m_hightLimit = travelLimit;
}

//---------------------------------------------------------------------------------------------------------

BlackStarEnemy::~BlackStarEnemy() {}

//---------------------------------------------------------------------------------------------------------

void BlackStarEnemy::move(const sf::Time& deltaTime, MovingVector& mov, StaticVector& stat)
{
	    
		m_flightTraveld += deltaTime.asSeconds();
		
		
		float flyDuration = m_hightLimit;
		float flyClosedDuration = m_hightLimit;

			if (m_flightTraveld <= flyDuration)
			{
				m_velocity.y = -3;
			}
			else if (m_flightTraveld <= flyDuration + flyClosedDuration)
			{
				m_velocity.y = 3;
			
			}
			else if (m_flightTraveld >= m_hightLimit * 2)
			{
				m_flightTraveld = 0;

			}
			m_sprite.move(m_velocity);
			animation(deltaTime);

	}

//-------------------------------------------------------------------------------------------------------------
//                             collision with kirby
//-------------------------------------------------------------------------------------------------------------

void BlackStarEnemy::handleCollison(Kirby& obj)
{
		obj.handleCollison(*this);
}
//----------------------Animation--------------------------------------------------------------
void BlackStarEnemy::animation(const sf::Time& deltaTime)
{
	m_numFrames = 4;
	m_frameWidth = 24/* width of a single frame */;
	m_frameHeight = 30/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	float desiredFrameDuration = 0.2f; // Adjust this value to change the animation speed
	if (m_elapsedFrameTime >= desiredFrameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 3;

	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight) - 5, -m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

}