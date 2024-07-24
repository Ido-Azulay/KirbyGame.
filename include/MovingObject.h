#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class MovingObject : public GameObject
{
public:
    using MovingVector = std::vector<std::unique_ptr <MovingObject>>;
    using StaticVector = std::vector<std::unique_ptr <StaticObject>>;

    MovingObject();
    MovingObject(const sf::Texture& tex);
    MovingObject(const sf::Vector2f& pos, const sf::Texture& tex);


    virtual ~MovingObject() = default;

    virtual void move(const sf::Time &delta, MovingVector&, StaticVector&) = 0;

    virtual void updateDirection(sf::Vector2f& obj, int num) = 0;

    //Collisions with map for moving objects:
    void handleFloorCollison(float groundlevel, const sf::Time &deltaTime);
    void handleCeilingCollison(float groundlevel, const sf::Time &deltaTime);
    void handleLeftWallCollison(float Walllevel, const sf::Time &deltaTime);
    void handleRightWallCollison(float Walllevel, const sf::Time &deltaTime);
    void setCollisionWithCeiling(bool set);
    void setCollisionWithRightWall(bool set);
    void setCollisionWithLeftWall(bool set);

    void setTexture(sf::Texture tex);

    void setOriginalPosition(sf::Vector2f pos);
    sf::Vector2f getOriginalPosition();

    bool getIsDead() const;
	bool get_is_disposed() const;
	void set_is_disposed();

    enum class Direction
    {
        Up,
        Down,
        Right,
        Left,
        Jump,
        Stay,
        Max,
    };

    void setDirection(Direction dir);
protected:

    Direction m_direction = Direction::Stay;
    sf::Vector2f directionToVector(Direction dir);

    void deadAnimation(const sf::Time &deltaTime);
    sf::Vector2f m_stepSize;
    sf::Vector2f m_original_position;
    sf::Sound m_sound;

	bool m_isDisposed = false;

	//Animation members
	int m_numFrames = 8;  // Number of frames in the animation
	float m_frameDuration = 0.1f;
	float m_elapsedFrameTime = 0.0f;  // Time elapsed since the last frame change
	int m_currentFrame = 0;  // Index of the current frame
	int m_frameWidth = 24/* width of a single frame */;
	int m_frameHeight = 24/* height of a single frame */;
	int m_numRows = 138 /* number of rows in the sprite sheet */;
	int m_desiredRow = 4;// 0-based index of the desired row

    //Collision booleans:
    bool m_isColidingWithCeiling = false;
    bool m_isColidingWithLeftWall = false;
    bool m_isColidingWithRightWall = false;
    sf::Vector2f m_velocity;
    const float m_gravity;
    bool m_isDead = false;


private:
    

};



