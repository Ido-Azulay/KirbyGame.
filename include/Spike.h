#pragma once

#include "mapObject.h"
#include "ConstAndEnum.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Spike : public mapObject {

public:
	Spike();
	virtual void createLine() override;
	float isCollison(sf::FloatRect obj);

private:

};