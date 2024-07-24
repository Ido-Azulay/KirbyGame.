/*

*/

#pragma once
#include "MovingObject.h"

class Floor;

class Kirby : public MovingObject
{
public:
	Kirby();
	Kirby(sf::Vector2f pos);
	~Kirby();

	virtual void move(const sf::Time &delta, MovingVector& mov, StaticVector& stat) override;
	virtual void updateDirection(sf::Vector2f& obj, int num) {};

	// map collisions:::
	void handleFloorCollison(float groundlevel, sf::Time &deltaTime);
	void handleCeilingCollison(float groundlevel, sf::Time &deltaTime);
	void handleLeftWallCollison(float Walllevel, sf::Time &deltaTime);
	void handleRightWallCollison(float Walllevel, sf::Time &deltaTime);
	void handleSpikeCollison(float groundlevel, sf::Time& deltaTime);

	// get & set for kirby:::
	bool getKirbyPuff();
	bool getKirbyStar();
	int getLives() const;
	int getScore() const;
	int getLevel() const;
	bool getIsInhale();
	bool getIsShootingFire();
	void setLife(int life);
	void setScore(int score);
	void setLevel(int level);
	void setKirbyPuff(bool set);
	void setKirbyStar(bool set);
	void setCollisionWithCeiling(bool set);
	void setCollisionWithRightWall(bool set);
	void setCollisionWithLeftWall(bool set);
	void setKirbyInhale(bool set);
	void setWhichDoor(int set);
	sf::Vector2f getPosition() const;
	sf::Vector2f getOriginalPosition() const;
	void setOriginalPosition(sf::Vector2f pos);
	bool isDirectionRight();
	void setLoaded(bool set);
	bool getLoaded() const;
	bool getIsIceMode() const;

	void CheckCollision(MovingVector& mov, StaticVector& stat);

	// handle collision for kirby with map objects::: 

	virtual void handleCollison(SwordEnemy& obj);
	virtual void handleCollison(Airpuff& obj) {};
	virtual void handleCollison(KirbyStar& obj) {};
	virtual void handleCollison(PlantEnemy& obj);
	virtual void handleCollison(OrangeEnemy& obj);
	virtual void handleCollison(FireEnemy& obj);
	virtual void handleCollison(FlyingEnemy& obj);
	virtual void handleCollison(IceManEnemy& obj);
	virtual void handleCollison(BlackStarEnemy& obj);

	virtual void handleCollison(LifeGift& obj);
	virtual void handleCollison(Apple& obj);



	
private:
	int m_lives = 5;
	int m_score = 0;
	bool m_isLoaded = false;

	//sounds members:
	float m_soundCounter = 0.f;
	float m_jumpSoundCounter = 0.f;
	std::vector< sf::Sound> m_sound;

	//Animation members:::
	int m_numFrames = 8;  // Number of frames in the animation
	float m_frameDuration = 0.1f;
	float m_elapsedFrameTime = 0.0f;  // Time elapsed since the last frame change
	int m_currentFrame = 0;  // Index of the current frame
	int m_frameWidth = 24/* width of a single frame */;
	int m_frameHeight = 24/* height of a single frame */;
	int m_numRows = 138 /* number of rows in the sprite sheet */;
	int m_desiredRow = 4;// 0-based index of the desired row

	const float m_gravity;

	//jump members
	const float m_jumpSpeed;
	const float m_jumpLimit;
	float m_jumpDistance;
	bool m_isJumping = false;
	bool m_isHit = false;
	//flight members
	const float m_flightSpeed;
	const float m_flightLimit;
	float m_flightDistance;
	bool m_isFlying = false;
	bool m_didStartFlight = false;
	bool m_kirbyPuff = false;
	bool m_isFalling = false;

	//slide members
	bool m_isDucking = false;
	const float m_slideSpeed;
	const float m_slideLimit;
	float m_slideDistance;
	bool m_isSliding = false;

	//inhale members:
	bool m_isInhale = false;
	bool m_isShootingFire = false;

	bool m_isColidingWithCeiling = false;
	bool m_isColidingWithLeftWall = false;
	bool m_isColidingWithRightWall = false;

	int m_WhichDoor;
	int m_level;

	bool m_isAte = false;
	bool m_fireMode = false;
	bool m_iceMode = false;
	char m_powerChar;
	bool m_ShootStar = false;


	sf::Vector2f m_velocity;

	void PressRight(sf::Time deltaTime);
	void PressLeft(sf::Time deltaTime);
	void handleStillAnimations(sf::Time deltaTime);

	//NORMAL KIRBY ANIMATIONS
	void StandStillAnimation(sf::Time deltaTime); //did
	void StandLeftAnimation(sf::Time deltaTime); //did
	void duckAnimation(sf::Time deltaTime);
	void duckLeftAnimation(sf::Time deltaTime);
	void WalkRightAnimation(sf::Time deltaTime);
	void WalkLeftAnimation(sf::Time deltaTime);
	void WalkDownAnimation(sf::Time deltaTime);
	void jumpAnimation(sf::Time deltaTime);
	void jumpLeftAnimation(sf::Time deltaTime);
	void startFlightAnimation(sf::Time deltaTime);
	void flightAnimation(sf::Time deltaTime);
	void flightLeftAnimation(sf::Time deltaTime);
	void releaseFlightAnimation(sf::Time deltaTIme);
	void releaseFlightLeftAnimation(sf::Time deltaTime);
	void inhaleRightAnimation(sf::Time deltaTime);
	void inhaleLeftAnimation(sf::Time deltaTime);
	void StandStillEatingAnimation(sf::Time deltaTime);
	void StandStillEatingLeftAnimation(sf::Time deltaTime);
	void WalkRightEatingAnimation(sf::Time deltaTime); //did
	void WalkLeftEatingAnimation(sf::Time deltaTime);
	void releaseStarLeftAnimation(sf::Time deltaTime);
	void releaseStarAnimation(sf::Time deltaTime);
	void hitAnimation(sf::Time deltaTime);
	void hitLeftAnimation(sf::Time deltaTime);

};
