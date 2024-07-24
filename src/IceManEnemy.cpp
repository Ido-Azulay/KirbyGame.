#include "SwordEnemy.h"
#include <iostream>
#include "Kirby.h"
#include "Airpuff.h"
#include "Inhale.h"
#include "KirbyStar.h"
#include "FireEnemy.h"
#include "IceManEnemy.h"


const int SIZE = 10;

IceManEnemy::IceManEnemy() :m_traveld(0.0f), m_travelLimit(2.0f)
{
    m_sprite.setTexture(Resources::instance().getTexture(Resources::t_iceManEnemy));
    m_char = '8';


}
IceManEnemy::IceManEnemy(sf::Vector2f pos, int travelLimit) :m_traveld(0.0f), m_travelLimit(travelLimit)
{
    m_sprite.setTexture(Resources::instance().getTexture(Resources::t_iceManEnemy));
    m_char = '8';
    m_sprite.setPosition(pos);
    m_original_position = pos;
    m_frameDuration = 0.15;

}



IceManEnemy::~IceManEnemy()
{

}

void IceManEnemy::setDirection(Direction dir)
{
    m_direction = dir;
}


void IceManEnemy::leftAnimation(const sf::Time& deltaTime)
{
	m_numFrames = 4;
	m_frameWidth = 24.7/* width of a single frame */;
	m_frameHeight = 29/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;

		if (m_currentFrame == 0)
		{
			m_currentFrame = 1;
		}
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 1.1, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight + 4));
	m_sprite.setScale(3.0f, 3.0f);
}




void IceManEnemy::rightAnimation(const sf::Time& deltaTime)
{
	m_numFrames = 4;
	m_frameWidth = 24.7/* width of a single frame */;
	m_frameHeight = 29/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;

		if (m_currentFrame == 0)
		{
			m_currentFrame = 1;
		}
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth);

	m_sprite.setTextureRect(sf::IntRect(framecalc + 1.1, (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight + 4));
	m_sprite.setScale(3.0f, 3.0f);

}


void IceManEnemy::inhaledAnimation(const sf::Time& deltaTime)
{
	m_currentFrame = 5;
	m_numFrames = 1;
	m_frameWidth = 24.7/* width of a single frame */;
	m_frameHeight = 28/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth);

	m_sprite.setTextureRect(sf::IntRect(framecalc + 1.1, (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight + 4));
	m_sprite.setScale(3.0f, 3.0f);

}

void IceManEnemy::inhaledLeftAnimation(const sf::Time& deltaTime)
{
	m_currentFrame = 5;
	m_numFrames = 1;
	m_frameWidth = 24.7/* width of a single frame */;
	m_frameHeight = 28/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth);

	m_sprite.setTextureRect(sf::IntRect(framecalc + 1.1, (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight + 4));
	m_sprite.setScale(3.0f, 3.0f);

}



void IceManEnemy::move(const sf::Time &deltaTime, MovingVector& mov, StaticVector& stat)
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


void IceManEnemy::handleCollison(Kirby& obj)
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

void IceManEnemy::handleCollison(Airpuff& obj)
{
    m_currentFrame = 0;
    m_isDead = true;
    m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));

    obj.handleCollison(*this);
}

void IceManEnemy::handleCollison(Inhale& obj)
{
    if (obj.isDirecrionRight())
    {
        m_direction = Direction::Left;
    }
    else m_direction = Direction::Right;

    m_isInhaled = true;
}

void IceManEnemy::handleCollison(KirbyStar& obj)
{
    m_currentFrame = 0;
    m_isDead = true;
    m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));

    obj.handleCollison(*this);
}

void IceManEnemy::handleCollison(Fire& obj)
{

    m_currentFrame = 0;
    m_isDead = true;
    m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));
}