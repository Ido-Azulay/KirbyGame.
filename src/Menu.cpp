#include "Menu.h"
#include "Resources.h"

const float BUTTON_SIZE_WIDTH = 600;
const float BUTTON_SIZE_HEIGHT = 100;

Menu::Menu()
{
	m_sound.setBuffer(Resources::instance().getSound(Resources::s_mouseClick));
	//setting textures and sizes for backrounds and buttons of the main menu

	m_background.setTexture(&Resources::instance().getMenuTexture(t_Backround));
	m_background.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGT));

	m_play_button.setTexture(&Resources::instance().getMenuTexture(t_Play));
	m_play_button.setSize(sf::Vector2f(BUTTON_SIZE_WIDTH, BUTTON_SIZE_HEIGHT));
	m_play_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4), (WINDOW_HEIGT - 550)));

	m_exit_button.setTexture(&Resources::instance().getMenuTexture(t_Exit));
	m_exit_button.setSize(sf::Vector2f(BUTTON_SIZE_WIDTH, BUTTON_SIZE_HEIGHT));
	m_exit_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4), (WINDOW_HEIGT - 170)));

	m_help_button.setTexture(&Resources::instance().getMenuTexture(t_Help));
	m_help_button.setSize(sf::Vector2f(BUTTON_SIZE_WIDTH, BUTTON_SIZE_HEIGHT));
	m_help_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4), (WINDOW_HEIGT - 360)));

	m_back_button.setTexture(&Resources::instance().getMenuTexture(t_Back));
	m_back_button.setSize(sf::Vector2f(BUTTON_SIZE_WIDTH, BUTTON_SIZE_HEIGHT));
	m_back_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4), (WINDOW_HEIGT - 120)));
	
	m_help_display.setTexture(&Resources::instance().getMenuTexture(t_helpBackround));
	m_help_display.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGT));

	m_gameOverDisplay.setTexture(&Resources::instance().getMenuTexture(t_Loose));
	m_gameOverDisplay.setSize(sf::Vector2f(WINDOW_WIDTH - 200, WINDOW_HEIGT));

	m_WinDisplay.setTexture(&Resources::instance().getMenuTexture(t_Win));
	m_WinDisplay.setSize(sf::Vector2f(WINDOW_WIDTH - 100, WINDOW_HEIGT));
}

Menu::~Menu()
{
}

//this function returns which button was pressed by the user and returns a char for each button
//so the controller will know which mode to run
//game help or back button
char Menu::handleClick(const sf::Event::MouseButtonEvent& event , sf::RenderWindow& window)
{
	if (m_play_button.getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
	{
		return PLAY;
	}

	if (m_exit_button.getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
	{
		return EXIT;
	}

	if (m_help_button.getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
	{
		m_draw_help = true;
		return HELP;
	}

	if (m_back_button.getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
	{
		m_draw_help = false;
		return BACK;
	}

	return false;
}


//this function makes the buttons a little darker when the mouse hovers over them
void Menu::handleHover(const sf::Event::MouseMoveEvent& event, sf::RenderWindow& window)
{

	if (m_play_button.getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
	{
		sf::Color c(255, 255, 255, 200); //setting the button with a darker rectangle
		m_play_button.setFillColor(c);
		//m_sound.play();
	}
	else
	{
		sf::Color c(255, 255, 255);
		m_play_button.setFillColor(c);
	}

	if (m_exit_button.getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
	{
		sf::Color c(255, 255, 255, 200);
		m_exit_button.setFillColor(c);
		//m_sound.play();
	}
	else {
		sf::Color c(255, 255, 255);
		m_exit_button.setFillColor(c);
	}

	if (m_help_button.getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
	{
		sf::Color c(255, 255, 255, 200);
		m_help_button.setFillColor(c);
		//m_sound.play();
	}
	else {
		sf::Color c(255, 255, 255);
		m_help_button.setFillColor(c);
	}

	if (m_back_button.getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
	{
		sf::Color c(255, 255, 255, 200);
		m_back_button.setFillColor(c);
		//m_sound.play();
	}
	else {
		sf::Color c(255, 255, 255);
		m_back_button.setFillColor(c);
	}

}

//this function draws the menu on the screen

void Menu::drawMenu(sf::RenderWindow &window)
{
	if (m_draw_help) //if user pressed help button draw the help screen
	{
		drawHelp(window); 
	}
	else {
		window.draw(m_background);
		window.draw(m_play_button);
		window.draw(m_help_button);
		window.draw(m_exit_button);
	}

}

void Menu::drawHelp(sf::RenderWindow &window)
{
	window.draw(m_help_display);
	window.draw(m_back_button);
}

//this function displays loose message

void Menu::displayLoose(sf::RenderWindow& window) 
{
	m_background.setSize(sf::Vector2f(WINDOW_WIDTH - 200, WINDOW_HEIGT));
	m_help_display.setSize(sf::Vector2f(WINDOW_WIDTH - 200, WINDOW_HEIGT));
	m_play_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4 - 100), (WINDOW_HEIGT - 550)));
	m_exit_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4 - 100), (WINDOW_HEIGT - 170)));
	m_help_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4 - 100), (WINDOW_HEIGT - 360)));
	m_back_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4 - 100), (WINDOW_HEIGT - 120)));
	window.draw(m_gameOverDisplay);
	
}

//this function displays win message
void Menu::displayWin(sf::RenderWindow& window)
{
	m_background.setSize(sf::Vector2f(WINDOW_WIDTH - 200, WINDOW_HEIGT));
	m_help_display.setSize(sf::Vector2f(WINDOW_WIDTH - 200, WINDOW_HEIGT));
	m_play_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4 - 100), (WINDOW_HEIGT - 550)));
	m_exit_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4 - 100), (WINDOW_HEIGT - 170)));
	m_help_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4 - 100), (WINDOW_HEIGT - 360)));
	m_back_button.setPosition(sf::Vector2f((WINDOW_WIDTH / 4 - 100), (WINDOW_HEIGT - 120)));

	window.draw(m_WinDisplay);

	
}

//this function returns if the user pressed the help button
bool Menu::getIsHelp()
{
	return m_draw_help;
}

//this function sets the help boolian member to false
//it means the user pressed the back button and now we display the main menu screen
void Menu::setIsHelp()
{
	m_draw_help = false;
}

