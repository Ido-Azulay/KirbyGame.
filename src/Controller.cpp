#include "Controller.h"

//===================================================CONSTRUCTOR==============================

Controller::Controller() :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGT), "Kirby: Nightmare In Dreamland"), m_level(1)
{
	m_map.LoadMap(m_level);
}


void Controller::Run()
{
	srand(static_cast<unsigned>(time(nullptr)));

	m_clock.restart(); //saves bugs

	m_sound.setBuffer(Resources::instance().getSound(Resources::s_gameSong));

	m_sound.setVolume(80);

	m_sound.setLoop(false);

	m_sound.play();

	while (m_window.isOpen())
	{
		m_window.clear();
		m_menu.drawMenu(m_window); //draw main menu screen
		m_window.display();

		char c; //each mouse click returns a char to a switch case 
		//RunGame();
		for (auto event = sf::Event{}; m_window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			
			case sf::Event::MouseButtonReleased:
				c = m_menu.handleClick(event.mouseButton, m_window); //menu click returns a char for case

				if (c == PLAY)
				{
					m_sound.setBuffer(Resources::instance().getSound(Resources::s_menuSong)); //swithced them

					m_sound.setVolume(100);

					m_sound.setLoop(false);

					m_sound.play();

					RunGame(); //runs game
				}
				if (c == EXIT)
				{
					if (m_menu.getIsHelp())  //because back and exit button are in the same place
					{
						m_menu.setIsHelp();
					}
					else  m_window.close();
				}
				break;


			case sf::Event::MouseMoved:

				m_menu.handleHover(event.mouseMove, m_window); //highlight the buttons the mouse hovers over
				break;
				
			}
		
		}
		
	}

}




void Controller::RunGame()
{
	srand(static_cast<unsigned>(time(nullptr)));
	m_clock.restart(); //saves bugs 

	while (m_window.isOpen())
	{
		if (m_map.getKirbyLives() <= 0)
		{
			
			sf::View v;
			sf::FloatRect r(0.f, 0.f, 1.f, 1.11f);
			v.setViewport(r);
			m_window.setView(v);
			m_window.clear();
			m_menu.displayLoose(m_window);
			m_window.display();
			
			m_sound.setBuffer(Resources::instance().getSound(Resources::s_looseSong));

			m_sound.setVolume(80);

			m_sound.setLoop(false);

			m_sound.play();

			auto pause = std::chrono::high_resolution_clock::now();
			std::this_thread::sleep_for(std::chrono::seconds(3));
			m_map.LoadMap(1);

			

			m_sound.setBuffer(Resources::instance().getSound(Resources::s_gameSong));

			m_sound.setVolume(80);

			m_sound.setLoop(false);

			m_sound.play();

			return;
		}

		if (m_map.getDoor() > 3)
		{

			sf::View v;
			sf::FloatRect r(0.f, 0.f, 1.f, 1.11f);
			v.setViewport(r);
			m_window.setView(v);
			m_window.clear();
			m_menu.displayWin(m_window);
			m_window.display();

			m_sound.setBuffer(Resources::instance().getSound(Resources::s_winSong));

			m_sound.setVolume(80);

			m_sound.setLoop(false);

			m_sound.play();

			auto pause = std::chrono::high_resolution_clock::now();
			std::this_thread::sleep_for(std::chrono::seconds(7));

			m_map.LoadMap(1);
			

			m_sound.setBuffer(Resources::instance().getSound(Resources::s_gameSong));

			m_sound.setVolume(80);

			m_sound.setLoop(false);

			m_sound.play();

			return;
		}
		drawMap(); //draw map 
		updateMap(); //update map characters movment and behaviors 

		for (auto event = sf::Event{}; m_window.pollEvent(event);) //if user wants to exit game during play
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			}
		}

	
	}
}

//this function draws the map
void Controller::drawMap()
{
	m_window.clear();
	m_map.drawMap(m_window);
	m_window.display();
}

//this function calls the update map function which handles all the objects momvent
void Controller::updateMap()
{
	auto deltaTime = m_clock.restart();
	m_map.updateMap(deltaTime);

}


