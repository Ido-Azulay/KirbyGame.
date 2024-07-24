#include "Kirby.h"
#include "StaticObject.h"
#include <iostream>
#include "MovingObject.h"
#include "SwordEnemy.h"
#include "PlantEnemy.h"
#include "Apple.h"
#include "LifeGift.h"
#include "IceManEnemy.h"
#include "BlackStarEnemy.h"


const float KirbySize = 50.f;
const float KirbySpeed = 300.f;


//******************************* CONTRUCTORS & DESTRUCTOR

Kirby::Kirby() :m_level(1), m_WhichDoor(-1), m_slideDistance(0.0f), m_slideLimit(15.0f), m_slideSpeed(3.5f), m_flightDistance(0.0f), m_flightLimit(10.0f), m_flightSpeed(1.5f), m_jumpDistance(0.0f), m_jumpLimit(0.7f), m_jumpSpeed(3.5f), m_gravity(1.2), m_velocity(sf::Vector2f(0, 0))
{

	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_Kirby));
	m_char = KIRBY;
	m_powerChar = ' ';
	m_ShootStar = false;
	m_direction = Direction::Right;
	
	m_sound.resize(Resources::s_total);
	m_sound[Resources::s_fly].setBuffer(Resources::instance().getSound(Resources::s_fly));
	m_sound[Resources::s_airPuff].setBuffer(Resources::instance().getSound(Resources::s_airPuff));
	m_sound[Resources::s_airSuck].setBuffer(Resources::instance().getSound(Resources::s_airSuck));
	m_sound[Resources::s_hitByEnemy].setBuffer(Resources::instance().getSound(Resources::s_starHit));
	m_sound[Resources::s_jump].setBuffer(Resources::instance().getSound(Resources::s_jump));
	m_sound[Resources::s_soperPower].setBuffer(Resources::instance().getSound(Resources::s_soperPower));
	m_sound[Resources::s_starShoot].setBuffer(Resources::instance().getSound(Resources::s_starShoot));
	m_sound[Resources::s_swallow].setBuffer(Resources::instance().getSound(Resources::s_swallow));
}

Kirby::Kirby(sf::Vector2f pos) : Kirby() //reuse default constructor
{
	m_sprite.setPosition(pos);
	m_char = KIRBY;
	m_powerChar = ' ';
	m_kirbyPuff = false;
	m_ShootStar = false;
}

Kirby::~Kirby()
{
}


//============================================== Movment Functions ===============================\\



void Kirby::move(const sf::Time &deltaTime, MovingVector& mov, StaticVector& stat)
{
	//For coordinates:

	//std::cout << "x: " << m_sprite.getPosition().x << " y: " << m_sprite.getPosition().y << std::endl;
	//std::cout << m_WhichDoor << std::endl;
	//std::cout << m_isShootingFire

	m_velocity.x = 0;
	m_velocity.y = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		PressRight(deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		PressLeft(deltaTime);
	}
	// For standing still animations: //
	else
	{
		handleStillAnimations(deltaTime);
		m_velocity.x = 0;
		
	}

	//jump mode
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		if (!m_isFlying && !m_isAte && !m_ShootStar)
		{
			m_isJumping = true;

			//jummp sound
			if (m_jumpSoundCounter < 1.5f)
			{
				m_jumpSoundCounter += deltaTime.asSeconds();
			}
			else {
				m_sound[Resources::s_jump].play();
				m_jumpSoundCounter = 0;
			}
		
			if (m_jumpDistance < m_jumpLimit)
			{

				m_velocity.y = -m_jumpSpeed;
				m_jumpDistance += 0.1f;
			}
			
		}
		if(m_isAte)
		{

			m_ShootStar = true;
			///sound handle
			if (m_soundCounter < 0.1f)
			{
				m_soundCounter += deltaTime.asSeconds();
			}
			else {
				m_sound[Resources::s_starShoot].play();
				m_soundCounter = 0;
			}
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (m_isAte)
		{
			if (m_powerChar == FIREENEMY)
			{
				m_fireMode = true;
				m_sprite.setTexture(Resources::instance().getTexture(Resources::t_fireKirby));
				m_sound[Resources::s_soperPower].play();
			}
			if (m_powerChar == ICEMANENEMY)
			{
				m_fireMode = true;
				m_sprite.setTexture(Resources::instance().getTexture(Resources::t_iceKirby));
				m_sound[Resources::s_soperPower].play();
			}
			else m_sound[Resources::s_swallow].play();
			m_isAte = false;
		}

		if (!m_isFlying && !m_isJumping ) {
			m_isDucking = true;

			if (m_direction == Direction::Right)
			{
				duckAnimation(deltaTime);
			}
			else duckLeftAnimation(deltaTime);
		}
		
	}


	//flying mode
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

		if (!m_isAte)
		{
			m_isJumping = false; //bug fix

			m_isFlying = true;
			m_isHit = false;
			
			///sound handle
			if (m_soundCounter < 0.3f)
			{
				m_soundCounter += deltaTime.asSeconds();
			}
			else {
				m_sound[Resources::s_fly].play();
				m_soundCounter = 0;
			}

			if (!m_isColidingWithCeiling)
			{
				m_velocity.y = -m_flightSpeed;
			}
		}
		if (m_WhichDoor == 0)
		{
			m_sprite.setPosition(2950.f, 2400.f);
			m_isLoaded = false;
			m_level = 2;
		}
		if (m_WhichDoor == 1)
		{
			m_sprite.setPosition(5100.f, 1881.f);
			m_isLoaded = false;
			m_level = 3;
		}
		if (m_WhichDoor == 2)
		{
			m_sprite.setPosition(2650.f, 450.f);
			m_isLoaded = false;
			m_level = 2;
		}
		if (m_WhichDoor == 3)
		{
			m_level = 4;
		}
	}

	//for maor and ido
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		m_sprite.setPosition(6639.f, 3167.f);
	}
	
	//spit mode
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		if (m_isFlying)
		{
			m_isFlying = false;
			m_didStartFlight = false;
			m_kirbyPuff = true;
			m_isFalling = true;
			m_currentFrame = 0;

			m_sound[Resources::s_airPuff].play();
		}

		else if (m_isDucking)
		{

			m_isSliding = true;
			m_slideDistance = 0;
		}

		else if (!m_kirbyPuff && !m_isFlying && !m_isAte && !m_isJumping)
			{
				if (m_fireMode)
				{
					m_isShootingFire = true;
				}
				else m_isInhale = true;
			}
	}
	else {
		m_isInhale = false;
		m_isShootingFire = false;
	}

	//gravity
	if (m_isFlying)
	{
		m_velocity.y += m_gravity/2;
	}
	else m_velocity.y += m_gravity;

	//move
	m_sprite.move(m_velocity * KirbySpeed * deltaTime.asSeconds());
	
	CheckCollision(mov, stat);
}

//===================================
//this function checks if kirby had Collision with any object on the map
//if it did had a collision the object that kirby had a collision with is calling his handleCollision 
//function which most of the time calls kirbys  handle collision function (Double dispatch)

void Kirby::CheckCollision(MovingVector& mov, StaticVector& stat)
{

	for (auto& statobj : stat)
	{
		if (getBounds().intersects(statobj->getBounds()))
		{
			statobj->handleCollison(*this);
		}
	}

	for (auto& moving : mov) // collisions
	{
		if (getBounds().intersects(moving->getBounds()))
		{
			moving->handleCollison(*this);

		}
	}
}



///////////////////////////////////////////////////////////////////////////
//***********/////////         COLISSION HANDLE          //////////******//



//this function handles the collision of Pacman with a ghost
void Kirby::handleCollison(SwordEnemy& obj)
{
	//if on super mode Pacman is not eaten and he gets 10 points
	if (m_isInhale)
	{
		m_isAte = true;
		m_powerChar = ' ';
		m_score += 5;
		m_isInhale = false;
	}
	else
	{
		if (m_direction == Direction::Right)
		{
			m_velocity.x -= m_jumpSpeed;

		}
		else m_velocity.x += m_jumpSpeed;

		m_velocity.y -= m_jumpSpeed;
		m_sprite.move(m_velocity * 20.f);
		m_lives--;
		m_sound[Resources::s_hitByEnemy].play();
		m_isHit = true;
	}
}

void Kirby::handleCollison(FireEnemy& obj)
{
	//if on super mode Pacman is not eaten and he gets 10 points
	if (m_isInhale)
	{
		m_isAte = true;
		m_score += 10;
		m_powerChar = FIREENEMY;
		m_isInhale = false;
	}
	else
	{
		if (m_direction == Direction::Right)
		{
			m_velocity.x -= m_jumpSpeed;

		}
		else m_velocity.x += m_jumpSpeed;

		m_velocity.y -= m_jumpSpeed;
		m_sprite.move(m_velocity * 20.f);
		m_lives--;
		m_sound[Resources::s_hitByEnemy].play();
		m_isHit = true;
	}
}


void Kirby::handleCollison(IceManEnemy& obj)
{
	//if on super mode Pacman is not eaten and he gets 10 points
	if (m_isInhale)
	{
		m_isAte = true;
		m_score += 10;
		m_powerChar = ICEMANENEMY;
		m_iceMode = true;
		m_isInhale = false;
	}
	else
	{
		if (m_direction == Direction::Right)
		{
			m_velocity.x -= m_jumpSpeed;

		}
		else m_velocity.x += m_jumpSpeed;

		m_velocity.y -= m_jumpSpeed;
		m_sprite.move(m_velocity * 20.f);
		m_lives--;
		m_sound[Resources::s_hitByEnemy].play();
		m_isHit = true;
	}
}

void Kirby::handleCollison(OrangeEnemy& obj)
{
	//if on super mode Pacman is not eaten and he gets 10 points
	if (m_isInhale)
	{
		m_isAte = true;
		m_score += 5;
		m_powerChar = ' ';
		m_isInhale = false;
	}
	else
	{
		if (m_direction == Direction::Right)
		{
			m_velocity.x -= m_jumpSpeed;
			
		}
		else m_velocity.x += m_jumpSpeed;

		m_velocity.y -= m_jumpSpeed;
		m_sprite.move(m_velocity * 20.f);
		m_lives--;
		m_sound[Resources::s_hitByEnemy].play();
		m_isHit = true;
	}
}

void Kirby::handleCollison(FlyingEnemy& obj)
{
	//if on super mode Pacman is not eaten and he gets 10 points
	if (m_isInhale)
	{
		m_isAte = true;
		m_powerChar = ' ';
		m_score += 5;
		m_isInhale = false;
	}
	else
	{
		if (m_direction == Direction::Right)
		{
			m_velocity.x -= m_jumpSpeed;
			
		}
		else m_velocity.x += m_jumpSpeed;

		m_velocity.y -= m_jumpSpeed;
		m_sprite.move(m_velocity * 20.f);
		m_lives--;
		m_sound[Resources::s_hitByEnemy].play();
		m_isHit = true;
	}
}

void Kirby::handleCollison(BlackStarEnemy& obj)
{
		if (m_direction == Direction::Right)
		{
			m_velocity.x -= m_jumpSpeed;
			
		}
		else m_velocity.x += m_jumpSpeed;

		//m_velocity.y -= m_jumpSpeed;
		m_isFlying = false;
		m_sprite.move(m_velocity * 20.f);
		m_lives--;
		m_sound[Resources::s_hitByEnemy].play();
		m_isHit = true;
	}




void Kirby::handleCollison(PlantEnemy& obj)
{
	if (m_isInhale)
	{
		m_isAte = true;
		m_powerChar = ' ';
		m_score += 5;
		m_isInhale = false;
	}
	else 
	{
		if (m_direction == Direction::Right)
		{
			m_velocity.x -= m_jumpSpeed;

		}
		else m_velocity.x += m_jumpSpeed;

		m_velocity.y -= m_jumpSpeed;
		m_sprite.move(m_velocity * 20.f);
		m_lives--;
		m_sound[Resources::s_hitByEnemy].play();
		m_isHit = true;
	}
}

void Kirby::handleCollison(Apple& obj)
{
	m_score += 20;
}

void Kirby::handleCollison(LifeGift& obj)
{
	m_score += 10;

	if (m_lives < 5)
	{
		m_lives++;
	}
	
}


void Kirby::handleFloorCollison(float groundlevel ,sf::Time &deltaTime)
{

	if (m_sprite.getPosition().y + m_sprite.getGlobalBounds().height < groundlevel)
	{

	}
	else
	{
		m_sprite.setPosition(m_sprite.getPosition().x, groundlevel - m_sprite.getGlobalBounds().height );

		m_jumpSoundCounter = 2.f;
		m_jumpDistance = 0.0f; //to enable jumping again
		m_isJumping = false;
		m_isFalling = false;
		m_velocity.x = 0;
		m_velocity.y = 0;
	}
}



void Kirby::handleSpikeCollison(float groundlevel, sf::Time& deltaTime)
{

	if (m_sprite.getPosition().y + m_sprite.getGlobalBounds().height < groundlevel)
	{

	}
	else
	{
		//m_sprite.setPosition(m_sprite.getPosition().x, groundlevel - m_sprite.getGlobalBounds().height);

		m_jumpDistance = 0.0f; //to enable jumping again
		m_isJumping = false;
		m_isFalling = false;

		if (m_direction == Direction::Right)
		{
			m_velocity.x -= m_jumpSpeed;

		}
		else m_velocity.x += m_jumpSpeed;

		m_velocity.y -= m_jumpSpeed * 5;
		m_sprite.move(m_velocity * 20.f);
		m_lives--;
		m_sound[Resources::s_hitByEnemy].play();
		m_isHit = true;
	}
}



void Kirby::handleCeilingCollison(float groundlevel, sf::Time &deltaTime)
{
	m_isColidingWithCeiling = true;
	m_jumpDistance = m_jumpLimit;
}

void Kirby::handleLeftWallCollison(float Walllevel, sf::Time &deltaTime)
{
	
	m_isColidingWithLeftWall = true;

}


void Kirby::handleRightWallCollison(float Walllevel, sf::Time &deltaTime)
{
	m_isColidingWithRightWall = true;
	//std::cout << "im here";
}





//===============================************===================================\\
//****							GET & SET FUNCTIONS							****\\
//****																		****\\
//****																		****\\
//==============================================================================\\


//sets the original position in the board.
//called when the board reads the level

//returns original position in board used when pacman hits demon or when a level is restarted
sf::Vector2f Kirby::getOriginalPosition() const
{
    return m_original_position;
}


sf::Vector2f Kirby::getPosition() const
{
    return m_sprite.getPosition();
}

int Kirby::getScore() const
{
    return m_score;
}

void Kirby::setOriginalPosition(sf::Vector2f pos)
{
    m_original_position = pos;

}

void Kirby::setWhichDoor(int set)
{
    m_WhichDoor = set;
}

void Kirby::setCollisionWithLeftWall(bool set)
{
    m_isColidingWithLeftWall = set;
}

void Kirby::setCollisionWithRightWall(bool set)
{
    m_isColidingWithRightWall = set;

}

void Kirby::setCollisionWithCeiling(bool set)
{
    m_isColidingWithCeiling = set;

}

void Kirby::setScore(int score)
{
	m_score = score;
}

void Kirby::setLevel(int Level)
{
	m_level = Level;
	m_WhichDoor = 0;
	m_isLoaded = false;
	m_fireMode = false;
	m_iceMode = false;
	m_sprite.setTexture(Resources::instance().getTexture(Resources::t_Kirby));
	
}

void Kirby::setKirbyInhale(bool set) 
{
	m_isInhale = set;
}

bool Kirby::getIsIceMode() const
{
	return m_iceMode;
}
bool Kirby::getIsInhale()
{
	return m_isInhale;
}

bool Kirby::getIsShootingFire()
{
	return m_isShootingFire;
}

bool Kirby::getKirbyPuff()
{
	return m_kirbyPuff;
}

bool Kirby::getKirbyStar()
{
	return m_ShootStar;
}

void Kirby::setKirbyPuff(bool set)
{
	m_kirbyPuff = set;
}

void Kirby::setKirbyStar(bool set)
{
	m_kirbyPuff = set;
	m_sound[Resources::s_starShoot].play();
}

void Kirby::setLife(int life)
{
	m_lives = life;
}


bool Kirby::isDirectionRight()
{
	if (m_direction == Direction::Right)
	{
		return true;
	}

	else return false;


}

void Kirby::setLoaded(bool set)
{
	m_isLoaded = set;
}

bool Kirby::getLoaded() const
{
	return m_isLoaded;
}

int Kirby::getLives() const
{
	return m_lives;
}

int Kirby::getLevel() const
{
	return m_level;
}




//===============================************===================================\\
//****								ANIMATION								****\\
//****																		****\\
//****																		****\\
//==============================================================================\\


void Kirby::WalkRightAnimation(sf::Time deltaTime) {

	 m_numFrames = 10;
	 m_frameWidth = 24/* width of a single frame */;
	 m_frameHeight = 24/* height of a single frame */;
	 m_desiredRow = 4;// 0-based index of the desired row



	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
			// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 4, (m_desiredRow * m_frameHeight) , m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);
}




void Kirby::WalkDownAnimation(sf::Time deltaTime) {

	m_numFrames = 8;
	m_frameWidth = 24/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 5;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 4, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);
}


void Kirby::StandStillAnimation(sf::Time deltaTime) {
	m_currentFrame = 0;
	m_numFrames = 2;
	m_frameWidth = 25; // width of a single frame
	m_frameHeight = 24; // height of a single frame
	m_desiredRow = 0; // 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	
	// Define the duration for opening and closing the eyes
	float eyeOpenDuration = 2.0f;
	float eyeClosedDuration = 0.5f;

	if (m_elapsedFrameTime <= eyeOpenDuration) {
		// Display the frame with open eyes
		m_currentFrame = 0;
	}
	else if (m_elapsedFrameTime <= eyeOpenDuration + eyeClosedDuration) {
		// Display the frame with closed eyes
		m_currentFrame = 1;
	}
	else {
		// Reset the animation
		m_currentFrame = 0;
		m_elapsedFrameTime = 0.0f;
	}



	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 4, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);
}



void Kirby::StandLeftAnimation(sf::Time deltaTime) {
	m_currentFrame = 0;
	m_numFrames = 2;
	m_frameWidth = 25; // width of a single frame
	m_frameHeight = 24; // height of a single frame
	m_desiredRow = 0; // 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();


	// Define the duration for opening and closing the eyes
	float eyeOpenDuration = 2.0f;
	float eyeClosedDuration = 0.5f;

	if (m_elapsedFrameTime <= eyeOpenDuration) {
		// Display the frame with open eyes
		m_currentFrame = 0;
	}
	else if (m_elapsedFrameTime <= eyeOpenDuration + eyeClosedDuration) {
		// Display the frame with closed eyes
		m_currentFrame = 1;
	}
	else {
		// Reset the animation
		m_currentFrame = 0;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 4;

	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);
}



void Kirby::WalkLeftAnimation(sf::Time deltaTime) {
	
	m_numFrames =  10;
	m_frameWidth = 24/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 4;// 0-based index of the desired row

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



void Kirby::jumpAnimation(sf::Time deltaTime)
{
	

	m_numFrames = 7;
	m_frameWidth = 25.7/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 3;// 0-based index of the desired row

	if(m_fireMode) //for bigger sprite 
	{
		m_numFrames = 6;
		m_frameWidth = 26.7/* width of a single frame */;
		m_frameHeight = 24/* height of a single frame */;
		m_desiredRow = 3;// 0-based index of the desired row
	}

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 4, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);
}


//////////////////////////////////////////////////////////////

void Kirby::jumpLeftAnimation(sf::Time deltaTime) {

	m_numFrames = 7;
	m_frameWidth = 25.7/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 3;// 0-based index of the desired row

	if (m_fireMode) //for bigger sprite 
	{
		m_numFrames = 6;
		m_frameWidth = 26.7/* width of a single frame */;
		m_frameHeight = 24/* height of a single frame */;
		m_desiredRow = 3;// 0-based index of the desired row
	}

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


void Kirby::flightAnimation(sf::Time deltaTime)
{

	m_numFrames = 5;
	m_frameWidth = 25/* width of a single frame */;
	m_frameHeight = 25/* height of a single frame */;

	if (m_didStartFlight)
	{
		m_desiredRow = 7;
		m_numFrames = 5;
		m_frameWidth = 29/* width of a single frame */;
		m_frameHeight = 25/* height of a single frame */;
	}
	else m_desiredRow = 6;
	

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 4, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

	if (m_currentFrame == m_numFrames - 1)
	{
		m_didStartFlight = true;
	}
}

void Kirby::flightLeftAnimation(sf::Time deltaTime)
{
	m_numFrames = 5;
	m_frameWidth = 25/* width of a single frame */;
	m_frameHeight = 25/* height of a single frame */;

	if (m_didStartFlight)
	{
		m_desiredRow = 7;
		m_numFrames = 5;
		m_frameWidth = 29/* width of a single frame */;
		m_frameHeight = 25/* height of a single frame */;
	}
	else m_desiredRow = 6;

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame

		m_currentFrame = (m_currentFrame + 1) % m_numFrames;

		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 4;


	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

	if (m_currentFrame == m_numFrames - 1)
	{
		m_didStartFlight = true;
	}
}



void Kirby::duckAnimation(sf::Time deltaTime)
{
		m_currentFrame = 0;
		m_numFrames = 2;
		m_frameWidth = 30; // width of a single frame
		m_frameHeight = 23; // height of a single frame
		m_desiredRow = 1; // 0-based index of the desired row

		m_elapsedFrameTime += deltaTime.asSeconds();


		// Define the duration for opening and closing the eyes
		float eyeOpenDuration = 2.0f;
		float eyeClosedDuration = 0.5f;

		if (m_elapsedFrameTime <= eyeOpenDuration) {
			// Display the frame with open eyes
			m_currentFrame = 0;
		}
		else if (m_elapsedFrameTime <= eyeOpenDuration + eyeClosedDuration) {
			// Display the frame with closed eyes
			m_currentFrame = 1;
		}
		else {
			// Reset the animation
			m_currentFrame = 0;
			m_elapsedFrameTime = 0.0f;
		}



		m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 6, (m_desiredRow * m_frameHeight) + 2, m_frameWidth, m_frameHeight - 3));
		m_sprite.setScale(3.0f, 3.0f);
}



void Kirby::duckLeftAnimation(sf::Time deltaTime)
{
	m_currentFrame = 0;
	m_numFrames = 2;
	m_frameWidth = 30; // width of a single frame
	m_frameHeight = 23; // height of a single frame
	m_desiredRow = 1; // 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();


	// Define the duration for opening and closing the eyes
	float eyeOpenDuration = 2.0f;
	float eyeClosedDuration = 0.5f;

	if (m_elapsedFrameTime <= eyeOpenDuration) {
		// Display the frame with open eyes
		m_currentFrame = 0;
	}
	else if (m_elapsedFrameTime <= eyeOpenDuration + eyeClosedDuration) {
		// Display the frame with closed eyes
		m_currentFrame = 1;
	}
	else {
		// Reset the animation
		m_currentFrame = 0;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 4;

	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight) + 2, -m_frameWidth, m_frameHeight - 3));
	m_sprite.setScale(3.0f, 3.0f);
}



void Kirby::releaseFlightAnimation(sf::Time deltaTime) {

	m_numFrames = 7;
	m_frameWidth = 25.7/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 11;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 4, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);
}



void Kirby::releaseFlightLeftAnimation(sf::Time deltaTime) {

	m_numFrames = 7;
	m_frameWidth = 25.7/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 11;// 0-based index of the desired row

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

void Kirby::inhaleRightAnimation(sf::Time deltaTime) {	

		m_numFrames = 6;
		m_frameWidth = 26/* width of a single frame */;
		m_frameHeight = 24/* height of a single frame */;
		m_desiredRow = 6;// 0-based index of the desired row

		m_elapsedFrameTime += deltaTime.asSeconds();

		if (m_elapsedFrameTime >= m_frameDuration && m_currentFrame != 4 && m_currentFrame != 5) {
			// Move to the next frame
			m_currentFrame = (m_currentFrame + 1) % m_numFrames;
			m_elapsedFrameTime = 0.0f;
		}

		m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 4, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
		m_sprite.setScale(3.0f, 3.0f);
	
}

void Kirby::inhaleLeftAnimation(sf::Time deltaTime) {

	m_numFrames = 6;
	m_frameWidth = 26/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 6;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration && m_currentFrame != 4 && m_currentFrame != 5) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 4;

	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

}



void Kirby::StandStillEatingAnimation(sf::Time deltaTime) {

	m_currentFrame = 0;
	m_numFrames = 2;
	m_frameWidth = 29/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 26;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();


	// Define the duration for opening and closing the eyes
	float eyeOpenDuration = 2.0f;
	float eyeClosedDuration = 0.5f;

	if (m_elapsedFrameTime <= eyeOpenDuration) {
		// Display the frame with open eyes
		m_currentFrame = 0;
	}
	else if (m_elapsedFrameTime <= eyeOpenDuration + eyeClosedDuration) {
		// Display the frame with closed eyes
		m_currentFrame = 1;
	}
	else {
		// Reset the animation
		m_currentFrame = 0;
		m_elapsedFrameTime = 0.0f;
	}



	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 4, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

}



void Kirby::StandStillEatingLeftAnimation(sf::Time deltaTime) {
	
	m_currentFrame = 0;
	m_numFrames = 2;
	m_frameWidth = 29/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 26;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();


	// Define the duration for opening and closing the eyes
	float eyeOpenDuration = 2.0f;
	float eyeClosedDuration = 0.5f;

	if (m_elapsedFrameTime <= eyeOpenDuration) {
		// Display the frame with open eyes
		m_currentFrame = 0;
	}
	else if (m_elapsedFrameTime <= eyeOpenDuration + eyeClosedDuration) {
		// Display the frame with closed eyes
		m_currentFrame = 1;
	}
	else {
		// Reset the animation
		m_currentFrame = 0;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 4;

	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);
}


void Kirby::WalkRightEatingAnimation(sf::Time deltaTime) {

	m_numFrames = 8;
	m_frameWidth = 29/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 29;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) - 2 , (m_desiredRow * m_frameHeight) - 8, m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);
}


void Kirby::WalkLeftEatingAnimation(sf::Time deltaTime) {

	m_numFrames = 10;
	m_frameWidth = 29/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 29;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame

		m_currentFrame = (m_currentFrame + 1) % m_numFrames;

		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) -2;


	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight) - 8, -m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);
}


//--------------------------------------------------------------------------------------

void Kirby::releaseStarAnimation(sf::Time deltaTime) {

	//m_currentFrame = 0;
	m_numFrames = 5;
	m_frameWidth = 29/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 24;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration && m_currentFrame != 4 && m_currentFrame != 5) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 2, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

	if (m_currentFrame == m_numFrames - 2)
	{
		m_ShootStar = false;
		m_isAte = false;
	}
}


void Kirby::releaseStarLeftAnimation(sf::Time deltaTime) {

	m_numFrames = 5;
	m_frameWidth = 29/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 24;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 2;

	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), -m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

	if (m_currentFrame == m_numFrames - 2)
	{
		m_ShootStar = false;
		m_isAte = false;
	}
}



void Kirby::hitAnimation(sf::Time deltaTime)
{
	m_numFrames = 9;
	m_frameWidth = 26/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 30;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	m_sprite.setTextureRect(sf::IntRect((m_currentFrame * m_frameWidth) + 2.9, (m_desiredRow * m_frameHeight), m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

	if(m_currentFrame == m_numFrames - 1)
	{
		m_isHit = false;
	}
}


void Kirby::hitLeftAnimation(sf::Time deltaTime)
{
	m_numFrames = 9;
	m_frameWidth = 26/* width of a single frame */;
	m_frameHeight = 24/* height of a single frame */;
	m_desiredRow = 30;// 0-based index of the desired row

	m_elapsedFrameTime += deltaTime.asSeconds();

	if (m_elapsedFrameTime >= m_frameDuration) {
		// Move to the next frame
		m_currentFrame = (m_currentFrame + 1) % m_numFrames;
		m_elapsedFrameTime = 0.0f;
	}

	int framecalc = ((m_currentFrame + 1) * m_frameWidth) + 2.9;



	m_sprite.setTextureRect(sf::IntRect(framecalc, (m_desiredRow * m_frameHeight), - m_frameWidth, m_frameHeight));
	m_sprite.setScale(3.0f, 3.0f);

	if (m_currentFrame == m_numFrames - 1)
	{
		m_isHit = false;
	}
}

void Kirby::handleStillAnimations(sf::Time deltaTime)
{
		if (m_isJumping)
		{
			if (m_direction == Direction::Right)
			{
				jumpAnimation(deltaTime);
			}
			else jumpLeftAnimation(deltaTime);

		}

		else if (m_isFlying)
		{
			if (m_direction == Direction::Right)
			{
				flightAnimation(deltaTime);
			}
			else flightLeftAnimation(deltaTime);
		}

		else if (m_isFalling)
		{
			if (m_direction == Direction::Right)
			{
				releaseFlightAnimation(deltaTime);
			}

			else if (m_direction == Direction::Left)
			{
				releaseFlightLeftAnimation(deltaTime);
			}
		}

		else if (m_isInhale || m_isShootingFire)
		{
			if (m_direction == Direction::Right)
			{
				inhaleRightAnimation(deltaTime);
			}

			else if (m_direction == Direction::Left)
			{
				inhaleLeftAnimation(deltaTime);
			}
		}

		else if (m_ShootStar)
		{
			if (m_direction == Direction::Right)
			{
				releaseStarAnimation(deltaTime);

			}
			else
			{
				releaseStarLeftAnimation(deltaTime);
			}
		}
		else if (m_direction == Direction::Left)
		{
			if (m_isAte)
			{
				StandStillEatingLeftAnimation(deltaTime);
			}

			else if (m_isHit)
			{
				hitLeftAnimation(deltaTime);
				m_iceMode = false;
				m_fireMode = false;
				m_sprite.setTexture(Resources::instance().getTexture(Resources::t_Kirby));
			}
			else	StandLeftAnimation(deltaTime);
		}
		else
		{
			if (m_isAte)
			{
				StandStillEatingAnimation(deltaTime);
			}

			else if (m_isHit)
			{
				hitAnimation(deltaTime);
				m_iceMode = false;
				m_fireMode = false;
				m_sprite.setTexture(Resources::instance().getTexture(Resources::t_Kirby));
			}

			else StandStillAnimation(deltaTime);

			m_isDucking = false;
		}
}

///////////////////////////////////PRESS MOVES////////////////////////////////////////////
void Kirby::PressRight(sf::Time deltaTime)
{
    m_direction = Direction::Right;

    if (!m_isColidingWithRightWall && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_velocity.x = 1; //KirbySpeed;
    }
    if (m_isHit)
    {
        hitAnimation(deltaTime);
        m_iceMode = false;
        m_fireMode = false;
        m_sprite.setTexture(Resources::instance().getTexture(Resources::t_Kirby));
    }
    else if (m_isJumping)
    {
        jumpAnimation(deltaTime);
    }
    else if (m_isFlying)
    {
        flightAnimation(deltaTime);
    }
    else if (m_isAte)
    {
        WalkRightEatingAnimation(deltaTime);
    }
    else WalkRightAnimation(deltaTime);
}

void Kirby::PressLeft(sf::Time deltaTime)
{
    if (!m_isColidingWithLeftWall && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_velocity.x = -1;
    }

    m_direction = Direction::Left;
    if (m_isHit)
    {
        hitLeftAnimation(deltaTime);
        m_iceMode = false;
        m_fireMode = false;
        m_sprite.setTexture(Resources::instance().getTexture(Resources::t_Kirby));
    }
    else if (m_isJumping)
    {
        jumpLeftAnimation(deltaTime);
    }
    else if (m_isFlying)
    {
        flightLeftAnimation(deltaTime);
    }
    else if (m_isAte)
    {
        WalkLeftEatingAnimation(deltaTime);
    }

    else WalkLeftAnimation(deltaTime);
}
