#include "SwordEnemy.h"
#include <iostream>
#include "Kirby.h"
#include "Airpuff.h"
#include "Inhale.h"
#include "KirbyStar.h"
#include "FlyingEnemy.h"
#include "Fire.h"


const int SIZE = 10;

FlyingEnemy::FlyingEnemy() :m_traveld(0.0f), m_travelLimit(2.0f), m_hightLimit(1.0f)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_flyingEnemy));
	m_char = 'Z';


}
FlyingEnemy::FlyingEnemy(sf::Vector2f pos, int travelLimit) :m_traveld(0.0f), m_travelLimit(travelLimit)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_flyingEnemy));
	m_char = 'Z';
	m_sprite.setPosition(pos);
	m_original_position = pos;
	m_frameDuration = 0.15;

}



FlyingEnemy::~FlyingEnemy()
{

}


void FlyingEnemy::leftAnimation(const sf::Time &deltaTime)
{
	m_numFrames = 5;
	m_frameWidth = 26/* width of a single frame */;
	m_frameHeight = 26/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 1, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);
}


void FlyingEnemy::setDirection(Direction dir)
{
	m_direction = dir;
}

void FlyingEnemy::rightAnimation(const sf::Time &deltaTime)
{
	m_numFrames = 5;
	m_frameWidth = 26/* width of a single frame */;
	m_frameHeight = 26/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 1;

	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

}


void FlyingEnemy::inhaledAnimation(const sf::Time &deltaTime)
{
	m_currentFrame = 6;
	m_numFrames = 1;
	m_frameWidth = 26/* width of a single frame */;
	m_frameHeight = 26/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 1;

	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

}

void FlyingEnemy::inhaledLeftAnimation(const sf::Time &deltaTime)
{
	m_currentFrame = 6;
	m_numFrames = 1;
	m_frameWidth = 26/* width of a single frame */;
	m_frameHeight = 26/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 1;

	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

}


void FlyingEnemy::move(const sf::Time &deltaTime, MovingVector& mov, StaticVector& stat)
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
			inhaledLeftAnimation(deltaTime);
			m_velocity.x -= 3;
			m_velocity.y += m_gravity;
			m_sprite.move(m_velocity);
		}
	}
	else {

		
		m_traveld += deltaTime.asSeconds();
		m_flightTraveld += deltaTime.asSeconds();

		float eyeOpenDuration = m_travelLimit;
		float eyeClosedDuration = m_travelLimit;
		float flyDuration = m_travelLimit/2 - 2.f;
		float flyClosedDuration = m_travelLimit/2 - 2.f;

		if (m_traveld <= eyeOpenDuration) {
			// Display the frame with open eyes

			leftAnimation(deltaTime);
			m_velocity.x = -3;

			if (m_flightTraveld <= flyDuration)
			{
				m_velocity.y = -3;
			}
			else if (m_flightTraveld <= flyDuration + flyClosedDuration)
			{
				m_velocity.y = 3;
			}
			else m_flightTraveld = 0;

			m_sprite.move(m_velocity);

		}
		else if (m_traveld <= eyeOpenDuration + eyeClosedDuration) {


			rightAnimation(deltaTime);
			m_velocity.x = 3;

			if (m_flightTraveld <= flyDuration)
			{
				m_velocity.y = -3;
			}
			else if (m_flightTraveld <= flyDuration + flyClosedDuration)
			{
				m_velocity.y = 3;
			}
			else m_flightTraveld = 0;

			m_sprite.move(m_velocity);
		}
		else {
			m_traveld = 0;
		}

	}
	//m_isDisposed = true;
}


void FlyingEnemy::handleCollison(Kirby& obj)
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

void FlyingEnemy::handleCollison(Airpuff& obj)
{ 
	m_currentFrame = 0;
	m_isDead = true;
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));

	obj.handleCollison(*this);
}

void FlyingEnemy::handleCollison(Inhale& obj)
{
	if (obj.isDirecrionRight())
	{
		m_direction = Direction::Left;
	}
	else m_direction = Direction::Right;

	m_isInhaled = true;
}

void FlyingEnemy::handleCollison(KirbyStar& obj)
{
	m_currentFrame = 0;
	m_isDead = true;
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));

	obj.handleCollison(*this);
}

void FlyingEnemy::handleCollison(Fire& obj)
{
	m_currentFrame = 0;
	m_isDead = true;
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));

	//obj.handleCollison(*this);
}