#pragma once

#include "mapObject.h"
#include "ConstAndEnum.h"
#include <SFML/Graphics.hpp>
#include <vector>

class LeftWall : public mapObject {

public:
	LeftWall();
	virtual void createLine() override;
	float isCollison(sf::FloatRect obj);

private:

};