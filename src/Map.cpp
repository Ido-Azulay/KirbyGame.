#include "Map.h"
#include "Airpuff.h"
#include <iostream>
#include "SwordEnemy.h"
#include "KirbyStar.h"
#include "PlantEnemy.h"
#include "OrangeEnemy.h"
#include "Fire.h"
#include "FireEnemy.h"
#include "FlyingEnemy.h"
#include "Apple.h"
#include "LifeGift.h"
#include "IceManEnemy.h"
#include "BlackStarEnemy.h"

//******************************* CONTRUCTORS & DESTRUCTOR ****************************\\

Map::Map() :m_inputFile("Level_1-1.txt"), m_fireCounter(0), m_StarCounter(0), m_floor(), m_ceiling(), m_camera(sf::FloatRect(0.0f, 0.0f, static_cast<float>(WINDOW_WIDTH), static_cast<float>(WINDOW_HEIGT))), m_lifeView(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGT))
{
	

	m_mapSprite.setTexture(Resources::instance().getTexture(Resources::instance().t_map1));
	

	m_mapSprite.setScale(5, 5);

	m_backGround.setTexture(Resources::instance().getTexture(Resources::instance().t_background));
	
	m_backGround.setScale(3, 3);
	//createFloorLine();
	
	//rectangles = createRectanglesOnLines(m_floorLine);

	if (!m_inputFile.is_open())
	{
		std::cerr << "could'nt open board text file\n";
		exit(EXIT_FAILURE);
	}

	m_inputFile.close();

	m_puffCounter = 0;
	m_InhaleCounter = 0;

	for (int i = 0; i < 5; i++)
	{
		sf::Sprite life;

		life.setTexture(Resources::instance().getTexture(Resources::t_tiny_kirby));
		life.setScale(3.f, 15.f);
		m_life.push_back(life);

	}

	intializeDoors();

	m_lifeView.setViewport(sf::FloatRect(0,0.9f,1,0.2f));

	for(int i = 1; i < m_life.size(); i++)
	{
		m_life[i].setPosition(m_life[i - 1].getGlobalBounds().left + 50 , m_life[i-1].getGlobalBounds().top);
		sf::Vector2f textpos(m_life[i].getPosition());

		if (i == 1)
		{
			textpos.x += 900;
			m_text.setPosition(textpos);
		}
		
	}


}

//==============================================================
//distructor
Map::~Map()
{
	m_inputFile.close();
}

//==============================================================
//this function restarts the board
//clears the vectors so it can read them new for the next level
//or when pacman is out of lives 

//void Map::restartBoard()
//{
//	m_movingObjects.clear();
//	m_staticObjects.clear();
//	m_board.clear();
//
//	//scale factor because eachtime we restart the game read board set scalse to pacman
//	//and makes it smaller and smaller , this is the fix we multiplay by the scalefactor^(-1)
//	sf::Vector2f scaleFactor = CalculateFactor();
//	scaleFactor.x = 1 / scaleFactor.x;
//	scaleFactor.y = 1 / scaleFactor.y;
//	m_pacman.setScale(scaleFactor);
//	m_text.resetTime();
//	m_text.setTime();
//}


//-----------------------------------------------------------------------------

//This function reads the board from the text file for each level of the game,
//and run through all objects (static and moving objects) and add each of them 
//to the wanted vector.
void Map::LoadMap(int level)
{


	m_inputFile.open("Level_1-1.txt");

	m_MapString.clear(); //clears the string before reading a new

	m_inputFile >> m_MapSize.x >> m_MapSize.y;

	m_inputFile.get(); //take endl after row and coll

	for (int i = 0; i < m_MapSize.y; i++) //reading board from text file to m_board string member
	{
		std::string line;
		std::getline(m_inputFile, line);
		m_MapString.push_back(line);
	}
	sf::Vector2f pos;
	sf::Vector2f scaleFactor = CalculateFactor(); //calculate factor to match sprite sizes to screen and level size

	m_inputFile.close();

	//going over the char matrix and pushing the objects to the static and moving object vectors of the board
	//each object has its own case

	//sf::Vector2f kirbypos(5051.f, 1801.f); //third door map
	
	//m_kirby.setLoaded(false);
	m_kirby.setLevel(1);
	m_kirby.setLife(5);
	m_kirby.setScore(0);

	sf::Vector2f kirbypos(50.f, 1500.f); 

	m_kirby.setScale(scaleFactor);
	m_kirby.setFactor(scaleFactor);
	
	m_kirby.setPosition(kirbypos);
	m_kirby.setOriginalPosition(kirbypos);
	m_kirby.setScale(scaleFactor);
	m_kirby.setFactor(scaleFactor);

	pos.x = 100;
	pos.y = 1300;
	m_staticObjects.push_back(std::make_unique<Apple>(pos));
	sf::Vector2f scale(2.5f, 2.5f);
	m_staticObjects.back()->setScale(scale);

	pos.x = 583;
	pos.y = 700;
	m_staticObjects.push_back(std::make_unique<Apple>(pos));
	m_staticObjects.back()->setScale(scale);

	pos.x = 2650;
	pos.y = 700;
	m_staticObjects.push_back(std::make_unique<Apple>(pos));
	m_staticObjects.back()->setScale(scale);

	pos.x = 6048;
	pos.y = 1700;
	m_staticObjects.push_back(std::make_unique<Apple>(pos));
	m_staticObjects.back()->setScale(scale);

	pos.x = 5615;
	pos.y = 1180;
	m_staticObjects.push_back(std::make_unique<LifeGift>(pos));
	m_staticObjects.back()->setScale(scale);

	pos.x = 2883;
	pos.y = 2233;
	m_staticObjects.push_back(std::make_unique<LifeGift>(pos));
	m_staticObjects.back()->setScale(scale);



}

//-----------------------------------------------------------------------------


//Function to go through all the objects inside the vectors ( static and moving ) 
//to draw them on the board, and same for pacman and fonts (aka time, score and so on),
//and update the direction of the objects as well as erasing the needed objects.
void Map::drawMap(sf::RenderWindow& window) const
{
	

	
	window.setView(m_camera);
	window.draw(m_backGround);
	window.draw(m_mapSprite);
	m_kirby.drawObject(window);

	

	for (auto& mov : m_movingObjects)
	{
		mov->drawObject(window);
	}

	for (auto& stat : m_staticObjects)
	{
		stat->drawObject(window);
	}

	
	//m_text.draw(window);*/


	//::::::::::::::::::DRAW FOR VISUAL TESTS:::::::::::::::::::::::::::

	//m_floor.drawLine(window);
	//m_ceiling.drawLine(window);
	//m_leftWall.drawLine(window);
	//m_rightWall.drawLine(window);
	//m_spikes.drawLine(window);
	/*for (const auto door : m_door)
	{
		window.draw(door);
	}*/

	window.setView(m_lifeView);

	for (int i = 0; i < m_kirby.getLives(); i++)
	{
		window.draw(m_life[i]);

	}
	m_text.draw(window);
}

//---------------------------------------------------------------------------------
//Function to update the board and movement for each of the needed objects on board
void Map::updateMap(const sf::Time& deltaTime)
{
	
	
	m_text.setScore(m_kirby.getScore());

	std::cout << "x: " << m_kirby.getPosition().x << " y: " << m_kirby.getPosition().y;
	std::cout << std::endl;

	if (!m_kirby.getLoaded())
	{
		loadEnemies();
	}

	m_kirby.move(deltaTime, m_movingObjects, m_staticObjects);

	KirbyPuff();
	Star();
	KirbyFire();
	KirbyInhale();
	
	sf::Vector2f targetPosition = m_kirby.getPosition();

	float dampingFactor = 0.1f;

	sf::Vector2f positionDifference = targetPosition - m_camera.getCenter();

	sf::Vector2f intermidietePosition = m_camera.getCenter() + positionDifference * dampingFactor;

	m_camera.setCenter(intermidietePosition);


	 //map objects collisions check
	CheckCollisionWithMapObjects(deltaTime);

		for (auto& mov : m_movingObjects) //regular ghosts movment
		{
	//		sf::Vector2f pos = m_pacman.getPosition(); //get current pacman position

	//		mov->updateDirection(pos, time); //function for ghots to update their movment direction according to pacmas location
			if (mov->getChar() == INHALE)
			{
				if (m_kirby.isDirectionRight())
				{
					sf::Vector2f pos = m_kirby.getPosition();
					pos.x = pos.x + 60;
					pos.y = pos.y - 10;
					mov->setPosition(pos);
				}
				else {
					sf::Vector2f pos = m_kirby.getPosition();
					pos.x = pos.x - 120;
					pos.y = pos.y - 10;
					mov->setPosition(pos);

				}
			}

			if (mov->getChar() == FIRE)
			{
				if (m_kirby.isDirectionRight())
				{
					sf::Vector2f pos = m_kirby.getPosition();
					pos.x = pos.x + 60;
					pos.y = pos.y - 10;
					mov->setPosition(pos);
				}
				else {
					sf::Vector2f pos = m_kirby.getPosition();
					pos.x = pos.x - 100;
					pos.y = pos.y - 10;
					mov->setPosition(pos);

				}
			}

			mov->move(deltaTime, m_movingObjects, m_staticObjects); //ghosts movement

		}

		
	eraseDeletedObjects();


}

int Map::getDoor() const
{
	return m_kirby.getLevel();
}

int Map::getKirbyLives() const
{
	return m_kirby.getLives();
}

//-----------------------------------------------------------------------------

//Function to calculate the factor for sprites to match the screen and board size
sf::Vector2f Map::CalculateFactor()
{

	sf::Vector2f scaleFactor;
	float heigt = (WINDOW_HEIGT - 280);
	float width = WINDOW_WIDTH;
	scaleFactor.x = std::min(heigt / (m_MapSize.x * SPRITE_SIZE), width / (m_MapSize.y * SPRITE_SIZE));
	scaleFactor.y = scaleFactor.x;

	return scaleFactor;
}

//-----------------------------------------------------------------------------

//Function to run through all objects (in two vectors) and arase what needed.
//and handle behavior for erased objects for example:
//when a certain key is erased we delete a door also 
void Map::eraseDeletedObjects()
{

	for (auto& mov : m_movingObjects) //regular ghosts movment
	{
		if (mov->getChar() == AIRPUFF && mov->get_is_disposed()) //if pacman ate super gift
		{
			m_puffCounter = 0;
			m_kirby.setKirbyPuff(false);
		}

		if (mov->getChar() == '*' && mov->get_is_disposed()) //if pacman ate super gift
		{
			m_StarCounter = 0;
			m_kirby.setKirbyStar(false);
		}
		

		if (mov->getChar() == 'I' && !m_kirby.getIsInhale()) //deleting kirby
		{
			m_InhaleCounter = 0;
			mov->set_is_disposed();
		}

		if (mov->getChar() == FIRE && !m_kirby.getIsShootingFire()) //deleting kirby
		{
			m_fireCounter = 0;
			mov->set_is_disposed();
		}
	}

	//erase all static objects that their m_isdisposed member is true (boolian member)
	std::erase_if(m_staticObjects, [](const auto& item) {return item->get_is_disposed(); });
	std::erase_if(m_movingObjects, [](const auto& item) {return item->get_is_disposed(); });
}

//==================================

//Function to able pacman to teleport from the sides of the board



///===========================================GET FUNCTIONS=========================


void Map::CheckCollisionWithMapObjects(sf::Time deltaTime)
{
	if (m_floor.isCollison(m_kirby.getBounds()) != -10000)
	{
		m_kirby.handleFloorCollison(m_floor.isCollison(m_kirby.getBounds()) , deltaTime);
	}

	if (m_ceiling.isCollison(m_kirby.getBounds()) != -10000)
	{
		m_kirby.handleCeilingCollison(m_ceiling.isCollison(m_kirby.getBounds()), deltaTime);
	}
	else
	{
		m_kirby.setCollisionWithCeiling(false);
	}

	if (m_leftWall.isCollison(m_kirby.getBounds()) != -10000)
	{
		m_kirby.handleLeftWallCollison(m_leftWall.isCollison(m_kirby.getBounds()), deltaTime);
	}
	else
	{
		m_kirby.setCollisionWithLeftWall(false);
	}

	if (m_rightWall.isCollison(m_kirby.getBounds()) != -10000)
	{
		m_kirby.handleRightWallCollison(m_rightWall.isCollison(m_kirby.getBounds()), deltaTime);
	}
	else
	{
		m_kirby.setCollisionWithRightWall(false);
	}

	if (m_spikes.isCollison(m_kirby.getBounds()) != -10000)
	{
		m_kirby.handleSpikeCollison(m_spikes.isCollison(m_kirby.getBounds()), deltaTime);
	}

	for (auto& mov : m_movingObjects) //regular ghosts movment
	{
		if (m_floor.isCollison(mov->getBounds()) != -10000)
		{
			mov->handleFloorCollison(m_floor.isCollison(mov->getBounds()), deltaTime);
		}

		if (m_ceiling.isCollison(mov->getBounds()) != -10000)
		{
			mov->handleCeilingCollison(m_ceiling.isCollison(mov->getBounds()), deltaTime);
		}
		else
		{
			mov->setCollisionWithCeiling(false);
		}

		if (m_leftWall.isCollison(mov->getBounds()) != -10000)
		{
			mov->handleLeftWallCollison(m_leftWall.isCollison(m_kirby.getBounds()), deltaTime);
		}
		else
		{
			mov->setCollisionWithLeftWall(false);
		}
		if (m_rightWall.isCollison(mov->getBounds()) != -10000)
		{
			mov->handleRightWallCollison(m_rightWall.isCollison(m_kirby.getBounds()), deltaTime);
		}
		else
		{
			mov->setCollisionWithRightWall(false);
		}

	}

	m_kirby.setWhichDoor(-1);

	for (int i = 0; i<m_door.size(); i++)
	{
		if (m_kirby.getBounds().intersects(m_door[i].getGlobalBounds()))
		{
			m_kirby.setWhichDoor(i);
		}
	}

}

void Map::KirbyPuff()
{
	if (m_kirby.getKirbyPuff())
	{
		if (m_puffCounter < 1)
		{
			sf::Vector2f pos = m_kirby.getPosition();

			m_movingObjects.push_back(std::make_unique<Airpuff>(pos));

			m_movingObjects.back()->setScale(CalculateFactor());

			if (m_kirby.isDirectionRight())
			{
				pos.x += 20;
				pos.y += 20;

				m_movingObjects.back()->setPosition(pos);

				m_movingObjects.back()->setDirection(MovingObject::Direction::Right);
			}

			else
			{
				m_movingObjects.back()->setDirection(MovingObject::Direction::Left);
				pos.x -= 20;
				pos.y += 20;

				m_movingObjects.back()->setPosition(pos);
			}
			m_puffCounter++;
		}

	}
}




void Map::KirbyInhale()
{
	if (m_kirby.getIsInhale())
	{
		if (m_InhaleCounter < 1)
		{
			sf::Vector2f pos = m_kirby.getPosition();

			m_movingObjects.push_back(std::make_unique<Inhale>(pos));

			m_movingObjects.back()->setScale(CalculateFactor());

			if (m_kirby.isDirectionRight())
			{

				m_movingObjects.back()->setDirection(MovingObject::Direction::Right);
			}

			else
			{
				m_movingObjects.back()->setDirection(MovingObject::Direction::Left);
			}
			m_InhaleCounter++;
		}

	}
	
}



void Map::Star()
{
	if (m_kirby.getKirbyStar())
	{
		if (m_StarCounter < 1)
		{
			sf::Vector2f pos = m_kirby.getPosition();

			m_movingObjects.push_back(std::make_unique<KirbyStar>(pos));

			m_movingObjects.back()->setScale(CalculateFactor() * 3.f);

			if (m_kirby.isDirectionRight())
			{
				pos.x += 20;
				pos.y += 15;

				m_movingObjects.back()->setPosition(pos);

				m_movingObjects.back()->setDirection(MovingObject::Direction::Right);
			}

			else
			{
				m_movingObjects.back()->setDirection(MovingObject::Direction::Left);
				pos.x -= 40;
				pos.y += 15;

				m_movingObjects.back()->setPosition(pos);
			}
			m_StarCounter++;
		}

	}
}



void Map::KirbyFire()
{
	if (m_kirby.getIsShootingFire())
	{
		
		if (m_fireCounter < 1)
		{
			
			sf::Vector2f pos = m_kirby.getPosition();
			if (m_kirby.getIsIceMode())
			{
				m_movingObjects.push_back(std::make_unique<Fire>(pos, false));
			}
			else m_movingObjects.push_back(std::make_unique<Fire>(pos , true));


			m_movingObjects.back()->setScale(CalculateFactor());

			if (m_kirby.isDirectionRight())
			{
				
				m_movingObjects.back()->setDirection(MovingObject::Direction::Right);
			}

			else
			{
				m_movingObjects.back()->setDirection(MovingObject::Direction::Left);
			}
			m_fireCounter++;
		}

	}

}


void Map::intializeDoors()
{
	sf::Vector2f size(50, 50);
	sf::RectangleShape rect(size);

	rect.setPosition(1018, 293);

	m_door.push_back(rect);

	rect.setPosition(2585, 470);

	m_door.push_back(rect);

	rect.setPosition(5050,1880);

	m_door.push_back(rect);

	rect.setPosition(6890 , 920);

	m_door.push_back(rect);
	
}

void Map::loadEnemies() 
{

	sf::Vector2f scaleFactor = CalculateFactor();
	sf::Vector2f pos;

	m_movingObjects.clear();

	if(m_kirby.getLevel() == 1)
	{
		m_kirby.setKirbyInhale(false);
		m_kirby.setKirbyPuff(false);
		m_kirby.setKirbyStar(false);
		m_fireCounter = 0;
		m_InhaleCounter = 0;
		m_puffCounter = 0;
		m_StarCounter = 0; //bugFixes

		pos.x = 683;
		pos.y = 948;
		m_movingObjects.push_back(std::make_unique<SwordEnemy>(pos, 5));
		m_movingObjects.back()->setScale(scaleFactor);

		pos.x = 653;
		pos.y = 300;
		m_movingObjects.push_back(std::make_unique<FlyingEnemy>(pos, 5));
		m_movingObjects.back()->setScale(scaleFactor);


		pos.x = 970;
		pos.y = 1025;
		m_movingObjects.push_back(std::make_unique<SwordEnemy>(pos, 2));
		m_movingObjects.back()->setScale(scaleFactor); pos.x = 970;


		pos.x = 615;
		pos.y = 1365;
		m_movingObjects.push_back(std::make_unique<OrangeEnemy>(pos, 2));
		m_movingObjects.back()->setScale(scaleFactor);

		pos.x = 800;
		pos.y = 1265;
		m_movingObjects.push_back(std::make_unique<OrangeEnemy>(pos, 3));
		m_movingObjects.back()->setScale(scaleFactor);

		pos.x = 252;
		pos.y = 778;
		m_movingObjects.push_back(std::make_unique<PlantEnemy>(pos, 2));
		m_movingObjects.back()->setScale(scaleFactor);
		
		pos.x = 893;
		pos.y = 630;
		m_movingObjects.push_back(std::make_unique<PlantEnemy>(pos, 2));
		m_movingObjects.back()->setScale(scaleFactor);
		
		pos.x = 275;
		pos.y = 550;
		m_movingObjects.push_back(std::make_unique<BlackStarEnemy>(pos, 4));
		m_movingObjects.back()->setScale(scaleFactor);

		pos.x = 770;
		pos.y = 450;
		m_movingObjects.push_back(std::make_unique<BlackStarEnemy>(pos, 3));
		m_movingObjects.back()->setScale(scaleFactor);

		m_kirby.setLoaded(true);
	}

	else if(m_kirby.getLevel() == 2)
	{
		m_kirby.setKirbyInhale(false);
		m_kirby.setKirbyPuff(false);
		m_kirby.setKirbyStar(false);
		m_fireCounter = 0;
		m_InhaleCounter = 0;
		m_puffCounter = 0;
		m_StarCounter = 0; //bugFixes


	pos.x = 3117;
	pos.y = 2398;
	m_movingObjects.push_back(std::make_unique<SwordEnemy>(pos, 0));
	m_movingObjects.back()->setScale(scaleFactor); pos.x = 970;

	pos.x = 2880;
	pos.y = 1913;
	m_movingObjects.push_back(std::make_unique<PlantEnemy>(pos, 2));
	m_movingObjects.back()->setScale(scaleFactor);

	pos.x = 3115;
	pos.y = 2073;
	m_movingObjects.push_back(std::make_unique<PlantEnemy>(pos, 2));
	m_movingObjects.back()->setScale(scaleFactor);

	pos.x = 3323;
	pos.y = 1513;
	m_movingObjects.push_back(std::make_unique<IceManEnemy>(pos, 2));
	m_movingObjects.back()->setScale(scaleFactor);

	pos.x = 3075;
	pos.y = 790;
	m_movingObjects.push_back(std::make_unique<OrangeEnemy>(pos, 15));
	m_movingObjects.back()->setScale(scaleFactor);

	pos.x = 3075;
	pos.y = 790;
	m_movingObjects.push_back(std::make_unique<OrangeEnemy>(pos, 10));
	m_movingObjects.back()->setScale(scaleFactor);

	pos.x = 3075;
	pos.y = 790;
	m_movingObjects.push_back(std::make_unique<OrangeEnemy>(pos, 3));
	m_movingObjects.back()->setScale(scaleFactor);

	pos.x = 3173;
	pos.y = 473;
	m_movingObjects.push_back(std::make_unique<PlantEnemy>(pos, 3));
	m_movingObjects.back()->setScale(scaleFactor);

	pos.x = 2746;
	pos.y = 468;
	m_movingObjects.push_back(std::make_unique<FireEnemy>(pos, 2));
	m_movingObjects.back()->setScale(scaleFactor);	
	
	pos.x = 2565;
	pos.y = 1050;
	m_movingObjects.push_back(std::make_unique<BlackStarEnemy>(pos, 4));
	m_movingObjects.back()->setScale(scaleFactor);
	
	pos.x = 2995;
	pos.y = 300;
	m_movingObjects.push_back(std::make_unique<BlackStarEnemy>(pos, 2));
	m_movingObjects.back()->setScale(scaleFactor);

	m_kirby.setLoaded(true);
	}


	else if (m_kirby.getLevel() == 3)
	{

		m_kirby.setKirbyInhale(false);
		m_kirby.setKirbyPuff(false);
		m_kirby.setKirbyStar(false);
		m_fireCounter = 0;
		m_InhaleCounter = 0;
		m_puffCounter = 0;
		m_StarCounter = 0; //bugFixes

		pos.x = 5794;
		pos.y = 520;
		m_movingObjects.push_back(std::make_unique<FlyingEnemy>(pos, 5));
		m_movingObjects.back()->setScale(scaleFactor);


		pos.x = 5842;
		pos.y = 1950;
		m_movingObjects.push_back(std::make_unique<IceManEnemy>(pos, 5));
		m_movingObjects.back()->setScale(scaleFactor);



		pos.x = 5336;
		pos.y = 520;
		m_movingObjects.push_back(std::make_unique<FlyingEnemy>(pos, 3));
		m_movingObjects.back()->setScale(scaleFactor);

		pos.x = 6080;
		pos.y = 520;
		m_movingObjects.push_back(std::make_unique<FlyingEnemy>(pos, 3));
		m_movingObjects.back()->setScale(scaleFactor);

		pos.x = 6542;
		pos.y = 1903;
		m_movingObjects.push_back(std::make_unique<OrangeEnemy>(pos, 8));
		m_movingObjects.back()->setScale(scaleFactor);

		pos.x = 6250;
		pos.y = 1920;
		m_movingObjects.push_back(std::make_unique<OrangeEnemy>(pos, 10));
		m_movingObjects.back()->setScale(scaleFactor);

		pos.x = 4910;
		pos.y = 710;
		m_movingObjects.push_back(std::make_unique<SwordEnemy>(pos, 3));
		m_movingObjects.back()->setScale(scaleFactor);

		pos.x = 5370;
		pos.y = 1410;
		m_movingObjects.push_back(std::make_unique<FireEnemy>(pos, 5));
		m_movingObjects.back()->setScale(scaleFactor);


		pos.x = 5955;
		pos.y = 1235;
		m_movingObjects.push_back(std::make_unique<PlantEnemy>(pos, 5));
		m_movingObjects.back()->setScale(scaleFactor);
		

		pos.x = 6200;
		pos.y = 1160;
		m_movingObjects.push_back(std::make_unique<PlantEnemy>(pos, 5));
		m_movingObjects.back()->setScale(scaleFactor);

		pos.x = 6710;
		pos.y = 750;
		m_movingObjects.push_back(std::make_unique<BlackStarEnemy>(pos, 3));
		m_movingObjects.back()->setScale(scaleFactor);

		pos.x = 5100;
		pos.y = 550;
		m_movingObjects.push_back(std::make_unique<BlackStarEnemy>(pos, 3));
		m_movingObjects.back()->setScale(scaleFactor);

		pos.x = 5800;
		pos.y = 550;
		m_movingObjects.push_back(std::make_unique<BlackStarEnemy>(pos, 3));
		m_movingObjects.back()->setScale(scaleFactor);

		m_kirby.setLoaded(true);
	}
}


