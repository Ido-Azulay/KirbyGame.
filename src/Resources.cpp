#pragma once

#include "Resources.h"

//=======================================constructor=======================
Resources::Resources()
{
    loadTextures();

    m_font.loadFromFile("ka1.ttf");
    loadSounds();
}

Resources& Resources::instance() //this is a singleton class so the loading of the resources will ouccur once.
{
    static Resources inst;  //static so the resources will called once
    return inst;
}


//loading wav files
void Resources::loadSounds()
{
    m_sound.resize(Sounds::s_total);

    m_sound[s_airPuff].loadFromFile("airPuff_s.wav");
    m_sound[s_airSuck].loadFromFile("airSuck_s.wav");
    m_sound[s_enemyDead].loadFromFile("enemyDead_s.wav");
    m_sound[s_fire].loadFromFile("fire_s.wav");
    m_sound[s_fly].loadFromFile("fly_s.wav");
    m_sound[s_gift].loadFromFile("gift_s.wav");
	m_sound[s_hitByEnemy].loadFromFile("hitByEnemy_s.wav");
	m_sound[s_jump].loadFromFile("jump_s.wav");
	m_sound[s_lose].loadFromFile("lose_s.wav");
	m_sound[s_soperPower].loadFromFile("soperPower_s.wav");
	m_sound[s_starHit].loadFromFile("starHit_s.wav");
	m_sound[s_starShoot].loadFromFile("starShoot_s.wav");
	m_sound[s_swallow].loadFromFile("swallow_s.wav");
	m_sound[s_winSong].loadFromFile("winSong.wav");
	m_sound[s_looseSong].loadFromFile("loseSong.wav");
	m_sound[s_menuSong].loadFromFile("MenuSong.wav");
	m_sound[s_gameSong].loadFromFile("GameSong.wav");
	m_sound[s_shootingIce].loadFromFile("shootingIce.wav");
	m_sound[s_mouseClick].loadFromFile("mouseSound.wav");
	m_sound[s_starDead].loadFromFile("starDead.wav");

}

//loading all images
void Resources::loadTextures()
{
    m_textureVec.resize(TextureObject::t_Total);

   // m_textureVec[TextureObject::t_Kirby].loadFromFile("Kirby.png");
    m_textureVec[TextureObject::t_Kirby].loadFromFile("Kirby_Normal.png");
    m_textureVec[TextureObject::t_Wall].loadFromFile("level1_floor.png");
    m_textureVec[TextureObject::t_AirPuff].loadFromFile("kirbySpit.png");
    //m_textureVec[TextureObject::t_Ghost].loadFromFile("red_ghost1.png");
  
    m_textureVec[TextureObject::t_map1].loadFromFile("Kirby_level1_map.png");
    m_textureVec[TextureObject::t_swordEnemy].loadFromFile("swordEnemy.png");

    m_textureVec[TextureObject::t_tiny_kirby].loadFromFile("tiny_kirby.png");

    m_textureVec[TextureObject::t_background].loadFromFile("BG.png");
    m_textureVec[TextureObject::t_inhale].loadFromFile("AirSuck1.png");
    m_textureVec[TextureObject::t_kirbyStar].loadFromFile("kirbyStar.png");
    m_textureVec[TextureObject::t_swordKirby].loadFromFile("swordKirby.png");
    m_textureVec[TextureObject::t_iceKirby].loadFromFile("iceKirby.png");
    m_textureVec[TextureObject::t_fireKirby].loadFromFile("fireKirby.png");

    m_textureVec[TextureObject::t_plantEnemy].loadFromFile("plantEnemy.png");
    m_textureVec[TextureObject::t_orangeEnemy].loadFromFile("waddle.png");
    m_textureVec[TextureObject::t_fire].loadFromFile("Fire.png");
    m_textureVec[TextureObject::t_fireEnemy].loadFromFile("fireEnemy.png");
    m_textureVec[TextureObject::t_deadAnimation].loadFromFile("deadAnimation.png");
    m_textureVec[TextureObject::t_flyingEnemy].loadFromFile("flyingEnemy.png");
    m_textureVec[TextureObject::t_apple].loadFromFile("apple.png");
    m_textureVec[TextureObject::t_kirbyLife].loadFromFile("kirbyLife.png");
    m_textureVec[TextureObject::t_ice].loadFromFile("Ice.png");
    m_textureVec[TextureObject::t_iceManEnemy].loadFromFile("iceManEnemy.png");
    m_textureVec[TextureObject::t_blackStarEnemy].loadFromFile("backStarEnemy.png");

    
	m_MenuTexture.resize(Menu_Textures::t_Total);

	m_MenuTexture[Menu_Textures::t_Back].loadFromFile("Menu_Back.png");

	m_MenuTexture[Menu_Textures::t_Backround].loadFromFile("menubackround.png");

	m_MenuTexture[Menu_Textures::t_Exit].loadFromFile("Menu_EXIT2.png");
	m_MenuTexture[Menu_Textures::t_Play].loadFromFile("Menu_play2.png");
	m_MenuTexture[Menu_Textures::t_Help].loadFromFile("Menu_Help2.png");
	m_MenuTexture[Menu_Textures::t_helpBackround].loadFromFile("helpMenu.png");
	m_MenuTexture[Menu_Textures::t_Loose].loadFromFile("loseScreen.png");
	m_MenuTexture[Menu_Textures::t_Win].loadFromFile("winScreen.png");
}


//========================================Get Functions =======================
//return sound by sound enum
sf::SoundBuffer& Resources::getSound(Sounds sound)
{
    return m_sound[sound];
}

//return disired texture by texture enum
const sf::Texture& Resources::getTexture(TextureObject texObj) const
{
    return m_textureVec[texObj];
}


//returns the font for board text display (score and time and lives)
const sf::Font& Resources::getFont() const
{
    return m_font;
}

const sf::Texture& Resources::getMenuTexture(Menu_Textures texture) const
{
	return m_MenuTexture[texture];
}