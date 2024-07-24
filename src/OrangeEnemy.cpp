#include "SwordEnemy.h"
#include <iostream>
#include "Kirby.h"
#include "Airpuff.h"
#include "Inhale.h"
#include "KirbyStar.h"
#include "OrangeEnemy.h"
#include "Fire.h"


const int SIZE = 10;

OrangeEnemy::OrangeEnemy() :m_traveld(0.0f), m_travelLimit(2.0f)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_orangeEnemy));
	m_char = 'O';


}
OrangeEnemy::OrangeEnemy(sf::Vector2f pos, int travelLimit) :m_traveld(0.0f), m_travelLimit(travelLimit)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_orangeEnemy));
	m_char = 'O';
	m_sprite.setPosition(pos);
	m_original_position = pos;
	m_frameDuration = 0.15;
	m_direction = Direction::Right;
}

OrangeEnemy::~OrangeEnemy() {}

// SET & GET ---------------------------------------------//
void OrangeEnemy::setDirection(Direction dir)
{
	m_direction = dir;
}
//----------------------Animation-------------------------//

void OrangeEnemy::leftAnimation(const sf::Time &deltaTime)
{
	m_numFrames = 5;
	m_frameWidth = 23.6/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row



	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 6, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);
}
//------------------------------------------------------------------------------------------------
void OrangeEnemy::rightAnimation(const sf::Time &deltaTime)
{
	m_numFrames = 5;
	m_frameWidth = 23.6/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame

		m_currentFrame = (m_currentFrame + 1) % m_numFrames;

		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 6;


	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);
}
//-------------------------------------------------------------------------------------------------

void OrangeEnemy::inhaledAnimation(const sf::Time &deltaTime)
{
	m_numFrames = 1;
	m_frameWidth = 26/* width of a single frame */;
	m_frameHeight = 26/* height of a single frame */;
	m_desiredRow = 2;// 0-based index of the desired row



	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 5, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);
}

void OrangeEnemy::inhaledLeftAnimation(const sf::Time &deltaTime)
{
	m_currentFrame = 1;
	m_numFrames = 1;
	m_frameWidth = 24 /* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 3;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame ) * m_frameWidth) + 4;

	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

}



//--------------------------------------:handleCollisions:-------------------------------------------------

void OrangeEnemy::handleCollison(Kirby& obj)
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



void OrangeEnemy::handleCollison(Airpuff& obj)
{
	//if on super mode Pacman is not eaten and he gets 10 points
	//m_isDisposed = true;
	//m_isDisposed = true;
	//m_sprite.setPosition(6639.f, 3167.f); //island of the dead
	m_currentFrame = 0;
	m_isDead = true;
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));
	obj.handleCollison(*this);
}

void OrangeEnemy::handleCollison(Inhale& obj)
{
	if (obj.isDirecrionRight())
	{
		m_direction = Direction::Left;
	}
	else m_direction = Direction::Right;

	m_isInhaled = true;
}


void OrangeEnemy::handleCollison(Fire& obj)
{

	m_currentFrame = 0;
	m_isDead = true;
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));
}

void OrangeEnemy::handleCollison(KirbyStar& obj)
{
	m_currentFrame = 0;
	m_isDead = true;
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));

	obj.handleCollison(*this);
}

//-----------------------------------------MOVE-----------------------------------------------------


void OrangeEnemy::move(const sf::Time &deltaTime, MovingVector& mov, StaticVector& stat)
{

	if (m_isDead)
	{
		deadAnimation(deltaTime);
	}

	else if (m_isInhaled)
	{
		if (m_direction == Direction::Right) {

			inhaledAnimation(deltaTime);
			m_velocity.x += 3;
			m_velocity.y += m_gravity;
			m_sprite.move(m_velocity);
		}
		else {
			inhaledAnimation(deltaTime);
			m_velocity.x -= 3;
			m_velocity.y += m_gravity;
			m_sprite.move(m_velocity);
		}
	}
	else {


		m_traveld += deltaTime.asSeconds();

		float eyeOpenDuration = m_travelLimit;
		float eyeClosedDuration = m_travelLimit;

		if (m_traveld <= eyeOpenDuration) {
			// Display the frame with open eyes
			
			rightAnimation(deltaTime);
			
			if (!m_isColidingWithLeftWall)
			{
				m_velocity.x = -4;
				m_velocity.y += m_gravity;
				m_sprite.move(m_velocity);
			}
		}
		else if (m_traveld <= eyeOpenDuration + eyeClosedDuration) {


			leftAnimation(deltaTime);
			
			if (!m_isColidingWithRightWall)
			{
				m_velocity.x = 4;
				m_velocity.y += m_gravity;
				m_sprite.move(m_velocity);
			}
		}
		else {
			m_traveld = 0;
		}

	}
	//m_isDisposed = true;
}