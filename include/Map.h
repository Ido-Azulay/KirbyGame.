/*
Board class - this class  hold functions to read each level from the txt files
and update and draw the board at each moment.

*/

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <memory>
#include "ConstAndEnum.h"
#include "StaticObject.h"
#include "MovingObject.h"
#include "mapObject.h"
#include "Airpuff.h"
#include "Ceiling.h"
#include "LeftWall.h"
#include "RightWall.h"
#include "SwordEnemy.h"
#include "Kirby.h"
#include "Floor.h"
#include "Inhale.h"
#include "KirbyStar.h"
#include "PlantEnemy.h"
#include "Spike.h"
#include "Apple.h"
#include "TextAndFont.h"
#include "LifeGift.h"
#include "BlackStarEnemy.h"


class Map {
public:
	Map();//
	~Map();//
	void LoadMap(int level);//
	void drawMap(sf::RenderWindow& window) const;//
	void updateMap(const sf::Time& deltaTime);//

	int getDoor() const;//

	int getKirbyLives() const;
	//int getNumOfCookies() const;
	//int getBoardTime() const;
	//void restartBoard();
	//void resetPacLives();
	
	
private:
	void intializeDoors();//
	void loadEnemies();//
	void CheckCollisionWithMapObjects(sf::Time deltaTime);//
	void KirbyPuff();//
	void Star();//
	void KirbyInhale();//
	void KirbyFire();//
	
	sf::Vector2f CalculateFactor();//
	//void pacTeleport();
	void eraseDeletedObjects();//

	sf::Vector2i m_MapSize;
	std::fstream m_inputFile;
	std::vector<std::string> m_MapString;
	//TextAndFont m_text;

	sf::Sprite m_mapSprite;
	sf::Sprite m_backGround;
	sf::View m_camera;
	sf::View m_lifeView;

	Kirby m_kirby;
	int m_puffCounter;
	int m_StarCounter;
	int m_InhaleCounter;
	int m_fireCounter;

	std::vector<sf::Sprite> m_life;
	Floor m_floor;
	Ceiling m_ceiling;
	RightWall m_rightWall;
	LeftWall m_leftWall;
	Spike m_spikes;
	TextAndFont m_text;

	std::vector<std::unique_ptr<MovingObject>> m_movingObjects;
	std::vector<std::unique_ptr<StaticObject>> m_staticObjects;

	std::vector<sf::RectangleShape> m_door;
	//sf::VertexArray  m_floorLine;
	//std::vector<sf::RectangleShape> rectangles;

};











