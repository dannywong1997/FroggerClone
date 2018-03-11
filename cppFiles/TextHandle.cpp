#include "TextHandle.h"

using namespace std;
TextHandle::TextHandle()
{
	loadFont();
}


TextHandle::~TextHandle()
{
}
void TextHandle::loadFont() 
{
	if (!font.loadFromFile("../font/Pixeled.ttf"))
	{
		cout << "Error 01: Font file missing." << endl;
	}
}
void TextHandle::initialize_tStartMenu()
{
	tStartMenu.setString("Press Space to start the game.");
	tStartMenu.setFont(font);
	tStartMenu.setFillColor(sf::Color::White);
	tStartMenu.setCharacterSize(15);
	tStartMenu.setPosition(15.0f, 200.0f);
}
void TextHandle::initialize_tRestart() {
	tRestart.setString("Press Space to restart.");
	tRestart.setFont(font);
	tRestart.setFillColor(sf::Color::White);
	tRestart.setCharacterSize(15);
	tRestart.setPosition(15.0f, 230.0f);
}
void TextHandle::draw_tRestart(sf::RenderWindow &tempWindow) {
	tempWindow.draw(tRestart);
}
void TextHandle::draw_tStartMenu(sf::RenderWindow &tempWindow) 
{
	tempWindow.draw(tStartMenu);
}
void TextHandle::initialize_tReady()
{
	tReady.setString("3");
	tReady.setFont(font);
	tReady.setFillColor(sf::Color::White);
	tReady.setCharacterSize(40);
	tReady.setPosition(190.0f, 200.0f);
}
void TextHandle::draw_tReady(sf::RenderWindow &tempWindow)
{
	tempWindow.draw(tReady);
}
void TextHandle::tReadyCountDown(sf::Clock &tempClock) 
{
	sf::Time tempTime = tempClock.getElapsedTime();
	if (tempTime.asSeconds() > 1.0f)
	{
		tReady.setString("2");
	}
	if (tempTime.asSeconds() > 2.0f)
	{
		tReady.setString("1");
	}
	if (tempTime.asSeconds() > 3.0f)
	{
		tReady.setString("Go!");
	}
	if (tempTime.asSeconds() > 4.0f)
	{
		tReady.setString(" ");
	}
}
void TextHandle::initialize_tHealthAndLevelCount(int Health, int Level)
{
	tHealthAndLevelCount.setString("Health:" + std::to_string(Health) + "     Current Level: " + std::to_string(Level));
	tHealthAndLevelCount.setFont(font);
	tHealthAndLevelCount.setFillColor(sf::Color::White);
	tHealthAndLevelCount.setCharacterSize(15);
	tHealthAndLevelCount.setPosition(0.0f, 460.0f);
}
void TextHandle::draw_tHealthAndLevelCount(sf::RenderWindow &tempWindow)
{
	tempWindow.draw(tHealthAndLevelCount);
}
void TextHandle::initialize_tGameOver()
{
	tGameOver.setCharacterSize(20);
	tGameOver.setPosition(10.0f, 100.0f);
	tGameOver.setFont(font);
}
void TextHandle::tGameOver_GoodEnd() {
	tGameOver.setString("Congrats!\nYou have beaten this \ngame.");
	tGameOver.setFillColor(sf::Color::Blue);
}
void TextHandle::tGameOver_BadEnd() {
	tGameOver.setString("Game Over!");
	tGameOver.setFillColor(sf::Color::Red);
}
void TextHandle::draw_tGameOver(sf::RenderWindow &tempWindow) {
	tempWindow.draw(tGameOver);
}