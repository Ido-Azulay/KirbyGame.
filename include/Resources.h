#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "ConstAndEnum.h"

class Resources
{
public:

	enum TextureObject
	{
		t_Kirby,
		t_normal_kirby,
		t_Wall,
		t_AirPuff,
		t_map1,
		t_swordEnemy,
		t_tiny_kirby,
		t_background,
		t_inhale,
		t_kirbyStar,
		t_swordKirby,
		t_fireKirby,
		t_iceKirby,
		t_plantEnemy,
		t_orangeEnemy,
		t_fire,
		t_fireEnemy,
		t_deadAnimation,
		t_flyingEnemy,
		t_apple,
		t_kirbyLife,
		t_ice,
		t_iceManEnemy,
		t_blackStarEnemy,
		// Add other...
		t_Total
	};

	enum Sounds
	{
		s_airPuff,
		s_airSuck,
		s_enemyDead,
		s_fire,
		s_fly,
		s_gift,
		s_hitByEnemy,
		s_jump,
		s_lose,
		s_soperPower,
		s_starHit,
		s_starShoot,
		s_swallow,
		s_winSong,
		s_looseSong,
		s_gameSong,
		s_menuSong,
		s_shootingIce,
		s_mouseClick,
		s_starDead,

		s_total
	};


	~Resources() = default;
	const sf::Texture& getTexture(TextureObject texObj) const;
	const sf::Font& getFont() const;
	sf::SoundBuffer& getSound(Sounds sound); 
	const sf::Texture& getMenuTexture(Menu_Textures texture) const;



	static Resources& instance(); //static so the resources will called once

private:
	Resources(); //private so there will be no duplicates
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;
	void loadSounds();

	
	void loadTextures();


	std::vector<sf::Texture> m_textureVec;

	std::vector<sf::Texture> m_MenuTexture;

	std::vector<sf::SoundBuffer> m_sound;
	sf::Font m_font;

};

