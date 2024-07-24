#include "MovingObject.h"
#include <iostream>

//======================================constructors===================================//
MovingObject::MovingObject() : m_velocity(sf::Vector2f(0, 0)), m_gravity(1.2)
{
    m_isDisposed = false;
    m_sound.setBuffer(Resources::instance().getSound(Resources::s_enemyDead));
}

MovingObject::MovingObject(const sf::Texture& tex) : GameObject(tex), m_velocity(sf::Vector2f(0, 0)), m_gravity(1.2)
{
    m_isDisposed = false;
    m_sound.setBuffer(Resources::instance().getSound(Resources::s_enemyDead));
}

MovingObject::MovingObject(const sf::Vector2f& pos, const sf::Texture& tex) : GameObject(pos, tex), m_velocity(sf::Vector2f(0, 0)), m_gravity(1.2)
{
    m_isDisposed = false;
    m_sound.setBuffer(Resources::instance().getSound(Resources::s_enemyDead));
    
}


//this function sets the object to its original position when the board was first read
void MovingObject::setOriginalPosition(sf::Vector2f pos)
{
    m_original_position = pos;
}

void MovingObject::setTexture(sf::Texture tex)
{
    m_sprite.setTexture(tex);
}

//this function returns the object's original position when the board was first read
sf::Vector2f MovingObject::getOriginalPosition()
{
    return m_original_position;
}

//this function gets a direction from the direction enum and returns a vector2f class
//it is used by the ghosts and the pacman
sf::Vector2f MovingObject::directionToVector(Direction dir)
{
    switch (dir)
    {
    case Direction::Up:
        return { 0, -1 };
    case Direction::Down:
        return { 0, 1 };
    case Direction::Right:
        return { 1, 0 };
    case Direction::Left:
        return { -1, 0 };
    default:
        return { 0, 0 };
    }
}



bool MovingObject::get_is_disposed() const
{
    return m_isDisposed;
}

void MovingObject::set_is_disposed()
{
    m_isDisposed = true;
}


void MovingObject::setDirection(Direction dir)
{
    m_direction = dir;
}

//==================================================handleCollision====================================
void MovingObject::handleFloorCollison(float groundlevel, const sf::Time &deltaTime)
{

    if (m_sprite.getPosition().y + m_sprite.getGlobalBounds().height < groundlevel)
    {

    }
    else
    {
        if (m_char != AIRPUFF && m_char != '*') {
            m_sprite.setPosition(m_sprite.getPosition().x, groundlevel - m_sprite.getGlobalBounds().height);

            m_velocity.x = 0;
            m_velocity.y = 0;
        }
    }
}



void MovingObject::handleCeilingCollison(float groundlevel,const sf::Time &deltaTime)
{
    m_isColidingWithCeiling = true;
  
}

void MovingObject::handleLeftWallCollison(float Walllevel,const sf::Time &deltaTime)
{

    m_isColidingWithLeftWall = true;
    if (m_char == '*')
    {
        m_isDisposed = true;
    }

}


void MovingObject::handleRightWallCollison(float Walllevel,const sf::Time &deltaTime)
{
    m_isColidingWithRightWall = true;

    if(m_char == '*')
    {
        m_isDisposed = true;
    }
}


void MovingObject::setCollisionWithLeftWall(bool set)
{
    m_isColidingWithLeftWall = set;
    
}

void MovingObject::setCollisionWithRightWall(bool set)
{
    m_isColidingWithRightWall = set;

}

void MovingObject::setCollisionWithCeiling(bool set)
{
    m_isColidingWithCeiling = set;

}

void MovingObject::deadAnimation(const sf::Time &deltaTime)
{
	m_frameDuration = 0.1f;
	m_numFrames = 7;
	m_frameWidth = 75/* width of a single frame */;
	m_frameHeight = 75/* height of a single frame */;
	m_desiredRow = 0;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}


	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth), (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(2.0f, 2.0f);

	if (m_currentFrame == m_numFrames - 1)
	{
        m_sound.play();
		m_sprite.setPosition(6639.f, 3167.f); //island of the dead
        m_isDead = false;
	}

}