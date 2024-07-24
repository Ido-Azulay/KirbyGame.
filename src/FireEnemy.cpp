#include "SwordEnemy.h"
#include <iostream>
#include "Kirby.h"
#include "Airpuff.h"
#include "Inhale.h"
#include "KirbyStar.h"
#include "FireEnemy.h"


const int SIZE = 10;

FireEnemy::FireEnemy() :m_traveld(0.0f), m_travelLimit(2.0f)
{
    m_sprite.setTexture(Resources::instance().getTexture(Resources::t_fireEnemy));
    m_char = '&';


}
FireEnemy::FireEnemy(sf::Vector2f pos, int travelLimit) :m_traveld(0.0f), m_travelLimit(travelLimit)
{
    m_sprite.setTexture(Resources::instance().getTexture(Resources::t_fireEnemy));
    m_char = '&';
    m_sprite.setPosition(pos);
    m_original_position = pos;
    m_frameDuration = 0.15;

}



FireEnemy::~FireEnemy()
{

}


void FireEnemy::leftAnimation(const sf::Time &deltaTime)
{
    m_numFrames = 4;
    m_frameWidth = 26/* width of a single frame */;
    m_frameHeight = 26/* height of a single frame */;
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

    m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 4, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
    m_sprite.setScale(3.0f, 3.0f);
}


void FireEnemy::setDirection(Direction dir)
{
    m_direction = dir;
}

void FireEnemy::rightAnimation(const sf::Time &deltaTime)
{
    m_numFrames = 4;
    m_frameWidth = 26/* width of a single frame */;
    m_frameHeight = 26/* height of a single frame */;
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

    int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 4;

    m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight));
    m_sprite.setScale(3.0f, 3.0f);

}


void FireEnemy::inhaledAnimation(const sf::Time &deltaTime)
{
    m_currentFrame = 0;
    m_numFrames = 2;
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

void FireEnemy::inhaledLeftAnimation(const sf::Time &deltaTime)
{
    m_currentFrame = 0;
    m_numFrames = 1;
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


void FireEnemy::move(const sf::Time &deltaTime, MovingVector& mov, StaticVector& stat)
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


void FireEnemy::handleCollison(Kirby& obj)
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

void FireEnemy::handleCollison(Airpuff& obj)
{
    //if on super mode Pacman is not eaten and he gets 10 points
    //m_isDisposed = true;
    //m_isDisposed = true;
    m_currentFrame = 0;
    m_isDead = true;
    m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));

    obj.handleCollison(*this);
}

void FireEnemy::handleCollison(Inhale& obj)
{
    //if on super mode Pacman is not eaten and he gets 10 points
    //m_isDisposed = true;
    //m_isDisposed = true;
    //m_sprite.setPosition(6639.f, 3167.f); //island of the dead
    //obj.handleCollison(*this);
    if (obj.isDirecrionRight())
    {
        m_direction = Direction::Left;
    }
    else m_direction = Direction::Right;

    m_isInhaled = true;
}

void FireEnemy::handleCollison(KirbyStar& obj)
{
    //if on super mode Pacman is not eaten and he gets 10 points
    //m_isDisposed = true;
    //m_isDisposed = true;
    m_currentFrame = 0;
    m_isDead = true;
    m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));

    obj.handleCollison(*this);
}

void FireEnemy::handleCollison(Fire& obj)
{

    m_currentFrame = 0;
    m_isDead = true;
    m_sprite.setTexture(Resources::instance().getTexture(Resources::t_deadAnimation));
}