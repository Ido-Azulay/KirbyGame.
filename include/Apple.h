#pragma once
#include "StaticObject.h"

class Apple : public StaticObject
{
public:
    Apple(const sf::Vector2f& pos);
    ~Apple();


    virtual void handleCollison(Kirby& obj);
	virtual void handleCollison(SwordEnemy& obj) {};
	virtual void handleCollison(Airpuff& obj) {};
	virtual void handleCollison(Inhale& obj) {};
	virtual void handleCollison(KirbyStar& obj) {};
	virtual void handleCollison(PlantEnemy& obj) {};
	virtual void handleCollison(OrangeEnemy& obj) {};
	virtual void handleCollison(Fire& obj) {};
	virtual void handleCollison(FireEnemy& obj) {};
	virtual void handleCollison(FlyingEnemy& obj) {};
	virtual void handleCollison(Apple& obj) {};


private:

};

