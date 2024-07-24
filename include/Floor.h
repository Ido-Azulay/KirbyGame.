#pragma once

#include "mapObject.h"
#include "ConstAndEnum.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Floor : public mapObject {

public:
	Floor();
	virtual void createLine() override;
	float isCollison(sf::FloatRect obj);

private:

};