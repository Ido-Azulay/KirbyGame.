#pragma once

#include "mapObject.h"
#include "ConstAndEnum.h"
#include <SFML/Graphics.hpp>
#include <vector>

class RightWall : public mapObject {

public:
	RightWall();
	virtual void createLine() override;
	float isCollison(sf::FloatRect obj);

private:

};