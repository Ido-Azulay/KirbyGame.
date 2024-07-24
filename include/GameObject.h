#pragma once 


#pragma once
#include "Resources.h"
#include "ConstAndEnum.h"
#include <SFML/Graphics.hpp>

//class MovingObject;

class Kirby;
class Floor;
class SwordEnemy;
class Airpuff;
class Inhale;
class KirbyStar;
class PlantEnemy;
class OrangeEnemy;
class Fire;
class FireEnemy;
class FlyingEnemy;
class Apple;
class LifeGift;
class IceManEnemy;
class BlackStarEnemy;


class GameObject
{
public:
	GameObject();
	GameObject(const sf::Texture& tex);
	GameObject(const sf::Vector2f& pos, const sf::Texture& tex);

	char getChar();

	void setScale(const sf::Vector2f& scale);

	~GameObject() = default;

	void drawObject(sf::RenderWindow& window) const;

	void setPosition(sf::Vector2f pos);

	sf::Vector2f getPosition() const;
	

	sf::FloatRect getBounds() const;

	void handleCollison(GameObject& obj);
	virtual void handleCollison(Kirby& obj) {};
	virtual void handleCollison(SwordEnemy& obj) {};
	virtual void handleCollison(Airpuff& obj) {};
	virtual void handleCollison(Inhale& obj) {};
	virtual void handleCollison(KirbyStar& obj) {};
	virtual void handleCollison(PlantEnemy& obj) {};
	virtual void handleCollison(OrangeEnemy& obj) {};
	virtual void handleCollison(Fire& obj){};
	virtual void handleCollison(FireEnemy& obj){};
	virtual void handleCollison(FlyingEnemy& obj){};
	virtual void handleCollison(Apple& obj){};
	virtual void handleCollison(LifeGift& obj){};
	virtual void handleCollison(IceManEnemy& obj){};
	virtual void handleCollison(BlackStarEnemy& obj){};
	
	void setFactor(sf::Vector2f factor);

protected:
	sf::Sprite m_sprite;
	char m_char;
	sf::Vector2f m_factor;
};

