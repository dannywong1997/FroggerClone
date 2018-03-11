#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
class TextHandle
{
public:
	TextHandle();
	~TextHandle();
	void loadFont();
	void initialize_tStartMenu();
	void initialize_tRestart();
	void initialize_tReady();
	void initialize_tGameOver();
	void tGameOver_GoodEnd();
	void tGameOver_BadEnd();
	void draw_tGameOver(sf::RenderWindow & tempWindow);
	void initialize_tHealthAndLevelCount(int Health, int Level);
	void tReadyCountDown(sf::Clock & tempClock);
	void draw_tReady(sf::RenderWindow &tempWindow);
	void draw_tStartMenu(sf::RenderWindow &tempWindow);
	void draw_tHealthAndLevelCount(sf::RenderWindow & tempWindow);
	void draw_tRestart(sf::RenderWindow & tempWindow);

private:
	sf::Font font;
	sf::Text tStartMenu, tReady, tHealthAndLevelCount, tRestart, tGameOver;
};

