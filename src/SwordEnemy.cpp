#include "SwordEnemy.h"
#include <iostream>
#include "Kirby.h"
#include "Airpuff.h"
#include "Inhale.h"
#include "KirbyStar.h"



const int SIZE = 10;

SwordEnemy::SwordEnemy() :m_traveld(0.0f), m_travelLimit(2.0f)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_swordEnemy));
	m_char = 'S';


}
SwordEnemy::SwordEnemy(sf::Vector2f pos , int travelLimit) :m_traveld(0.0f) , m_travelLimit(travelLimit)
{
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_swordEnemy));
	m_char = 'S';
	m_sprite.setPosition(pos);
	m_original_position = pos;
	m_frameDuration = 0.15;

}



SwordEnemy::~SwordEnemy()
{

}


void SwordEnemy::leftAnimation(const sf::Time &deltaTime)
{
	m_numFrames = 4;
	m_frameWidth = 29/* width of a single frame */;
	m_frameHeight = 26/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 4, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);
}


void SwordEnemy::setDirection(Direction dir)
{
	m_direction = dir;
}

void SwordEnemy::rightAnimation(const sf::Time &deltaTime)
{
	m_numFrames = 4;
	m_frameWidth = 29/* width of a single frame */;
	m_frameHeight = 26/* height of a single frame */;
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


void SwordEnemy::attackAnimation(const sf::Time &deltaTime)
{
	m_numFrames = 8;
	m_frameWidth = 27/* width of a single frame */;
	m_frameHeight = 40/* height of a single frame */;
	m_desiredRow = 1;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		if (m_currentFrame == 2 && m_currentFrame == 3)
		{
			m_currentFrame++;
		}
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame ) * m_frameWidth) + 4;

	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight ));
	m_sprite.setScale(3.0f, 3.0f);

}


void SwordEnemy::inhaledAnimation(const sf::Time &deltaTime)
{
	m_numFrames = 2;
	m_frameWidth = 29/* width of a single frame */;
	m_frameHeight = 26/* height of a single frame */;
	m_desiredRow = 3;// 0-based index of the desired row

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

void SwordEnemy::inhaledLeftAnimation(const sf::Time &deltaTime)
{
	m_numFrames = 2;
	m_frameWidth = 29/* width of a single frame */;
	m_frameHeight = 26/* height of a single frame */;
	m_desiredRow = 3;// 0-based index of the desired row

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


void SwordEnemy::move(const sf::Time &deltaTime, MovingVector& mov, StaticVector& stat)
{
	if (m_isDead)
	{
		deadAnimation(deltaTime);
	}
	else if (m_travelLimit >  -0.99f && m_travelLimit < 0.01f)
	{
		leftAnimation(deltaTime);

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
			inhaledLeftAnimation(deltaTime);
			m_velocity.x -= 1.2;
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

			leftAnimation(deltaTime);
			m_velocity.x = -1;
			m_velocity.y += m_gravity;
			m_sprite.move(m_velocity);

		}
		else if (m_traveld <= eyeOpenDuration + eyeClosedDuration) {


			rightAnimation(deltaTime);
			m_velocity.x = 1;
			m_velocity.y += m_gravity;
			m_sprite.move(m_velocity);
		}
		else {
			m_traveld = 0;
		}

	}
		//m_isDisposed = true;
}


void SwordEnemy::handleCollison(Kirby& obj)
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

void SwordEnemy::handleCollison(Airpuff& obj)
{
	m_currentFrame = 0;
	m_isDead = true;
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));
	
	obj.handleCollison(*this);
}

void SwordEnemy::handleCollison(Inhale& obj)
{
	if (obj.isDirecrionRight())
	{
		m_direction = Direction::Left;
	}
	else m_direction = Direction::Right;

	m_isInhaled = true;
}

void SwordEnemy::handleCollison(KirbyStar& obj)
{
	m_sound.play();
	m_currentFrame = 0;
	m_isDead = true;
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));

	obj.handleCollison(*this);
}

void SwordEnemy::handleCollison(Fire& obj)
{

	m_currentFrame = 0;
	m_isDead = true;
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));
}