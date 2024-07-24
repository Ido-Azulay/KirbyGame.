#include "SwordEnemy.h"
#include <iostream>
#include "Kirby.h"
#include "Airpuff.h"
#include "Inhale.h"
#include "KirbyStar.h"
#include "PlantEnemy.h"
#include "Fire.h"

//--------------------------------------------------------------------------------------------------------

const int SIZE = 10;

//--------------------------------------------------------------------------------------------------------

PlantEnemy::PlantEnemy()
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_plantEnemy));
	m_char = 'W';
}

//--------------------------------------------------------------------------------------------------------

PlantEnemy::PlantEnemy(sf::Vector2f pos, int travelLimit)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_plantEnemy));
	m_char = 'W';
	m_sprite.setPosition(pos);
	m_original_position = pos;
	m_frameDuration = 0.15;
}

//---------------------------------------------------------------------------------------------------------

PlantEnemy::~PlantEnemy() {}

//---------------------------------------------------------------------------------------------------------

void PlantEnemy::move(const sf::Time &deltaTime, MovingVector& mov, StaticVector& stat)
{


	if (m_isDead)
	{
		deadAnimation(deltaTime);
	}

	else if (m_isInhaled)
	{
		if (m_direction == Direction::Right) {

			inhaledAnimation(deltaTime);
			m_velocity.x += 1.2;
			m_velocity.y += m_gravity;
			m_sprite.move(m_velocity);
		}

		else {
			inhaledAnimation(deltaTime);
			m_velocity.x -= 1.2;
			m_velocity.y += m_gravity;
			m_sprite.move(m_velocity);
		}
	}
	else
	{
		rightAnimation(deltaTime);
		//m_velocity.x = 0.1;
		m_velocity.y += m_gravity;
		m_sprite.move(m_velocity);

	}
}


//-------------------------------------------------------------------------------------------------------------

void PlantEnemy::handleCollison(Kirby& obj)
{
	if (!m_isDead) {
		if (m_isInhaled)
		{

			m_sprite.setPosition(6639.f, 3167.f); //island of the dead
		}
		else {
			m_currentFrame = 0;
			m_isDead = true;
			m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));
		}
		obj.handleCollison(*this);
	}
}

void PlantEnemy::handleCollison(Airpuff& obj)
{
	m_currentFrame = 0;
	m_isDead = true;
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));

	obj.handleCollison(*this);
}

void PlantEnemy::handleCollison(KirbyStar& obj)
{
	m_currentFrame = 0;
	m_isDead = true;
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));

	obj.handleCollison(*this);
}

void PlantEnemy::handleCollison(Inhale& obj)
{
	if (obj.isDirecrionRight())
	{
		m_direction = Direction::Left;
	}
	else m_direction = Direction::Right;

	m_isInhaled = true;
}

void PlantEnemy::handleCollison(Fire& obj)
{

	m_currentFrame = 0;
	m_isDead = true;
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));
}


//---------------------------------------------------------------------------------------------------------------

void PlantEnemy::rightAnimation(const sf::Time &deltaTime)
{
	m_numFrames = 7;
	m_frameWidth = 24/* width of a single frame */;
	m_frameHeight = 28/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	float desiredFrameDuration = 0.2f; // Adjust this value to change the animation speed
	if (m_elapsedFrameTime >= desiredFrameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 4;

	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight) - 5, -m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

}

void PlantEnemy::inhaledAnimation(const sf::Time &deltaTime)
{
	m_currentFrame = 5;
	m_numFrames = 2;
	m_frameWidth = 24/* width of a single frame */;
	m_frameHeight = 28/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 4;

	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

}