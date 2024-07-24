#pragma once

#include "mapObject.h"
#include "ConstAndEnum.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Ceiling : public mapObject {

public:
	Ceiling();
	virtual void createLine() override;
	float isCollison(sf::FloatRect obj);

private:

};